// use case: wrapps known interface into another interface

#include <iostream>
#include <string>

//target interface
class IController;
//client
class Game;
//adaptee
class Joystick;
//adapter
class JoystickApdapter;


class Game {
public:
    void play(IController *controller) {}
};
class IController {
public:
    virtual void pressedKey(uint8_t key_code) = 0;

private:
    //  keys pressed
};

class Joystick {
public:
    uint8_t getUpStrenght();
};

class JoystickAdapter : public IController {
public:
    JoystickAdapter(Joystick *jstck) : joystick(jstck) {}
    void pressedKey(uint8_t key_code) {
        if (joystick->getUpStrenght() > 0) {
            //set keys pressed
        }
    }

private:
    Joystick *joystick;
};
