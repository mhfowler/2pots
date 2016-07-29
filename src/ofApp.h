#pragma once

#include "ofMain.h"
#include "subApp.h"
#include "params.h"
#include "spiralsApp.h"
#include "testApp.h"
#include "line1App.h"
#include "b1App.h"
#include "c1App.h"
#include "a1App.h"
#include "a2App.h"
#include "test2App.h"
#include "redLinesApp.h"

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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofSerial serial;
    
    appParams params;
    
    
    ofArduino	ard;
    bool		bSetupArduino;			// flag variable for setting up arduino once
    
    
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void analogPinChanged(const int & pinNum);
    void updateArduino();
    
    void buttonAPressed();
    
    ofColor dotColor;
    int buttonAState = 0;
    
    void increasePotA();
    void increasePotB();
    void decreasePotA();
    void decreasePotB();
    
    
        redLinesApp redLinesApp;
        spiralsApp spiralsApp;
    line1App line1App;
        a1App a1App;
       a2App a2App;
        b1App b1App;
            c1App c1App;
     test2App testApp;
    
    vector<subApp*> apps = {
        &redLinesApp,
        &spiralsApp,
        &line1App,
//        &a1App,
        &a2App,
        &b1App,
        &c1App,
        &testApp
    };
    
    subApp * currentApp;
    
};
