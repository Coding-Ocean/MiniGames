#pragma once
#include "SCENE.h"
#include "../libOne/inc/libOne.h"


class TITLE :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        char str[16];
    };
private:
    DATA Title;
public:
    TITLE(class GAME2* game);
    ~TITLE();
    void create();
    void draw();
    void nextScene();


};

