//use case: you'd need to represent part-whole hierarchies of objects

#include <iostream>

//component
class GameEntity {
public:
    virtual void update() = 0;
    void addComponent(GameEntity *entity) {}
    void removeComponent(GameEntity *entity) {}
    template <class T>
    void getComponent<T>() {}
    virtual ~GameEntity() {}
};

//leaf
class MeshRenderer : public GameEntity {
public:
    void setMesh();
};
class Transform : public GameEntity {
public:
    void update();
};
//compositable
class Player : public GameEntity {
public:
    void update() override;
};
