//
//  layer_main.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "layer_main.h"
#include "SimpleAudioEngine.h"
#include "obj_myself.h"
#include "obj_bullet.h"
#include "obj_enemy.h"
#include "config.h"
#include "cj_2.h"
#include "meteo.h"


cocos2d::CCLayer *layer_m = NULL;

using namespace cocos2d;
using namespace CocosDenshion;




CCScene* layer_main::scene()
{
    CCScene *scene = CCScene::create();
    
    //载入背景层
    layer_background *layer_background = layer_background::create();
    scene->addChild(layer_background);
    
    
    //载入本层
    layer_main *layer_main = layer_main::create();
    scene->addChild(layer_main);
    
    layer_m = layer_main;
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(MUSIC_BACKGROUND_FIGHT_RESOURCE);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_BACKGROUND_FIGHT_RESOURCE,true);

    
    return scene;
}



bool layer_main::init()
{
    if( !CCLayer::init() )
    {
        return false;
    }
    this->setTouchEnabled(true);
    
    MY_SCORE = 0;
    sprintf(MY_SCORE_UPDATE, "%d", MY_SCORE);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(MUSIC_GET_ITEM_GB_RESOURCE);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(MUSIC_ENEMY_HITTED_RESOURCE);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(MUSIC_ALERT_RESOURCE);
    
    
    

    
    
    //初始化自己
    this->schedule(schedule_selector(layer_main::init_myself),0.5);
    //碰撞控制
    this->schedule(schedule_selector(layer_main::auto_collide),0.1);
    //出怪
    this->schedule(schedule_selector(layer_main::game_start),2);
    
    this->schedule(schedule_selector(layer_main::meteo_1),5);
    
    CCLabelTTF *label = CCLabelTTF::create("GOLD:", "Marker Felt", 21);
    this->addChild(label,100,9998);
    label->setPosition(ccp(240, 450));
    label->setColor( ccYELLOW );
    
    
    CCLabelBMFont *lbEnemy = CCLabelBMFont::labelWithString("0", "font09.fnt");
    lbEnemy->setAnchorPoint(ccp(0, 1));
    lbEnemy->setScale(0.8f);
    lbEnemy->setPosition(ccp(270, 450));
    this->addChild(lbEnemy, 100, 9999);
    
    CCLabelTTF *label_2 = CCLabelTTF::create("SCORE:", "Marker Felt", 21);
    this->addChild(label_2,100,9998);
    label_2->setPosition(ccp(30, 450));
    label_2->setColor( ccYELLOW );
    
    
    CCLabelBMFont *lbEnemy_2 = CCLabelBMFont::labelWithString("0", "font09.fnt");
    lbEnemy_2->setAnchorPoint(ccp(0, 1));
    lbEnemy_2->setScale(0.8f);
    lbEnemy_2->setPosition(ccp(90, 450));
    this->addChild(lbEnemy_2, 100, 9990);
    
    
    
    
//    this->setIsAutoRemoveOnFinish(true)
    return true;
}









bool layer_main::init_myself()
{
    CCSprite *sprite_myself_body = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    if(!sprite_myself_body)
    {
        obj_myself::obj_myself();
        this->unschedule(schedule_selector( layer_main::init_myself ));
        
        this->schedule(schedule_selector(layer_main::shoot),BULLET_SPEED);
        
//        meteo *obj_meteo = new meteo;
//        obj_meteo->init();
    }
    return true;
}





void layer_main::shoot()
{
    CCSprite *sprite_myself_body = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    if(sprite_myself_body)
    {
        obj_bullet *obj = new obj_bullet;
        obj->init(sprite_myself_body);
    }
}





bool layer_main::auto_collide()
{
    MY_SCORE += 10;
    sprintf(MY_SCORE_UPDATE, "%d", MY_SCORE);
    CCLabelBMFont *view_gb = (CCLabelBMFont*)getChildByTag(9990);
    view_gb->CCLabelBMFont::setString(MY_SCORE_UPDATE);
    
    
    
    for (int ii = BULLET_ID[0]; ii <= BULLET_ID[11]; ii++)
    {
        
        
        CCSprite *sprinte_bullet = (CCSprite*)getChildByTag(ii);
        if(sprinte_bullet)
        {
            
            CCPoint point_bullet = sprinte_bullet->getPosition();
            if( point_bullet.y >= (SCREEN_HIGH+10) )
            {
                this->removeChild(sprinte_bullet, true);
                if(ii==BULLET_ID[0]){BULLET_A=1;}
                else if(ii==BULLET_ID[1]){BULLET_B=1;}
                else if(ii==BULLET_ID[2]){BULLET_C=1;}
                else if(ii==BULLET_ID[3]){BULLET_D=1;}
                else if(ii==BULLET_ID[4]){BULLET_E=1;}
                else if(ii==BULLET_ID[5]){BULLET_F=1;}
                else if(ii==BULLET_ID[6]){BULLET_G=1;}
                else if(ii==BULLET_ID[7]){BULLET_H=1;}
                else if(ii==BULLET_ID[8]){BULLET_I=1;}
                else if(ii==BULLET_ID[9]){BULLET_J=1;}
                else if(ii==BULLET_ID[10]){BULLET_K=1;}
                else if(ii==BULLET_ID[11]){BULLET_L=1;}
            }
        }
    }
    
    
    for (int i=0; i<=(ENEMY_MEMBER_SUM_MAX-1); i++)
    {
        CCSprite *sprinte_myself = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
        
        if(ENEMY_STAT[i] == 2)
        {
            CCSprite *sprinte_enemy_body = (CCSprite*)getChildByTag(ENEMY_ID[i]);
            CCSprite *sprinte_enemy_wind_a = (CCSprite*)getChildByTag(ENEMY_ID[i]+100);
            CCSprite *sprinte_enemy_wind_b = (CCSprite*)getChildByTag(ENEMY_ID[i]+200);
            CCSprite *sprinte_enemy_eye_a = (CCSprite*)getChildByTag(ENEMY_ID[i]+300);
            CCSprite *sprinte_enemy_eye_b = (CCSprite*)getChildByTag(ENEMY_ID[i]+400);
//            CCProgressTimer *sprinte_enemy_hp = (CCProgressTimer*)getChildByTag(ENEMY_ID[i]+500);
            
            for (int ii = BULLET_ID[0]; ii <= BULLET_ID[11]; ii++)
            {
                CCSprite *sprinte_bullet = (CCSprite*)getChildByTag(ii);
                if(sprinte_bullet)
                {
                    bool is_collide = false;
                    if(sprinte_enemy_body)
                    {
                        is_collide = CCRect::CCRectIntersectsRect(sprinte_bullet->boundingBox(), sprinte_enemy_body->boundingBox());
                    }

                    if(is_collide)
                    {
                        CCPoint point = sprinte_enemy_body->getPosition();
                        
                        int new_value = ENEMY_HP[i]-BULLET_FORCE;
                        if(new_value <= 0)
                        {
                            this->removeChild(sprinte_enemy_body, true);
                            this->removeChild(sprinte_enemy_wind_a, true);
                            this->removeChild(sprinte_enemy_wind_b, true);
                            this->removeChild(sprinte_enemy_eye_a, true);
                            this->removeChild(sprinte_enemy_eye_b, true);
                            CCProgressTimer *sprinte_enemy_hp_d = (CCProgressTimer*)getChildByTag(ENEMY_ID[i]+500);
                            if(sprinte_enemy_hp_d)
                            {
                                this->removeChild(sprinte_enemy_hp_d, true);
                            }
                            ENEMY_HP[i] = ENEMY_HP_MAX[i];
                            ENEMY_STAT[i] = 1;
                            MY_SCORE += 10;
                            
                            CCSprite *item_gb = new CCSprite();
                            item_gb->initWithFile(SPRITE_ITEM_GB_RESOURCE);
                            item_gb->setPosition( ccp(point.x, point.y) );
                            item_gb->setScale(global_scale);
                            this->addChild(item_gb, 0,ENEMY_ID[i]+600);
                            
                            int rand_item_gb_x = 0 + rand() % (SCREEN_WIDTH-0+1) ;
                            CCJumpTo* mJumpTo = CCJumpTo::actionWithDuration(2.0f, ccp(rand_item_gb_x, 1), 230.0f, 1);
                            CCActionInterval*  seq_aa = (CCActionInterval*)(CCSequence::actions(mJumpTo, NULL));
                            item_gb->runAction(seq_aa);
                        }
                        CCProgressTimer *sprinte_enemy_hp = (CCProgressTimer*)getChildByTag(ENEMY_ID[i]+500);
                        if(sprinte_enemy_hp && new_value > 0)
                        {
                            sprinte_enemy_hp->setPercentage(ENEMY_HP[i]);
                            sprinte_enemy_hp->setPosition( ccp(point.x, point.y-20) );
                            sprinte_enemy_hp->setType(kCCProgressTimerTypeBar);
                            CCFiniteTimeAction *action_1 = CCMoveTo::create((ENEMY_SPEED*(point.y-1))/520,ccp(point.x,0));
                            sprinte_enemy_hp->runAction(action_1);
                            CCProgressTo *to = CCProgressTo::actionWithDuration(0.1, new_value);
                            sprinte_enemy_hp->runAction(to);
                            ENEMY_HP[i] -= BULLET_FORCE;
                            CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(MUSIC_ENEMY_HITTED_RESOURCE,false);
                        }else
                        {
                            CCSprite *sprinte_enemy_body = (CCSprite*)getChildByTag(ENEMY_ID[i]);
                            if(sprinte_enemy_body)
                            {
                                CCProgressTimer *sprinte_enemy_hp = CCProgressTimer::progressWithSprite(CCSprite::create(SPRITE_ENEMY_HP_RESOURCE));
                                sprinte_enemy_hp->setPercentage(ENEMY_HP[i]);
                                sprinte_enemy_hp->setPosition( ccp(point.x, point.y-20) );
                                sprinte_enemy_hp->setType(kCCProgressTimerTypeBar);
                                sprinte_enemy_hp->setScale(global_scale);
                                sprinte_enemy_hp->setMidpoint(ccp(0,0));
                                sprinte_enemy_hp->setBarChangeRate(ccp(1,0));
                                this->addChild(sprinte_enemy_hp,0,ENEMY_ID[i]+500);
                                CCFiniteTimeAction *action_1 = CCMoveTo::create((ENEMY_SPEED*(point.y-1))/520,ccp(point.x,0));
                                sprinte_enemy_hp->runAction(action_1);
                                
                                CCProgressTo *to = CCProgressTo::actionWithDuration(0.1, new_value);
                                sprinte_enemy_hp->runAction(to);
                                ENEMY_HP[i] -= BULLET_FORCE;
                                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(MUSIC_ENEMY_HITTED_RESOURCE,false);
                            }
                            
                        }
                        
                        
                        
                        
                        
                    }
                }
            }
        }
        CCSprite *sprinte_enemy_body = (CCSprite*)getChildByTag(ENEMY_ID[i]);
        CCSprite *sprinte_enemy_wind_a = (CCSprite*)getChildByTag(ENEMY_ID[i]+100);
        CCSprite *sprinte_enemy_wind_b = (CCSprite*)getChildByTag(ENEMY_ID[i]+200);
        CCSprite *sprinte_enemy_eye_a = (CCSprite*)getChildByTag(ENEMY_ID[i]+300);
        CCSprite *sprinte_enemy_eye_b = (CCSprite*)getChildByTag(ENEMY_ID[i]+400);
       
            if(sprinte_enemy_body)
            {
                CCPoint point_enemy_body = sprinte_enemy_body->getPosition();
                if( point_enemy_body.y <= 5)
                {
                    this->removeChild(sprinte_enemy_body, true);
                    ENEMY_STAT[i] = 1;
                }
            }
            if(sprinte_enemy_wind_a)
            {
                CCPoint point_enemy_wind_a = sprinte_enemy_wind_a->getPosition();
                if( point_enemy_wind_a.y <= 5)
                {
                    this->removeChild(sprinte_enemy_wind_a, true);
                }
            }
            if(sprinte_enemy_wind_b)
            {
                CCPoint point_enemy_wind_b = sprinte_enemy_wind_b->getPosition();
                if( point_enemy_wind_b.y <= 5)
                {
                    this->removeChild(sprinte_enemy_wind_b, true);
                }
            }
            if(sprinte_enemy_eye_a)
            {
                CCPoint point_enemy_eye_a = sprinte_enemy_eye_a->getPosition();
                if( point_enemy_eye_a.y <= 10)
                {
                    this->removeChild(sprinte_enemy_eye_a, true);
                }
            }
            if(sprinte_enemy_eye_b)
            {
                CCPoint point_enemy_eye_b = sprinte_enemy_eye_b->getPosition();
                if( point_enemy_eye_b.y <= 10)
                {
                    this->removeChild(sprinte_enemy_eye_b, true);
                }
            }
            CCSprite *sprinte_item_gb = (CCSprite*)getChildByTag(ENEMY_ID[i]+600);
            if(sprinte_item_gb)
            {
                CCPoint a = sprinte_item_gb->getPosition();
                if( a.y <= 5)
                {
                    this->removeChild(sprinte_item_gb, true);
                }
            }
            CCProgressTimer *sprinte_enemy_hp_end = (CCProgressTimer*)getChildByTag(ENEMY_ID[i]+500);
            if(sprinte_enemy_hp_end)
            {
                CCPoint point_enemy_hp = sprinte_enemy_hp_end->getPosition();
                if( point_enemy_hp.y <= 5)
                {
                    this->removeChild(sprinte_enemy_hp_end, true);
                    ENEMY_HP[i] = ENEMY_HP_MAX[i];
                    ENEMY_STAT[i] = 1;
                }
            }
        
            CCSprite *sprite_meteo = (CCSprite*)getChildByTag(SPRITE_METEO);
            CCParticleSystem *sprite_meteo_lizi = (CCParticleSystem*)getChildByTag(SPRITE_METEO_LIZI);
            if(sprite_meteo)
            {
                CCPoint a = sprite_meteo->getPosition();
                if( a.y <= 5)
                {
                    this->removeChild(sprite_meteo, true);
                    this->removeChild(sprite_meteo_lizi, true);
                }
                bool is_had_meteo = CCRect::CCRectIntersectsRect(sprite_meteo->boundingBox(), sprinte_myself->boundingBox());
                if(is_had_meteo)
                {
                    BULLET_A=1;
                    BULLET_B=1;
                    BULLET_C=1;
                    BULLET_D=1;
                    BULLET_E=1;
                    BULLET_F=1;
                    BULLET_G=1;
                    BULLET_H=1;
                    BULLET_I=1;
                    BULLET_J=1;
                    BULLET_K=1;
                    BULLET_L=1;
                    
                    ENEMY_HP[0]  = 100;
                    ENEMY_HP[1]  = 100;
                    ENEMY_HP[2]  = 100;
                    ENEMY_HP[3]  = 100;
                    ENEMY_HP[4]  = 100;
                    ENEMY_HP[5]  = 100;
                    ENEMY_HP[6]  = 100;
                    ENEMY_HP[7]  = 100;
                    ENEMY_HP[8]  = 100;
                    ENEMY_HP[9]  = 100;
                    ENEMY_HP[10]  = 100;
                    ENEMY_HP[11]  = 100;
                    ENEMY_HP[12]  = 100;
                    ENEMY_HP[13]  = 100;
                    ENEMY_HP[14]  = 100;
                    
                    ENEMY_STAT[0]  = 1;
                    ENEMY_STAT[1]  = 1;
                    ENEMY_STAT[2]  = 1;
                    ENEMY_STAT[3]  = 1;
                    ENEMY_STAT[4]  = 1;
                    ENEMY_STAT[5]  = 1;
                    ENEMY_STAT[6]  = 1;
                    ENEMY_STAT[7]  = 1;
                    ENEMY_STAT[8]  = 1;
                    ENEMY_STAT[9]  = 1;
                    ENEMY_STAT[10]  = 1;
                    ENEMY_STAT[11]  = 1;
                    ENEMY_STAT[12]  = 1;
                    ENEMY_STAT[13]  = 1;
                    ENEMY_STAT[14]  = 1;
                    
                    sleep(1);
                    
                    CCTextureCache::sharedTextureCache()->removeAllTextures();
                    CCDirector *pDirector = CCDirector::sharedDirector();
                    cj_2 *layer_cj_2 = new cj_2();
                    CCScene *pScene = layer_cj_2->scene();
                    pDirector->replaceScene(pScene);
                    
                }
                
            }
    
        //吃金币
        if(sprinte_item_gb)
        {
            bool is_had_gb = CCRect::CCRectIntersectsRect(sprinte_item_gb->boundingBox(), sprinte_myself->boundingBox());
            if(is_had_gb)
            {
                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(MUSIC_GET_ITEM_GB_RESOURCE,false);
                MY_SCORE_GB += 1;
                sprintf(MY_SCORE_GB_UPDATE, "%d", MY_SCORE_GB);
                CCLabelBMFont *view_gb = (CCLabelBMFont*)getChildByTag(9999);
                view_gb->CCLabelBMFont::setString(MY_SCORE_GB_UPDATE);
                this->removeChild(sprinte_item_gb, true);

            }
        }
        
        if(sprinte_enemy_body)
        {
            bool is_head = CCRect::CCRectIntersectsRect(sprinte_enemy_body->boundingBox(), sprinte_myself->boundingBox());
            if(is_head)
            {
                BULLET_A=1;
                BULLET_B=1;
                BULLET_C=1;
                BULLET_D=1;
                BULLET_E=1;
                BULLET_F=1;
                BULLET_G=1;
                BULLET_H=1;
                BULLET_I=1;
                BULLET_J=1;
                BULLET_K=1;
                BULLET_L=1;

                ENEMY_HP[0]  = 100;
                ENEMY_HP[1]  = 100;
                ENEMY_HP[2]  = 100;
                ENEMY_HP[3]  = 100;
                ENEMY_HP[4]  = 100;
                ENEMY_HP[5]  = 100;
                ENEMY_HP[6]  = 100;
                ENEMY_HP[7]  = 100;
                ENEMY_HP[8]  = 100;
                ENEMY_HP[9]  = 100;
                ENEMY_HP[10]  = 100;
                ENEMY_HP[11]  = 100;
                ENEMY_HP[12]  = 100;
                ENEMY_HP[13]  = 100;
                ENEMY_HP[14]  = 100;

                ENEMY_STAT[0]  = 1;
                ENEMY_STAT[1]  = 1;
                ENEMY_STAT[2]  = 1;
                ENEMY_STAT[3]  = 1;
                ENEMY_STAT[4]  = 1;
                ENEMY_STAT[5]  = 1;
                ENEMY_STAT[6]  = 1;
                ENEMY_STAT[7]  = 1;
                ENEMY_STAT[8]  = 1;
                ENEMY_STAT[9]  = 1;
                ENEMY_STAT[10]  = 1;
                ENEMY_STAT[11]  = 1;
                ENEMY_STAT[12]  = 1;
                ENEMY_STAT[13]  = 1;
                ENEMY_STAT[14]  = 1;
                
                sleep(1);
                
                CCTextureCache::sharedTextureCache()->removeAllTextures();
                CCDirector *pDirector = CCDirector::sharedDirector();
                cj_2 *layer_cj_2 = new cj_2();
                CCScene *pScene = layer_cj_2->scene();
                pDirector->replaceScene(pScene);
                
            }
            
            
            
        }

        
    }
   
    
    
    
    
    
    
    
    
    return true;
}




bool layer_main::game_start()
{
    obj_enemy *obj_e = new obj_enemy;
    obj_e->init();
    return true;
}






















void layer_main::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}




bool layer_main::ccTouchBegan(CCTouch *pTouches, CCEvent *pEvent)
{
//    CCPoint location = pTouches->getLocationInView();
//    location = CCDirector::sharedDirector()->convertToGL(location);
    
//    CCSprite *sprite_myself_body   = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
//    CCSprite *sprite_myself_wind_a = (CCSprite*)getChildByTag(SPRITE_MYSELF_WIND_A);
//    CCSprite *sprite_myself_wind_b = (CCSprite*)getChildByTag(SPRITE_MYSELF_WIND_B);
//    
//    bool ret_sprite_myself_body    = CCRect::CCRectContainsPoint(sprite_myself_body->boundingBox(), location);
//    bool ret_sprite_myself_wind_a  = CCRect::CCRectContainsPoint(sprite_myself_wind_a->boundingBox(), location);
//    bool ret_sprite_myself_wind_b  = CCRect::CCRectContainsPoint(sprite_myself_wind_b->boundingBox(), location);
//    if(ret_sprite_myself_body || ret_sprite_myself_wind_a || ret_sprite_myself_wind_b)
//    {
        layer_main::touch = true;
//    }
    return true;
}




void layer_main::ccTouchEnded(CCTouch *pTouches, CCEvent *pEvent)
{
    layer_main::touch = false;
}




void layer_main::ccTouchMoved(CCTouch *pTouches, CCEvent *pEvent)
{
    CCPoint location = pTouches->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    CCSprite *sprite_myself_body   = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    CCSprite *sprite_myself_wind_a = (CCSprite*)getChildByTag(SPRITE_MYSELF_WIND_A);
    CCSprite *sprite_myself_wind_b = (CCSprite*)getChildByTag(SPRITE_MYSELF_WIND_B);
    
    if(layer_main::touch == true)
    {
        float endx = location.x;
        sprite_myself_body->setPosition(ccp(endx,SPRITE_MYSELF_BODY_POSITION[1]));
        sprite_myself_wind_a->setPosition(ccp(endx-20,SPRITE_MYSELF_WIND_A_POSITION[1]));
        sprite_myself_wind_b->setPosition(ccp(endx+20,SPRITE_MYSELF_WIND_A_POSITION[1]));
        
        CCSprite *sprite_warn_line = (CCSprite*)getChildByTag(SPRITE_M_LINE);
        if(sprite_warn_line)
        {
            sprite_warn_line->setPositionX(endx);
        }
    }
}









bool layer_main::meteo_1()
{
    CCSprite *sprite_myself_body   = (CCSprite*)getChildByTag(SPRITE_MYSELF_BODY);
    CCPoint a = sprite_myself_body->getPosition();
    
    CCSprite *sprite_warn_line = new CCSprite();
    sprite_warn_line->initWithFile("warn_line.png");
    
    sprite_warn_line->setPosition(ccp(a.x, 250));
    sprite_warn_line->setScaleY(2.0);
    this->addChild(sprite_warn_line, -1, SPRITE_M_LINE);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(MUSIC_ALERT_RESOURCE,false);
    
    
    
    CCActionInterval *actionMove1 = CCFadeOut::actionWithDuration(0.5);
    CCActionInterval *actionMove2 = CCFadeIn::actionWithDuration(0.5);
    
    CCActionInterval *seq_b = (CCActionInterval*)(CCSequence::actions(actionMove1, actionMove2, actionMove1, actionMove2, actionMove1, actionMove2, actionMove1, NULL));
    
    sprite_warn_line->runAction(seq_b);
    
    this->schedule(schedule_selector(layer_main::meteo_2),3);
    return true;
}


bool layer_main::meteo_2()
{
//    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopAllEffects();
    CCSprite *sprite_warn_line = (CCSprite*)getChildByTag(SPRITE_M_LINE);
    CCPoint a = sprite_warn_line->getPosition();
    this->removeChild(sprite_warn_line, true);
    this->unschedule(schedule_selector(layer_main::meteo_2));
    
    
    
    CCSprite *sprite_meteo = new CCSprite();
    sprite_meteo->initWithFile("meteo.png");
    sprite_meteo->setPosition(ccp(a.x, SCREEN_HIGH+30));
    sprite_meteo->setScale(global_scale);
    this->addChild(sprite_meteo, 10, SPRITE_METEO);
    
    CCFiniteTimeAction *bj_a = CCMoveTo::create(1,ccp(a.x,0));
    sprite_meteo->runAction(bj_a);
    
    
    CCParticleSystem *m_emitter;
    m_emitter = CCParticleFireworks::node();
    m_emitter->retain();
    m_emitter->setTotalParticles(50);
    m_emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage("dust_02.png"));
    m_emitter->setPosition(ccp(a.x, SCREEN_HIGH+50));
    m_emitter->setAngle(90);
    m_emitter->setAngleVar(5);
    m_emitter->setLife(1);
    m_emitter->setLifeVar(1);
    m_emitter->setPosVar(ccp(3, 3));
    m_emitter->setStartSize(30);
    m_emitter->setStartSizeVar(40);
    m_emitter->setEndSize(0.0f);
    m_emitter->setEndSizeVar(0.0f);
    ccColor4F endColor2 = { 255, 255, 255, 255 };
    m_emitter->setEndColor(endColor2);
    
    this->addChild(m_emitter, 10, SPRITE_METEO_LIZI);
    CCFiniteTimeAction *bj_b = CCMoveTo::create(1,ccp(a.x,50));
    m_emitter->runAction(bj_b);
    
    
    return true;
}










void layer_main::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
