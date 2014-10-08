#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSeedRandom();
    
 //   ofSetBackgroundAuto(false);
 //   ofBackground(0);
//    dest1 = ofPoint( ofRandomWidth(), ofRandomHeight() );
//    dest2 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    
//    car1.setInit( ofGetWindowSize() / 2, ofPoint(10, -5) );
//    car2.setInit( ofGetWindowSize() / 2, ofPoint(10, 5) );
//    
//    car1.color = ofColor(0,255,0);
//    car2.color = ofColor(0,0,255);
    
    num = 50;
    for(int i=0; i < num; i++){
        
        Particle fillCar;
        cars.push_back(fillCar);
        cars[i].setInit(ofGetWindowSize() / 2, ofPoint(10, 5));
        
        ofPoint fillDest;
        dest.push_back(fillDest);
        dest[i].x = ofRandomWidth();
        dest[i].y = ofRandomHeight();
        
        ofColor fillColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255) );
        origColor.push_back(fillColor);
        
    }
    
    ofBackground(255);
    
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // apply steering force
//    car1.seek( dest1 );
//    car2.seek( dest2 );

    for(int i=0; i < num; i++){
        cars[i].seek(dest[i]);
    
    }
    
    // apply repelling force
    //float area = 200;
//    if( car1.getPosition().distance( car2.getPosition() ) < area ){
//        car1.color = ofColor(255,0,0);
//        car2.color = ofColor(255,0,0);
//        
//        car1.addRepulsionForce( car2.getPosition(), area,  0.1 );
//        car2.addRepulsionForce( car1.getPosition(), area, 0.1 );
//    }else{
//        car1.color = ofColor(0,255,0);
//        car2.color = ofColor(0,0,255);
//    }
//    
    
    float area = 50;
    for(int i=0;i<num; i++){
        //note the j for loop is starting at i+1 to not double count cases
        for(int j=i+1; j<num; j++){
            
            ////check to see if i=j; note in this case we do not need it because we are starting j @ i+1
//            if(i==j){
//                continue;
//            }
            //////
            
            
            if(cars[i].getPosition().distance(cars[j].getPosition()) < area ){
                cars[i].color = ofColor(255,0,0);
                cars[j].color = ofColor(255,0,0);
                
                cars[i].addRepulsionForce( cars[j].getPosition(), area,  0.1 );
                cars[j].addRepulsionForce( cars[i].getPosition(), area, 0.1 );
            
            }else{
                cars[i].color = origColor[i];
                cars[j].color = origColor[j];
            }
        }
        
    }
    

    
    // update physics
//    car1.update();
//    car2.update();
//    
//    if( car1.getPosition().distance(dest1) < 5){
//        dest1 = ofPoint( ofRandomWidth(), ofRandomHeight() );
//    }
//    
//    if( car2.getPosition().distance(dest2) < 5){
//        dest2 = ofPoint( ofRandomWidth(), ofRandomHeight() );
// 
//    }
    

    for(int i=0; i < num; i++){
    
        cars[i].update();
        
        if(cars[i].getPosition().distance(dest[i]) < 5){
            dest[i] = ofPoint(ofRandomWidth(), ofRandomHeight() );
            
        }
    
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   ofBackground(255);
    
//    ofSetColor( car1.color );
//    ofCircle( dest1, 4 );
//    car1.draw();
//    
//    ofSetColor( car2.color );
//    ofCircle( dest2, 4 );
//    car2.draw();

    for(int i =0 ; i < num; i++){
        ofSetColor(cars[i].color, 85);
        ofCircle(dest[i], 4);
        cars[i].draw();
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
