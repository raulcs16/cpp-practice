#include <iostream>
#include <stack>
#include <string>

class PlayerMemento {

public:
    PlayerMemento(int hp, int level, std::string checkpoint);

private:
    int hp;
    int level;
    std::string checkpoint;
};

class Player {
public:
    void setState(int hp, int level, std::string checkPoint);
    void load(const PlayerMemento &memento);
    PlayerMemento save() const;

private:
    int hp;
    int level;
    std::string checkpoint;
};

class LevelHistory {
public:
    void save(const PlayerMemento &m);
    PlayerMemento lastCheckPoint() {
        PlayerMemento checkpoint = history.top();
        history.pop();
        return checkpoint;
    }

private:
    std::stack<PlayerMemento> history;
}