//
//  obj_myself.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "obj_myself.h"
#include "SimpleAudioEngine.h"



using namespace cocos2d;
using namespace CocosDenshion;

obj_myself::obj_myself()
{
    this->init();
}


obj_myself::~obj_myself()
{
    
}



bool obj_myself::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    
    CCSprite *pMyself = new CCSprite();
    pMyself->initWithFile("sunny_01.png");
    pMyself->setTextureRect(CCRectMake(0, 0, 45, 110));
    pMyself->setPosition( ccp(100, 50) );
    pMyself->setScale(obj_myself::scale);
    this->addChild(pMyself, 0,5);
    
    CCSprite *pMyself_wind_a = new CCSprite();
    pMyself_wind_a->initWithFile("sunny_01.png");
    pMyself_wind_a->setTextureRect(CCRectMake(45, 0, 100, 60));
    pMyself_wind_a->setPosition( ccp(85, 40) );
    pMyself_wind_a->setScale(obj_myself::scale);
    this->addChild(pMyself_wind_a, 0,6);
    
    CCSprite *pMyself_wind_b = new CCSprite();
    pMyself_wind_b->initWithFile("sunny_01.png");
    pMyself_wind_b->setTextureRect(CCRectMake(45, 0, 100, 60));
    pMyself_wind_b->setFlipX(true);
    pMyself_wind_b->setPosition( ccp(112, 40) );
    pMyself_wind_b->setScale(obj_myself::scale);
    this->addChild(pMyself_wind_b, 0,7);

    
    
    
    return true;
}


























