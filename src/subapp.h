#pragma once

#include "ofMain.h"
#include "params.h"

class subApp {
public:
    void init(appParams * paramsArg) {
        params = paramsArg;
    };
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void cleanup() = 0;
    
    appParams * params;
};

