#pragma once
#include "SCENE.h"
namespace GAME20 {
    class STAGE :
        public SCENE
    {
    public:
        STAGE(class GAME* game);
        ~STAGE();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}
