#include "ofMain.h"
#include "subApp.h"

class b1App : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    void cDrawLine(ofPolyline line);
};
