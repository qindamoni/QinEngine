//
//  GLProgram.h
//  Qin
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#ifndef __Qin__GLProgram__
#define __Qin__GLProgram__

#include "Core/Base.h"
#include "glfW3.h"

class GLProgram : public Base
{
public:
    static GLProgram* getInstance();
    
    bool init();
    
    void use();
    
    GLuint getProgram(){return _program;};
    
protected:
    GLuint _program;
    
    const char* _vShaderSource  =   "attribute vec4 vVertex;"
                                    "uniform mat4 mvp;"
                                    "void main(void) "
                                    "{"
                                        "gl_Position =  mvp * vVertex; "
                                    "}";
    
    const char* _fShaderSource =    "uniform vec4 vColor;"
                                    "void main(void) "
                                    "{"
                                        "gl_FragColor = vec4(1,1,0,1);"
                                    "}";
};

#endif /* defined(__Qin__GLProgram__) */
