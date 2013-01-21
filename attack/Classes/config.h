//
//  config.h
//  attack
//
//  Created by gerry on 13-1-18.
//
//

#ifndef __attack__config__
#define __attack__config__

#include <iostream>
#include "SimpleAudioEngine.h"

using namespace std;

extern float global_scale;
extern int SCREEN_HIGH;
extern int SCREEN_WIDTH;
extern int MY_SCORE_GB;
extern int MY_SCORE;

extern char MY_SCORE_UPDATE[1];
extern char MY_SCORE_GB_UPDATE[1];

extern char *SPRITE_MYSELF_RESOURCE;
extern char *SPRITE_BULLET_RESOURCE;
extern char *SPRITE_DRAGON_01_RESOURCE;
extern char *SPRITE_DRAGON_02_RESOURCE;
extern char *SPRITE_ENEMY_HP_RESOURCE;
extern char *SPRITE_ITEM_GB_RESOURCE;


extern char *MUSIC_BACKGROUND_FIGHT_RESOURCE;
extern char *MUSIC_GET_ITEM_GB_RESOURCE;
extern char *MUSIC_ENEMY_HITTED_RESOURCE;

extern float BULLET_SPEED;
extern int BULLET_A;
extern int BULLET_B;
extern int BULLET_C;
extern int BULLET_D;
extern int BULLET_E;
extern int BULLET_F;
extern int BULLET_G;
extern int BULLET_H;
extern int BULLET_I;
extern int BULLET_J;
extern int BULLET_K;
extern int BULLET_L;
extern int BULLET_FORCE;
extern int BULLET_ID[12];

extern int ENEMY_ID[15];
extern int ENEMY_HP[15];
extern int ENEMY_MEMBER_MAX;
extern int ENEMY_MEMBER_SUM_MAX;
extern int ENEMY_STAT[15];
extern int ENEMY_SPEED;

extern int SPRITE_ENEMY_BODY_RET[4];
extern int SPRITE_ENEMY_WIND_RET[4];
extern int SPRITE_ENEMY_EYES_A_RET[4];
extern int SPRITE_ENEMY_EYES_B_RET[4];

extern int SPRITE_MYSELF_BODY;
extern int SPRITE_MYSELF_BODY_RET[4];
extern int SPRITE_MYSELF_BODY_POSITION[2];

extern int SPRITE_MYSELF_WIND_A;
extern int SPRITE_MYSELF_WIND_A_RET[4];
extern int SPRITE_MYSELF_WIND_A_POSITION[2];

extern int SPRITE_MYSELF_WIND_B;
extern int SPRITE_MYSELF_WIND_B_RET[4];
extern int SPRITE_MYSELF_WIND_B_POSITION[2];











#endif /* defined(__attack__config__) */
