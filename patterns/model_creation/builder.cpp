


class GameCharacter {
public:
    void setName(const std::string &name_);
    void setWeapon(const std::string &weapon_);
    void setArmor(const std::string &armor_);
    void setSkill(const std::string &skill_);
    void setMount(const std::string &mount_);

private:
    std::string name;
    std::string weapon;
    std::string armor;
    std::string mount;
};

class CharacterBuilder {
public:
    virtual void buildName() = 0;
    virtual void buildWeapon() = 0;
    virtual void buildArmor() = 0;
    virtual void buildSkill() = 0;
    virtual void buildMount() = 0;
    virtual GameCharacter getCharcter() = 0;
};

// === Concrete Builder: Warrior ===
class WarriorBuilder : public CharacterBuilder {
private:
    std::unique_ptr<GameCharacter> character;

public:
    WarriorBuilder() { character = std::make_unique<GameCharacter>(); }

    void buildName() override { character->setName("Conan the Warrior"); }
    void buildWeapon() override { character->setWeapon("Greatsword"); }
    void buildArmor() override { character->setArmor("Heavy Plate"); }
    void buildSkill() override { character->setSkill("Berserk Rage"); }
    void buildMount() override { character->setMount("War Horse"); }

    std::unique_ptr<GameCharacter> getCharacter() override { return std::move(character); }
};

// === Concrete Builder: Mage ===
class MageBuilder : public CharacterBuilder {
private:
    std::unique_ptr<GameCharacter> character;

public:
    MageBuilder() { character = std::make_unique<GameCharacter>(); }

    void buildName() override { character->setName("Elandra the Mage"); }
    void buildWeapon() override { character->setWeapon("Staff of Wisdom"); }
    void buildArmor() override { character->setArmor("Mystic Robe"); }
    void buildSkill() override { character->setSkill("Arcane Blast"); }
    void buildMount() override { /* Mage doesn't get a mount */ }

    std::unique_ptr<GameCharacter> getCharacter() override { return std::move(character); }
};

class CharacterDirector {
public:
    void construct(CharacterBuilder &builder) {
        builder.buildName();
        builder.buildWeapon();
        builder.buildArmor();
        builder.buildSkill();
        builder.buildMount();
    }
};