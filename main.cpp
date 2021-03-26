#include <iostream>
#include <math.h>
#include <vector>
#include "block.h"

#define MEM_WORDS 4096
#define WORD_SIZE 32

#define BLOCKS 256
#define BLOCKS_WORDS 4
#define BLOCKS_BITS 32

int binaryToDecimal(std::string binaryNumber) {
    return std::stoi(binaryNumber, 0, 2);
}

int getIndexSize() {
    return log2(BLOCKS);
}

int getOffsetSize() {
    return log2(BLOCKS_WORDS) + 2;
}

int getTagSize() {
    return BLOCKS_BITS - getIndexSize() - getOffsetSize();
}

void printVector2D(std::vector<Block> vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << "index " << i << ": [ ";
        std::cout << vector[i].visited << " " + vector[i].tag + " " + vector[i].data << " ";
        std::cout << "]" << std::endl;
    }
}

void read(int endereco, std::vector<Block> blocks) {
    if (blocks[endereco].visited != -1) std::cout << "Hit" << std::endl;
    if (blocks[endereco].visited == -1) std::cout << "Miss" << std::endl;
}

int main() {
    int endereco, operacao;
    std::string dado;

    // 20 bits tag, 8 bits index, 4 bits offset
    std::cin >> endereco;
    std::cin >> operacao;
    std::cin >> dado;

    std::vector<Block> blocks(BLOCKS);

    // printVector2D(kblocks);
    if (operacao == 0) read(endereco, blocks);
    // else write(endereco, dado)
    // std::cout << getTagSize() << getIndexSize() << getOffsetSize() << std::endl;
    // std::cout << endereco << operacao << dado << std::endl; 
    return 0;
}