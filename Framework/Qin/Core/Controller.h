//
//  Controller.h
//  Qin
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#ifndef __Qin__Controller__
#define __Qin__Controller__

#include "Core/Base.h"
#include "Core/View.h"

class View;
class Controller : public Base
{
public:
    static Controller* create(){return nullptr;};
    
    bool init();
    
    virtual void onEnter();
    
    void render();
    
    void setView(View* view);
protected:
    View* _view;
};

#endif /* defined(__Qin__Controller__) */
