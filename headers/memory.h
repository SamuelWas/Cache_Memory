#include <math.h>
#define MEM_WORDS 4096
#define WORD_SIZE 32
class Memory {
public:
    Memory() {
        blocks = std::vector<std::string> (MEM_WORDS, "memoryData");
        indexSize = log2(MEM_WORDS);
    }

    std::string read(std::string endereco);
    void write(std::string endereco, std::string dado);
    int binaryToDecimal(std::string binaryNumber);

    std::vector<std::string> blocks;
    int indexSize;
};

std::string Memory::read(std::string endereco) {
    return blocks[binaryToDecimal(endereco)];
}

void Memory::write(std::string endereco, std::string dado) {
    blocks[binaryToDecimal(endereco)] = dado;
}

int Memory::binaryToDecimal(std::string binaryNumber) {
    return std::stoi(binaryNumber, 0, 2);
}