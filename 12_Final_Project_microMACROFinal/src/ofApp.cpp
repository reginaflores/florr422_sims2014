#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    //initialize variables
    num = 1000;
    boxWidth = 700;
    boxHeight = 700;
    boxDepth = 500;
    noiseFactor = 0.001;
    minVel = -2;
    maxVel = 2;
    opacity = 100;
    length = 80;
    speedRotate = 0.16;
    thick = 1;

    
    //initialize noise array
    for(int i = 0; i < 9; i++){
        noiseArray.push_back(ofRandom(0,noiseFactor));
    }
    
    //initialize particles array
    for(int i =0; i < num; i++){
        Particle p;
        particles.push_back(p);
        particles[i].init(boxWidth, boxHeight, boxDepth, noiseArray, minVel, maxVel, opacity, length, thick, colorOn);
    }
    
    
    //////////////////////////
    //Gui Setup
    gui = new ofxUICanvas();
    
    gui->addLabel("Adjust the fields");
    gui->addLabel("and press spacebar");
    gui->addLabel("to update");
    gui->addLabel(" ");
    
    gui-> addIntSlider("System Size", 10, 3000, &num);
    gui-> addSlider("Noise Factor", 0, 0.05, &noiseFactor);
    gui-> addSlider("Min Velocity", -20, 0, &minVel);
    gui-> addSlider("Max Velocity", 0, 20, &maxVel);
    gui-> addIntSlider("Opacity", 0, 255, &opacity);
    gui-> addIntSlider("String Length", 3, 100, &length);
    gui->addIntSlider("Line Thickness", 0, 20, &thick);
    gui->addSlider("Box Rotation", 0, 0.5, &speedRotate);
    
    gui->addToggle("Fullscreen", &toggleOn);
    
    gui->addToggle("Light", &lightOn);
    gui->addToggle("Color", &colorOn);
    gui->addToggle("FXA Pass", &fxaPassOn);
    gui->addToggle("Bloom", &bloomOn);
    gui->addToggle("dofPassOn", &dofPassOn);
    gui->addToggle("Kalaidascope", &kalOn);
    gui->addToggle("Noise Warp", &noiseWarpOn);
    gui->addToggle("Pixel", &pixelPassOn);
    gui->addToggle("Edge", &edgePassOn);
    gui->addToggle("Vertical", &vertTiltOn);
    gui->addToggle("God Ray", &godRayOn);
    
    gui-> autoSizeToFitWidgets();
    
    ofAddListener(gui-> newGUIEvent, this, &ofApp::guiEvent);
    /////////////////////////
    
    
    // Setup post-processing chain
    post.init(ofGetWidth(), ofGetHeight());
    
    fxaPass = post.createPass<FxaaPass>();
    bloomPass = post.createPass<BloomPass>();
    dofPass = post.createPass<DofPass>();
    kalPass = post.createPass<KaleidoscopePass>();
    noiseWarpPass = post.createPass<NoiseWarpPass>();
    pixelPass = post.createPass<PixelatePass>();
    edgePass = post.createPass<EdgePass>();
    verticalTilt = post.createPass<VerticalTiltShifPass>();
    godRaysPass = post.createPass<GodRaysPass>();
    


}

//--------------------------------------------------------------
void ofApp::update(){
    
    //check if gui num is bigger than size
    while(particles.size()<num){
        Particle p;
        p.init(boxWidth, boxHeight, boxDepth, noiseArray, minVel, maxVel, opacity, length, thick, colorOn);
        particles.push_back(p);
        //particles[particles.size()-1].init(boxWidth, boxHeight, boxDepth, noiseArray);
    }
    
    for(int i =0; i < num; i++){
        particles[i].update();
        particles[i].bounding();
    }

    //ofxPostProcessing
    fxaPass->setEnabled(fxaPassOn);
    bloomPass->setEnabled(bloomOn);
    dofPass->setEnabled(dofPassOn);
    kalPass->setEnabled(kalOn);
    noiseWarpPass->setEnabled(noiseWarpOn);
    pixelPass->setEnabled(pixelPassOn);
    edgePass->setEnabled(edgePassOn);
    verticalTilt->setEnabled(vertTiltOn);
    godRaysPass->setEnabled(godRayOn);
    

}

//--------------------------------------------------------------
void ofApp::refresh(){
    
    //clear noise array and put in a new set of numbers from the gui
    noiseArray.clear();
    
    for(int i = 0; i < 9; i++){
        noiseArray.push_back(ofRandom(0,noiseFactor));
    }
    
    for(int i = 0; i < num; i++){
        particles[i].setNoiseArray(noiseArray);
        particles[i].setVelocity(minVel, maxVel);
        particles[i].setOpacity(opacity);
        particles[i].setLength(length);
        particles[i].setThick(thick);
    }
    

}
//--------------------------------------------------------------
void ofApp::draw(){
    
    post.begin(cam);
    //cam.begin();
    
    if(lightOn){
        light.enable();
    } else{
        light.disable();
    }
    
    //rotate the cam
    ofRotate(ofGetFrameNum()*speedRotate, 0, 1, 0);


    ofNoFill();
    //ofDrawBox(0, 0, 0, 200, 200, 200);
    ofSetColor(255,255,255,100);
    ofDrawBox(0, 0, 0, boxWidth, boxHeight, boxDepth);
   
    /////////////////////////
    //this gives the strings color or B/W
    if(colorOn){
        ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255), opacity);
        cout<<colorOn<<endl;
    }else {
        ofSetColor(255,255,255, opacity);
    }
    /////////////////////////
    
    
    for(int i =0; i < num; i++){
        //ofSetColor(0);
        particles[i].draw();
    }
    
    
    light.disable();
    //cam.end();
    post.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        refresh();
    }

    if( key == 'g'){
        
        gui->toggleVisible();
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
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e){
    
    if(e.getName()=="Fullscreen"){
        ofToggleFullscreen();
    }
}


