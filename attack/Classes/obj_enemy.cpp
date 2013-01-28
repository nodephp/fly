//
//  obj_enemy.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "obj_enemy.h"
#include "SimpleAudioEngine.h"
#include "layer_main.h"
#include "config.h"

using namespace cocos2d;
using namespace CocosDenshion;


obj_enemy::obj_enemy()
{
    
}


obj_enemy::~obj_enemy()
{
    
}



bool obj_enemy::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    if(!layer_m)
    {
        return false;
    }
    

    
    
    int rand_min = 1;
    int rand_max = 2;
    char *dragon_img;
    for (int i = 1; i <= ENEMY_MEMBER_MAX; i++)
    {
        int id = get_enemy_id();
        if(id == 0)
        {
            continue;
        }
        
        int dragon_type = rand_min + rand() % (rand_max-rand_min+1) ;
        if(dragon_type == 1)
        {
            dragon_img = SPRITE_DRAGON_01_RESOURCE;
        }else
        {
            dragon_img = SPRITE_DRAGON_02_RESOURCE;
        }

        
        CCSprite *sprite_enemy_body = new CCSprite();
        sprite_enemy_body->initWithFile(dragon_img);
        sprite_enemy_body->setTextureRect(CCRectMake(SPRITE_ENEMY_BODY_RET[0], SPRITE_ENEMY_BODY_RET[1], SPRITE_ENEMY_BODY_RET[2], SPRITE_ENEMY_BODY_RET[3]));
        sprite_enemy_body->setPosition(ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+30), SCREEN_HIGH));
        sprite_enemy_body->setScale(global_scale);
        layer_m->addChild(sprite_enemy_body, 0, id);
        
        
        
        
        CCSprite *sprite_enemy_wind_a = new CCSprite();
        sprite_enemy_wind_a->initWithFile(dragon_img);
        sprite_enemy_wind_a->setTextureRect(CCRectMake(SPRITE_ENEMY_WIND_RET[0], SPRITE_ENEMY_WIND_RET[1], SPRITE_ENEMY_WIND_RET[2], SPRITE_ENEMY_WIND_RET[3]));
        sprite_enemy_wind_a->setPosition(ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+11), SCREEN_HIGH));
        sprite_enemy_wind_a->setScale(global_scale);
        layer_m->addChild(sprite_enemy_wind_a, 0, id+100);
        
        
        CCSprite *sprite_enemy_wind_b = new CCSprite();
        sprite_enemy_wind_b->initWithFile(dragon_img);
        sprite_enemy_wind_b->setTextureRect(CCRectMake(SPRITE_ENEMY_WIND_RET[0], SPRITE_ENEMY_WIND_RET[1], SPRITE_ENEMY_WIND_RET[2], SPRITE_ENEMY_WIND_RET[3]));
        sprite_enemy_wind_b->setFlipX(true);
        sprite_enemy_wind_b->setPosition( ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+52), SCREEN_HIGH));
        sprite_enemy_wind_b->setScale(global_scale);
        layer_m->addChild(sprite_enemy_wind_b, 0, id+200);
        
        
        
        
        CCSprite *sprite_enemy_eye_a = new CCSprite();
        sprite_enemy_eye_a->initWithFile(dragon_img);
        sprite_enemy_eye_a->setTextureRect(CCRectMake(SPRITE_ENEMY_EYES_A_RET[0], SPRITE_ENEMY_EYES_A_RET[1], SPRITE_ENEMY_EYES_A_RET[2], SPRITE_ENEMY_EYES_A_RET[3]));
        sprite_enemy_eye_a->setPosition(ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+24), SCREEN_HIGH+6));
        sprite_enemy_eye_a->setScale(global_scale);
        layer_m->addChild(sprite_enemy_eye_a, 0, id+300);
        
        
        CCSprite *sprite_enemy_eye_b = new CCSprite();
        sprite_enemy_eye_b->initWithFile(dragon_img);
        sprite_enemy_eye_b->setTextureRect(CCRectMake(SPRITE_ENEMY_EYES_A_RET[0], SPRITE_ENEMY_EYES_A_RET[1], SPRITE_ENEMY_EYES_A_RET[2], SPRITE_ENEMY_EYES_A_RET[3]));
        sprite_enemy_eye_b->setFlipX(true);
        sprite_enemy_eye_b->setPosition(ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+36), SCREEN_HIGH+6));
        sprite_enemy_eye_b->setScale(global_scale);
        layer_m->addChild(sprite_enemy_eye_b, 0, id+400);
        
        
        
        
        CCFiniteTimeAction *action_body_1 = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+30),0));
        sprite_enemy_body->runAction(action_body_1);

        CCFiniteTimeAction *action_wind_a = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+11),0));
        sprite_enemy_wind_a->runAction(action_wind_a);
        
        CCFiniteTimeAction *action_wind_b = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+52),0));
        sprite_enemy_wind_b->runAction(action_wind_b);
        
        CCFiniteTimeAction *action_eye_a = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+24),6));
        sprite_enemy_eye_a->runAction(action_eye_a);
        
        CCFiniteTimeAction *action_eye_b = CCMoveTo::create(ENEMY_SPEED,ccp((SCREEN_WIDTH/ENEMY_MEMBER_MAX*(i-1)+36),6));
        sprite_enemy_eye_b->runAction(action_eye_b);
        
        
        
        
        
        
        //    CCSkewBy CCRotateTo
        CCActionInterval*  act1_a = CCRotateTo::actionWithDuration(0.3, 33);
        CCActionInterval*  act2_a = CCRotateTo::actionWithDuration(0.3, -33);
        CCActionInterval*  seq_a = (CCActionInterval*)(CCSequence::actions(act1_a, act2_a, NULL));
        CCAction*  rep1 = CCRepeatForever::actionWithAction(seq_a);
        
        CCActionInterval*  act1_b = CCRotateTo::actionWithDuration(0.3, -33);
        CCActionInterval*  act2_b = CCRotateTo::actionWithDuration(0.3, 33);
        CCActionInterval*  seq_b = (CCActionInterval*)(CCSequence::actions(act1_b, act2_b, NULL));
        CCAction*  rep2 = CCRepeatForever::actionWithAction(seq_b);
        
        sprite_enemy_wind_a->runAction(rep1);
        sprite_enemy_wind_b->runAction(rep2);
        

        
        
        
    }

    
    return true;
}



int obj_enemy::get_enemy_id()
{
    int id=0;
    for (int ii=0; ii<=14; ii++)
    {
        if(ENEMY_STAT[ii] == 1)
        {
            id = ENEMY_ID[ii];
            ENEMY_STAT[ii] = 2;
            break;
        }
    }
    return id;
}



















