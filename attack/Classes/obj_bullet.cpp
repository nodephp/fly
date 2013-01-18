//
//  obj_bullet.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "obj_bullet.h"
#include "SimpleAudioEngine.h"
#include "layer_main.h"
#include "config.h"

using namespace cocos2d;
using namespace CocosDenshion;


obj_bullet::obj_bullet()
{

}


obj_bullet::~obj_bullet()
{
    
}



bool obj_bullet::init(CCSprite *sprite_myself_body)
{
    if( !CCLayer::init() )
    {
        return false;
    }
    if(!layer_m)
    {
        return false;
    }

    CCPoint point_myself_body = sprite_myself_body->getPosition();
    
    int id=0;
    for (int ii=0; ii<=11; ii++)
    {
        if(ii==0)
        {
            if(BULLET_A == 1)
            {
                id = BULLET_ID[ii];
                BULLET_A = 2;
                break;
            }
        }else if(ii==1)
        {
            if(BULLET_B == 1)
            {
                id = BULLET_ID[ii];
                BULLET_B = 2;
                break;
            }
        }else if(ii==2)
        {
            if(BULLET_C == 1)
            {
                id = BULLET_ID[ii];
                BULLET_C = 2;
                break;
            }
        }else if(ii==3)
        {
            if(BULLET_D == 1)
            {
                id = BULLET_ID[ii];
                BULLET_D = 2;
                break;
            }
        }else if(ii==4)
        {
            if(BULLET_E == 1)
            {
                id = BULLET_ID[ii];
                BULLET_E = 2;
                break;
            }
        }else if(ii==5)
        {
            if(BULLET_F == 1)
            {
                id = BULLET_ID[ii];
                BULLET_F = 2;
                break;
            }
        }else if(ii==6)
        {
            if(BULLET_G == 1)
            {
                id = BULLET_ID[ii];
                BULLET_G = 2;
                break;
            }
        }else if(ii==7)
        {
            if(BULLET_H == 1)
            {
                id = BULLET_ID[ii];
                BULLET_H = 2;
                break;
            }
        }else if(ii==8)
        {
            if(BULLET_I == 1)
            {
                id = BULLET_ID[ii];
                BULLET_I = 2;
                break;
            }
        }else if(ii==9)
        {
            if(BULLET_J == 1)
            {
                id = BULLET_ID[ii];
                BULLET_J = 2;
                break;
            }
        }else if(ii==10)
        {
            if(BULLET_K == 1)
            {
                id = BULLET_ID[ii];
                BULLET_K = 2;
                break;
            }
        }else if(ii==11)
        {
            if(BULLET_L == 1)
            {
                id = BULLET_ID[ii];
                BULLET_L = 2;
                break;
            }
        }
    }
    
    if(id>=100)
    {
        auto_bullet(point_myself_body.x,point_myself_body.y,id);
    }

    
    
    return true;
}



bool obj_bullet::auto_bullet(int x, int y, int id)
{
    if(!layer_m)
    {
        return false;
    }
    CCSprite *auto_bullet = new CCSprite();
    auto_bullet->initWithFile(SPRITE_BULLET_RESOURCE);
    auto_bullet->setPosition( ccp(x, y) );
    layer_m->addChild(auto_bullet, 0, id);
    CCFiniteTimeAction *action = CCMoveTo::create(1,ccp(x,SCREEN_HIGH+10));
    auto_bullet->runAction(action);
}






















