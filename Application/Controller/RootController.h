//
//  RootController.h
//  HelloWorld
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#ifndef __HelloWorld__RootController__
#define __HelloWorld__RootController__

#include "Qin.h"
#include "RootView.h"

class RootController : public Controller
{
public:
    static RootController* create();
    
    virtual void onEnter();
};

#endif /* defined(__HelloWorld__RootController__) */
