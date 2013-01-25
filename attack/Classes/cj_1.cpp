//
//  cj_1.cpp
//  attack
//
//  Created by gerry on 13-1-21.
//
//

#include "cj_1.h"
#include "SimpleAudioEngine.h"
#include "layer_main.h"
#include "config.h"
#include "server_http.h"
using namespace std;

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* cj_1::scene()
{
    CCScene *scene = CCScene::create();
    
    layer_background *layer_background = layer_background::create();
    scene->addChild(layer_background);
    
    cj_1 *cj_1 = cj_1::create();
    scene->addChild(cj_1);
    return scene;
}

bool cj_1::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    
    
    ///////////////////////////////////////////////////////////
    CCSprite *pMyself = new CCSprite();
    pMyself->initWithFile(SPRITE_MYSELF_RESOURCE);
    pMyself->setTextureRect(CCRectMake(28,0,35,24));
    pMyself->setPosition( ccp(100,50) );
    pMyself->setScale(global_scale);
    this->addChild(pMyself,10);

    
    ///////////////////////////////////////////////////////////

    server_http *obj_sh = new server_http();
    char *http_url = "http://tfish.kingnet.com/test.php";
//    obj_sh->init(http_url);
    string sd = obj_sh->init(http_url);
    http_url = NULL;
    
    CCLOG("%i",obj_sh->read_json_int(sd, 2,"1","gb","",""));

    CCSprite *BJ = new CCSprite();
    BJ->initWithFile("character_01.png");
    BJ->setPosition(ccp(150,300));
    BJ->setScale(global_scale);
    this->addChild(BJ, 0);
    
    CCFiniteTimeAction *bj_a = CCMoveTo::create(1,ccp(150,320));
    CCFiniteTimeAction *bj_b = CCMoveTo::create(1,ccp(150,280));
    
    CCActionInterval*  seq_b = (CCActionInterval*)(CCSequence::actions(bj_a, bj_b, NULL));
    CCAction*  rep2 = CCRepeatForever::actionWithAction(seq_b);
    
    BJ->runAction(rep2);

    
    CCLabelTTF *start_btn = CCLabelTTF::create("START", "Marker Felt", 23);
    this->addChild(start_btn,1,9996);
    start_btn->setPosition(ccp(150, 50));
    
    this->setTouchEnabled(true);
    return true;
    
    
    return true;
}




void cj_1::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool cj_1::ccTouchBegan(CCTouch *pTouches, CCEvent *pEvent)
{
    CCLabelTTF *start_btn = (CCLabelTTF*)getChildByTag(9996);
    CCPoint location = pTouches->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    CCLOG("x_%f",location.x);
    CCLOG("y_%f",location.y);
    
    bool ret = CCRect::CCRectContainsPoint(start_btn->boundingBox(), location);
    if(ret)
    {
        CCTextureCache::sharedTextureCache()->removeAllTextures();
        CCDirector *pDirector = CCDirector::sharedDirector();
        pDirector->setAnimationInterval(1.0 / 60);
        layer_main *layer_mains = new layer_main();
        CCScene *pScene = layer_mains->scene();
        pDirector->replaceScene(pScene);
    }
    
    return true;
}

void cj_1::ccTouchEnded(CCTouch *pTouches, CCEvent *pEvent)
{
    
    
}

void cj_1::ccTouchMoved(CCTouch *pTouches, CCEvent *pEvent)
{
    
}



















void cj_1::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

