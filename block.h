class Block {
public:
    Block() {
        visited = -1;
        tag = "empty";
        data = "empty";
    }
    int visited;
    std::string tag;
    std::string data;
};