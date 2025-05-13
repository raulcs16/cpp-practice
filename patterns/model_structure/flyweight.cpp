
#include <iostream>
#include <memory>
#include <string>

//holds what doenst change
class TreeType {
public:
    TreeType(const string &type, string &text);
    void draw(int x, int y, int h);

private:
    string type;
    string texture;
};

//creates or returns ref to TreeType
class TreePool {
public:
    std::shared_ptr<TreeType> getTreeType(const std::string &type);
};

//holds wha changes
class Tree {
public:
    Tree(int x, int y, int height);

private:
    int x, int y, int height;
};