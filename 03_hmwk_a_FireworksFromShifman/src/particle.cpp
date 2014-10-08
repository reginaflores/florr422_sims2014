//
//  particle.cpp
//  emptyExample
//
//  Created by Regina Flores on 9/16/14.
//
//

#include "particle.h"

//constructor
particle::particle(ofPoint l){

    acceleration = ofPoint(0, 0.05);
   // velocity = ofPoint(ofRandom(-1,1), ofRandom(-2,0));
    velocity.set(ofRandom(-1,1),ofRandom(-2,0));
    location = l;
    lifeSpan = 225.0;
    
}

void particle:: run(){
    
    update();
    display();

}

void particle::update(){
    
    velocity += acceleration;
    location += velocity;
    lifeSpan -= 2.0;
    
}

void particle::display(){
    
    ofSetColor(255 - lifeSpan);
    ofFill();
    ofEllipse(location.x, location.y, 8, 8);
    

}

bool particle::isDead(){

    if(lifeSpan < 0.0){
        return true;
    }
    else{
        return false;
    }


}