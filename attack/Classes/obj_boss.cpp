//
//  obj_boss.cpp
//  attack
//
//  Created by gerry on 13-1-26.
//
//

#include "obj_boss.h"
#include "SimpleAudioEngine.h"
#include "layer_main.h"
#include "config.h"

using namespace cocos2d;
using namespace CocosDenshion;


obj_boss::obj_boss()
{
    this->init();
}


obj_boss::~obj_boss()
{
    
}



bool obj_boss::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    if(!layer_m)
    {
        return false;
    }
    

//    CCSprite *sprite_enemy_body = new CCSprite();
//    sprite_enemy_body->initWithFile(SPRITE_DRAGON_02_RESOURCE);
//    sprite_enemy_body->setTextureRect(CCRectMake(SPRITE_ENEMY_BODY_RET[0], SPRITE_ENEMY_BODY_RET[1], SPRITE_ENEMY_BODY_RET[2], SPRITE_ENEMY_BODY_RET[3]));
//    sprite_enemy_body->setPosition(ccp((SCREEN_WIDTH/2), SCREEN_HIGH));
//    sprite_enemy_body->setScale(global_scale);
//    layer_m->addChild(sprite_enemy_body, 0, id);
//    
//    
//    
//    
//    CCSprite *sprite_enemy_wind_a = new CCSprite();
//    sprite_enemy_wind_a->initWithFile(dragon_img);
//    sprite_enemy_wind_a->setTextureRect(CCRectMake(SPRITE_ENEMY_WIND_RET[0], SPRITE_ENEMY_WIND_RET[1], SPRITE_ENEMY_WIND_RET[2], SPRITE_ENEMY_WIND_RET[3]));
//    sprite_enemy_wind_a->setPosition(ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+11), SCREEN_HIGH));
//    sprite_enemy_wind_a->setScale(global_scale);
//    layer_m->addChild(sprite_enemy_wind_a, 0, id+100);
//    
//    
//    CCSprite *sprite_enemy_wind_b = new CCSprite();
//    sprite_enemy_wind_b->initWithFile(dragon_img);
//    sprite_enemy_wind_b->setTextureRect(CCRectMake(SPRITE_ENEMY_WIND_RET[0], SPRITE_ENEMY_WIND_RET[1], SPRITE_ENEMY_WIND_RET[2], SPRITE_ENEMY_WIND_RET[3]));
//    sprite_enemy_wind_b->setFlipX(true);
//    sprite_enemy_wind_b->setPosition( ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+52), SCREEN_HIGH));
//    sprite_enemy_wind_b->setScale(global_scale);
//    layer_m->addChild(sprite_enemy_wind_b, 0, id+200);
//    
//    
//    
//    
//    CCSprite *sprite_enemy_eye_a = new CCSprite();
//    sprite_enemy_eye_a->initWithFile(dragon_img);
//    sprite_enemy_eye_a->setTextureRect(CCRectMake(SPRITE_ENEMY_EYES_A_RET[0], SPRITE_ENEMY_EYES_A_RET[1], SPRITE_ENEMY_EYES_A_RET[2], SPRITE_ENEMY_EYES_A_RET[3]));
//    sprite_enemy_eye_a->setPosition(ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+24), SCREEN_HIGH+6));
//    sprite_enemy_eye_a->setScale(global_scale);
//    layer_m->addChild(sprite_enemy_eye_a, 0, id+300);
//    
//    
//    CCSprite *sprite_enemy_eye_b = new CCSprite();
//    sprite_enemy_eye_b->initWithFile(dragon_img);
//    sprite_enemy_eye_b->setTextureRect(CCRectMake(SPRITE_ENEMY_EYES_A_RET[0], SPRITE_ENEMY_EYES_A_RET[1], SPRITE_ENEMY_EYES_A_RET[2], SPRITE_ENEMY_EYES_A_RET[3]));
//    sprite_enemy_eye_b->setFlipX(true);
//    sprite_enemy_eye_b->setPosition(ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+36), SCREEN_HIGH+6));
//    sprite_enemy_eye_b->setScale(global_scale);
//    layer_m->addChild(sprite_enemy_eye_b, 0, id+400);
//    
//    
//    
//    
//    CCFiniteTimeAction *action_body_1 = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+30),0));
//    sprite_enemy_body->runAction(action_body_1);
//    
//    CCFiniteTimeAction *action_wind_a = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+11),0));
//    sprite_enemy_wind_a->runAction(action_wind_a);
//    
//    CCFiniteTimeAction *action_wind_b = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+52),0));
//    sprite_enemy_wind_b->runAction(action_wind_b);
//    
//    CCFiniteTimeAction *action_eye_a = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+24),6));
//    sprite_enemy_eye_a->runAction(action_eye_a);
//    
//    CCFiniteTimeAction *action_eye_b = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+36),6));
//    sprite_enemy_eye_b->runAction(action_eye_b);
    
    
    
    
    
    
    //    CCSkewBy CCRotateTo
//    CCActionInterval*  act1_a = CCRotateTo::actionWithDuration(0.3, 33);
//    CCActionInterval*  act2_a = CCRotateTo::actionWithDuration(0.3, -33);
//    CCActionInterval*  seq_a = (CCActionInterval*)(CCSequence::actions(act1_a, act2_a, NULL));
//    CCAction*  rep1 = CCRepeatForever::actionWithAction(seq_a);
//    
//    CCActionInterval*  act1_b = CCRotateTo::actionWithDuration(0.3, -33);
//    CCActionInterval*  act2_b = CCRotateTo::actionWithDuration(0.3, 33);
//    CCActionInterval*  seq_b = (CCActionInterval*)(CCSequence::actions(act1_b, act2_b, NULL));
//    CCAction*  rep2 = CCRepeatForever::actionWithAction(seq_b);
//    
//    sprite_enemy_wind_a->runAction(rep1);
//    sprite_enemy_wind_b->runAction(rep2);
    
    
    
    return true;
}

























