//
//  obj_myself.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "obj_myself.h"
#include "SimpleAudioEngine.h"
#include "layer_main.h"

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
    CCLOG("%i",g_nNum);
    CCLOG("%p",layer_m);
    if(!layer_m)
    {
        return false;
    }
    
    CCSprite *pMyself = new CCSprite();
    pMyself->initWithFile("sunny_01.png");
    pMyself->setTextureRect(CCRectMake(0, 0, 45, 110));
    pMyself->setPosition( ccp(100, 50) );
    pMyself->setScale(obj_myself::scale);
    layer_m->addChild(pMyself,0,1);
    
    CCSprite *pMyself_wind_a = new CCSprite();
    pMyself_wind_a->initWithFile("sunny_01.png");
    pMyself_wind_a->setTextureRect(CCRectMake(45, 0, 100, 60));
    pMyself_wind_a->setPosition( ccp(85, 40) );
    pMyself_wind_a->setScale(obj_myself::scale);
    layer_m->addChild(pMyself_wind_a, 0,2);
    
    CCSprite *pMyself_wind_b = new CCSprite();
    pMyself_wind_b->initWithFile("sunny_01.png");
    pMyself_wind_b->setTextureRect(CCRectMake(45, 0, 100, 60));
    pMyself_wind_b->setFlipX(true);
    pMyself_wind_b->setPosition( ccp(112, 40) );
    pMyself_wind_b->setScale(obj_myself::scale);
    layer_m->addChild(pMyself_wind_b, 0,3);

    CCActionInterval*  act1_a = CCSkewTo::actionWithDuration(0.3, 22,0);
    CCActionInterval*  act2_a = CCSkewTo::actionWithDuration(0.3, -22,0);
    CCActionInterval*  seq_a = (CCActionInterval*)(CCSequence::actions(act1_a, act2_a, NULL));
    CCAction*  rep1 = CCRepeatForever::actionWithAction(seq_a);
    
    CCActionInterval*  act1_b = CCSkewTo::actionWithDuration(0.3, -22,0);
    CCActionInterval*  act2_b = CCSkewTo::actionWithDuration(0.3, 22,0);
    CCActionInterval*  seq_b = (CCActionInterval*)(CCSequence::actions(act1_b, act2_b, NULL));
    CCAction*  rep2 = CCRepeatForever::actionWithAction(seq_b);
    
    pMyself_wind_a->runAction(rep1);
    pMyself_wind_b->runAction(rep2);
    
    
    
//    getChildByTag_a(1);
    
    return true;
}




CCSprite* obj_myself::getChildByTag_a(int idd)
{
    CCSprite *getChildByTag_a = (CCSprite*)getChildByTag(idd);
    CCLOG("%p",getChildByTag_a);
    return getChildByTag_a;
}




















