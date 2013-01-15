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
    
//    //逐渐显示一个图片的动作，第二个参数是百分比
//    CCProgressTo *to1 = CCProgressTo::actionWithDuration(2, 100);
//    CCProgressTo *to2 = CCProgressTo::actionWithDuration(2, 100);
//    
//    //建立CCProgressTimer对象，利用文件PathSister
//    CCProgressTimer *left = CCProgressTimer::progressWithFile(s_pPathSister1);
//    
//    //顺时针旋转
//    left->setType( kCCProgressTimerTypeRadialCW );
//    //逆时针旋转
//    //left->setType( kCCProgressTimerTypeRadialCCW );
//    //水平的从左到右：kCCProgressTimerTypeHorizontalBarLR
//    //水平的从右到左：kCCProgressTimerTypeHorizontalBarRL
//    //垂直的从下往上：kCCProgressTimerTypeVerticalBarBT
//    //垂直的从上往下：kCCProgressTimerTypeVerticalBarTB
//    addChild(left);
//    left->setPosition(CCPointMake(100, s.height/2));
//    left->runAction( CCRepeatForever::actionWithAction(to1));
    
    bool bRet = false;
    do
    {
        CC_BREAK_IF(! CCLayer::init());
        s = CCDirector::sharedDirector()->getWinSize();
        
        m_map1 = CCSprite::create("Space1.png");//分别初始化好两个地图
        m_map2 = CCSprite::create("Space1.png");
        
        m_map1->setAnchorPoint(ccp(0,0));
        m_map2->setAnchorPoint(ccp(0,0));
        
        m_map1->setScaleX(0.5);
        m_map1->setScaleY(0.472);
        m_map2->setScaleX(0.5);
        m_map2->setScaleY(0.472);
        
        m_map1->setPosition(ccp(0,0));
        m_map2->setPosition(ccp(0,480));//这里注意,我们把第二章地图的位置放在场景的最上方...因为地图是要往下走的..值根据屏幕高度
        
        this->addChild(m_map1,0,1);
        this->addChild(m_map2,0,2);
        
        scheduleUpdate();//启动Update更新
        bRet = true;
    } while (0);
    
    
    CCSprite *pMyself = new CCSprite();
    pMyself->initWithFile("sunny_01.png");
    pMyself->setTextureRect(CCRectMake(0, 0, 45, 110));
    pMyself->setPosition( ccp(100, 50) );
    this->addChild(pMyself, 0,5);
    
    CCSprite *pMyself_wind_a = new CCSprite();
    pMyself_wind_a->initWithFile("sunny_01.png");
    pMyself_wind_a->setTextureRect(CCRectMake(45, 0, 100, 60));
    pMyself_wind_a->setPosition( ccp(65, 40) );
    this->addChild(pMyself_wind_a, 0,6);
    
    CCSprite *pMyself_wind_b = new CCSprite();
    pMyself_wind_b->initWithFile("sunny_01.png");
    pMyself_wind_b->setTextureRect(CCRectMake(45, 0, 100, 60));
    pMyself_wind_b->setFlipX(true);
    pMyself_wind_b->setPosition( ccp(130, 40) );
    this->addChild(pMyself_wind_b, 0,7);
    
    

//    CCArray* framesList = CCArray::create();
//    framesList->addObject(CCSpriteFrame::create("sunny_01.png", CCRectMake(45, 0, 100, 60)));
//    framesList->addObject(CCSpriteFrame::create("sunny_01.png", CCRectMake(40, 0, 20, 40)));
//    framesList->addObject(CCSpriteFrame::create("sunny_01.png", CCRectMake(60, 0, 20, 60)));
//
//    // should last 2.8 seconds. And there are 14 frames.
//    
//    CCAnimation *animation = CCAnimation::createWithSpriteFrames(framesList, 0.2f);
//    animation->setLoops(-1);  //设置为无限循环
//    pMyself_wind_a->runAction(CCAnimate::create(animation));
//    pMyself_wind_b->runAction(CCAnimate::create(animation));

//    CCFiniteTimeAction *putdown_a = CCRotateTo::actionWithDuration(0.3, -30);
//    CCRepeat *fz3d_a = CCRepeat::actionWithAction(putdown_a, -1);
//    
//    CCFiniteTimeAction *putdown_b = CCRotateTo::actionWithDuration(0.3, 30);
//    CCRepeat *fz3d_b = CCRepeat::actionWithAction(putdown_b, -1);
//    
//    pMyself_wind_a->runAction( CCSpawn::actions(putdown_a, fz3d_a) );
//    pMyself_wind_b->runAction( CCSpawn::actions(putdown_b, fz3d_b) );


    
//    CCSkewBy CCRotateTo
    CCActionInterval*  act1_a = CCSkewTo::actionWithDuration(0.3, 22,0);
    CCActionInterval*  act2_a = CCSkewTo::actionWithDuration(0.3, -22,0);
    CCActionInterval*  seq_a = (CCActionInterval*)(CCSequence::actions(act1_a, act2_a, NULL));
    CCAction*  rep1 = CCRepeatForever::actionWithAction(seq_a);
    
    CCActionInterval*  act1_b = CCSkewTo::actionWithDuration(0.3, -22,0);
    CCActionInterval*  act2_b = CCSkewTo::actionWithDuration(0.3, 22,0);
    CCActionInterval*  seq_b = (CCActionInterval*)(CCSequence::actions(act1_b, act2_b, NULL));
    CCAction*  rep2 = CCRepeatForever::actionWithAction(seq_b);
    
    pMyself_wind_a->runAction(rep1);
    pMyself_wind_b->runAction(rep2);
    
    
    auto_enemy('yyy');
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
    
    CCSprite *sprinte_11_a = (CCSprite*)getChildByTag(21);
    CCSprite *sprinte_12_a = (CCSprite*)getChildByTag(22);
    CCSprite *sprinte_13_a = (CCSprite*)getChildByTag(23);
    CCSprite *sprinte_14_a = (CCSprite*)getChildByTag(24);
    
    CCSprite *sprinte_11_b = (CCSprite*)getChildByTag(31);
    CCSprite *sprinte_12_b = (CCSprite*)getChildByTag(32);
    CCSprite *sprinte_13_b = (CCSprite*)getChildByTag(33);
    CCSprite *sprinte_14_b = (CCSprite*)getChildByTag(34);
    
    CCSprite *sprinte_11_y_a = (CCSprite*)getChildByTag(41);
    CCSprite *sprinte_12_y_a = (CCSprite*)getChildByTag(42);
    CCSprite *sprinte_13_y_a = (CCSprite*)getChildByTag(43);
    CCSprite *sprinte_14_y_a = (CCSprite*)getChildByTag(44);
    
    CCSprite *sprinte_11_y_b = (CCSprite*)getChildByTag(51);
    CCSprite *sprinte_12_y_b = (CCSprite*)getChildByTag(52);
    CCSprite *sprinte_13_y_b = (CCSprite*)getChildByTag(53);
    CCSprite *sprinte_14_y_b = (CCSprite*)getChildByTag(54);
    
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
            this->removeChild(sprinte_11_a, true);
            this->removeChild(sprinte_11_b, true);
            this->removeChild(sprinte_11_y_a, true);
            this->removeChild(sprinte_11_y_b, true);
        }
        
        if(ret_2)
        {
            CCLOG("2");
            this->removeChild(sprinte_12, true);
            this->removeChild(sprinte_12_a, true);
            this->removeChild(sprinte_12_b, true);
            this->removeChild(sprinte_12_y_a, true);
            this->removeChild(sprinte_12_y_b, true);
        }
        
        if(ret_3)
        {
            CCLOG("3");
            this->removeChild(sprinte_13, true);
            this->removeChild(sprinte_13_a, true);
            this->removeChild(sprinte_13_b, true);
            this->removeChild(sprinte_13_y_a, true);
            this->removeChild(sprinte_13_y_b, true);
        }
        
        if(ret_4)
        {
            CCLOG("4");
            this->removeChild(sprinte_14, true);
            this->removeChild(sprinte_14_a, true);
            this->removeChild(sprinte_14_b, true);
            this->removeChild(sprinte_14_y_a, true);
            this->removeChild(sprinte_14_y_b, true);
        }

        
        CCPoint a = sprinte_xxx->getPosition();
        if( a.y>=477)
        {
            this->removeChild(sprinte_xxx, true);
            if(ii==101)
            {
                game_bj::a=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("a", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==102)
            {
                game_bj::b=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("b", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==103)
            {
                game_bj::c=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("c", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==104)
            {
                game_bj::d=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("d", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==105)
            {
                game_bj::e=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("e", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==106)
            {
                game_bj::f=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("f", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==107)
            {
                game_bj::g=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("g", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==108)
            {
                game_bj::h=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("h", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==109)
            {
                game_bj::i=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("i", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==110)
            {
                game_bj::j=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("j", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==111)
            {
                game_bj::k=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("k", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }else if(ii==112)
            {
                game_bj::l=1;
//                CCUserDefault::sharedUserDefault()->setIntegerForKey("l", 1);
//                CCUserDefault::sharedUserDefault()->flush();
            }
        }
    }
    }
    
    
    for (int i=11; i<=14; i++)
    {
        CCSprite *sprinte_yyy = (CCSprite*)getChildByTag(i);
        CCSprite *sprinte_yyy_a = (CCSprite*)getChildByTag(i+10);
        CCSprite *sprinte_yyy_b = (CCSprite*)getChildByTag(i+20);
        CCSprite *sprinte_yyy_y_a = (CCSprite*)getChildByTag(i+30);
        CCSprite *sprinte_yyy_y_b = (CCSprite*)getChildByTag(i+40);
        if(sprinte_yyy)
        {
            CCPoint a = sprinte_yyy->getPosition();
            if( a.y <= 4)
            {
                this->removeChild(sprinte_yyy, true);
            }
        }
        if(sprinte_yyy_a)
        {
            CCPoint a = sprinte_yyy_a->getPosition();
            if( a.y <= 4)
            {
                this->removeChild(sprinte_yyy_a, true);
            }
        }
        if(sprinte_yyy_b)
        {
            CCPoint a = sprinte_yyy_b->getPosition();
            if( a.y <= 4)
            {
                this->removeChild(sprinte_yyy_b, true);
            }
        }
        if(sprinte_yyy_y_a)
        {
            CCPoint a = sprinte_yyy_y_a->getPosition();
            if( a.y <= 4)
            {
                this->removeChild(sprinte_yyy_y_a, true);
            }
        }
        if(sprinte_yyy_y_b)
        {
            CCPoint a = sprinte_yyy_y_b->getPosition();
            if( a.y <= 4)
            {
                this->removeChild(sprinte_yyy_y_b, true);
            }
        }
    }
    
        
}

//自动生成敌人
void game_bj::auto_enemy(char id)
{
    for (int i=11; i<=14; i++)
    {
        CCSprite *auto_bullet_1 = new CCSprite();
        auto_bullet_1->initWithFile("dragon_01.png");
        auto_bullet_1->setTextureRect(CCRectMake(0, 0, 85, 190));
        auto_bullet_1->setPosition( ccp((i-11)*100+10, 480) );
        this->addChild(auto_bullet_1, 0, i);
        
        
        
        
        CCSprite *pMyself_wind_a = new CCSprite();
        pMyself_wind_a->initWithFile("dragon_01.png");
        pMyself_wind_a->setTextureRect(CCRectMake(85, 50, 60, 70));
        pMyself_wind_a->setPosition( ccp((i-11)*100-30, 520) );
        this->addChild(pMyself_wind_a, 0, i+10);
        
        
        CCSprite *pMyself_wind_b = new CCSprite();
        pMyself_wind_b->initWithFile("dragon_01.png");
        pMyself_wind_b->setTextureRect(CCRectMake(85, 50, 60, 70));
        pMyself_wind_b->setFlipX(true);
        pMyself_wind_b->setPosition( ccp((i-11)*100+50, 520) );
        this->addChild(pMyself_wind_b, 0, i+20);
        
        

        
        CCSprite *pMyself_wind_y_a = new CCSprite();
        pMyself_wind_y_a->initWithFile("dragon_01.png");
        pMyself_wind_y_a->setTextureRect(CCRectMake(110, 10, 10, 20));
        pMyself_wind_y_a->setPosition( ccp((i-11)*100-1, 487) );
        this->addChild(pMyself_wind_y_a, 0, i+30);
        
        
        CCSprite *pMyself_wind_y_b = new CCSprite();
        pMyself_wind_y_b->initWithFile("dragon_01.png");
        pMyself_wind_y_b->setTextureRect(CCRectMake(110, 10, 10, 20));
        pMyself_wind_y_b->setFlipX(true);
        pMyself_wind_y_b->setPosition( ccp((i-11)*100+20, 487) );
        this->addChild(pMyself_wind_y_b, 0, i+40);
        
        
        
        
        CCFiniteTimeAction *action_1 = CCMoveTo::create(7,ccp((i-11)*100+10,1));
        auto_bullet_1->runAction(action_1);
        
        CCFiniteTimeAction *action_a = CCMoveTo::create(7,ccp((i-11)*100-10,1));
        pMyself_wind_a->runAction(action_a);
        
        CCFiniteTimeAction *action_b = CCMoveTo::create(7,ccp((i-11)*100+30,1));
        pMyself_wind_b->runAction(action_b);
        
        CCFiniteTimeAction *action_y_a = CCMoveTo::create(7,ccp((i-11)*100-1,1));
        pMyself_wind_y_a->runAction(action_y_a);
        
        CCFiniteTimeAction *action_y_b = CCMoveTo::create(7,ccp((i-11)*100+20,1));
        pMyself_wind_y_b->runAction(action_y_b);

        
        
        
        
        
        //    CCSkewBy CCRotateTo
        CCActionInterval*  act1_a = CCRotateTo::actionWithDuration(0.3, 33);
        CCActionInterval*  act2_a = CCRotateTo::actionWithDuration(0.3, -33);
        CCActionInterval*  seq_a = (CCActionInterval*)(CCSequence::actions(act1_a, act2_a, NULL));
        CCAction*  rep1 = CCRepeatForever::actionWithAction(seq_a);
        
        CCActionInterval*  act1_b = CCRotateTo::actionWithDuration(0.3, -33);
        CCActionInterval*  act2_b = CCRotateTo::actionWithDuration(0.3, 33);
        CCActionInterval*  seq_b = (CCActionInterval*)(CCSequence::actions(act1_b, act2_b, NULL));
        CCAction*  rep2 = CCRepeatForever::actionWithAction(seq_b);
        
        pMyself_wind_a->runAction(rep1);
        pMyself_wind_b->runAction(rep2);
        
        
        
    }
    
    
//    CCSprite *auto_bullet_1 = new CCSprite();
//    auto_bullet_1->initWithFile("dragon_01.png");
//    auto_bullet_1->setTextureRect(CCRectMake(0, 0, 85, 190));
//    auto_bullet_1->setPosition( ccp(10, 480) );
//    this->addChild(auto_bullet_1, 0, 11);
//    CCFiniteTimeAction *action_1 = CCMoveTo::create(7,ccp(10,1));
//    auto_bullet_1->runAction(action_1);
//    
//    CCSprite *auto_bullet_2 = new CCSprite();
//    auto_bullet_2->initWithFile("dragon_01.png");
//    auto_bullet_2->setTextureRect(CCRectMake(0, 0, 85, 190));
//    auto_bullet_2->setPosition( ccp(110, 480) );
//    this->addChild(auto_bullet_2, 0, 12);
//    CCFiniteTimeAction *action_2 = CCMoveTo::create(7,ccp(110,1));
//    auto_bullet_2->runAction(action_2);
//    
//    
//    CCSprite *auto_bullet_3 = new CCSprite();
//    auto_bullet_3->initWithFile("dragon_01.png");
//    auto_bullet_3->setTextureRect(CCRectMake(0, 0, 85, 190));
//    auto_bullet_3->setPosition( ccp(210, 480) );
//    this->addChild(auto_bullet_3, 0, 13);
//    CCFiniteTimeAction *action_3 = CCMoveTo::create(7,ccp(210,1));
//    auto_bullet_3->runAction(action_3);
//    
//    
//    CCSprite *auto_bullet_4 = new CCSprite();
//    auto_bullet_4->initWithFile("dragon_01.png");
//    auto_bullet_4->setTextureRect(CCRectMake(0, 0, 85, 190));
//    auto_bullet_4->setPosition( ccp(310, 480) );
//    this->addChild(auto_bullet_4, 0, 14);
//    CCFiniteTimeAction *action_4 = CCMoveTo::create(7,ccp(310,1));
//    auto_bullet_4->runAction(action_4);

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
//                float a = CCUserDefault::sharedUserDefault()->getIntegerForKey("a");
                float a = game_bj::a;
                if(a==1)
                {
                    id = 101;
                    game_bj::a=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("a", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==2)
            {
//                float b = CCUserDefault::sharedUserDefault()->getIntegerForKey("b");
                float b = game_bj::b;
                if(b==1)
                {
                    id = 102;
                    game_bj::b=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("b", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==3)
            {
//                float c = CCUserDefault::sharedUserDefault()->getIntegerForKey("c");
                float c = game_bj::c;
                if(c==1)
                {
                    id = 103;
                    game_bj::c=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("c", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==4)
            {
//                float d = CCUserDefault::sharedUserDefault()->getIntegerForKey("d");
                float d = game_bj::d;
                if(d==1)
                {
                    id = 104;
                    game_bj::d=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("d", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==5)
            {
//                float e = CCUserDefault::sharedUserDefault()->getIntegerForKey("e");
                float e = game_bj::e;
                if(e==1)
                {
                    id = 105;
                    game_bj::e=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("e", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==6)
            {
//                float f = CCUserDefault::sharedUserDefault()->getIntegerForKey("f");
                float f = game_bj::f;
                if(f==1)
                {
                    id = 106;
                    game_bj::f=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("f", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==7)
            {
//                float b = CCUserDefault::sharedUserDefault()->getIntegerForKey("g");
                float g = game_bj::g;
                if(g==1)
                {
                    id = 107;
                    game_bj::g=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("g", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==8)
            {
//                float h = CCUserDefault::sharedUserDefault()->getIntegerForKey("h");
                float h = game_bj::h;
                if(h==1)
                {
                    id = 108;
                    game_bj::h=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("h", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==9)
            {
//                float i = CCUserDefault::sharedUserDefault()->getIntegerForKey("i");
                float i = game_bj::i;
                if(i==1)
                {
                    id = 109;
                    game_bj::i=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("i", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==10)
            {
//                float j = CCUserDefault::sharedUserDefault()->getIntegerForKey("j");
                float j = game_bj::j;
                if(j==1)
                {
                    id = 110;
                    game_bj::j=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("j", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==11)
            {
//                float k = CCUserDefault::sharedUserDefault()->getIntegerForKey("k");
                float k = game_bj::k;
                if(k==1)
                {
                    id = 111;
                    game_bj::k=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("k", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
                    break;
                }
            }else if(ii==12)
            {
//                float l = CCUserDefault::sharedUserDefault()->getIntegerForKey("l");
                float l = game_bj::l;
                if(l==1)
                {
                    id = 112;
                    game_bj::l=2;
//                    CCUserDefault::sharedUserDefault()->setIntegerForKey("l", 2);
//                    CCUserDefault::sharedUserDefault()->flush();
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
    CCSprite *sprinte_5 = (CCSprite*)getChildByTag(5);
    CCSprite *sprinte_6 = (CCSprite*)getChildByTag(6);
    CCSprite *sprinte_7 = (CCSprite*)getChildByTag(7);
    float endx = location.x;
    sprinte_5->setPosition(ccp(endx,50));
    sprinte_6->setPosition(ccp(endx-35,40));
    sprinte_7->setPosition(ccp(endx+30,40));
    return true;
}

void game_bj::ccTouchEnded(CCTouch *pTouches, CCEvent *pEvent)
{
    
    
}

void game_bj::ccTouchMoved(CCTouch *pTouches, CCEvent *pEvent)
{
    CCPoint location = pTouches->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    CCSprite *sprinte_5 = (CCSprite*)getChildByTag(5);
    CCSprite *sprinte_6 = (CCSprite*)getChildByTag(6);
    CCSprite *sprinte_7 = (CCSprite*)getChildByTag(7);
    bool ret_5 = CCRect::CCRectContainsPoint(sprinte_5->boundingBox(), location);
    bool ret_6 = CCRect::CCRectContainsPoint(sprinte_6->boundingBox(), location);
    bool ret_7 = CCRect::CCRectContainsPoint(sprinte_7->boundingBox(), location);
    if(ret_5 || ret_6 || ret_7)
    {
        float endx = location.x;
        sprinte_5->setPosition(ccp(endx,50));
        sprinte_6->setPosition(ccp(endx-35,40));
        sprinte_7->setPosition(ccp(endx+30,40));
    }
}

























void game_bj::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
