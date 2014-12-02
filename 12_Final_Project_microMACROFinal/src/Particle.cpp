//
//  Particle.cpp
//  12_Final_Project_2
//
//  Created by Regina Flores on 11/28/14.
//
//

#include "Particle.h"


Particle::Particle(){
    
    
}
//--------------------------------------------------------------

void Particle::init( int _boxWidth, int _boxHeight, int _boxDepth, vector<float> _noiseArray, float _minVel, float _maxVel, int _opacity, int _length, int _thick, bool _colorOn){

    boxWidth = _boxWidth;
    boxHeight = _boxHeight;
    boxDepth = _boxDepth;
    
    noiseArray = _noiseArray;
    
    minVel = _minVel;
    maxVel = _maxVel;
    opacity = _opacity;
    thick = _thick;
    colorOn = _colorOn;
    
    pos.x = ofRandom(-boxWidth/2, boxWidth/2);
    pos.y = ofRandom(-boxHeight/2, boxHeight/2);
    pos.z = ofRandom(-boxDepth/2, boxDepth/2);
    
    vel.x = ofRandom(-2,2);
    vel.y = ofRandom(-2,2);
    vel.z = ofRandom(-2,2);
    
    
    
}
//--------------------------------------------------------------

void Particle::draw(){

    ofBeginShape();
    
    /////////////////////////
    //this gives the strings color or B/W
//    if(colorOn){
//        ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255), opacity);
//        cout<<colorOn<<endl;
//    }else {
//        ofSetColor(255,255,255, opacity);
//    }
    /////////////////////////

    //Build the strings
    ofSetLineWidth(thick);
    for(int i =0; i < posArray.size(); i++){

        ofCurveVertex(posArray[i].x, posArray[i].y, posArray[i].z);
    }
    
    ofEndShape();
}

//--------------------------------------------------------------

void Particle::update(){
    

    vel.x = ofMap(ofNoise(noiseArray[0]*pos.x, noiseArray[1]*pos.y, noiseArray[2]*pos.z, 30), 0, 1, minVel, maxVel);
    vel.y = ofMap(ofNoise(noiseArray[3]*pos.x, noiseArray[4]*pos.y, noiseArray[5]*pos.z, 100), 0, 1, minVel, maxVel);
    vel.z = ofMap(ofNoise(noiseArray[6]*pos.x, noiseArray[7]*pos.y, noiseArray[8]*pos.z, 3), 0, 1, minVel, maxVel);

    pos = pos + vel;
    
    
    posArray.push_back(pos);
    
    if(posArray.size()>length){
        posArray.erase(posArray.begin()); //erases the oldest element of posArray
    }
    
}
//--------------------------------------------------------------

void Particle::randomPos(){

    pos.x = ofRandom(-boxWidth/2, boxWidth/2);
    pos.y = ofRandom(-boxHeight/2, boxHeight/2);
    pos.z = ofRandom(-boxDepth/2, boxDepth/2);
    
}

//--------------------------------------------------------------
void Particle::setNoiseArray( vector<float> _noiseArray ){

    noiseArray = _noiseArray;
    
}
//--------------------------------------------------------------

void Particle::setVelocity(float _minVel, float _maxVel){
    minVel = _minVel;
    maxVel = _maxVel;

}
//--------------------------------------------------------------
void Particle::setOpacity(int _opacity){

    opacity = _opacity;
}
//--------------------------------------------------------------
void Particle::setLength(int _length){
    length = _length;
}
//--------------------------------------------------------------
void Particle::setThick(int _thick){
    thick = _thick;
}

//--------------------------------------------------------------

void Particle::bounding(){

    if(pos.y > boxHeight/2){
        pos.y = -boxHeight/2;
        posArray.clear();
        randomPos();
    
    }
    if(pos.y < -boxHeight/2){
        pos.y = boxHeight/2;
        posArray.clear();
        randomPos();

    }
    
    if(pos.x > boxWidth/2){
        pos.x = -boxWidth/2;
        posArray.clear();
        randomPos();

    }
    if(pos.x < -boxWidth/2){
        pos.x = boxWidth/2;
        posArray.clear();
        randomPos();

    }
    if(pos.z < -boxDepth/2){
        pos.z = boxDepth/2;
        posArray.clear();
        randomPos();

    }
    if(pos.z > boxDepth/2){
        pos.z = -boxDepth/2;
        posArray.clear();
        randomPos();

    }


}