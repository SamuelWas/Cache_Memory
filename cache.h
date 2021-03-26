#define BLOCKS 256
#define BLOCKS_WORDS 4
#define BLOCKS_BITS 32

class Cache {
public:
    Cache() {
        blocks = std::vector<Block> (BLOCKS);
    }
    void read(int endereco);
    int getIndexSize();
    int getOffsetSize();
    int getTagSize();

    void print();
    std::vector<Block> blocks;
};

void Cache::read(int endereco) {
    if (blocks[endereco].valid != -1) std::cout << "Hit" << std::endl;
    if (blocks[endereco].valid == -1) std::cout << "Miss" << std::endl;
}

int Cache::getIndexSize() {
    return log2(BLOCKS);
}

int Cache::getOffsetSize() {
    return log2(BLOCKS_WORDS) + 2;
}

int Cache::getTagSize() {
    return BLOCKS_BITS - getIndexSize() - getOffsetSize();
}

void Cache::print() {
    for (int i = 0; i < blocks.size(); i++) {
        std::cout << "index " << i << ": [ ";
        std::cout << blocks[i].valid << " " + blocks[i].tag + " " + blocks[i].data << " ";
        std::cout << "]" << std::endl;
    }
}
