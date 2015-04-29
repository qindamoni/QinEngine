//
//  View.cpp
//  Qin
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#include "View.h"

View::View()
{

}

bool View::init()
{
    for(size_t i = 0; i < sizeof(_vertex) / sizeof(_vertex[0]); i++){
        _vertex[i][0] = 0.0f;
        _vertex[i][1] = 0.0f;
    }
    
    setAnchorPoint(0.5,0.5);
    
    return true;
}

void View::setAnchorPoint(float x,float y)
{
    _ax = x;
    _ay = y;
}

void View::setScale(float x,float y)
{
    _sx = x;
    _sy = y;
}

void View::setRotate(float r)
{
    _r = r;
}


void View::onEnter()
{
   
}

void View::draw()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    Application* App    = Application::getInstance();
    GLProgram* program  = App->getProgram();
    
    M3DMatrix44f projectionMatrix;
    M3DMatrix44f modelViewMatrix;
    M3DMatrix44f modelViewProjectionMatrix;
 
    App->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, projectionMatrix);
    App->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, modelViewMatrix);
    
    m3dMatrixMultiply44(modelViewProjectionMatrix,projectionMatrix,modelViewMatrix);
    
    M3DMatrix44f slefTransform;
    M3DMatrix44f finalMatrix;
    
    getTransform(slefTransform);
    m3dMatrixMultiply44(finalMatrix,modelViewProjectionMatrix,slefTransform);
    
    GLint location = glGetUniformLocation(program->getProgram(),"mvp");
    glUniformMatrix4fv(location,1,GL_FALSE,finalMatrix);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,_vertex);
    glEnableVertexAttribArray(0);
    program->use();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void View::getTransform(M3DMatrix44f transfrom)
{
    M3DMatrix44f beforeTransformMatrix;
    M3DMatrix44f transformMatrix;
    M3DMatrix44f scaleMatrix;
    M3DMatrix44f rotateMatrix;
    
    m3dTranslationMatrix44(beforeTransformMatrix,-_w * _ax,-_h * _ay,0);
    
    m3dTranslationMatrix44(transformMatrix,_x, _y,0);
    
    m3dScaleMatrix44(scaleMatrix,_sx,_sy,0);
    
    m3dRotationMatrix44(rotateMatrix,_r,0,0,1);
    
    M3DMatrix44f x;
    M3DMatrix44f y;
    
    m3dMatrixMultiply44(x,rotateMatrix,beforeTransformMatrix);
    m3dMatrixMultiply44(y,scaleMatrix,x);
    m3dMatrixMultiply44(transfrom,transformMatrix,y);
    
    return;
    /**
    m3dMatrixMultiply44(x,scaleMatrix,transformMatrix);
    m3dMatrixMultiply44(transfrom,rotateMatrix,x);
    **/
    
    m3dMatrixMultiply44(x,scaleMatrix,beforeTransformMatrix);
    m3dMatrixMultiply44(y,rotateMatrix,x);
    m3dMatrixMultiply44(transfrom,transformMatrix,y);
}

void View::setPosition(float x, float y)
{
    _x = x;
    _y = y;
}

void View::setSize(float w, float h)
{
    _vertex[0][1]   = h;
    _vertex[1][0]   = w;
    _vertex[1][1]   = h;
    _vertex[3][0]   = w;

    _w = w;
    _h = h;
}














