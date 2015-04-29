//
//  Application.cpp
//  Qin
//
//  Created by love on 22/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#include "Application.h"

static Application* instance = 0;

Application::Application()
{
    _isRun = false;
}

Application::~Application()
{

}

Application* Application::getInstance()
{
    if(!instance){
        instance = new Application();
        instance->init();
    }
    
    return instance;
}

bool Application::init()
{
    glfwInit();
    
    initMatrixStack();
    
    return true;
}

void Application::setSize(float width,float height)
{
    _width  = width;
    _height = height;
}

int Application::run()
{
    if(_isRun){
        return true;
    }
    
    _window     = glfwCreateWindow(_width,_height,"HelloWorld", NULL, NULL);
    glfwMakeContextCurrent(_window);
    
    _isRun      = true;
    _program    = GLProgram::getInstance();
    
    m3dMakePerspectiveMatrix(_projectionMatrix,60.0, _width/_height, 1.0,_height / 2 / tan(30 * M3D_PI / 180) + _height / 2);
    m3dTranslationMatrix44(_viewMatrix,0,0,(0 -_height) / 2 / tan(30 * M3D_PI / 180));

    if(_controller){
        _controller->onEnter();
    }
    
    while(!glfwWindowShouldClose(_window)){
        startRender();
        
        glfwSwapBuffers(_window);
        glfwPollEvents();
        
        usleep(static_cast<useconds_t>(1.0f/60.0f*1000.0f *1000));
    }
    
    return true;
}

bool Application::setController(Controller* controller)
{
    if(_controller != controller){
        _controller = controller;
    }
    
    return true;
}

void Application::startRender()
{
    if(!_controller){
        return;
    }
    
    pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, _projectionMatrix);
    
    pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _viewMatrix);
    
    _controller->render();

    popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

void Application::initMatrixStack(){
    loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE);
    
    _projectionStackPointer = 1;
    _modelViewStackPointer  = 1;
    _textureStackPointer    = 1;
}

void Application::pushMatrix(MATRIX_STACK_TYPE type)
{
    if(type == MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW)
    {
        _modelViewStackPointer ++;
        m3dCopyMatrix44(_modelViewMatrixStack[_modelViewStackPointer], _modelViewMatrixStack[_modelViewStackPointer - 1]);
    }
    else if(type == MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION)
    {
        _projectionStackPointer ++;
        m3dCopyMatrix44(_projectionMatrixStack[_projectionStackPointer], _projectionMatrixStack[_projectionStackPointer - 1]);
    }
    else if(type == MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE)
    {
        _textureStackPointer ++;
        m3dCopyMatrix44(_textureMatrixStack[_textureStackPointer], _textureMatrixStack[_textureStackPointer - 1]);
    }
    else
    {
        return;
    }
}

void Application::popMatrix(MATRIX_STACK_TYPE type)
{
    if(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW == type)
    {
        _modelViewStackPointer --;
    }
    else if(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION == type)
    {
        _projectionStackPointer --;
    }
    else if(MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE == type)
    {
        _textureStackPointer --;
    }
    else
    {
        return;
    }
}

void Application::loadIdentityMatrix(MATRIX_STACK_TYPE type)
{
    if(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW == type)
    {
        m3dLoadIdentity44(_modelViewMatrixStack[_modelViewStackPointer]);
    }
    else if(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION == type)
    {
        m3dLoadIdentity44(_projectionMatrixStack[_projectionStackPointer]);
    }
    else if(MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE == type)
    {
        m3dLoadIdentity44(_textureMatrixStack[_textureStackPointer]);
    }
    else
    {
        return;
    }
}

void Application::loadMatrix(MATRIX_STACK_TYPE type, const M3DMatrix44f& mat)
{
    if(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW == type)
    {
        m3dCopyMatrix44(_modelViewMatrixStack[_modelViewStackPointer],mat);
    }
    else if(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION == type)
    {
        m3dCopyMatrix44(_projectionMatrixStack[_projectionStackPointer],mat);
    }
    else if(MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE == type)
    {
        m3dCopyMatrix44(_textureMatrixStack[_textureStackPointer],mat);
    }
    else
    {
       return;
    }
}

void Application::getMatrix(MATRIX_STACK_TYPE type,M3DMatrix44f mMatrix)
{
    if(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW == type)
    {
        m3dCopyMatrix44(mMatrix, _modelViewMatrixStack[_modelViewStackPointer]);
    }
    else if(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION == type)
    {
        m3dCopyMatrix44(mMatrix, _projectionMatrixStack[_projectionStackPointer]);
    }
    else if(MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE == type)
    {
        m3dCopyMatrix44(mMatrix, _textureMatrixStack[_textureStackPointer]);
    }
    else
    {
        return;
    }
}


















