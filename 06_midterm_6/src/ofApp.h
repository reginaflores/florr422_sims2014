#pragma once

#include "ofMain.h"
#include "Particles.h"

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
    

    //Cam variables
    ofEasyCam       cam;
    ofLight         light;

    //itterative vars
    int num;
    int numP;
    
    //var to create lines
    float dist;
    //var to create noise variablity
    float noisey;
    
    //vector to create the particles
    vector<Particle> MyParticles;
    
    //vector to create the points on the sphere
    vector<ofPoint> points;
    
    //vectors to create the spherical structure
    vector<float> theta;
    vector<float> phi;
    vector<int> radiusA;
    vector<int> radiusB;
    vector<int> radiusC;
    
    //changing "variables" so that the sphere can have movement
    vector<float> changeTheta;
    vector<float> changePhi;
    

    
};

