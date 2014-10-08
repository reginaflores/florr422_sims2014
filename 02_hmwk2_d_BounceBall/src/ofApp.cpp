#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    posX=0;
    posY=0;
    radius=50;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //giving the ball some fake gravity
    speedX = speedX + 0.05;
    speedY = speedY + 0.05;
    
    //position to vary with gravity
    posX = posX + speedX;
    posY = posY + speedY;
    
    //creating the ball
    ofSetColor(0);
    ofCircle(posX, posY, radius);
    
    //give movement frame boundaries
    if(posX > ofGetWidth() || posX < 0){
        speedX = -speedX;
        speedX = speedX * 0.9;
    }
    if(posY > ofGetHeight() || posY < 0){
        
        speedY = -speedY;
        speedY = speedY * 0.9;
    }
    
    //give the ball a dampening effect
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
