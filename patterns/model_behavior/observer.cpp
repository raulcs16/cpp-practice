#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Observer;

class Subject {
public:
    void attachObserver(std::shared_ptr<Observer> obs);
    void notify(const std::string &message);

protected:
    std::vector<std::shared_ptr<Observer>> observers;
};

class Observer {
public:
    virtual void onNotify(const std::string &message) = 0;
    virtual ~Observer() = default;
};

class HealthBar : Observer {
public:
    void onNotify(const std::string &message) override;
};

class Inventory : Observer {
public:
    void onNotify(const std::string &message) override;
};

class PlayerUI : public Subject {
public:
    void updateHealthBar(int health) { notify("health: " + healt); }
    void updateInventory(int id, int count) { notify("inventory: " + id + ", count: " + count); }
};
