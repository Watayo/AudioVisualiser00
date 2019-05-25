//
//  Object.h
//  patternExample
//
//  
//
//

#ifndef patternExample_Object_h
#define patternExample_Object_h

class slide : public ofPoint{
private:
    
    ofPoint p;
    
    float speed;
    
public:
    
    slide():speed(0.1){
    }
    
    void set(float _px,float _py,float _pz){
        p.x = _px;
        p.y = _py;
        p.z = _pz;
    }
    
    void set(float _px,float _py){
        p.x = _px;
        p.y = _py;
    }
    
    void imSet(float _px,float _py,float _pz){
        p.x = _px;
        p.y = _py;
        p.z = _pz;
        
        x = _px;
        y = _py;
        z = _pz;
    }
    
    void imSet(float _px,float _py){
        p.x = _px;
        p.y = _py;
        
        x = _px;
        y = _py;
        
    }
    
    void update(){
        x += (p.x - x) * speed;
        y += (p.y - y) * speed;
        z += (p.z - z) * speed;
    }
};


class Primitive{
public:
    
    ofPoint pos;
    slide size;
    slide rotate;
    ofColor color;
     
    void update(){
        
    }
    
   
    void draw(){
        
        color.set(50, 80, 255, 255);
        size.set(10,10);
        pos.set(ofGetWidth() * 0.5 ,ofGetHeight() * 0.5);
        
        ofPushMatrix();
        ofPushStyle();
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofNoFill();
        ofSetColor(color.r, color.g, color.b, color.a);
        ofTranslate(pos.x, pos.y, pos.z);
        
       
        ofRotateX(rotate.x);
        ofRotateY(rotate.y);
        ofRotateZ(rotate.z);
        
    
//        ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
//        ofTranslate(pos.x,pos.y,pos.z);
        
        ofDrawBox(0, 0, 0, size.x, size.y, size.z);
        ofPopStyle();
            

    }
};

#endif


