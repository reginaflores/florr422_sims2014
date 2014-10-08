#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
    //p.explosion();

    num = 1000;
   
    for(int i=0; i < num; i++){
        Particle fillParticle;
        fillParticle.setup();
        arrayParticle.push_back(fillParticle);
    
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    for(int i = 0; i < arrayParticle.size(); i++){
        arrayParticle[i].explosion();
        arrayParticle[i].draw();
        
    }

    //this code works for just 240 frames
//    for(int j=0; j < arrayParticle.size(); j++){
//        //% giving remainder of framcount/240 
//        if(ofGetFrameNum()%240 == 0){
//            arrayParticle[j].restart();
//        }
//            
//    }
    
    
    for(int j=0; j < arrayParticle.size(); j++){
        //% giving remainder of framcount/240
        if(ofGetFrameNum() % arrayParticle[j].someNumber == 0){
            arrayParticle[j].restart();
        }
        
    }
    
    //ofCircle(p.pos.x, p.pos.y, p.radius);
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
