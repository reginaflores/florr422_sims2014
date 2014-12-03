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
		
    void refresh();
    
    ofEasyCam cam;
    
    int num;
    int boxWidth;
    int boxHeight;
    int boxDepth;
    float noiseFactor;
    float minVel;
    float maxVel;
    int opacity;
    int length;
    
    float speedRotate;

    vector<Particle> particles;
    vector<float> noiseArray;

    ofxUICanvas *gui;

};
