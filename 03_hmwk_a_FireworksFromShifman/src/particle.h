//
//  particle.h
//  emptyExample
//
//  Created by Regina Flores on 9/16/14.
//
//

#pragma once
#include "ofMain.h"

class particle{

public:
    
    particle(ofPoint l);
    void run();
    void update();
    void display();
    bool isDead();
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float lifeSpan;

    

};

