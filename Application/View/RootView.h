//
//  RootView.h
//  HelloWorld
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#ifndef __HelloWorld__RootView__
#define __HelloWorld__RootView__

#include "Qin.h"

class RootView : public View
{
public:
    static RootView* create();
    
    virtual void onEnter();
};

#endif /* defined(__HelloWorld__RootView__) */
