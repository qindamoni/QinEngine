//
//  View.h
//  Qin
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#ifndef __Qin__View__
#define __Qin__View__

#include "glfw3.h"

#include "Core/Application.h"
#include "Math/Math3d.h"

#import <OpenGL/glext.h>

class View
{
public:
    void draw();
    
    bool init();
    
    void setPosition(float x,float y);
    void setSize(float w,float y);
    void getTransform(M3DMatrix44f transfrom);
    void setAnchorPoint(float x,float y);
    void setScale(float x,float y);
    void setRotate(float r);
    
    static View* create(){return nullptr;};
    
    virtual void onEnter();
protected:
    View();
    
protected:
    float _x;
    float _y;
    float _w;
    float _h;
    float _ax;
    float _ay;
    float _sx;
    float _sy;
    float _r;
    
    M3DVector2f _vertex[4];
};

#endif /* defined(__Qin__View__) */
