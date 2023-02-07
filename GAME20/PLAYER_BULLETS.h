#pragma once
#include "BULLETS.h"
namespace GAME20 {
    class PLAYER_BULLETS :
        public BULLETS
    {
    public:
        PLAYER_BULLETS(class GAME* game);
        void create();
    };
}
