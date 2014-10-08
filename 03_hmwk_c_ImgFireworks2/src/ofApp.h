#pragma once

#include "ofMain.h"
#include "particles.h"

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
		
    //Particle p; //instance of the Particle Class
    vector<Particle> arrayParticle; //creating an array list of type Partlicle
    int num;
    
    
    //load the image
    ofImage spiral;
    
};
