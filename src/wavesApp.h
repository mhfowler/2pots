#include "ofMain.h"
#include "subApp.h"

class wavesApp : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    void cDrawLine(ofPolyline line);
};
