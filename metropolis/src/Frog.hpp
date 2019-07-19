#ifndef Frog_hpp
#define Frog_hpp
#include "ofApp.h"
#include <stdio.h>
#include "MCMC.hpp"

#define uc unsigned char

class Frog{
    int x, y;
    MCMC* pool;
public:
    Frog();
    void update();
    void von_move();
    void metropolis(int, int);
    bool diceRoller(uc, uc);
    int getX();
    int getY();
};


#endif /* Frog_hpp */




