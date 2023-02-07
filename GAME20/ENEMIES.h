#pragma once
#include "GAME_OBJECT.h"
#include"../libOne/inc/libOne.h"
namespace GAME20 {
    class ENEMIES :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img;
            int totalNum;
            int curNum;
            int cnt;
            float targetPosY;
            float refTheta;
            float thetaSpeed;
            float triggerInterval;
            float ofstLaunchDist;
            //collision
            float bcRadius;
            float invincibleTime;
            int initHp;
           
        };
    private:
        //共通データ
        DATA Enemy;
        //単体データ配列
    private:
        struct ENEMY {
            VECTOR2 pos;
            float levelSpeed;
            float fallSpeed;
            float ofsTheta;
            float triggerErapsedTime;
            float invincibleRestTime;
            int hp;
            COLOR color;
        };
        ENEMY* Enemies;
    public:
        ENEMIES(class GAME* game);
        ~ENEMIES();
        void create();
        void init();
        void update();
        void move();
        void collision();
        void draw();

        //getter
        int curNum() { return Enemy.curNum; }
        int cnt() { return Enemy.cnt; }
    };
}
