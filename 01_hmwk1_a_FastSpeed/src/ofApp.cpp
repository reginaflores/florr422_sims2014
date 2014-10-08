#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    x = 0;

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    x=x+ofGetWidth();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //making a square to start at (0, middle screen)
    ofRect(x, ofGetHeight()/2, 55, 55);
    
    

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
