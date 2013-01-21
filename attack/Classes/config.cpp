//
//  config.cpp
//  attack
//
//  Created by gerry on 13-1-18.
//
//

#include "config.h"

float global_scale = 0.45;
int SCREEN_HIGH    = 480;
int SCREEN_WIDTH   = 320;

int MY_SCORE_GB    = 0;
int MY_SCORE       = 0;
char MY_SCORE_UPDATE[1];
char MY_SCORE_GB_UPDATE[1];

char *SPRITE_MYSELF_RESOURCE                 = "sunny_01.png";
char *SPRITE_BULLET_RESOURCE                 = "bullet_01_02.png";
char *SPRITE_DRAGON_01_RESOURCE              = "dragon_01.png";
char *SPRITE_DRAGON_02_RESOURCE              = "dragon_02.png";
char *SPRITE_ENEMY_HP_RESOURCE               = "hatchling_exp_02.png";
char *SPRITE_ITEM_GB_RESOURCE                = "item_coin.png";

char *MUSIC_BACKGROUND_FIGHT_RESOURCE        = "dragon_flight.mp3";
char *MUSIC_GET_ITEM_GB_RESOURCE             = "get_coin.wav";
char *MUSIC_ENEMY_HITTED_RESOURCE            = "fire_explo.wav";


float BULLET_SPEED                                = 0.1;
int BULLET_A                                      = 1;
int BULLET_B                                      = 1;
int BULLET_C                                      = 1;
int BULLET_D                                      = 1;
int BULLET_E                                      = 1;
int BULLET_F                                      = 1;
int BULLET_G                                      = 1;
int BULLET_H                                      = 1;
int BULLET_I                                      = 1;
int BULLET_J                                      = 1;
int BULLET_K                                      = 1;
int BULLET_L                                      = 1;
int BULLET_ID[12]                                 = {101,102,103,104,105,106,107,108,109,110,111,112};
int BULLET_FORCE                                  = 1;

int ENEMY_ID[15]                                  = {10001,10002,10003,10004,10005,10006,
                                                    10007,10008,10009,10010,10011,10012,
                                                    10013,10014,10015};
int ENEMY_HP[15]                                  = {100,100,100,100,100,100,100,100,
                                                    100,100,100,100,100,100,100};

int ENEMY_MEMBER_MAX                              = 5;
int ENEMY_MEMBER_SUM_MAX                          = 15;
int ENEMY_STAT[15]                                = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int ENEMY_SPEED                                   = 7;

int SPRITE_ENEMY_BODY_RET[4]                      = {0, 0, 85, 190};
int SPRITE_ENEMY_WIND_RET[4]                      = {85, 50, 60, 70};
int SPRITE_ENEMY_EYES_A_RET[4]                    = {110, 10, 10, 20};
int SPRITE_ENEMY_EYES_B_RET[4]                    = {};



int SPRITE_MYSELF_BODY                            = 1;
int SPRITE_MYSELF_BODY_RET[4]                     = {0, 0, 45, 110};
int SPRITE_MYSELF_BODY_POSITION[2]                = {100,50};

int SPRITE_MYSELF_WIND_A                          = 2;
int SPRITE_MYSELF_WIND_A_RET[4]                   = {45, 0, 100, 60};
int SPRITE_MYSELF_WIND_A_POSITION[2]              = {85, 40};

int SPRITE_MYSELF_WIND_B                          = 3;
int SPRITE_MYSELF_WIND_B_RET[4]                   = {45, 0, 100, 60};
int SPRITE_MYSELF_WIND_B_POSITION[2]              = {112, 40};




















