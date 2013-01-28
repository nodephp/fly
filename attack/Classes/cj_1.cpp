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
#include "config.h"
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
    
//    CCSprite *pMyself = new CCSprite();
//    pMyself->initWithFile("meteo.png");
//    pMyself->setTextureRect(CCRectMake(4,3,56,57));
////    ccColor3B endColor2 = { 255, 250, 250 };
////    pMyself->setColor(endColor2 );
////    pMyself->setScaleY(4);
////    pMyself->setScaleX(2.0);
//    
//    pMyself->setPosition( ccp(100,280) );
//    pMyself->setScale(global_scale);
//    this->addChild(pMyself,10);

    CCSprite *sprite_meteo = new CCSprite();
    sprite_meteo->initWithFile("meteo.png");
    sprite_meteo->setTextureRect(CCRectMake(4,3,56,57));
    sprite_meteo->setPosition(ccp(100, SCREEN_HIGH+30));
    sprite_meteo->setScale(global_scale);
    this->addChild(sprite_meteo, 11, SPRITE_METEO);
    
    CCFiniteTimeAction *bj_aa = CCMoveTo::create(1,ccp(100,0));
    sprite_meteo->runAction(bj_aa);
    
    
    CCParticleSystem *m_emitter;
    m_emitter = CCParticleFireworks::node();
    m_emitter->retain();
    m_emitter->setTotalParticles(55);
    m_emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage("dust_02.png"));
    m_emitter->setPosition(ccp(100, SCREEN_HIGH));
    m_emitter->setAngle(90);
    m_emitter->setAngleVar(3);
    m_emitter->setLife(1);
    m_emitter->setLifeVar(1);
    m_emitter->setPosVar(ccp(3, 3));
    m_emitter->setStartSize(30);
    m_emitter->setStartSizeVar(50);
    m_emitter->setEndSize(30);
    m_emitter->setEndSizeVar(50);
    ccColor4F endColor2 = { 200, 200, 200, 10 };
    m_emitter->setEndColor(endColor2);
    m_emitter->setStartColor(endColor2);
    m_emitter->setEndColor(endColor2);
    m_emitter->setOpacityModifyRGB(true);
    
    this->addChild(m_emitter, 10, SPRITE_METEO_LIZI);
    CCFiniteTimeAction *bj_bb = CCMoveTo::create(1,ccp(100,50));
    m_emitter->runAction(bj_bb);
    
    CCSprite *pMyselfa = new CCSprite();
    CCSpriteBatchNode *batch = CCSpriteBatchNode::create("speedup.png");
    pMyselfa = CCSprite::createWithTexture(batch->getTexture());
    pMyselfa->setTextureRect(CCRectMake(0, 0, 80, 100));
    pMyselfa->setPosition( ccp(250, 200) );
    pMyselfa->setScale(2);
    this->addChild(pMyselfa, 115,5);
    CCArray* framesList = CCArray::create();
    framesList->addObject(CCSpriteFrame::createWithTexture(batch->getTexture(), CCRectMake(80, 0, 80, 115)));
    framesList->addObject(CCSpriteFrame::createWithTexture(batch->getTexture(), CCRectMake(160, 0, 80, 115)));
    framesList->addObject(CCSpriteFrame::createWithTexture(batch->getTexture(), CCRectMake(240, 0, 80, 115)));
    framesList->addObject(CCSpriteFrame::createWithTexture(batch->getTexture(), CCRectMake(320, 0, 80, 115)));
    framesList->addObject(CCSpriteFrame::createWithTexture(batch->getTexture(), CCRectMake(400, 0, 80, 115)));
    framesList->addObject(CCSpriteFrame::createWithTexture(batch->getTexture(), CCRectMake(480, 0, 80, 115)));
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(framesList, 0.05f);
    animation->setLoops(-1);  //设置为无限循环
    pMyselfa->runAction(CCAnimate::create(animation));
    
    
    ///////////////////////////////////////////////////////////

//    server_http *obj_sh = new server_http();
//    char *http_url = "http://tfish.kingnet.com/test.php";
////    obj_sh->init(http_url);
//    string sd = obj_sh->init(http_url);
//    http_url = NULL;
//    
//    CCLOG("%i",obj_sh->read_json_int(sd, 2,"1","gb","",""));
    
    ///////////////////////////////////////////////////////////


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

