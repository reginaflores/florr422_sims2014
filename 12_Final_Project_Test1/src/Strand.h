//
//  Strand.h
//  12_Final_Project_1
//
//  Created by Regina Flores on 11/27/14.
//
//

#pragma once
#include "ofMain.h"

class Strand{
    
public:
    
    ofPoint pos;
    //ofPoint vel;
    float angle;
    float mag;
    
    ofPoint prevPos;
    ofColor color;
    
    int mode;
    
    void init(int _mode);
    void update();
    void draw();
    void connect(vector<Strand> &strands);
    
    
};