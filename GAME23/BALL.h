#pragma once
#include "ACTOR.h"
namespace GAME23
{
    class BALL :
        public ACTOR
    {
    public:
        BALL(class GAME* game);
        ~BALL();
        void init();
        void update();
        void draw();
    private:
        void Wall();
        void Collision();
        void Move();
        int i;
		int Img;
    };
}

