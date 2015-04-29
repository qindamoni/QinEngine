//
//  GLProgram.cpp
//  Qin
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#include "GLProgram.h"

GLProgram* GLProgram::getInstance()
{
    GLProgram* program = new GLProgram();
    
    if(program && program->init()){
        return program;
    }
    
    return nullptr;
}

bool GLProgram::init()
{
    _program = glCreateProgram();
    
    GLuint vShader;
    GLuint fShader;
    
    vShader = glCreateShader(GL_VERTEX_SHADER);
    fShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    glShaderSource(vShader, 1, &_vShaderSource, NULL);
    glShaderSource(fShader, 1, &_fShaderSource, NULL);
    
    glCompileShader(vShader);
    glCompileShader(fShader);
    
    GLint testVal;
    
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &testVal);
    if(testVal == GL_FALSE)
    {
        printf("error in vshader");
        
        glDeleteShader(vShader);
        glDeleteShader(fShader);
        return (GLuint) NULL;
    }
    
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &testVal);
    if(testVal == GL_FALSE)
    {
        printf("error in fShader");
        
        glDeleteShader(vShader);
        glDeleteShader(fShader);
        return (GLuint) NULL;
    }
    
    glAttachShader(_program, vShader);
    glAttachShader(_program, fShader);
    
    glBindAttribLocation(_program, 0, "vVertex");
    
    glLinkProgram(_program);
    
    glGetProgramiv(_program, GL_LINK_STATUS, &testVal);
    if(testVal == GL_FALSE)
    {
        printf("error in program");
        
        glDeleteProgram(_program);
        return (GLuint) NULL;
    }
    
    glDeleteShader(vShader);
    glDeleteShader(fShader);
    
    return true;
}

void GLProgram::use()
{
    glUseProgram(_program);
}