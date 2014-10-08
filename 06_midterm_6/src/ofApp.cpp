#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //create the particles
    numP = 200;
    //create the line segments
    num = 2000;

    //filling all my arrays
    for(int i =0; i < num; i++){
        ofPoint p;
        points.push_back(p);
        
        float t;
        theta.push_back(t);
        
        float ph;
        phi.push_back(ph);
        
        int rA;
        radiusA.push_back(rA);

        int rB;
        radiusB.push_back(rB);
        
        int rC;
        radiusC.push_back(rC);
        
        float chPh;
        changePhi.push_back(chPh);
        
        float cT;
        changeTheta.push_back(cT);
        
    }
    
    //put the sphere in the setup function so all the points would not be moving
    for(int i = 0; i < num; i++){
        
        theta[i] = ofRandom(0,2*PI);
        phi[i] = ofRandom(0,PI);
        radiusA[i] = ofRandom(280,300);
        radiusB[i] = ofRandom(250,280);
        radiusC[i] = ofRandom(100,200);
        
        points[i] = ofPoint(radiusA[i]*cos(theta[i])*sin(phi[i]), radiusB[i]*sin(theta[i])*sin(phi[i]), radiusC[i]*cos(phi[i]));
        
        changeTheta[i] = ofRandom(0,0.01);
        changePhi[i] = ofRandom(0,0.1);
        
    }
    
    //generating particle system
    for(int i =0; i < numP; i++){
        MyParticles.push_back(Particle());
        MyParticles[i].init();
    }
    
    //attempt to make code go faster by using points array insead of ofPoints
    for(int i=0;i<num ;i++){
        points.push_back(ofPoint( radiusA[i]*cos(theta[i])*sin(phi[i]),radiusB[i]*sin(theta[i])*sin(phi[i]),radiusC[i]*cos(phi[i])));
    
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){
   

    for(int i =0; i < numP; i++){
        MyParticles[i].update(MyParticles);
        //MyParticles[i].bounding();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //points.clear();
    //ofBackground(0);
    //ofSetColor(0);
    
   ofBackground(29,144,213);
   ofSetColor(255, 50);
    
    //note that easy cam gives you the ability to move the "camera" w/ mouse
    ofPushMatrix();
    
    cam.begin();
    light.enable();
    ofEnableLighting();
    glEnable(GL_DEPTH_TEST);
    
  //ofBackground(45,1,211);
    //drawing the sphere using points on a surface
    for(int i = 0; i < num; i++){
        points[i].x =radiusA[i]*cos(theta[i])*sin(phi[i]);
        points[i].y =radiusB[i]*sin(theta[i])*sin(phi[i]);
        points[i].z = radiusC[i]*cos(phi[i]);
        
        if(radiusC[i] < 200){
            radiusC[i] ++;
        }
        
        //noisey = (float) mouseY/1000.0;
        //noisey = sin(0.01*ofGetFrameNum());
        //radius[i] = ofNoise(theta[i]*noisey, phi[i]*noisey)*400;
        
        theta[i] += changeTheta[i];
        phi[i] += changePhi[i];
    }
    
    //connecting lines
    for(int i = 0; i< num; i++){
        for(int j = i+1; j < num; j++){
            dist = pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) + pow(points[i].z - points[j].z, 2);
            
            if (dist < 2*1024) {
                ofSetColor(255, 50);
                //ofSetColor(45,1,211);
                // ofSetColor(17,254,23,30);
                ofSetLineWidth(1.5);
                ofLine(points[i].x, points[i].y, points[i].z, points[j].x, points[j].y, points[j].z);
            }
            
        }
    }
    

    //drawing my particles
    for(int i = 0; i < numP; i++){
        
        //making the particles different colors
        if(i < numP/2){
           // ofSetColor(45,1,211);
            //ofSetColor(17,254,23,30);
            ofSetColor(255);
            MyParticles[i].draw();
        }else{
            //ofSetColor(255,0,0);
            ofSetColor(255, 50);
            MyParticles[i].draw();
        }
    
        
      //trying to keep the particles bound in the sphere
      if(MyParticles[i].pos.y > radiusA[i]){
          MyParticles[i].vel = -MyParticles[i].vel;
      }
      if(MyParticles[i].pos.y < -radiusA[i]){
          MyParticles[i].vel = -MyParticles[i].vel;
      }
      
      if(MyParticles[i].pos.x > radiusA[i]){
          MyParticles[i].vel = -MyParticles[i].vel;
      }
      if(MyParticles[i].pos.x < -radiusA[i]){
          MyParticles[i].vel = -MyParticles[i].vel;
      }
      if(MyParticles[i].pos.z < -200){
          MyParticles[i].vel = -MyParticles[i].vel;
      }
      if(MyParticles[i].pos.z > 200){
          MyParticles[i].vel = -MyParticles[i].vel;
      }
      
  
  }

    glDisable(GL_DEPTH_TEST);
    ofDisableLighting();
    light.disable();
    cam.end();
    
    ofPopMatrix();

    //write the frames to files
    //cout<<ofToString("frame"+ofToString(ofGetFrameNum(), 1, 5, '0'))<<endl;
    //ofSaveScreen(ofToString("frame"+ofToString(ofGetFrameNum(), 1, 5, '0')+".png"));
    
    
    
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
