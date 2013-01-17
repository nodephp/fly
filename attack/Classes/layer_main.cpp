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


int g_nNum=11;
cocos2d::CCLayer *layer_m=NULL;

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
    this->schedule(schedule_selector(layer_main::game_start),1);
    return true;
}


bool layer_main::addChild_a(CCSprite *pSprite, int idd)
{
    this->addChild(pSprite, 0,idd);
    return true;
}

bool layer_main::game_start()
{
    CCLOG("111");
    CCSprite *sprinte_1 = (CCSprite*)getChildByTag(1);
    if(!sprinte_1)
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
    
    
    
    
    CCSprite *sprinte_5 = (CCSprite*)getChildByTag(1);
    CCSprite *sprinte_6 = (CCSprite*)getChildByTag(2);
    CCSprite *sprinte_7 = (CCSprite*)getChildByTag(3);
    
//    CCLOG("%p",sprinte_5);
//    CCLOG("%p",sprinte_6);
//    CCLOG("%p",sprinte_7);
    
    bool ret_5 = CCRect::CCRectContainsPoint(sprinte_5->boundingBox(), location);
    bool ret_6 = CCRect::CCRectContainsPoint(sprinte_6->boundingBox(), location);
    bool ret_7 = CCRect::CCRectContainsPoint(sprinte_7->boundingBox(), location);
    if(ret_5 || ret_6 || ret_7)
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
    
    CCSprite *sprinte_5 = (CCSprite*)getChildByTag(1);
    CCSprite *sprinte_6 = (CCSprite*)getChildByTag(2);
    CCSprite *sprinte_7 = (CCSprite*)getChildByTag(3);
    
    if(layer_main::touch == true)
    {
        float endx = location.x;
        sprinte_5->setPosition(ccp(endx,50));
        sprinte_6->setPosition(ccp(endx-15,40));
        sprinte_7->setPosition(ccp(endx+12,40));
    }
}
























void layer_main::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
