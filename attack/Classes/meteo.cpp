//
//  meteo.cpp
//  attack
//
//  Created by gerry on 13-1-22.
//
//

#include "meteo.h"
#include "SimpleAudioEngine.h"
#include "layer_main.h"
#include "config.h"

using namespace cocos2d;
using namespace CocosDenshion;


meteo::meteo()
{
    
}


meteo::~meteo()
{
    
}



bool meteo::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    if(!layer_m)
    {
        return false;
    }
    CCLOG("222");
    
    CCSprite *sprite_warn_line = new CCSprite();
    sprite_warn_line->initWithFile("warn_line.png");

    sprite_warn_line->setPosition(ccp(100, 250));
    sprite_warn_line->setScaleY(2.0);
    layer_m->addChild(sprite_warn_line, -1, 20);
    
    CCSprite *sprite_meteo = new CCSprite();
    sprite_meteo->initWithFile("meteo.png");
    sprite_meteo->setPosition(ccp(100, SCREEN_HIGH+10));
    sprite_meteo->setScale(global_scale);
    layer_m->addChild(sprite_meteo, 10, 21);
    
    
    
    CCActionInterval *actionMove1 = CCFadeOut::actionWithDuration(1);
    CCActionInterval *actionMove2 = CCFadeIn::actionWithDuration(1);

    CCActionInterval *seq_b = (CCActionInterval*)(CCSequence::actions(actionMove1, actionMove2, actionMove1, actionMove2, actionMove1, actionMove2, actionMove1, NULL));
    
    sprite_warn_line->runAction(seq_b);
//    layer_m->removeChild(sprite_warn_line, true);
 
    CCFiniteTimeAction *bj_a = CCMoveTo::create(1,ccp(150,320));
    
    
    
//    CCSprite *sprite_booster_run_01 = new CCSprite();
//    sprite_booster_run_01->initWithFile("booster_run_01.png");
//    sprite_booster_run_01->setPosition(ccp(100, 250));
////    sprite_booster_run_01->setScale(global_scale);
//    layer_m->addChild(sprite_booster_run_01, 9, 22);

    
    return true;
}



bool meteo::setp_1()
{
    CCLOG("111");
    CCSprite *sprite_warn_line = (CCSprite*)layer_m->getChildByTag(20);
    layer_m->removeChild(sprite_warn_line, true);
    this->unschedule(schedule_selector( meteo::setp_1 ));
    
    
    CCSprite *sprite_meteo = new CCSprite();
    sprite_meteo->initWithFile("meteo.png");
    sprite_meteo->setPosition(ccp(100, 250));
    layer_m->addChild(sprite_meteo, 10, 21);
       
    CCSprite *sprite_booster_run_01 = new CCSprite();
    sprite_booster_run_01->initWithFile("booster_run_01.png");
    sprite_booster_run_01->setPosition(ccp(100, 250));
    layer_m->addChild(sprite_booster_run_01, 10, 22);
   
    return true;
}



















