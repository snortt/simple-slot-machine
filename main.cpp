#include <iostream>
#include "game.hpp"

int main() {
    // Limpar a tela
    std::cout << "\x1B[2J\x1B[H";
    Game g;
    g.newGame();

    return 0;
}
