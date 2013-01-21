//
//  cj_2.cpp
//  attack
//
//  Created by gerry on 13-1-21.
//
//

#include "cj_2.h"
#include "SimpleAudioEngine.h"
#include "layer_main.h"
#include "config.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCScene* cj_2::scene()
{
    CCScene *scene = CCScene::create();
    cj_2 *cj_1 = cj_2::create();
    scene->addChild(cj_1);
    return scene;
}

bool cj_2::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    
    CCSprite *BJ = new CCSprite();
    BJ->initWithFile("sd_01.png");
    BJ->setPosition(ccp(72,80));
    BJ->setScale(global_scale);
    this->addChild(BJ, 0);
    
    CCLabelTTF *label = CCLabelTTF::create("GOLD:", "Marker Felt", 21);
    this->addChild(label,0,9998);
    label->setPosition(ccp(240, 350));
    label->setColor( ccYELLOW );
    
    sprintf(MY_SCORE_GB_UPDATE, "%d", MY_SCORE_GB);
    CCLabelBMFont *lbEnemy = CCLabelBMFont::labelWithString(MY_SCORE_GB_UPDATE, "font09.fnt");
    lbEnemy->setAnchorPoint(ccp(0, 1));
    lbEnemy->setScale(0.8f);
    lbEnemy->setPosition(ccp(270, 350));
    this->addChild(lbEnemy, 1, 9999);
    
    CCLabelTTF *label_2 = CCLabelTTF::create("SCORE:", "Marker Felt", 21);
    this->addChild(label_2,0,9998);
    label_2->setPosition(ccp(30, 350));
    label_2->setColor( ccYELLOW );
    
    sprintf(MY_SCORE_UPDATE, "%d", MY_SCORE);
    CCLabelBMFont *lbEnemy_2 = CCLabelBMFont::labelWithString(MY_SCORE_UPDATE, "font09.fnt");
    lbEnemy_2->setAnchorPoint(ccp(0, 1));
    lbEnemy_2->setScale(0.8f);
    lbEnemy_2->setPosition(ccp(90, 350));
    this->addChild(lbEnemy_2, 1, 9990);

    
    
    CCLabelTTF *start_btn = CCLabelTTF::create("RESTART", "Marker Felt", 23);
    this->addChild(start_btn,0,9995);
    start_btn->setPosition(ccp(150, 180));
    
    this->setTouchEnabled(true);
    return true;
    
    
    return true;
}




void cj_2::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool cj_2::ccTouchBegan(CCTouch *pTouches, CCEvent *pEvent)
{
    CCLabelTTF *start_btn = (CCLabelTTF*)getChildByTag(9995);
    CCPoint location = pTouches->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    bool ret = CCRect::CCRectContainsPoint(start_btn->boundingBox(), location);
    if(ret)
    {
        CCDirector *pDirector = CCDirector::sharedDirector();
        layer_main *layer_mains = new layer_main();
        CCScene *pScene = layer_mains->scene();
        pDirector->replaceScene(pScene);
    }

    return true;
}

void cj_2::ccTouchEnded(CCTouch *pTouches, CCEvent *pEvent)
{
    
    
}

void cj_2::ccTouchMoved(CCTouch *pTouches, CCEvent *pEvent)
{
    
}



















void cj_2::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

