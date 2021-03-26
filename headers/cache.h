#define BLOCKS 256
#define BLOCKS_WORDS 4
#define BLOCKS_BITS 32

class Cache {
public:
    Cache() {
        blocks = std::vector<Block> (BLOCKS);
        hits = 0;
        misses = 0;

        indexSize =  log2(BLOCKS);
        offsetSize = log2(BLOCKS_WORDS) + 2;
        tagSize =  BLOCKS_BITS - indexSize - offsetSize;
    }
    
    std::string read(std::string endereco);
    std::string write(std::string endereco, std::string dado);

    int indexSize;
    int offsetSize;
    int tagSize;

    std::string getIndex(std::string endereco);
    int binaryToDecimal(std::string binaryNumber);

    void print();

    std::vector<Block> blocks;
    int hits;
    int misses;
};

std::string Cache::read(std::string endereco) {
    std::string index = getIndex(endereco);
    int indexDecimal = binaryToDecimal(index);

    if (!blocks[indexDecimal].valid) {
        misses++;
        return "MISS";
    }
    hits++;
    return "HIT";

}

std::string Cache::write(std::string endereco, std::string dado) {
    std::string index = getIndex(endereco);
    int indexDecimal = binaryToDecimal(index);

    if (!blocks[indexDecimal].valid) {
        blocks[indexDecimal].valid = 1;
        blocks[indexDecimal].data = dado;
        return "W";
    }
    return "Another value on block, need to write-back!";

}

std::string Cache::getIndex(std::string endereco) {
    return endereco.substr(tagSize, indexSize);
}

int Cache::binaryToDecimal(std::string binaryNumber) {
    return std::stoi(binaryNumber, 0, 2);
}

void Cache::print() {
    for (int i = 0; i < blocks.size(); i++) {
        std::cout << "index " << i << ": [ ";
        std::cout << blocks[i].valid << " " + blocks[i].tag + " " + blocks[i].data << " ";
        std::cout << "]" << std::endl;
    }
}
