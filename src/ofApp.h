#pragma once

#include "ofMain.h"
#include "subApp.h"
#include "params.h"
#include "spiralsApp.h"
#include "testApp.h"
#include "line1App.h"
#include "d1App.h"
#include "h1App.h"
#include "e1App.h"
#include "g1App.h"
#include "g2App.h"
#include "e2App.h"
#include "e3App.h"
#include "e4App.h"
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
    float lastButtonPress;
    
    void increasePotA();
    void increasePotB();
    void decreasePotA();
    void decreasePotB();
    
    
        redLinesApp redLinesApp;
        spiralsApp spiralsApp;
    g1App g1App;
        g2App g2App;
        a1App a1App;
       a2App a2App;
        b1App b1App;
            c1App c1App;
            d1App d1App;
         e1App e1App;
     test2App testApp;
        e2App e2App;
            e3App e3App;
            e4App e4App;
            h1App h1App;
    
    vector<subApp*> apps = {
        
        &redLinesApp,
        
//        &line1App,
//        &a1App,
        
//        &testApp,
        
//               &a2App, // noise rectangle
        &a1App, // noise square
        &b1App, // glitch triangles
        &spiralsApp,
        
             &h1App, // just light
        
//        &e1App,
//        &c1App,
//        &d1App,
//                   &e2App,
//                   &e3App,
//             &e4App
        
        &g1App,       // two hand drawn squares
//             &g2App   // light shade
    };
    
    subApp * currentApp;
    
};
