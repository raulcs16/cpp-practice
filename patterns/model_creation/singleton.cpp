
#include <iostream>

class SoundManagerSingleton {
public:
    static SoundManagerSingleton *Instance();

protected:
    SoundManagerSingleton();

private:
    static SoundManagerSingleton _instance;
};

SoundManagerSingleton *SoundManagerSingleton::_instance = 0;

SoundManagerSingleton *SoundManagerSingleton::Instance() {
    if (_instance == 0) {
        _instance = new SoundManagerSingleton;
    }
    return _instance;
}