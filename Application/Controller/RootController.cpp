//
//  RootController.cpp
//  HelloWorld
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#include "RootController.h"

RootController* RootController::create()
{
    RootController* controller = new RootController();
    if(controller && controller->init())
    {
        return controller;
    }
    
    return nullptr;
}

void RootController::onEnter()
{
    View* view = RootView::create();
    
    this->setView(view);
    
    Controller::onEnter();
}