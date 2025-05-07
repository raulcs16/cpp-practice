//use case: alternative to subclasses, by dynamically injecting responsibilites through classes,
//end up with a stack of classes DecA(DecB(DecC(..Decorator)))

#include <iostream>

//component
class Weapon {
public:
    virtual ~Weapon() {}
    virtual std::string getDescription() const = 0;
    virtual int getDamage() const = 0;
};

//conceret compoent
class BaseSword : public Weapon {
public:
    BasicSword() {}
    std::string getDescription() const override;
    int getDamage() const override;
};
//Decorator Base
class WeaponDecorator : public Weapon {
public:
    WeaponDecorator(Weapon *decoratedWeapon);
    std::string getDescription() const override;
    int getDamage() const override;

protected:
    Weapon *decorated_weapon;
};
//ConcreteImplementation
class FireEnchatment : public WeaponDecorator {
public:
    FireEnchatment(Weapon *decorated_weapon) : WeaponDecorator(decorated_weapon) {}
    std::string getDescription() const override;
    int getDamage() const override;
};

class SharpnessEnchatment : public WeaponDecorator {
public:
    SharpnessEnchatment(Weapon *decorated_weapon) : WeaponDecorator(decorated_weapon) {}
    std::string getDescription() const override;
    int getDamage() const override;
};