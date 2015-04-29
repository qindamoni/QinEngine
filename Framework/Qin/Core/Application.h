//
//  Application.h
//  Qin
//
//  Created by love on 22/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#ifndef __Qin__Application__
#define __Qin__Application__

#include "Core/Controller.h"
#include "Render/GLProgram.h"
#include "glfw3.h"
#include <sys/time.h>
#include <unistd.h>
#include <stack>
#include "Math/Math3d.h"

enum class MATRIX_STACK_TYPE
{
    MATRIX_STACK_MODELVIEW,
    MATRIX_STACK_PROJECTION,
    MATRIX_STACK_TEXTURE
};

class Controller;

class Application
{
public:
    static Application* getInstance();
    
    bool    setController(Controller* controller);
    
    bool    init();
    int     run();
    void    startRender();
    void    setSize(float width,float height);
    
    GLProgram* getProgram(){return _program;};
    
    void initMatrixStack();
    void pushMatrix(MATRIX_STACK_TYPE type);
    void popMatrix(MATRIX_STACK_TYPE type);
    void loadMatrix(MATRIX_STACK_TYPE type,const M3DMatrix44f& mat);
    void loadIdentityMatrix(MATRIX_STACK_TYPE type);
    void getMatrix(MATRIX_STACK_TYPE type,M3DMatrix44f mat);
    
protected:
    Controller*     _controller;
    GLProgram*      _program;
    bool            _isRun;
    float           _height;
    float           _width;
    
    M3DMatrix44f    _projectionMatrix;
    M3DMatrix44f    _viewMatrix;
    
    
    M3DMatrix44f    _projectionMatrixStack[16];
    M3DMatrix44f    _modelViewMatrixStack[16];
    M3DMatrix44f    _textureMatrixStack[16];
    
    int _projectionStackPointer;
    int _modelViewStackPointer;
    int _textureStackPointer;
    
protected:
    Application();
    virtual ~Application();
  
    GLFWwindow* _window;
};

#endif /* defined(__Qin__Application__) */
