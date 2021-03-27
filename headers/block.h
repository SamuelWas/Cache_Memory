#define BLOCKS_WORDS 4

class Block {
public:
    Block() {
        valid = 0;
        tag = "empty";
        words = std::vector<std::string> (BLOCKS_WORDS, "emptyCache");
        offset = "empty";
    }
    int valid;
    std::string tag;
    std::vector<std::string> words;
    std::string offset;
};