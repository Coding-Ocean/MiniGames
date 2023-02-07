#pragma once
#include "SCENE.h"
namespace GAME20 {
    class GAME_CLEAR :
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
        DATA Clear;
    public:
        GAME_CLEAR(class GAME* game);
        ~GAME_CLEAR();
        void create();
        void update();
        void draw();
        void nextScene();
    };

}