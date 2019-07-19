#define mcmc MCMC::getInstance()
#define sample Pond::getInstance()
#include "Frog.hpp"

Frog::Frog(){
    pool = mcmc;
    this->x = ofRandom(pool->getWidth());
    this->y = ofRandom(pool->getHeight());
}

void Frog::update(){
    uc& pixel = pool->getPixels()[xytoidx(x, y, pool->getWidth())];
    pixel = ofClamp(pixel + 1, 0, 255);
    
    if(pixel > pool->getMax()){
        pool->setMax(pixel);
    }
    
    von_move();
    
    if(pool->getMax() >= 255){
        //        cout<<"Reached Maximum"<<endl;
    }
}

void Frog::von_move(){
    float r = ofRandom(1);
    int tx = x;
    int ty = y;
    
    if(r<0.25){
        tx+=1;
        if(tx>=pool->getWidth()) tx = 0;
    }else if(r<0.5){
        tx-=1;
        if(tx<0) tx = pool->getWidth();
    }else if(r<0.75){
        ty+=1;
        if(ty>=pool->getHeight()) ty = 0;
    }else{
        ty-=1;
        if(ty<0) ty = pool->getHeight();
    }
    
    metropolis(tx, ty);
}

void Frog::metropolis(int tx, int ty){
    uc mine = sample->getPixels()[xytoidx(x, y, sample->getWidth())];
    uc other = sample->getPixels()[xytoidx(tx, ty, sample->getWidth())];
    
    if(other<mine && diceRoller(mine, other)==false) return; //deny
    
    x = tx;
    y = ty;
}

bool Frog::diceRoller(uc mine, uc other){
    int total = (int)mine + (int)other;
    float rand = ofRandom(total);
    
    
    if(rand<(float)mine*0.07){
        return false;
    }else{
        return true;
    }
}

int Frog::getX(){
    return x;
}

int Frog::getY(){
    return y;
}
