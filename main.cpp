#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
#include <fstream>
#include "headers/block.h"
#include "headers/cache.h"

#define BLOCKS_BITS 12

int binaryToDecimal(std::string binaryNumber) {
    return std::stoi(binaryNumber, 0, 2);
}

std::string decimalToBinary(int decimal) {
    return std::bitset<BLOCKS_BITS>(decimal).to_string();
}

int main() {
    int endereco, operacao;
    std::string dado;

    Memory mem;
    Cache cache(mem);


    std::ofstream results;
    results.open("results.txt",  std::ofstream::out | std::ofstream::trunc);

    std::string result;

    // 2 bits tag, 8 bits index, 2 bits offset
    std::cin >> endereco;
    do{
        std::cin >> operacao;


        std::string response;
        if (operacao == 0) {
            response = cache.read(decimalToBinary(endereco));
            result += std::to_string(endereco) + " " + std::to_string(operacao) + " " + response + "\n";
        }
        if (operacao == 1) {
            std::cin >> dado;
            response = cache.write(decimalToBinary(endereco), dado);
            result += std::to_string(endereco) + " " + std::to_string(operacao) + " " + dado + " " + response + "\n";
        }
    } while (std::cin >> endereco);
    // cache.print();

    results << "READS: " << cache.reads << std::endl;
    results << "WRITES: " << cache.writes << std::endl;
    results << "HITS: " << cache.hits << std::endl;
    results << "MISSES: " << cache.misses << std::endl;
    results << "HIT RATE: " << float(cache.hits) / float(cache.reads) << std::endl;
    results << "MISS RATE: " << float(cache.misses) / float(cache.reads) << std::endl;
    results << std::endl;
    results << result;

    results.close();
    return 0;
}