//
//  layer_main.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "layer_main.h"
#include "layer_background.h"
#include "SimpleAudioEngine.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCScene* layer_main::scene()
{
    //载入背景层
    CCScene *scene = CCScene::create();
    layer_background *layer_background = layer_background::create();
    scene->addChild(layer_background);

    
    //载入本层
    layer_main *layer_main = layer_main::create();
    scene->addChild(layer_main);
    return scene;
}

bool layer_main::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    

    
    this->setTouchEnabled(true);
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
    CCSprite *sprinte_5 = (CCSprite*)getChildByTag(5);
    CCSprite *sprinte_6 = (CCSprite*)getChildByTag(6);
    CCSprite *sprinte_7 = (CCSprite*)getChildByTag(7);
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
    
    CCSprite *sprinte_5 = (CCSprite*)getChildByTag(5);
    CCSprite *sprinte_6 = (CCSprite*)getChildByTag(6);
    CCSprite *sprinte_7 = (CCSprite*)getChildByTag(7);
    
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
