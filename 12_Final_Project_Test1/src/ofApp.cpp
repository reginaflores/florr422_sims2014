#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    num = 1000;
    mode = ofRandom(1,4);
    cout<<mode<<endl;
    
    for(int i=0; i < num; i++){
        
        Strand s;
        strands.push_back(s);
        strands[i].init(mode);
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < num; i++){
        
        strands[i].update();
        strands[i].connect(strands);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundAuto(false);
    
    for(int i = 0; i < num; i++){
        ofSetColor(255, 255, 255, 80);
        strands[i].draw();

    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key==' ') {
        setup();
    }
    
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
