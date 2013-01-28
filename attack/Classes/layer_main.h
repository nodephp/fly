//
//  layer_main.h
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#ifndef __attack__layer_main__
#define __attack__layer_main__

#include <iostream>
#include "cocos2d.h"
#include "layer_background.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//#include "obj_myself.h"
using namespace std;

extern cocos2d::CCLayer *layer_m;


class layer_background;
//class obj_myself;


class layer_main : public cocos2d::CCLayer
{
public:
    static cocos2d::CCScene* scene();
    virtual bool init();
    virtual bool init_myself();
    virtual bool game_start();
    virtual bool boss_start();
    virtual bool be_attack(int damage);
    virtual void shoot();
    virtual bool auto_collide();
    bool touch = false;
    static float scale;
    
    virtual bool meteo_1();
    virtual bool meteo_2();
    
    virtual bool speed_up();
    virtual bool speed_up_end();
    
    
    void registerWithTouchDispatcher();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    
    
    
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(layer_main);
};


#endif /* defined(__attack__layer_main__) */
