#pragma once
#include "SCENE.h"
#include"../libOne/inc/libOne.h"
#include"TITLE.h"
namespace GAME20 {
    class TITLE :
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
        DATA Title;
    public:
        TITLE(class GAME* game);
        ~TITLE();
        void create();
        void draw();
        void nextScene();
    };
}
