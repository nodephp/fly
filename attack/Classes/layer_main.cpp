//
//  layer_main.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "layer_main.h"
#include "SimpleAudioEngine.h"
#include "obj_myself.h"
#include "config.h"


cocos2d::CCLayer *layer_m = NULL;

using namespace cocos2d;
using namespace CocosDenshion;




CCScene* layer_main::scene()
{
    CCScene *scene = CCScene::create();
    
    //载入背景层
    layer_background *layer_background = layer_background::create();
    scene->addChild(layer_background);
    
    
    //载入本层
    layer_main *layer_main = layer_main::create();
    scene->addChild(layer_main);
    
    layer_m = layer_main;
    

    
    return scene;
}



bool layer_main::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    this->setTouchEnabled(true);
    
    
    //初始化自己
    this->schedule(schedule_selector(layer_main::game_start),0.5);
    
    
    
    
    
    
    
    
    return true;
}





bool layer_main::game_start()
{
    CCSprite *sprite_myself_body = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    if(!sprite_myself_body)
    {
        obj_myself::obj_myself();
        this->unschedule(schedule_selector( layer_main::game_start ));
    }
    return true;
}



void layer_main::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}




bool layer_main::ccTouchBegan(CCTouch *pTouches, CCEvent *pEvent)
{
    CCPoint location = pTouches->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    CCSprite *sprite_myself_body   = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    CCSprite *sprite_myself_wind_a = (CCSprite*)getChildByTag(SPRITE_MYSELF_WIND_A);
    CCSprite *sprite_myself_wind_b = (CCSprite*)getChildByTag(SPRITE_MYSELF_WIND_B);
    
    bool ret_sprite_myself_body    = CCRect::CCRectContainsPoint(sprite_myself_body->boundingBox(), location);
    bool ret_sprite_myself_wind_a  = CCRect::CCRectContainsPoint(sprite_myself_wind_a->boundingBox(), location);
    bool ret_sprite_myself_wind_b  = CCRect::CCRectContainsPoint(sprite_myself_wind_b->boundingBox(), location);
    if(ret_sprite_myself_body || ret_sprite_myself_wind_a || ret_sprite_myself_wind_b)
    {
        layer_main::touch = true;
    }
    return true;
}

void layer_main::ccTouchEnded(CCTouch *pTouches, CCEvent *pEvent)
{
    layer_main::touch = false;
}

void layer_main::ccTouchMoved(CCTouch *pTouches, CCEvent *pEvent)
{
    CCPoint location = pTouches->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    CCSprite *sprite_myself_body   = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    CCSprite *sprite_myself_wind_a = (CCSprite*)getChildByTag(SPRITE_MYSELF_WIND_A);
    CCSprite *sprite_myself_wind_b = (CCSprite*)getChildByTag(SPRITE_MYSELF_WIND_B);
    
    if(layer_main::touch == true)
    {
        float endx = location.x;
        sprite_myself_body->setPosition(ccp(endx,SPRITE_MYSELF_BODY_POSITION[1]));
        sprite_myself_wind_a->setPosition(ccp(endx-15,SPRITE_MYSELF_WIND_A_POSITION[1]));
        sprite_myself_wind_b->setPosition(ccp(endx+12,SPRITE_MYSELF_WIND_A_POSITION[1]));
    }
}
























void layer_main::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
