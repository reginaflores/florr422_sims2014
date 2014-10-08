#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    //ofTranslate(width/2, height/2);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    
    //cam.begin();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2, -200);
    ofScale(100,100);
    
    float a = 0+sin(ofGetElapsedTimeMillis()*.001);
    float b = -2.3;
    float c = 2.4;
    float d = -2.1;
    
    float numPoints = 10000;
    
    float x0=0;
    float x1=0;
    float y0=0;
    float y1 = 0;
    
    
    for(int i=0; i<numPoints; i++){
        x1=sin(a*y0)-cos(b*x0);
        y1=sin(c*x0)-cos(d*y0);
        ofPoint(x1,y1);
        ofCircle(x1, y1, 0.01);
        //line(x1, y1, x1+0.001, y1);
        x0=x1;
        y0=y1;
    }
    //cam.end();
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
