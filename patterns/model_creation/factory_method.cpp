

#include <iostream>


//product
class PowerUp {
public:
    virtual void activate() const = 0;
};

// concrete products
class HealthBoost : public PowerUp {
public:
    void activate() const override;
};

class SpeedBoost : public PowerUp {
public:
    void activate() const override;
};


//creator
class PowerUpFactory {
public:
    virtual PowerUp createPowerUp() const = 0;
}

//concrete factories

class HealthBoostFactory : public PowerUpFactory {
public:
    PowerUp createPowerUp() const override { return HealthBoost; }
};
class SpeedBoostFactory : public PowerUpFactory {
public:
    PowerUp createPowerUp() const override { return SpeedBoost; }
};