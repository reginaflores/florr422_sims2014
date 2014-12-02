#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxUI.h"
#include "ofxPostProcessing.h"



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
    ofLight light;
    
    int num;
    int boxWidth;
    int boxHeight;
    int boxDepth;
    float noiseFactor;
    float minVel;
    float maxVel;
    int opacity;
    int length;
    int thick;
    bool colorOn;
    
    float speedRotate;

    vector<Particle> particles;
    vector<float> noiseArray;

    ofxUICanvas *gui;

    //light toggle
    bool lightOn;
    
    //fullscreen
    bool toggleOn;
    
    //ofxPostProcessing
    ofxPostProcessing post;

    bool fxaPassOn;
    bool bloomOn;
    bool dofPassOn;
    bool kalOn;
    bool noiseWarpOn;
    bool pixelPassOn;
    bool edgePassOn;
    bool vertTiltOn;
    bool godRayOn;
    
    shared_ptr<FxaaPass> fxaPass;
    shared_ptr<BloomPass> bloomPass;
    shared_ptr<DofPass> dofPass;
    shared_ptr<KaleidoscopePass> kalPass;
    shared_ptr<NoiseWarpPass> noiseWarpPass;
    shared_ptr<PixelatePass> pixelPass;
    shared_ptr<EdgePass> edgePass;
    shared_ptr<VerticalTiltShifPass> verticalTilt;
    shared_ptr<GodRaysPass> godRaysPass;

};
