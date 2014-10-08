#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	
	myRectangle.pos.x = 100;
	myRectangle.pos.y = 50;
    
   // ofSetBackgroundAuto(false);
   
    //radius = 100;
    circleCenterX = ofGetWidth()/2;
    circleCenterY = ofGetHeight()/2;
    
    for(int i = 0; i < 1000; i++){
        offsetTheta[i] = ofRandom(0.1);
        offsetRadius[i] = ofRandom(2);
    }

	
}

//--------------------------------------------------------------
void testApp::update(){
	myRectangle.xenoToPoint(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
    
    
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
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
