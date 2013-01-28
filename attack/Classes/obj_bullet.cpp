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
        if(BULLET_STAT[ii] == 1)
        {
            id = BULLET_ID[ii];
            BULLET_STAT[ii] = 2;
            break;
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






















