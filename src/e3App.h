#include "ofMain.h"
#include "subApp.h"

class  e3App : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    ofPolyline line;
    
    void cDrawLine(ofPolyline line);
};
