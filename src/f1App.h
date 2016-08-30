#include "ofMain.h"
#include "subApp.h"

class  f1App : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    vector<ofPoint> pathPoints;
};
