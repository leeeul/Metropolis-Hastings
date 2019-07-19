#include "MCMC.hpp"
#include "Frog.hpp"

MCMC* MCMC::instance = nullptr;

MCMC* MCMC::getInstance(){
    if(instance==nullptr){
        instance = new MCMC(ofGetWidth()*0.5, ofGetHeight(), 10000);
    }
    
    return instance;
}

MCMC::MCMC(int width, int height, int num_of_frogs)
:Pond(width, height, false), NUM_OF_FROGS(num_of_frogs), max_val(0), frogs(nullptr), showFrog(true)
{
    cout<<"Just Created MCMC"<<endl;
}

MCMC::~MCMC(){
    if(instance==nullptr) return;
    cout<<"Terminate MCMC..."<<endl;
    
    MCMC* temp = instance;
    instance = nullptr;
    delete temp;
    
    if(pixels){
        cout<<"Terminate MCMC's Screen..."<<endl;
        delete[] pixels;
        pixels = nullptr;
    }
    
    if(frogs){
        cout<<"Terminate Frogs..."<<endl;
        delete[] frogs;
        frogs = nullptr;
    }
}

void MCMC::update(){
    if(frogs == nullptr){
        createFrogs();
    }
    
    for(int i=0; i<NUM_OF_FROGS; ++i){
        frogs[i].update();
    }
}

void MCMC::createFrogs(){
    if(frogs) return;
    frogs = new Frog[NUM_OF_FROGS];
    cout<<"Just Created Frogs"<<endl;
}

unsigned char MCMC::getMax(){
    return max_val;
}

void MCMC::setMax(unsigned char i){
    max_val = i;
}

void MCMC::draw(int x, int y){
    tex.loadData(pixels, width, height, GL_LUMINANCE);
    tex.draw(x, y, width, height);
    
    if(showFrog == false) return;
    
    for(int i=0; i<NUM_OF_FROGS; ++i){
        Frog& f = frogs[i];
        ofDrawEllipse(f.getX(), f.getY(), 2, 2);
    }
}

void MCMC::toggle(){
    showFrog =! showFrog;
}
