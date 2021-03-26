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
    
    std::string read(int endereco);
    std::string write(int endereco, std::string dado);

    int indexSize;
    int offsetSize;
    int tagSize;

    void print();

    std::vector<Block> blocks;
    int hits;
    int misses;
};

std::string Cache::read(int endereco) {
    if (!blocks[endereco].valid) {
        misses++;
        return "MISS";
    }
    hits++;
    return "HIT";

}

std::string Cache::write(int endereco, std::string dado) {
    if (!blocks[endereco].valid) {
        blocks[endereco].valid = 1;
        blocks[endereco].data = dado;
        return "W";
    }
    return "Memory occupied!";

}

void Cache::print() {
    for (int i = 0; i < blocks.size(); i++) {
        std::cout << "index " << i << ": [ ";
        std::cout << blocks[i].valid << " " + blocks[i].tag + " " + blocks[i].data << " ";
        std::cout << "]" << std::endl;
    }
}
