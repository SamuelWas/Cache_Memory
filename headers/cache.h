#define BLOCKS 256
#define BLOCKS_WORDS 4
#define BLOCKS_BITS 12
#include "memory.h"

class Cache {
public:
    Cache(Memory &mem) 
    :
    memory(mem)
    {
        blocks = std::vector<Block> (BLOCKS);
        hits = 0;
        misses = 0;

        indexSize =  log2(BLOCKS);
        offsetSize = log2(BLOCKS_WORDS);
        tagSize =  BLOCKS_BITS - indexSize - offsetSize;
    }
    
    std::string read(std::string endereco);
    void readFromMemory(std::string endereco);
    std::string write(std::string endereco, std::string dado);

    std::string getIndex(std::string endereco);
    std::string getOffset(std::string endereco);
    std::string getTag(std::string endereco);

    int binaryToDecimal(std::string binaryNumber);
    std::string decimalToBinary(int decimal);

    int indexSize;
    int offsetSize;
    int tagSize;

    void print();

    Memory & memory;
    std::vector<Block> blocks;
    int hits;
    int misses;
};

std::string Cache::read(std::string endereco) {
    std::string index = getIndex(endereco);
    int indexDecimal = binaryToDecimal(index);
    if (!blocks[indexDecimal].valid) {
        misses++;
        readFromMemory(endereco);
        return "MISS";
    }
    hits++;
    return "HIT";
}

void Cache::readFromMemory(std::string endereco) {
    std::string index = getIndex(endereco);
    std::string tag = getTag(endereco);
    int indexDecimal = binaryToDecimal(index);

    for (int wordOffset = 0; wordOffset < BLOCKS_WORDS; wordOffset++) {
        blocks[indexDecimal].words[wordOffset] = memory.read(tag + index + decimalToBinary(wordOffset));
    }
    blocks[indexDecimal].tag = tag;
    blocks[indexDecimal].valid = 1;
}

std::string Cache::write(std::string endereco, std::string dado) {
    // std::string index = getIndex(endereco);
    // int indexDecimal = binaryToDecimal(index);

    // if (!blocks[indexDecimal].valid) {
    //     blocks[indexDecimal].valid = 1;
    //     blocks[indexDecimal].data = dado;
    //     return "W";
    // }
    return "Write not implemented";

}

std::string Cache::getIndex(std::string endereco) {
    return endereco.substr(tagSize, indexSize);
}


std::string Cache::getTag(std::string endereco) {
    return endereco.substr(0, tagSize);
}


std::string Cache::getOffset(std::string endereco) {
    return endereco.substr(indexSize, offsetSize);
}

int Cache::binaryToDecimal(std::string binaryNumber) {
    return std::stoi(binaryNumber, 0, 2);
}

std::string Cache::decimalToBinary(int decimal) {
    const int bits = log2(BLOCKS_WORDS);
    return std::bitset<bits>(decimal).to_string();
}

void Cache::print() {
    for (int index = 0; index < blocks.size(); index++) {
        std::cout << "index " << index << ": [ ";
        std::cout << blocks[index].valid << " " + blocks[index].tag + " ";
        for (int wordOffset = 0; wordOffset < BLOCKS_WORDS; wordOffset++) {
            std::cout << blocks[index].words[wordOffset] << " ";
        }
        std::cout << "]" << std::endl;
    }
}
