#ifndef _SLOTMACHINE_HPP_
#define _SLOTMACHINE_HPP_

#define MAX_BET_DIGITS 3
#define BET_MIN_DIGIT 2
#define BET_MAX_DIGIT 7

class SlotMachine {
    public:
        int MakeBet(int);
        int getN1(void) const;
        int getN2(void) const;
        int getN3(void) const;
    
    private:
        int getRandomInt(int, int);
        int n1;
        int n2;
        int n3;
};
    
#endif

