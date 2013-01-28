//
//  config.cpp
//  attack
//
//  Created by gerry on 13-1-18.
//
//

#include "config.h"

float global_scale = 1;
//int SCREEN_HIGH    = 960;
//int SCREEN_WIDTH   = 640;
int SCREEN_HIGH    = 480;
int SCREEN_WIDTH   = 320;

int MY_SCORE_GB    = 0;
int MY_SCORE       = 0;
char MY_SCORE_UPDATE[1];
char MY_SCORE_GB_UPDATE[1];

char *SPRITE_MYSELF_RESOURCE                 = "avata_1.png";
char *SPRITE_BULLET_RESOURCE                 = "bullet_01_02.png";
char *SPRITE_DRAGON_01_RESOURCE              = "dragon_01.png";
char *SPRITE_DRAGON_02_RESOURCE              = "dragon_02.png";
char *SPRITE_ENEMY_HP_RESOURCE               = "hatchling_exp_02.png";
char *SPRITE_ITEM_GB_RESOURCE                = "item_coin.png";

char *MUSIC_BACKGROUND_FIGHT_RESOURCE        = "dragon_flight.mp3";
char *MUSIC_GET_ITEM_GB_RESOURCE             = "get_coin.wav";
char *MUSIC_ENEMY_HITTED_RESOURCE            = "fire_explo.wav";
char *MUSIC_ALERT_RESOURCE                   = "alert_big.wav";


float BULLET_SPEED                                = 0.1;
int BULLET_STAT[12]                               = {1,1,1,1,1,1,1,1,1,1,1,1};
int BULLET_ID[12]                                 = {101,102,103,104,105,106,107,108,109,110,111,112};
int BULLET_FORCE                                  = 10;

int ENEMY_ID[15]                                  = {10001,10002,10003,10004,10005,10006,
                                                    10007,10008,10009,10010,10011,10012,
                                                    10013,10014,10015};
int ENEMY_HP[15]                                  = {100,100,100,100,100,100,100,100,
                                                    100,100,100,100,100,100,100};
int ENEMY_HP_MAX[15]                              = {100,100,100,100,100,100,100,100,
                                                    100,100,100,100,100,100,100};

int ENEMY_MEMBER_MAX                              = 5;
int ENEMY_MEMBER_SUM_MAX                          = 15;
int ENEMY_STAT[15]                                = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int ENEMY_SPEED                                   = 2;

int SPRITE_ENEMY_BODY_RET[4]                      = {0,0,39,60};
int SPRITE_ENEMY_WIND_RET[4]                      = {45,28,16,31};
int SPRITE_ENEMY_EYES_A_RET[4]                    = {110, 10, 10, 20};
int SPRITE_ENEMY_EYES_B_RET[4]                    = {};



int MYSELF_HP                                     = 100;
int MYSELF_HP_ID                                  = 100;
int SPRITE_MYSELF_BODY                            = 1;
int SPRITE_MYSELF_BODY_RET[4]                     = {0,0,25,60};
int SPRITE_MYSELF_BODY_POSITION[2]                = {160,80};

int SPRITE_MYSELF_WIND_A                          = 2;
int SPRITE_MYSELF_WIND_A_RET[4]                   = {28,0,35,24};
int SPRITE_MYSELF_WIND_A_POSITION[2]              = {160,75};

int SPRITE_MYSELF_WIND_B                          = 3;
int SPRITE_MYSELF_WIND_B_RET[4]                   = {28,0,35,24};
int SPRITE_MYSELF_WIND_B_POSITION[2]              = {160,75};


//BOSS
int SPRITE_BOSS_ID                                = 50000;




//陨石
int SPRITE_METEO                                  = 21;
int SPRITE_M_LINE                                 = 20;
int SPRITE_METEO_LIZI                             = 22;



//背景速度
int back_ground_speed          = 5;


//关卡
int s_1_p_1_max_km             = 10000;
int s_1_p_1_enemy_speed        = 3;









//玩法
int sprite_speed_up_id       = 998;
bool speed_up_stat           = false;

