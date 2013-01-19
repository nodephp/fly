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
#include "obj_bullet.h"
#include "obj_enemy.h"
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
    this->schedule(schedule_selector(layer_main::init_myself),0.5);
    
    
    
    //碰撞控制
    this->schedule(schedule_selector(layer_main::auto_collide),0.1);
    
    
    //出怪
    this->schedule(schedule_selector(layer_main::game_start),5);
    
    
    
    return true;
}









bool layer_main::init_myself()
{
    CCSprite *sprite_myself_body = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    if(!sprite_myself_body)
    {
        obj_myself::obj_myself();
        this->unschedule(schedule_selector( layer_main::init_myself ));
        
        this->schedule(schedule_selector(layer_main::shoot),BULLET_SPEED);
    }
    return true;
}





void layer_main::shoot()
{
    CCSprite *sprite_myself_body = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    if(sprite_myself_body)
    {
        obj_bullet *obj = new obj_bullet;
        obj->init(sprite_myself_body);
    }
}





bool layer_main::auto_collide()
{
    for (int ii = BULLET_ID[0]; ii <= BULLET_ID[11]; ii++)
    {
        
        
        CCSprite *sprinte_bullet = (CCSprite*)getChildByTag(ii);
        if(sprinte_bullet)
        {
            
            CCPoint point_bullet = sprinte_bullet->getPosition();
            if( point_bullet.y >= (SCREEN_HIGH+10) )
            {
                this->removeChild(sprinte_bullet, true);
                if(ii==BULLET_ID[0]){BULLET_A=1;}
                else if(ii==BULLET_ID[1]){BULLET_B=1;}
                else if(ii==BULLET_ID[2]){BULLET_C=1;}
                else if(ii==BULLET_ID[3]){BULLET_D=1;}
                else if(ii==BULLET_ID[4]){BULLET_E=1;}
                else if(ii==BULLET_ID[5]){BULLET_F=1;}
                else if(ii==BULLET_ID[6]){BULLET_G=1;}
                else if(ii==BULLET_ID[7]){BULLET_H=1;}
                else if(ii==BULLET_ID[8]){BULLET_I=1;}
                else if(ii==BULLET_ID[9]){BULLET_J=1;}
                else if(ii==BULLET_ID[10]){BULLET_K=1;}
                else if(ii==BULLET_ID[11]){BULLET_L=1;}
            }
        }
    }
    
    
    for (int i=0; i<=(ENEMY_MEMBER_SUM_MAX-1); i++)
    {
        if(ENEMY_STAT[i] == 2)
        {
            CCSprite *sprinte_enemy_body = (CCSprite*)getChildByTag(ENEMY_ID[i]);
            CCSprite *sprinte_enemy_wind_a = (CCSprite*)getChildByTag(ENEMY_ID[i]+100);
            CCSprite *sprinte_enemy_wind_b = (CCSprite*)getChildByTag(ENEMY_ID[i]+200);
            CCSprite *sprinte_enemy_eye_a = (CCSprite*)getChildByTag(ENEMY_ID[i]+300);
            CCSprite *sprinte_enemy_eye_b = (CCSprite*)getChildByTag(ENEMY_ID[i]+400);
//            CCProgressTimer *sprinte_enemy_hp = (CCProgressTimer*)getChildByTag(ENEMY_ID[i]+500);
            
            for (int ii = BULLET_ID[0]; ii <= BULLET_ID[11]; ii++)
            {
                CCSprite *sprinte_bullet = (CCSprite*)getChildByTag(ii);
                if(sprinte_bullet)
                {
                    bool is_collide = false;
                    if(sprinte_enemy_body)
                    {
                        is_collide = CCRect::CCRectIntersectsRect(sprinte_bullet->boundingBox(), sprinte_enemy_body->boundingBox());
                    }

                    if(is_collide)
                    {
                        CCPoint point = sprinte_enemy_body->getPosition();
                        
                        int new_value = ENEMY_HP[i]-BULLET_FORCE;
                        if(new_value <= 0)
                        {
                            this->removeChild(sprinte_enemy_body, true);
                            this->removeChild(sprinte_enemy_wind_a, true);
                            this->removeChild(sprinte_enemy_wind_b, true);
                            this->removeChild(sprinte_enemy_eye_a, true);
                            this->removeChild(sprinte_enemy_eye_b, true);
                            CCProgressTimer *sprinte_enemy_hp_d = (CCProgressTimer*)getChildByTag(ENEMY_ID[i]+500);
                            if(sprinte_enemy_hp_d)
                            {
                                this->removeChild(sprinte_enemy_hp_d, true);
                            }
                            ENEMY_HP[i] = 100;
                            ENEMY_STAT[i] = 1;
                        }
                        CCProgressTimer *sprinte_enemy_hp = (CCProgressTimer*)getChildByTag(ENEMY_ID[i]+500);
                        if(sprinte_enemy_hp && new_value > 0)
                        {
                            sprinte_enemy_hp->setPercentage(ENEMY_HP[i]);
                            sprinte_enemy_hp->setPosition( ccp(point.x, point.y-20) );
                            sprinte_enemy_hp->setType(kCCProgressTimerTypeBar);
                            CCFiniteTimeAction *action_1 = CCMoveTo::create((ENEMY_SPEED*(point.y-1))/520,ccp(point.x,0));
                            sprinte_enemy_hp->runAction(action_1);
                            CCProgressTo *to = CCProgressTo::actionWithDuration(0.1, new_value);
                            sprinte_enemy_hp->runAction(to);
                            ENEMY_HP[i]= ENEMY_HP[i]-10;
                        }else
                        {
                            CCSprite *sprinte_enemy_body = (CCSprite*)getChildByTag(ENEMY_ID[i]);
                            if(sprinte_enemy_body)
                            {
                                CCProgressTimer *sprinte_enemy_hp = CCProgressTimer::progressWithSprite(CCSprite::create(SPRITE_ENEMY_HP_RESOURCE));
                                sprinte_enemy_hp->setPercentage(ENEMY_HP[i]);
                                sprinte_enemy_hp->setPosition( ccp(point.x, point.y-20) );
                                sprinte_enemy_hp->setType(kCCProgressTimerTypeBar);
                                sprinte_enemy_hp->setScale(global_scale);
                                sprinte_enemy_hp->setMidpoint(ccp(0,0));
                                sprinte_enemy_hp->setBarChangeRate(ccp(1,0));
                                this->addChild(sprinte_enemy_hp,0,ENEMY_ID[i]+500);
                                CCFiniteTimeAction *action_1 = CCMoveTo::create((ENEMY_SPEED*(point.y-1))/520,ccp(point.x,0));
                                sprinte_enemy_hp->runAction(action_1);
                                
                                CCProgressTo *to = CCProgressTo::actionWithDuration(0.1, new_value);
                                sprinte_enemy_hp->runAction(to);
                                ENEMY_HP[i]= ENEMY_HP[i]-10;
                            }
                            
                        }
                        
                        
                        
                        
                        CCSprite *item_gb = new CCSprite();
                        item_gb->initWithFile(SPRITE_ITEM_GB_RESOURCE);
                        item_gb->setPosition( ccp(point.x, point.y) );
                        item_gb->setScale(global_scale);
                        this->addChild(item_gb, 0,ENEMY_ID[i]+600);
                        CCJumpTo* mJumpTo = CCJumpTo::actionWithDuration(2.0f, ccp(280, 1), 230.0f, 1);
                        CCActionInterval*  seq_aa = (CCActionInterval*)(CCSequence::actions(mJumpTo, NULL));
                        item_gb->runAction(seq_aa);
                    }
                }
            }
        }
        CCSprite *sprinte_enemy_body = (CCSprite*)getChildByTag(ENEMY_ID[i]);
        CCSprite *sprinte_enemy_wind_a = (CCSprite*)getChildByTag(ENEMY_ID[i]+100);
        CCSprite *sprinte_enemy_wind_b = (CCSprite*)getChildByTag(ENEMY_ID[i]+200);
        CCSprite *sprinte_enemy_eye_a = (CCSprite*)getChildByTag(ENEMY_ID[i]+300);
        CCSprite *sprinte_enemy_eye_b = (CCSprite*)getChildByTag(ENEMY_ID[i]+400);
       
            if(sprinte_enemy_body)
            {
                CCPoint point_enemy_body = sprinte_enemy_body->getPosition();
                if( point_enemy_body.y <= 5)
                {
                    this->removeChild(sprinte_enemy_body, true);
                }
            }
            if(sprinte_enemy_wind_a)
            {
                CCPoint point_enemy_wind_a = sprinte_enemy_wind_a->getPosition();
                if( point_enemy_wind_a.y <= 5)
                {
                    this->removeChild(sprinte_enemy_wind_a, true);
                }
            }
            if(sprinte_enemy_wind_b)
            {
                CCPoint point_enemy_wind_b = sprinte_enemy_wind_b->getPosition();
                if( point_enemy_wind_b.y <= 5)
                {
                    this->removeChild(sprinte_enemy_wind_b, true);
                }
            }
            if(sprinte_enemy_eye_a)
            {
                CCPoint point_enemy_eye_a = sprinte_enemy_eye_a->getPosition();
                if( point_enemy_eye_a.y <= 10)
                {
                    this->removeChild(sprinte_enemy_eye_a, true);
                }
            }
            if(sprinte_enemy_eye_b)
            {
                CCPoint point_enemy_eye_b = sprinte_enemy_eye_b->getPosition();
                if( point_enemy_eye_b.y <= 10)
                {
                    this->removeChild(sprinte_enemy_eye_b, true);
                }
            }
            CCSprite *sprinte_item_gb = (CCSprite*)getChildByTag(ENEMY_ID[i]+600);
            if(sprinte_item_gb)
            {
                CCPoint a = sprinte_item_gb->getPosition();
                if( a.y <= 5)
                {
                    this->removeChild(sprinte_item_gb, true);
                }
            }
            CCProgressTimer *sprinte_enemy_hp_end = (CCProgressTimer*)getChildByTag(ENEMY_ID[i]+500);
            if(sprinte_enemy_hp_end)
            {
                CCPoint point_enemy_hp = sprinte_enemy_hp_end->getPosition();
                if( point_enemy_hp.y <= 5)
                {
                    this->removeChild(sprinte_enemy_hp_end, true);
                    ENEMY_HP[i] = 100;
                    ENEMY_STAT[i] = 1;
                }
            }

            
    }
    
    
    
    
    
     
    
    return true;
}




bool layer_main::game_start()
{
    obj_enemy *obj_e = new obj_enemy;
    obj_e->init();
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
