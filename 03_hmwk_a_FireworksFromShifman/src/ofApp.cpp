#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void ofApp::update(){

}


bool removeIfDead(particle& p){
    return p.isDead();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    particles.push_back(particle(ofPoint(ofGetWindowWidth()/2, 50)));
    
    for( int i = 0; i < particles.size(); i++){
    
        particles[i].run();
        
       // if(particles[i].isDead()){
       //     particles.erase(particles.begin()+i);
            
            
       // }
    
    }
    
    ofRemove(particles, removeIfDead);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}