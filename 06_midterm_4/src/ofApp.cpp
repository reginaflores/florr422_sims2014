#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);

    //create the particles
    num = 2000;

    for(int i =0; i < num; i++){
        
        Particle p;
        MyParticles.push_back(p);
        MyParticles[i].init();
   
        
    }
    
    
    for(int i =0; i < num; i++){
        ofPoint p;
        points.push_back(p);
        
        float t;
        theta.push_back(t);
        
        float ph;
        phi.push_back(ph);
        
        int r;
        radius.push_back(r);
        
        float chPh;
        changePhi.push_back(chPh);
        
        float cT;
        changeTheta.push_back(cT);
        
    }
    
    //put the sphere in the setup function so all the points would not be moving
    for(int i = 0; i < num; i++){
        
        theta[i] = ofRandom(0,2*PI);
        phi[i] = ofRandom(0,PI);
        radius[i] = ofRandom(280,300);
        
        points[i] = ofPoint(radius[i]*cos(theta[i])*sin(phi[i]), radius[i]*sin(theta[i])*sin(phi[i]), radius[i]*cos(phi[i]));
        
        changeTheta[i] = ofRandom(0,0.01);
        changePhi[i] = ofRandom(0,0.1);
        
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i =0; i < num; i++){
        MyParticles[i].update(MyParticles);
        MyParticles[i].bounding();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(29,144,213);
	ofSetColor(255, 50);
    
    //note that easy cam gives you the ability to move the "camera" w/ mouse
    ofPushMatrix();
    
    cam.begin();
    light.enable();
    ofEnableLighting();
    glEnable(GL_DEPTH_TEST);
    
    //drawing my particles
    for(int i = 0; i < num; i++){
        MyParticles[i].draw();
    }
    
    
    
    ofBackground(29,144,213);
    for(int i = 0; i < num; i++){
        
        points[i] = ofPoint(radius[i]*cos(theta[i])*sin(phi[i]), radius[i]*sin(theta[i])*sin(phi[i]), radius[i]*cos(phi[i]));
        
        //ofCircle(points[i], 1);
        //ofDrawSphere(points[i], 1);
        
        
        if(radius[i] < 300){
            radius[i] ++;
        }
        
        //noisey = (float) mouseY/1000.0;
        
        //noisey = sin(0.01*ofGetFrameNum());
        
        //radius[i] = ofNoise(theta[i]*noisey, phi[i]*noisey)*400;
        
        theta[i] += changeTheta[i];
        phi[i] += changePhi[i];
    }
    
    for(int i = 0; i< num; i++){
        for(int j = i+1; j < num; j++){
            dist = pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) + pow(points[i].z - points[j].z, 2);
            
            if (dist < 2*1024) {
                ofSetColor(255, 50);
                ofSetLineWidth(1.5);
                ofLine(points[i].x, points[i].y, points[i].z, points[j].x, points[j].y, points[j].z);
            }
            
            
        }
    }
    

    
    
    
    glDisable(GL_DEPTH_TEST);
    ofDisableLighting();
    light.disable();
    cam.end();
    
    ofPopMatrix();
    
    cout<<ofToString("frame"+ofToString(ofGetFrameNum(), 1, 5, '0'))<<endl;
    
    ofSaveScreen(ofToString("frame"+ofToString(ofGetFrameNum(), 1, 5, '0')+".png"));
    
    
    
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
