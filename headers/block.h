#define BLOCKS_WORDS 4

class Block {
public:
    Block() {
        valid = 0;
        tag = "empty";
        words = std::vector<std::string> (BLOCKS_WORDS, "emptyCache");
        dirty = 0;
    }

    int valid;
    int dirty;
    std::string tag;
    std::vector<std::string> words;

    void write(std::string tagAddress, int offset, std::string dado);
};

void Block::write(std::string tagAddress, int offset, std::string dado) {
    valid = 1;
    dirty = 1;
    tag = tagAddress;
    words[offset] = dado;
}