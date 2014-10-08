#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "rectangle.h"

class testApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();

		rectangle myRectangle;
    
        float radius[1000];
        float theta[1000];
        int circleCenterX;
        int circleCenterY;
        float offsetTheta[1000];
        float offsetRadius[1000];
};

#endif

