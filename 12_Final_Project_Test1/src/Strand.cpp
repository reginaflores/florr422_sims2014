//
//  Strand.cpp
//  12_Final_Project_1
//
//  Created by Regina Flores on 11/27/14.
//
//

#include "Strand.h"


void Strand::init(int _mode) {

    pos.x = ofRandom(-ofGetWidth(), ofGetWidth());
    pos.y = ofRandom(-ofGetHeight(), ofGetHeight());
    
    //vel.x = ofRandom(-10,10);
    //vel.y = ofRandom(-10,10);
    
    angle = ofRandom(0,TWO_PI);
    mag = ofRandom(0,20);

    color = ofColor(255, ofRandom(0,255));
    
    //mode = floor(ofRandom(3));
   //mode = 3; //note this mode looks most like the web network
    
    mode = _mode;
}

void Strand:: update(){
    
    prevPos = pos;
    
    //pos = pos + vel;

    pos.x = pos.x + mag*cos(angle);
    pos.y = pos.y + mag*sin(angle);
    

}

void Strand::connect(vector<Strand> &strands){ //reference - it wont copy the strands when passing... it just provides the address in memory of the vector itself

    for(int i = 0; i < strands.size(); i++){
        //determining if the strand in the loop is itself
        //to avoid itself
        if (&strands[i] == this) {
            continue;
        }
    
        // distance between me and particles[i]
        float dist = pow(strands[i].pos.x - pos.x, 2) + pow(strands[i].pos.y - pos.y, 2);
        dist = sqrt(dist);
        
        if (dist < 10) {
            
            //vel = vel*(0.99);
            mag = mag*0.99;
            
            ////////////////////////////
            if(mode == 1){
            //iteration 1
            angle = angle+0.03;
            }else if(mode == 2){
            //iteration 2
            angle = strands[i].angle;
            }else if(mode == 3){
            //iteration 3
            angle = ofLerp(angle, strands[i].angle, 0.2);
            }
            ////////////////////////////
            
            
        }
    
    }


}

void Strand::draw(){

    //ofCircle(pos.x, pos.y, ofRandom(1,3));
    ofSetColor(color);
    ofLine(prevPos.x, prevPos.y, pos.x, pos.y);
    
}


