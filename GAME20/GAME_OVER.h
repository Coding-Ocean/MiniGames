#pragma once
#include "SCENE.h"
namespace GAME20 {
    class GAME_OVER :
        public SCENE
    {
    public:
        struct DATA {
            int img;
            COLOR backColor;
            COLOR textColor;
            float textSize;
            VECTOR2 pos;
            char str[16];
        };
    private:
        DATA Over;
    public:
        GAME_OVER(class GAME* game);
        ~GAME_OVER();
        void create();
        void update();
        void draw();
        void nextScene();
    };
}
