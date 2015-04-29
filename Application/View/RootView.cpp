//
//  RootView.cpp
//  HelloWorld
//
//  Created by love on 23/4/15.
//  Copyright (c) 2015年 Qin. All rights reserved.
//

#include "RootView.h"

RootView* RootView::create()
{
    RootView* view = new RootView();
    
    if(view && view->init()){
        return view;
    }
    
    return nullptr;
}

void RootView::onEnter(){
    this->setPosition(0,0);
    
    this->setAnchorPoint(0.5,0.5);
    
    this->setScale(1,1);
    
    this->setRotate(0);
    
    this->setSize(200,200);
    
    View::onEnter();
}












