#include <iostream>

class HealthWidget {
public:
    HealthWidget() {}
    void displayHealth(uint health) {
        if (health >= 0) {
            std::cout << "Health: " << health << std::endl;
        } else
            std::cout << "Dead\n";
    }
};
class CoordWidget {
public:
    CoordWidget() {}
    void displayPos(uint x, uint y) { std::cout << "[" << x << "," << y << "]" << std::endl; }
};

class PlayerModel {
public:
    PlayerModel(uint startX = 0, uint startY = 0, uint startHealth = 100, uint startLives = 3)
        : x(startX), y(startY), health(startHealth), lives(startLives) {
        healthView = nullptr;
        coordView = nullptr;
    }
    void setHealthView(HealthWidget *view) { healthView = view; }
    void setCoordView(CoordWidget *view) { coordView = view; }
    void moveUp() { y--; }
    void moveDown() { y++; }
    void moveLeft() { x--; }
    void moveRight() { x++; }
    void notifyViews() {
        if (healthView != nullptr)
            healthView->displayHealth(health);
        if (coordView != nullptr)
            coordView->displayPos(x, y);
    }

    uint &getHealth() { return health; }
    uint &getLives() { return lives; }


private:
    uint health;
    uint x;
    uint y;
    uint lives;
    CoordWidget *coordView;
    HealthWidget *healthView;
};

class RandPlayerController {
public:
    RandPlayerController() { model = nullptr; }
    void setModel(PlayerModel *m) { model = m; }
    void move() {
        if (model == nullptr)
            return;
        uint dir = rand() % 4;
        switch (dir) {
        case 0: model->moveDown(); break;
        case 1: model->moveUp(); break;
        case 2: model->moveLeft(); break;
        case 3: model->moveRight(); break;
        default: break;
        }
    }

private:
    PlayerModel *model;
};
class HealthSystem {
public:
    static void damagePlayer(PlayerModel &player, uint damage) {
        auto &hp = player.getHealth();
        if (hp <= damage) {
            hp = 0;
        } else {
            hp -= damage;
        }
    }
};

int main() {
    HealthWidget healthGUI;
    CoordWidget coordGUI;
    PlayerModel player;

    player.setHealthView(&healthGUI);
    player.setCoordView(&coordGUI);

    RandPlayerController contrl;
    contrl.setModel(&player);

    int rounds = 3;
    while (rounds) {
        player.notifyViews();
        contrl.move();
        HealthSystem::damagePlayer(player, 10);
        rounds--;
    }

    return 0;
}