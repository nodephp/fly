#ifndef __game_bj_SCENE_H__
#define __game_bj_SCENE_H__

#include "cocos2d.h"

class game_bj : public cocos2d::CCLayer
{
public:
    virtual bool init();

    static cocos2d::CCScene* scene();
    void update(float dt);
    void auto_bullet(int x, int y, char id);
    void auto_pz(char id);
    void auto_enemy(char id);
    void listen();
    void shoot();
    void enemy();

    
    void registerWithTouchDispatcher();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent);
    

    
    
    void menuCloseCallback(CCObject* pSender);

    CREATE_FUNC(game_bj);

protected:
	cocos2d::CCSize s ;
	cocos2d::CCSprite *m_map1;
	cocos2d::CCSprite *m_map2;
    //	cocos2d::CCSpriteFrameCache* cache;
};

#endif // __HELLOWORLD_SCENE_H__


