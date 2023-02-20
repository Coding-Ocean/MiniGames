#pragma once
#include "ACTOR.h"
namespace GAME00 {

    class BALL :
        public ACTOR {
    public:
        BALL(class GAME* game);
        ~BALL();
        void init();
        void update();
        void draw();

    private:
        void Move();
        void Wall();

        void Pad_Coli(class BALL*ball);
        void Block_Coli(class BALL*ball);

        void Collision();
    };
}
