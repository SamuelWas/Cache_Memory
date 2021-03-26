class Block {
public:
    Block() {
        valid = 0;
        tag = "empty";
        data = "empty";
    }
    int valid;
    std::string tag;
    std::string data;
};