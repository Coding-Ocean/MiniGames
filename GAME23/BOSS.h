#pragma once
#include "ACTOR.h"
namespace GAME23
{
    class BOSS :
        public ACTOR
    {
    public:
        BOSS(class GAME* game);
        ~BOSS();
        void init();
        void update();
        void draw();
        int bossImg;
    };
}



