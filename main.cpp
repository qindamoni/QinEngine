//
//  main.cpp
//  HelloWorld
//
//  Created by love on 22/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//
#include "Qin.h"
#include "RootController.h"

int main(){
    Application* App        = Application::getInstance();
    Controller* controller  = RootController::create();
    
    App->setSize(1136,640);
    App->setController(controller);
    
    return App->run();
}