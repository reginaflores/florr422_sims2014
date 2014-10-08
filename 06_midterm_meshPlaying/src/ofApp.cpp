#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
   
    image.loadImage("cmb.jpg");
    image.resize(200, 200);
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    float intensityThreshold = 150.0;
    int w = image.getWidth();
    int h = image.getHeight();
//    for (int x=0; x<w; ++x) {
//        for (int y=0; y<h; ++y) {
//            ofColor c = image.getColor(x, y);
//            float intensity = c.getLightness();
//            if (intensity >= intensityThreshold) {
//                float saturation = c.getSaturation();
//                float z = ofMap(saturation, 0, 255, -100, 100);
//                ofVec3f pos(4*x, 4*y, z);
//                mesh.addVertex(pos);
//                mesh.addColor(c);
//            }        }
//    }
    
    
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(4*x, 4*y, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
                
                // And add this line:
                // It will create a ofVec3f with 3 random values
                // These will allow us to move the x, y and z coordinates of each vertex independently
                offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }
    
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    // ...
    // Omitting the code for creating vertices for clarity
    // but don't erase it from your file!
    
    // Let's add some lines!
    float connectionDistance = 30;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }



    // We need to calculate our center point for the mesh
    // ofMesh has a method called getCentroid() that will
    // find the average location over all of our vertices
    //    http://en.wikipedia.org/wiki/Centroid
    meshCentroid = mesh.getCentroid();
    
    // Now that we know our centroid, we need to know the polar coordinates (distance and angle)
    // of each vertex relative to that center point.
    // We've found the distance between points before, but what about the angle?
    // This is where atan2 comes in.  atan2(y, x) takes an x and y value and returns the angle relative
    //     to the origin (0,0).  If we want the angle between two points (x1, y1) and (x2, y2) then we
    //     just need to use atan2(y2-y1, x2-x1).
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        float distance = vert.distance(meshCentroid);
        float angle = atan2(vert.y-meshCentroid.y, vert.x-meshCentroid.x);
        distances.push_back(distance);
        angles.push_back(angle);
    }
    
    // These variables will allow us to toggle orbiting on and off
    orbiting = false;
    startOrbitTime = 0.0;
    meshCopy = mesh;        // Store a copy of the mesh, so that we can reload the original state
    
    mouseDisplacement = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (mouseDisplacement) {
        // Get the mouse location - it must be relative to the center of our screen because of the ofTranslate() command in draw()
        ofVec3f mouse(mouseX, ofGetWidth()-mouseY, 0);
        
        // Loop through all the vertices in the mesh and move them away from the mouses
        for (int i=0; i<mesh.getNumVertices(); ++i) {
            ofVec3f vertex = meshCopy.getVertex(i);
            float distanceToMouse = mouse.distance(vertex);
            
            // Scale the displacement based on the distance to the mouse
            // Small distance to mouse should yield a small displacement
            float displacement = ofMap(distanceToMouse, 0, 400, 300.0, 0, true);
            
            // Calculate the direction from the mouse to the current vertex
            ofVec3f direction = vertex - mouse;
            
            // Normalize the direction so that it has a length of one
            // This lets us easily change the length of the vector later
            direction.normalize();
            
            // Push the vertex in the direction away from the mouse and push it
            // a distance equal to the value of the variable displacement
            ofVec3f displacedVertex = vertex + displacement*direction;
            mesh.setVertex(i, displacedVertex);
        }
    }
    
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 0.75;
        ofVec3f timeOffsets = offsets[i];
        
        // A typical design pattern for using Perlin noise uses a couple parameters:
        // ofSignedNoise(time*timeScale+timeOffset)*displacementScale
        //     ofSignedNoise(time) gives us noise values that change smoothly over time
        //     ofSignedNoise(time*timeScale) allows us to control the smoothness of our noise (smaller timeScale, smoother values)
        //     ofSignedNoise(time+timeOffset) allows us to use the same Perlin noise function to control multiple things and have them look as if they are moving independently
        //     ofSignedNoise(time)*displacementScale allows us to change the bounds of the noise from [-1, 1] to whatever we want
        // Combine all of those parameters together, and you've got some nice control over your noise
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        mesh.setVertex(i, vert);
    }

    
    if (orbiting) {
        int numVerts = mesh.getNumVertices();
        for (int i=0; i<numVerts; ++i) {
            ofVec3f vert = mesh.getVertex(i);
            float distance = distances[i];
            float angle = angles[i];
            float elapsedTime = ofGetElapsedTimef() - startOrbitTime;
            
            // Lets adjust the speed of the orbits such that things that are closer to
            // the center rotate faster than things that are more distant
            float speed = ofMap(distance, 0, 200, 1, 0.25, true);
            
            // To find the angular rotation of our vertex, we use the current time and
            // the starting angular rotation
            float rotatedAngle = elapsedTime * speed + angle;
            
            // Remember that our distances are calculated relative to the centroid of the mesh, so
            // we need to shift everything back to screen coordinates by adding the x and y of the centroid
            vert.x = distance * cos(rotatedAngle) + meshCentroid.x;
            vert.y = distance * sin(rotatedAngle) + meshCentroid.y;
            
            mesh.setVertex(i, vert);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
    
    cout<<ofToString("frame"+ofToString(ofGetFrameNum(), 1, 5, '0'))<<endl;
    ofSaveScreen(ofToString("frame"+ofToString(ofGetFrameNum(), 1, 5, '0')+".png"));
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'm') {
        mouseDisplacement = !mouseDisplacement;  // Inverts the boolean
        mesh = meshCopy;  // Restore the original mesh
    }

    
    if (key == 'o') {
        orbiting = !orbiting;           // This inverts the boolean
        startOrbitTime = ofGetElapsedTimef();
        mesh = meshCopy;            // This restores the mesh to its original values
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
