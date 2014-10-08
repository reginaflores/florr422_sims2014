#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(1);
    
   //initialize positions to 0
   posX1 = 0;
   posY1 = 0;
   posX2 = 0;
   posY2 = 0;
    
    positionChanger = false;
    shapeChanger  = false;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    if(shapeChanger == true){
        ofSetColor(255,0,0);
        ofCircle(posX1, posY1, 55);
        ofSetColor(0,255,0);
        ofCircle(posX2, posY2, 55);

    } else{
        ofSetColor(255);
        ofRect(posX1,posY1, 55,55);
        ofSetColor(0);
        ofRect(posX2, posY2, 55, 55);
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
    
    
    
    if(positionChanger == true){
        posX1 = x;
        posY1 = y;
        positionChanger = false;
        shapeChanger = false;
    }else{
        posX2 = x;
        posY2 = y;
        positionChanger = true;
        shapeChanger = true;
    }
    

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
