#pragma once
#include "GAME_OBJECT.h"
#include"../libOne/inc/libOne.h"
namespace GAME20 {
    class BULLETS :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int totalNum;
            int curNum;
            int img;
            float advSpeed;
            float angSpeed;
            float bcRadius;

        };
    private:
        //共通データ
        DATA Bullet;
        //単体データ配列
        struct BULLET {
            VECTOR2 pos;
            VECTOR2 vec;
            float angle;
        };
        BULLET* Bullets;
    protected:
        void SetBullets(const BULLETS::DATA& data);
    public:
        BULLETS(class GAME* game);
        ~BULLETS();
        void init();
        void launch(const VECTOR2& pos, const VECTOR2& vec);
        void update();
        void kill(int i);
        void draw();

        VECTOR2 pos(int i) { return Bullets[i].pos; }
        float bcRadius() { return Bullet.bcRadius; }
        int curNum() { return Bullet.curNum; }
    };
}
