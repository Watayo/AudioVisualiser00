#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //setting
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //配置
    for(int i = 0; i < Num; i++){
        Primitive drawObject;
        box.push_back(drawObject);
        
    }
    //midiSewtting
    midiIn.openPort(); //ポート番号を指定してい開く
    
    midiIn.addListener(this);
    
    midiIn.setVerbose(true);
    midiIn.ignoreTypes(false, false, false);
    
    
    
    //audio
    beat.load("0506-2019Artcore2.wav");
    beat.setLoop(true);
    beat.setVolume(1.0);
    beat.play();
    
    fftSmooth  = new float [8192];
    for(int i = 0; i < 8192; i++){
        fftSmooth[i] = 0;
    }
     
    bands = 64;
    //guisetting
    gui.setup("gui");
    gui.add(pos.set("position", ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), ofVec3f(150, 150, 150)));
    gui.add(size.set("scale", Size, ofVec3f(0, 0, 0), ofVec3f(80, 80, 80)));
    gui.add(rotate.set("rotate", Rotate, ofVec3f(0, 0, 0), ofVec3f(360.0, 360.0, 360.0)));
    gui.add(GlobalRotate.setup("GlobalRotate", false));
    gui.add(maxVol.set("Vol", 0.25, 0.0, 1.0));
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    float Val;
    float * value = ofSoundGetSpectrum(bands);
    for(int i = 0; i < bands; i++){
        fftSmooth[i] *= 0.90f;
        if(fftSmooth[i] < value[i]){
            fftSmooth[i] = value[i];
            Val += value[i];
            fftSmooth[i] *= 100;
        }
    }
    
        for(int i = 0; i < box.size(); i++){
            if(midiMessage.control == 1){
                midiMessage.value = (float)midiMessage.value;
                float Value01 = ofMap(midiMessage.value, 0.0, 127.0, 0.0, 360.0);
                Rotate.x = Value01;
//                box[i].rotate.x = i * fftSmooth[32] * Rotate.x * 0.004;
            }
            if(midiMessage.control == 2){
                midiMessage.value = (float)midiMessage.value;
                float Value02 = ofMap(midiMessage.value, 0.0, 127.0, 0.0, 360.0);
                Rotate.y = Value02;
//                box[i].rotate.y = i * fftSmooth[32] * Rotate.y * 0.004;
            }
            if(midiMessage.control == 3){
                midiMessage.value = (float)midiMessage.value;
                float Value03 = ofMap(midiMessage.value, 0.0, 127.0, 0.0, 360.0);
                Rotate.z = Value03;
//                box[i].rotate.z = i * fftSmooth[32] * Rotate.z * 0.004;
            }
            if(midiMessage.control == 5){
                midiMessage.value = (float)midiMessage.value;
                float Value05 = ofMap(midiMessage.value, 0.0, 127.0, 0.0, 80.0);
                Size.x = Value05;
//                box[i].size.x = 0.3 * i * fftSmooth[32] * Size.x + 30;
            }
            if(midiMessage.control == 6){
                midiMessage.value = (float)midiMessage.value;
                float Value06 = ofMap(midiMessage.value, 0.0, 127.0, 0.0, 80.0);
                Size.y = Value06;
            }
            if(midiMessage.control == 7){
                midiMessage.value = (float)midiMessage.value;
                float Value07 = ofMap(midiMessage.value, 0.0, 127.0, 0.0, 80.0);
                Size.z = Value07;
            }
         
            box[i].pos.x = (i - box.size() * 0.2) * fftSmooth[32] * pos->x ;
            box[i].pos.y = (i - box.size() * 0.2) * fftSmooth[32] * pos->y ;
            box[i].pos.z = (i - box.size() * 0.2) * fftSmooth[32] * pos->z ;
          
            box[i].rotate.x = i * fftSmooth[32] * Rotate.x * 0.004;
            box[i].rotate.y = i * fftSmooth[32] * Rotate.y * 0.004;
            box[i].rotate.z = i * fftSmooth[32] * Rotate.z * 0.004;
            
            box[i].size.x = 0.3 * i * fftSmooth[32] * Size.x + 30;
            box[i].size.y = 0.3 * i * fftSmooth[32] * Size.y + 30;
            box[i].size.z = 0.3 * i * fftSmooth[32] * Size.z + 30;

            
            box[i].update();
        }
    
        
    
    cout << "midiMessage.pitch = " << midiMessage.pitch << endl;
    cout << "midiMessage.control = " << midiMessage.control << endl;
    cout << midiMessage.value << endl;
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofSetColor(120, 180, 245, 255);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
   
    ofPushMatrix();
    
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateX(globalRotate.x);
    ofRotateY(globalRotate.y);
    ofRotateZ(globalRotate.z);
    ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
    
    for(int i = 0; i < box.size(); i++){
        box[i].draw();
    }
    
    ofPopMatrix();
    
    cam.end();
    
//    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
void ofApp::newMidiMessage(ofxMidiMessage& msg){
    //最新モメッセージジのコピーを作る
    midiMessage = msg;
    
    if(midiMessage.getStatusString(midiMessage.status) == "Note On"){
        manager.willConstBuffer(midiMessage.pitch);
    }
}
//
void ofApp::exit(){
    midiIn.closePort();
    midiIn.removeListener(this);
}

