//
//  Controller.cpp
//  Qin
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#include "Controller.h"

bool Controller::init()
{
    return true;
}

void Controller::onEnter()
{
    if(_view){
        _view->onEnter();
    }
}

void Controller::render()
{
    _view->draw();
}

void Controller::setView(View* view)
{
    _view = view;
}