
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class GameActor() {
public:
    void move();
    void jump();
    void attack();
};

class Move : public Command {
    GameActor *actor;
    float distance;
    string direction;

public:
    MoveCommand(GameActor *a, const std::string &dir, float dist);
    execute() override;
    undo() override;
};