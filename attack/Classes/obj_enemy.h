//
//  obj_enemy.h
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#ifndef __attack__obj_enemy__
#define __attack__obj_enemy__

#include <iostream>
#include "cocos2d.h"




class obj_enemy : public cocos2d::CCLayer
{
public:
    obj_enemy();
    virtual ~obj_enemy();
    virtual bool init();
    virtual int get_enemy_id();
    
    
};
#endif /* defined(__attack__obj_enemy__) */
