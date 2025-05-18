#include <cstlib>
#include <ctime>
#include <iostream>
#include <memory>

class AIStrategy {
public:
    virtual void execute() = 0;
    virtual ~AIStrategy() = default;
};

class RandChoice : AIStrategy {
public:
    void execute() override;
};
class WeightedRandom : AIStrategy {
public:
    void execute() override;
};

class Context : AIStrategy {
public:
    void execute() override;
};

class Bot {
public:
    void setStrategy(std::shared_ptr<AIStrategy> strat);
    void makeChoice() {
        if (strategy) {
            strategy->execute();
        } else {
            return;
        }
    }

private:
    std::shared_ptr<AIStrategy> strategy;
};
