#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    radius = 280;
    //theta = .1;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofLine(200, 30, 280, 300);
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofCircle(0,0, radius);
    
//    for(int i = 0; i< 2*PI; i++){
//        posInit.x = radius * cos(0);
//        posInit.y = radius * sin(0);
//        
//        posFin.x = radius * cos(theta);
//        posFin.y = radius * sin(theta);
    //theta = mouseX/100.0;
    theta = theta + 0.1;
    //if(theta < PI/2 && theta > 0 ){
        ofLine(0,0, radius*cos(theta), radius*sin(theta));
        
    //}else{
    //    theta = 0;
   // }
    
    
    
 //       ofLine(0,0,posFin.x, posFin.y);
 //   }
    
    //solid drawing
    cam.begin();
    ofNoFill();
    ofDrawBox(0, 0, 0, 55, 55, 55);
    cam.end();
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
