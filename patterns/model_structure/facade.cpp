

class AssetLoader {
public:
    void loadTextures();
    void loadSounds();
};

class WorldManager {
public:
    void initWorld();
    void spawnPlayer();
};

class InputManager {
public:
    void pollInputEvents();
};

class GameEngine {
public:
    void run() {
        AssetLoader assets;
        WorldManager world;
        InputManager input;

        assets.loadTextures();
        assets.loadSounds();

        world.initWorld();
        world.spawnPlayer();

        while (true) {
            input.pollInputEvents();
        }
    }

private:
};