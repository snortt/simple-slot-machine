#ifndef GAME_HPP
#define GAME_HPP

#include "slot.hpp"

class Game {
    public:
        Game();
        Game(int);
        int newGame(void);
        int getMoney(void) const;
        void setMoney(int); 
        
    private:
        int money;
};
#endif
