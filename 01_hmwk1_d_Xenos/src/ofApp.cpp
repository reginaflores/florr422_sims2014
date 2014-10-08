#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //posX = ofGetWidth()/2;
    //posY = ofGetHeight()/2;
    
   //speed = .95;
    
    for(int i=1; i < 1000; i++){
        speed[i] = ofRandom(0.85,0.98);
        rectColor[i] = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255), ofRandom(0,255));
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofRect(posX, posY, 55, 55);
    //posX = (speed)*posX + (1-speed)* mouseX;
    //posY = (speed)*posY + (1-speed)* mouseY;

    for(int i = 0; i < 1000; i++){
        ofSetColor(rectColor[i]);
        ofRect(posX[i], posY[i], 55, 55);
        posX[i] = (speed[i])*posX[i] + (1-speed[i])* mouseX;
        posY[i] = (speed[i])*posY[i] + (1-speed[i])* mouseY;
        
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
