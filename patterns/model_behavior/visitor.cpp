
#include <iostream>

class Tree;
class Rock;
class TeasureChest;

class GameObjectVisitor {
public:
    virtual void visit(Tree &tree) = 0;

    virtual void visist(Rock &rock) = 0;

    virtual void visist(TeasureChest) = 0;
};

class GameObject {
public:
    void accept(GameObjectVisitor &visitor);
    void swayInWind();
};

class Rock : public GameObject {
    void accept(GameObjectVisitor &visitor) override;
    void crack();
};
class Tree : public GameObject {
    void accept(GameObjectVisitor &visitor) override;
    void open();
    ;
};