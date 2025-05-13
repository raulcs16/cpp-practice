
#include <iostream>
#include <memory>
#include <string>

class InputHandler {
protected:
    std::__shared_ptr<InputHandler> next;

public:
    void setNext(std::shared_ptr<InputHandler> handler) { next = handler; }
    virtual void handleInput(const std::string &command) {
        if (next)
            next->handleInput(command);
        else
            return;
    }
    virtual void ~Input() = default;
};

class UIHandler : public InputHandler {
public:
    void handleInput(const std::string &command) override {
        if (command == "pause")
            std::cout << "UI... stuff\n";
        else
            InputHandler::handleInput(command);
    }
};

class PlayerHandler : public InputHandler {
public:
    void handleInput(const std::string &command) override {
        if (command == "move") {
            std::cout << "Player moving...\n";
            else InputHandler::handleInput(command);
        }
    }
}