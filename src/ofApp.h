#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Primitive.h"
#include "ofxMidi.h"
#include "ofxMidiOutputManager.h"
class ofApp : public ofBaseApp, public ofxMidiListener{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    //midisetting
    void exit();
    void newMidiMessage(ofxMidiMessage& msg);
  
    //gui
    ofxPanel gui;
    ofParameter<ofVec3f> pos;
    ofVec3f position;
    ofParameter<ofVec3f> size;
    ofVec3f Size;
    ofParameter<ofVec3f> rotate;
    ofVec3f Rotate;
    ofParameter<float> maxVol;
    ofParameter<int> repeat;
    ofxToggle GlobalRotate;
    slide globalRotate;
    //動的配列
    vector<Primitive> box;
    static const int Num = 64;
    
    bool revers;
    
    bool bang;
    bool bHide;
    
    ofEasyCam cam;
    //audio
    ofSoundPlayer beat;
    float * fftSmooth;
    int bands;
    float currentPos;
    
    float* smoothedVol;
    float r;
    
   // midi setting
    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;
    ofxMidiOutputManager manager;
    
};
