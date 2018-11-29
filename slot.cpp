#include <iostream>
#include <random>
#include "slot.hpp"

int SlotMachine::getN1(void) const { return n1; }
int SlotMachine::getN2(void) const { return n2; }
int SlotMachine::getN3(void) const { return n3; }

int SlotMachine::MakeBet(int _money) {
    n1 = getRandomInt(BET_MIN_DIGIT, BET_MAX_DIGIT);
    n2 = getRandomInt(BET_MIN_DIGIT, BET_MAX_DIGIT);
    n3 = getRandomInt(BET_MIN_DIGIT, BET_MAX_DIGIT);

    std::cout << "[ " << n1 << " " << n2 << " " << n3 << " ]" << std::endl;

    if ( (n1 == n2) && (n1 == n3) && (n1 == 7) ) {
        std::cout << "Você recebeu 10x sua aposta!" << std::endl;
        return (_money * 10);
    }
    else if ( (n1 == n2) && (n1 == n3) ) {
        std::cout << "Você recebeu 5x sua aposta!" << std::endl;
        return (_money * 5);
    }
    else if ( (n1 == n2) || (n1 == n3) || (n2 == n3) ) {
        std::cout << "Você recebeu 3x sua aposta!" << std::endl;
        return (_money * 3);
    }
    else {
        std::cout << "Você perdeu sua aposta!" << std::endl;
        return 0;
    }
}

int SlotMachine::getRandomInt(int _min, int _max) { 
    int num = 0;
    
    std::random_device rd;                              // get random number from hardware
    std::mt19937 eng(rd());                             // seed the generator
    std::uniform_int_distribution<> distr(_min, _max);  // define the range
    num = distr(eng);                                   // generate number

    return num;
};

