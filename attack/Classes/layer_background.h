//
//  layer_background.h
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#ifndef __attack__layer_background__
#define __attack__layer_background__

#include <iostream>
#include "cocos2d.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


class layer_background : public cocos2d::CCLayer
{
public:
    static cocos2d::CCScene* scene();
    virtual bool init();
    void update(float dt);
   
    
    void menuCloseCallback(CCObject* pSender);
    
    CREATE_FUNC(layer_background);
    
    
protected:
    cocos2d::CCSize s ;
	cocos2d::CCSprite *m_map1;
	cocos2d::CCSprite *m_map2;
    
};


#endif /* defined(__attack__layer_background__) */
