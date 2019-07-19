#ifndef Pond_hpp
#define Pond_hpp

#include <stdio.h>
#include "ofMain.h"

class Pond{
    static Pond* instance;
    void setRandom(bool rand);
protected:
    int width, height;
    unsigned char* pixels;
    ofTexture tex;
    Pond(int width, int height, bool rand);
public:
    static Pond* getInstance();
    virtual ~Pond();
    virtual void draw(int x, int y);
    unsigned char* getPixels();
    
    int getWidth();
    int getHeight();
};

int xytoidx(int x, int y, int width);

#endif /* Pond_hpp */
