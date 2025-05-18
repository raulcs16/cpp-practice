#include <iostream>
#include <memory>
#include <string>

//mediator
class SecuirtySystem;
//collegue
class Device {
public:
    Device(SecuirtySystem *mediator);
    virtual std::string getName() const = 0;
    virtual ~Device() = default;
};

class SecuritySystem {
public:
    virtual void notify(Device *sender, const std::string &event) = 0;
    virtual ~SecuirtySystem() = default;
};

class CardEntryLock : public Device {
public:
    CardEntryLock(SecuirtySystem *mediator) : Device(mediator) {}
    void lock();
    void unlock();
    void notifyBreach() {
        if (mediator) {
            mediator->notify(this, "breach at door")
        }
    }

private:
    SecuirtySystem *mediator = nullptr;
};

class SoundAlarm : Device {

public:
    SoundAlarm(SecuirtySystem *mediator) : Device(mediator) {}
    void turnOn();
    void turnOff();
    void notifyBreach() {
        if (mediator) {
            mediator->notify(this, "alarm going off")
        }
    }

private:
    SecuirtySystem *mediator = nullptr;
};
