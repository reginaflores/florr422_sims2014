#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofBackground(0);
    //radius = 100;
    circleCenterX = ofGetWidth()/2;
    circleCenterY = ofGetHeight()/2;
    
    for(int i = 0; i < 1000; i++){
        offsetTheta[i] = ofRandom(0.1);
        offsetRadius[i] = ofRandom(2);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //translating (0,0) to center of screen
    ofTranslate(circleCenterX, circleCenterY);
    
    for(int i = 0; i < 1000; i++){
        
        //angle of large circle
        //theta[i] = theta[i] + ofRandom(0.1,0.15);
        theta[i] = theta[i] + offsetTheta[i];
        
        //the (x,y) positions of the large circle we use to create spiral
        int x = radius[i]*cos(theta[i]);
        int y = radius[i]*sin(theta[i]);
        //making small circle to travel in spiral
        ofSetColor(255, 0.1*i);
        ofCircle(x, y, 1);
        //offset radius of large circle to create spiral effect
        //radius[i] = radius[i] + ofRandom(0.1,0.5);
        radius[i] = radius[i] + offsetRadius[i];
        
    }
    
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
