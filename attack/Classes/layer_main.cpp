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
        this->unschedule(schedule_selector( layer_main::game_start ));
        
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
    
    
    return true;
}




bool layer_main::game_start()
{
    
    
    
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
