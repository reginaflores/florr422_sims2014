
//
//  Particle.h
//  12_Final_Project_2
//
//  Created by Regina Flores on 11/28/14.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    
    Particle();
    
    void init(int _boxWidth,
              int _boxHeight,
              int _boxDepth,
              vector<float> _noiseArray,
              float _minVel,
              float _maxVel,
              int _opacity,
              int _length,
              int _thick,
              bool colorOn);
    void draw();
    void update();
    void bounding();
    void randomPos();
    void setNoiseArray(vector<float> _noiseArray);
    void setVelocity(float _minVel, float _maxVel);
    void setOpacity(int _opacity);
    void setLength(int _length);
    void setThick(int _thick);
    
    //position and velocity variables
    ofPoint pos;
    vector<ofPoint> posArray;
    ofPoint vel;
    
    
    //passed variables
    int boxWidth;
    int boxHeight;
    int boxDepth;
    float minVel;
    float maxVel;
    int opacity;
    int length;
    int thick;
    bool colorOn;

    //random array to varry noise function
    vector<float> noiseArray;

    
    
};
