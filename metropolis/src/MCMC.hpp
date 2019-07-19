#ifndef MCMC_hpp
#define MCMC_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Pond.hpp"
class Frog;

class MCMC : public Pond{
    static MCMC* instance;
    MCMC(int width, int height, int num_frog);
    
    const int NUM_OF_FROGS;
    Frog* frogs;
    void createFrogs();
    bool showFrog;
    
    unsigned char max_val;
    
public:
    static MCMC* getInstance();
    virtual ~MCMC();
    void update();
    unsigned char getMax();
    void setMax(unsigned char);
    virtual void draw(int x, int y);
    void toggle();
};

#endif
