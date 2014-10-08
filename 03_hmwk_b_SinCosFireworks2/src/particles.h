//
//  particles.h
//  03_hmwk_a_Fireworks2
//
//  Created by Regina Flores on 9/21/14.
//
//

//note you can get rid of this stuff

//#ifndef ___3_hmwk_a_Fireworks2__particles__
//#define ___3_hmwk_a_Fireworks2__particles__
//
//#include <iostream>
//
//#endif /* defined(___3_hmwk_a_Fireworks2__particles__) */

#pragma once
#include "ofMain.h"

class Particle {

public:
    void explosion();
    void draw();
    void setup(); //initial state
    void restart();

    ofPoint pos;
    ofColor color;
    ofPoint vel;
    int radius;
    int someNumber;
    
    float theta;
    int radius2;
    
};