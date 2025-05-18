
#include <iostream>

class Tree;
class Rock;
class TeasureChest;

class GameObjectVisitor {
public:
    virtual void visit(tree &tree) = 0;

    virtual void visist(rock &rock) = 0;

    virtual void visist(teasurechest) = 0;
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

class LooterVisotor : public GameObjectVisitor {
private:
public:
    void visit(tree &tree) override = 0;
    void visist(rock &rock) override = 0;
    void visist(teasurechest) override = 0;
}
