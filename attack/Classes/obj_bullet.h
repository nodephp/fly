//
//  obj_bullet.h
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#ifndef __attack__obj_bullet__
#define __attack__obj_bullet__

#include <iostream>
#include "cocos2d.h"




class obj_bullet : public cocos2d::CCLayer
{
public:
    obj_bullet();
    virtual ~obj_bullet();
    virtual bool init(cocos2d::CCSprite *sprite_myself_body);
    virtual bool auto_bullet(int x, int y, int id);
    
    
};

#endif /* defined(__attack__obj_bullet__) */
