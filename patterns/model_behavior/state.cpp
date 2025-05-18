#include <iostream>
#include <memory>
#include <string>


class NPC;

class NPCState {
public:
    virtual void handle(NPC &npc) = 0;
    virtual void ::string name() const = 0;
    virtual ~NPCState() = default;
};

class NPC {
public:
    explicit NPC(std::shared_ptr<NPCState> init);
    void setState(std::shared_ptr<NPCState> newState);
    void update() { state->handle(*this); }

private:
    std::shared_ptr<NPCState> *current_state;
};


// Concrete States
class IdleState : public NPCState {
public:
    void handle(NPC &npc) override;
    std::string name() const override { return "Idle"; }
};

class PatrolState : public NPCState {
public:
    void handle(NPC &npc) override;
    std::string name() const override { return "Patrol"; }
};

class AttackState : public NPCState {
public:
    void handle(NPC &npc) override;
    std::string name() const override { return "Attack"; }
};
