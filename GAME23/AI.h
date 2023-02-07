#pragma once
#include "ACTOR.h"
namespace GAME23
{
    class AI :
        public ACTOR
    {
    public:
        AI(class GAME* game);
        ~AI();
        void init();
        void update();
        void draw();
    };
}


