#include "Game.h"


using namespace sf;

int main() {
    // init game engine
    Game game;

    //Game loop
    while (game.running()){
        // Update
        game.update();
        // Render
        game.render();
    }
}