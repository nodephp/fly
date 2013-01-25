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
#include "config.h"

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
    if(!layer_m)
    {
        return false;
    }
    
//    CCLOG("%c",SPRITE_MYSELF_BODY_RESOURCE);

    CCSprite *pMyself = new CCSprite();
    pMyself->initWithFile(SPRITE_MYSELF_RESOURCE);
    pMyself->setTextureRect(CCRectMake(SPRITE_MYSELF_BODY_RET[0], SPRITE_MYSELF_BODY_RET[1], SPRITE_MYSELF_BODY_RET[2], SPRITE_MYSELF_BODY_RET[3]));
    pMyself->setPosition( ccp(SPRITE_MYSELF_BODY_POSITION[0], SPRITE_MYSELF_BODY_POSITION[1]) );
    pMyself->setScale(global_scale);
    layer_m->addChild(pMyself,0,SPRITE_MYSELF_BODY);
    
    CCSprite *pMyself_wind_a = new CCSprite();
    pMyself_wind_a->initWithFile(SPRITE_MYSELF_RESOURCE);
    pMyself_wind_a->setTextureRect(CCRectMake(SPRITE_MYSELF_WIND_A_RET[0], SPRITE_MYSELF_WIND_A_RET[1], SPRITE_MYSELF_WIND_A_RET[2], SPRITE_MYSELF_WIND_A_RET[3]));
    pMyself_wind_a->setPosition( ccp(SPRITE_MYSELF_WIND_A_POSITION[0], SPRITE_MYSELF_WIND_A_POSITION[1]) );
    pMyself_wind_a->setScale(global_scale);
    layer_m->addChild(pMyself_wind_a, 0,SPRITE_MYSELF_WIND_A);
    
    CCSprite *pMyself_wind_b = new CCSprite();
    pMyself_wind_b->initWithFile(SPRITE_MYSELF_RESOURCE);
    pMyself_wind_b->setTextureRect(CCRectMake(SPRITE_MYSELF_WIND_B_RET[0], SPRITE_MYSELF_WIND_B_RET[1], SPRITE_MYSELF_WIND_B_RET[2], SPRITE_MYSELF_WIND_B_RET[3]));
    pMyself_wind_b->setFlipX(true);
    pMyself_wind_b->setPosition( ccp(SPRITE_MYSELF_WIND_B_POSITION[0], SPRITE_MYSELF_WIND_B_POSITION[1]) );
    pMyself_wind_b->setScale(global_scale);
    layer_m->addChild(pMyself_wind_b, 0,SPRITE_MYSELF_WIND_B);

    pMyself_wind_a->setAnchorPoint(ccp(1,0));
    pMyself_wind_b->setAnchorPoint(ccp(0,0));
    
    CCActionInterval*  act1_a = CCSkewTo::actionWithDuration(0.3, 15,0);
    CCActionInterval*  act2_a = CCRotateTo::actionWithDuration(0.3, -20);
    CCActionInterval*  act3_a = CCRotateTo::actionWithDuration(0.3, -40);
    CCActionInterval*  act4_a = CCSkewTo::actionWithDuration(0.3, -15,0);
    CCActionInterval*  seq_a = (CCActionInterval*)(CCSequence::actions(act1_a,act2_a,act4_a,act3_a,NULL));
    CCAction*  rep1 = CCRepeatForever::actionWithAction(seq_a);
    
    CCActionInterval*  act1_b = CCSkewTo::actionWithDuration(0.3, -15,0);
    CCActionInterval*  act2_b = CCRotateTo::actionWithDuration(0.3, 20);
    CCActionInterval*  act3_b = CCRotateTo::actionWithDuration(0.3, 40);
    CCActionInterval*  act4_b = CCSkewTo::actionWithDuration(0.3, 15,0);
    CCActionInterval*  seq_b = (CCActionInterval*)(CCSequence::actions(act1_b,act2_b,act4_b,act3_b,NULL));
    CCAction*  rep2 = CCRepeatForever::actionWithAction(seq_b);
    
    pMyself_wind_a->runAction(rep1);
    pMyself_wind_b->runAction(rep2);
    
    
    
    
    return true;
}

























