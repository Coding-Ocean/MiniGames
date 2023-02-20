#pragma once
#include "ACTOR.h"
namespace GAME00 {
    class BLOCK :
        public ACTOR {
    public:
        BLOCK(class GAME* game);
        ~BLOCK();
        void init();
        void update();
        void draw();
    };
}
