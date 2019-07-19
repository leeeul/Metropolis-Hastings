#include "ofApp.h"
#define pond Pond::getInstance()
#define mcmc MCMC::getInstance()
//--------------------------------------------------------------
void ofApp::setup(){
    
}

//--------------------------------------------------------------
void ofApp::update(){
    mcmc->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    pond->draw(0,0);
    mcmc->draw(ofGetWidth()*0.5,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' '){
        mcmc->toggle();
    }
}
