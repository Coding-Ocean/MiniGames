#pragma once
#include "GAME_OBJECT.h"
#include"../libOne/inc/libOne.h"
namespace GAME20 {
    class PLAYER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img;
            VECTOR2 pos;
            float advSpeed;
            float angle;
            float limmitW;
            float limmitH;
            //launch
            VECTOR2 launchVec;
            float triggerErapsedTime;
            float triggerInterval;
            float ofstLaunchDist;
            //collision
            float bcRadius;
            

        };
    private:
        DATA Player;
    public:
        PLAYER(class GAME* game);
        void create();
        void init();
        void update();
        void move();
        void lanch();
        void draw();

        //getter
        VECTOR2 pos() { return Player.pos; }

    };
}
