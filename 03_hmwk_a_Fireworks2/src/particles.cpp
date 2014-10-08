//
//  particles.cpp
//  03_hmwk_a_Fireworks2
//
//  Created by Regina Flores on 9/21/14.
//
//

#include "particles.h"

void Particle:: explosion(){

    //gives me random rgb values
    color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));

//
//    pos.x = ofRandom(0,ofGetWidth());
//    pos.y = ofRandom(0, ofGetHeight());
    
    //give particles behavior
    pos.x = pos.x + vel.x;
    pos.y = pos.y + vel.y;
    

}

void Particle:: draw(){
    
    ofSetColor(color);
    ofCircle(pos.x, pos.y, radius);


}

void Particle::setup(){
    
    color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    radius = 2;
    vel.x = ofRandom(-1,1);
    vel.y = ofRandom(-1,1);
    
    someNumber = ofRandom(1,400);
    
}

void Particle::restart(){
    //color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    

}