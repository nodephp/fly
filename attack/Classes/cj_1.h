//
//  cj_1.h
//  attack
//
//  Created by gerry on 13-1-21.
//
//

#ifndef __attack__cj_1__
#define __attack__cj_1__

#include <iostream>

#include "cocos2d.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


class cj_1 : public cocos2d::CCLayer
{
public:
    static cocos2d::CCScene* scene();
    virtual bool init();
    
    void registerWithTouchDispatcher();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    
    void menuCloseCallback(CCObject* pSender);
    
    CREATE_FUNC(cj_1);
    
    
    
};


#endif /* defined(__attack__layer_background__) */
