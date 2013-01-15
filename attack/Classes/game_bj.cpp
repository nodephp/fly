#include "game_bj.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* game_bj::scene()
{
    CCScene *scene = CCScene::create();
    game_bj *layer = game_bj::create();
    scene->addChild(layer);
    return scene;
}


bool game_bj::init()
{

    if ( !CCLayer::init() )
    {
        return false;
    }
    CCUserDefault::sharedUserDefault()->setIntegerForKey("a", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("b", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("c", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("d", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("e", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("f", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("g", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("h", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("i", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("j", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("k", 1);
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->setIntegerForKey("l", 1);
    CCUserDefault::sharedUserDefault()->flush();

    
    bool bRet = false;
    do
    {
        CC_BREAK_IF(! CCLayer::init());
        s = CCDirector::sharedDirector()->getWinSize();
        
        m_map1 = CCSprite::create("Space.png");//分别初始化好两个地图
        m_map2 = CCSprite::create("Space.png");
        
        m_map1->setAnchorPoint(ccp(0,0));
        m_map2->setAnchorPoint(ccp(0,0));
        
        m_map1->setPosition(ccp(0,0));
        m_map2->setPosition(ccp(0,480));//这里注意,我们把第二章地图的位置放在场景的最上方...因为地图是要往下走的..值根据屏幕高度
        
        this->addChild(m_map1,0,1);
        this->addChild(m_map2,0,2);
        
        scheduleUpdate();//启动Update更新
        
        CCSprite *pMyself = new CCSprite();
        pMyself->initWithFile("me.png");
        pMyself->setPosition( ccp(100, 10) );
        this->addChild(pMyself, 0,5);
        

//        CCSpriteBatchNode *mgr = CCSpriteBatchNode::batchNodeWithFile("flight.png", 5);
//		CC_BREAK_IF(! mgr);
//		this->addChild(mgr, 0, 4);
//
//		CCSprite *sprite = CCSprite::spriteWithTexture(mgr->getTexture(), CCRectMake(0, 0, 31, 30));
//		CC_BREAK_IF(! sprite);
//		mgr->addChild(sprite, 1, 5);
//		sprite->setScale(1.1f);
//		sprite->setAnchorPoint(ccp(0, 1));
//		sprite->setPosition(ccp(150, 30));
        
        
        bRet = true;
    } while (0);
    
    
    
    this->setTouchEnabled(true);
    this->schedule(schedule_selector(game_bj::listen),0.1);
    this->schedule(schedule_selector(game_bj::shoot),0.1);
    this->schedule(schedule_selector(game_bj::enemy),10.1);
    
    
    return bRet;

}

void game_bj::update(float dt)
{
    //创建两个点对象..分别保存两张地图的位置
    CCPoint map_1p = m_map1->getPosition();
    CCPoint map_2p = m_map2->getPosition();
    
    //每次调用这个函数的时候就设置两张地图的位置..这里的-3值越大也就越快.
    m_map1->setPosition(ccp(map_1p.x, map_1p.y - 3));
    m_map2->setPosition(ccp(map_2p.x, map_2p.y - 3));
    
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



//自动子弹射击
void game_bj::auto_bullet(int x, int y, char id)
{
    CCSprite *auto_bullet = new CCSprite();
    auto_bullet->initWithFile("butlet.png");
    auto_bullet->setPosition( ccp(x, y) );
    this->addChild(auto_bullet, 0, id);
//    CCSprite *sprinte_temp = (CCSprite*)getChildByTag(id);
    CCFiniteTimeAction *action = CCMoveTo::create(1,ccp(x,490));
    auto_bullet->runAction(action);
}


//碰撞检测
void game_bj::auto_pz(char id)
{
    CCSprite *sprinte_11 = (CCSprite*)getChildByTag(11);
    CCSprite *sprinte_12 = (CCSprite*)getChildByTag(12);
    CCSprite *sprinte_13 = (CCSprite*)getChildByTag(13);
    CCSprite *sprinte_14 = (CCSprite*)getChildByTag(14);
    
    for (int ii = 101; ii<=112; ii++)
    {
    CCSprite *sprinte_xxx = (CCSprite*)getChildByTag(ii);
    if(sprinte_xxx)
    {
//        CCLOG("44");
        bool ret_1 = false;
        bool ret_2 = false;
        bool ret_3 = false;
        bool ret_4 = false;
        
        if(sprinte_11)
        {
            ret_1 = CCRect::CCRectIntersectsRect(sprinte_xxx->boundingBox(), sprinte_11->boundingBox());
        }
        
        if(sprinte_12)
        {
            ret_2 = CCRect::CCRectIntersectsRect(sprinte_xxx->boundingBox(), sprinte_12->boundingBox());
        }
        
        if(sprinte_13)
        {
            ret_3 = CCRect::CCRectIntersectsRect(sprinte_xxx->boundingBox(), sprinte_13->boundingBox());
        }
        
        if(sprinte_14)
        {
            ret_4 = CCRect::CCRectIntersectsRect(sprinte_xxx->boundingBox(), sprinte_14->boundingBox());
        }
        
        if(ret_1)
        {
            CCLOG("1");
            this->removeChild(sprinte_11, true);
        }
        
        if(ret_2)
        {
            CCLOG("2");
            this->removeChild(sprinte_12, true);
        }
        
        if(ret_3)
        {
            CCLOG("3");
            this->removeChild(sprinte_13, true);
        }
        
        if(ret_4)
        {
            CCLOG("4");
            this->removeChild(sprinte_14, true);
        }

        
        CCPoint a = sprinte_xxx->getPosition();
        if( a.y>=477)
        {
            this->removeChild(sprinte_xxx, true);
            if(ii==101)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("a", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==102)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("b", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==103)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("c", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==104)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("d", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==105)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("e", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==106)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("f", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==107)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("g", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==108)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("h", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==109)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("i", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==110)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("j", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==111)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("k", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==112)
            {
                CCUserDefault::sharedUserDefault()->setIntegerForKey("l", 1);
                CCUserDefault::sharedUserDefault()->flush();
            }
        }
    }
    }
    
    
    for (int i=11; i<=14; i++)
    {
        CCSprite *sprinte_yyy = (CCSprite*)getChildByTag(i);
        if(sprinte_yyy)
        {
            CCPoint a = sprinte_yyy->getPosition();
            if( a.y <= 4)
            {
                this->removeChild(sprinte_yyy, true);
            }
        }
    }
    
        
}

//自动生成敌人
void game_bj::auto_enemy(char id)
{
    CCSprite *auto_bullet_1 = new CCSprite();
    auto_bullet_1->initWithFile("enemy.png");
    auto_bullet_1->setPosition( ccp(10, 480) );
    this->addChild(auto_bullet_1, 0, 11);
    CCFiniteTimeAction *action_1 = CCMoveTo::create(7,ccp(10,1));
    auto_bullet_1->runAction(action_1);
    
    CCSprite *auto_bullet_2 = new CCSprite();
    auto_bullet_2->initWithFile("enemy.png");
    auto_bullet_2->setPosition( ccp(110, 480) );
    this->addChild(auto_bullet_2, 0, 12);
    CCFiniteTimeAction *action_2 = CCMoveTo::create(7,ccp(110,1));
    auto_bullet_2->runAction(action_2);
    
    
    CCSprite *auto_bullet_3 = new CCSprite();
    auto_bullet_3->initWithFile("enemy.png");
    auto_bullet_3->setPosition( ccp(210, 480) );
    this->addChild(auto_bullet_3, 0, 13);
    CCFiniteTimeAction *action_3 = CCMoveTo::create(7,ccp(210,1));
    auto_bullet_3->runAction(action_3);
    
    
    CCSprite *auto_bullet_4 = new CCSprite();
    auto_bullet_4->initWithFile("enemy.png");
    auto_bullet_4->setPosition( ccp(310, 480) );
    this->addChild(auto_bullet_4, 0, 14);
    CCFiniteTimeAction *action_4 = CCMoveTo::create(7,ccp(310,1));
    auto_bullet_4->runAction(action_4);

}


//不断监听
void game_bj::listen()
{
    auto_pz(999);
}

void game_bj::shoot()
{
    CCSprite *sprinte = (CCSprite*)getChildByTag(5);
    if(sprinte)
    {
        CCPoint aa = sprinte->getPosition();

        int id=0;
        for (int ii=1; ii<=12; ii++)
        {
            if(ii==1)
            {
                float a = CCUserDefault::sharedUserDefault()->getIntegerForKey("a");
                if(a==1)
                {
                    id = 101;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("a", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==2)
            {
                float b = CCUserDefault::sharedUserDefault()->getIntegerForKey("b");
                if(b==1)
                {
                    id = 102;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("b", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==3)
            {
                float c = CCUserDefault::sharedUserDefault()->getIntegerForKey("c");
                if(c==1)
                {
                    id = 103;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("c", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==4)
            {
                float d = CCUserDefault::sharedUserDefault()->getIntegerForKey("d");
                if(d==1)
                {
                    id = 104;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("d", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==5)
            {
                float e = CCUserDefault::sharedUserDefault()->getIntegerForKey("e");
                if(e==1)
                {
                    id = 105;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("e", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==6)
            {
                float f = CCUserDefault::sharedUserDefault()->getIntegerForKey("f");
                if(f==1)
                {
                    id = 106;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("f", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==7)
            {
                float b = CCUserDefault::sharedUserDefault()->getIntegerForKey("g");
                if(b==1)
                {
                    id = 107;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("g", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==8)
            {
                float h = CCUserDefault::sharedUserDefault()->getIntegerForKey("h");
                if(h==1)
                {
                    id = 108;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("h", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==9)
            {
                float i = CCUserDefault::sharedUserDefault()->getIntegerForKey("i");
                if(i==1)
                {
                    id = 109;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("i", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==10)
            {
                float j = CCUserDefault::sharedUserDefault()->getIntegerForKey("j");
                if(j==1)
                {
                    id = 110;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("j", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==11)
            {
                float k = CCUserDefault::sharedUserDefault()->getIntegerForKey("k");
                if(k==1)
                {
                    id = 111;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("k", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==12)
            {
                float l = CCUserDefault::sharedUserDefault()->getIntegerForKey("l");
                if(l==1)
                {
                    id = 112;
                    CCUserDefault::sharedUserDefault()->setIntegerForKey("l", 2);
                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }
        }
        
        if(id>=100)
        {
            auto_bullet(aa.x,aa.y,id);
        }
        
    }
}

void game_bj::enemy()
{
    auto_enemy('yyy');
}



void game_bj::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}




bool game_bj::ccTouchBegan(CCTouch *pTouches, CCEvent *pEvent)
{
    CCPoint location = pTouches->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    CCSprite *sprinte = (CCSprite*)getChildByTag(5);
    float endx = location.x;
    float endy = location.y;
    sprinte->setPosition(ccp(endx,10));
    return true;
}

void game_bj::ccTouchEnded(CCTouch *pTouches, CCEvent *pEvent)
{
    
    
}

void game_bj::ccTouchMoved(CCTouch *pTouches, CCEvent *pEvent)
{
    CCPoint location = pTouches->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    CCSprite *sprinte = (CCSprite*)getChildByTag(5);
    bool ret = CCRect::CCRectContainsPoint(sprinte->boundingBox(), location);
    if(ret)
    {
        float endx = location.x;
        float endy = location.y;
        sprinte->setPosition(ccp(endx,10));
    }
}

























void game_bj::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
