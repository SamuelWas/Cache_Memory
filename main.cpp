#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
#include "headers/block.h"
#include "headers/cache.h"

#define MEM_WORDS 4096
#define WORD_SIZE 32

int binaryToDecimal(std::string binaryNumber) {
    return std::stoi(binaryNumber, 0, 2);
}

std::string decimalToBinary(int decimal) {
    return std::bitset<WORD_SIZE>(decimal).to_string();
}

int main() {
    int endereco, operacao;
    std::string dado;

    Cache cache;

    // 20 bits tag, 8 bits index, 4 bits offset
    std::cin >> endereco;
    do{
        std::cin >> operacao;


        std::string response;
        if (operacao == 0) {
            response = cache.read(decimalToBinary(endereco));
            std::cout << endereco << " " << operacao << " " + response << std::endl;
        }
        else {
            std::cin >> dado;
            response = cache.write(decimalToBinary(endereco), dado);
            std::cout << endereco << " " << operacao << " " +  dado + " " + response << std::endl;
        }


        // else write(endereco, dado)

        // cache.print();
        // std::cout << getTagSize() << getIndexSize() << getOffsetSize() << std::endl;

    } while (std::cin >> endereco);
    return 0;
}