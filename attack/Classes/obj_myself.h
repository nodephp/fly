//
//  obj_myself.h
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#ifndef __attack__obj_myself__
#define __attack__obj_myself__

#include <iostream>
#include "cocos2d.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "layer_main.h"


//class layer_main;

class obj_myself : public cocos2d::CCLayer
{
public:
    obj_myself();
    virtual ~obj_myself();
    virtual bool init();
    float scale = 0.45;
    virtual cocos2d::CCSprite* getChildByTag_a(int idd);
    
//    layer_main *layer_mm;
    
    CREATE_FUNC(obj_myself);
};


#endif /* defined(__attack__obj_myself__) */
