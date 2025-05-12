
#include <iostream>
#include <memory>
#include <unordered_map>

class Enemy {
public:
    virtual void attack() const = 0;
    virtual std::unique_ptr<Enemy> clone() const = 0;
    virtual ~Enemy() = default;
};

class Goblin : public Enemy {
public:
    void attack() const override;
    std::unique_ptr<Enemy> clone() const override { return std::make_unique<Goblin>(*this); }
};

class Dragon : public Enemy {
public:
    void attack() const override;
    std::unique_ptr<Enemy> clone() const override { return std::make_unique<Dragon>(*this); }
};

class EnemyMotherShip {

public:
    std::unique_ptr<Enemy> createClone(std::string &name) const;

private:
    std::unordered_map<std::string, std::unique_ptr<Enemy>> enemies;
};