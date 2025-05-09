
//abstract A
class MeleEnemy {
public:
    virtual void attack() = 0;
};
//abstract B
class RangedEnemy {
public:
    virtual void attack() = 0;
};

// concrete A 1
class Zombie : public MeleEnemy {
public:
    void attack() override;
};

//concrete A 2
class Spider : public MeleEnemy {
public:
    void attack() override;
};

//concrete B1

class Skeleton : public RangedEnemy {
public:
    void attack() override;
};

//conrete B2

class PlasmaShooter : public RangedEnemy {

public:
    void attack() override;
};


//Abstract Factory

class EnemyFactory {
public:
    virtual void SpawnMeleEnemy() = 0;
    virtual void SpawnRangedEnemy() = 0;
};

class NoobFactoy : EnemyFactory {
public:
    void SpawnMeleEnemy() override {
        //spawn <Zombie>
    };
    void SpawnRanged() override {
        //spawn <Skeleton>
    };
};
class MidFactoy : EnemyFactory {
public:
    void SpawnMeleEnemy() override {
        //spawn <Spider>
    };
    void SpawnRanged() override {
        //spawn <PlasmaShooter>
    };
};