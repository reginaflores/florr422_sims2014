#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
    //ofPoint dest1, dest2;
    //Particle car1, car2;
    
    //this is a vecotor (aka "arraylist") of cars from class particle
    vector<Particle> cars;
    vector<ofPoint> dest;
    vector<ofColor> origColor;
    
    int num;
};
