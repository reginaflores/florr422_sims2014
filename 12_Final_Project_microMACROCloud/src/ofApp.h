#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxUI.h"


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
	
    //function to refresh the system when GUI is called
    void refresh();
    
    //Easycam to show 3D
    ofEasyCam cam;
    
    //basic screen variables
    int num;
    int boxWidth;
    int boxHeight;
    int boxDepth;
    
    //array of noise
    vector<float> noiseArray;
    
    //Variables for GUI
    float noiseFactor;
    float minVel;
    float maxVel;
    int opacity;
    int length;
    float speedRotate;
    
    //Particles system defintion
    vector<Particle> particles;

    //GUI define
    ofxUICanvas *gui;

};
