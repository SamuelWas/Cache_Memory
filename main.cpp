#include <iostream>
#include <math.h>
#include <vector>
#include "block.h"
#include "cache.h"

#define MEM_WORDS 4096
#define WORD_SIZE 32

int binaryToDecimal(std::string binaryNumber) {
    return std::stoi(binaryNumber, 0, 2);
}

int main() {
    int endereco, operacao;
    std::string dado;

    // 20 bits tag, 8 bits index, 4 bits offset
    std::cin >> endereco;
    std::cin >> operacao;
    std::cin >> dado;

    Cache cache;

    if (operacao == 0) cache.read(endereco);
    // else write(endereco, dado)

    // cache.print();
    // std::cout << getTagSize() << getIndexSize() << getOffsetSize() << std::endl;
    // std::cout << endereco << operacao << dado << std::endl; 
    return 0;
}