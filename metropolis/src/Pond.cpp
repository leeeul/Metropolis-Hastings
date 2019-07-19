#include "Pond.hpp"

int xytoidx(int x, int y, int width){
    return y*width + x;
}

Pond* Pond::instance = nullptr;

Pond* Pond::getInstance(){
    if(instance==nullptr){
        instance = new Pond(ofGetWidth()*0.5, ofGetHeight(), true);
    }
    
    return instance;
}

Pond::~Pond(){
    if(instance==nullptr) return;
    cout<<"Terminate Pond..."<<endl;
    
    Pond* temp = instance;
    instance = nullptr;
    delete temp;
    
    if(pixels == nullptr) return;
    cout<<"Terminate Pond' Screen..."<<endl;
    
    delete[] pixels;
    pixels = nullptr;
}

Pond::Pond(int width, int height, bool rand)
:width(width), height(height), pixels(new unsigned char[width*height])
{
    setRandom(rand);
    cout<<"Just Created Pond"<<endl;
}

void Pond::draw(int x, int y){
    tex.draw(x, y, width, height);
}

void Pond::setRandom(bool rand){
    for(int x=0; x<width; ++x){
        for(int y=0; y<height; ++y){
            pixels[xytoidx(x, y, width)] = (unsigned char)(ofNoise(x*0.008, y*0.008)*(rand?255:0));
        }
    }
    tex.loadData(pixels, width, height, GL_LUMINANCE);
}

unsigned char* Pond::getPixels(){
    return pixels;
}

int Pond::getWidth(){
    return width;
}

int Pond::getHeight(){
    return height;
}
