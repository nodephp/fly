//
//  obj_boss.h
//  attack
//
//  Created by gerry on 13-1-26.
//
//

#ifndef __attack__obj_boss__
#define __attack__obj_boss__

#include <iostream>
#include "cocos2d.h"




class obj_boss : public cocos2d::CCLayer
{
public:
    obj_boss();
    virtual ~obj_boss();
    virtual bool init();
    
    
    CREATE_FUNC(obj_boss);
};
#endif /* defined(__attack__obj_boss__) */
