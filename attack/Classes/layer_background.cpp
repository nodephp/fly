//
//  layer_background.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "layer_background.h"
#include "SimpleAudioEngine.h"
#include "config.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCScene* layer_background::scene()
{
    CCScene *scene = CCScene::create();
    layer_background *layer_background = layer_background::create();
    scene->addChild(layer_background);
    return scene;
}

bool layer_background::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    
    bool bRet = false;
    do
    {
        CC_BREAK_IF(! CCLayer::init());
        s = CCDirector::sharedDirector()->getWinSize();
        
        
        CCSpriteBatchNode *batch = CCSpriteBatchNode::create("Space2.png"); 
        
        m_map1 = CCSprite::createWithTexture(batch->getTexture());
        m_map2 = CCSprite::createWithTexture(batch->getTexture());
        
        m_map1->setAnchorPoint(ccp(0,0));
        m_map2->setAnchorPoint(ccp(0,0));
        
//        m_map1->setScaleX(0.95);
//        m_map1->setScaleY(1);
//        m_map2->setScaleX(0.95);
//        m_map2->setScaleY(1);
        
        m_map1->setPosition(ccp(0,0));
        m_map2->setPosition(ccp(0,SCREEN_HIGH));//这里注意,我们把第二章地图的位置放在场景的最上方...因为地图是要往下走的..值根据屏幕高度
        
        this->addChild(m_map1,0,1);
        this->addChild(m_map2,0,2);
        
        scheduleUpdate();//启动Update更新
        bRet = true;
    } while (0);
    
    
//    CCSprite *s = CCSprite::create("Space2.png");
//    this->addChild(s,0,1);
//    return true;
    
    
    
    return bRet;
}





void layer_background::update(float dt)
{
    //创建两个点对象..分别保存两张地图的位置
    CCPoint map_1p = m_map1->getPosition();
    CCPoint map_2p = m_map2->getPosition();
    
    //每次调用这个函数的时候就设置两张地图的位置..这里的-3值越大也就越快.
    m_map1->setPosition(ccp(map_1p.x, map_1p.y - back_ground_speed));
    m_map2->setPosition(ccp(map_2p.x, map_2p.y - back_ground_speed));
    
    //分别判断地图.如果完全出场景了..马上调整位置接上
    if (map_2p.y < 0)
    {
        float temp = map_2p.y + 480;//因为我的分辨率是320x480的..所以加了一个屏幕的高度.也就是480
        m_map1->setPosition(ccp(map_1p.x, temp));
    }
    if (map_1p.y < 0)
    {
        float temp = map_1p.y + 480;
        m_map2->setPosition(ccp(map_2p.x, temp));
    }
}

















void layer_background::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

