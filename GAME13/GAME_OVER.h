#pragma once
#include "SCENE.h"
#include "../libOne/inc/libOne.h"


class GAME_OVER :
    public SCENE
{
public:
    struct DATA{
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        char str[16];
    };
private:
    DATA Game_Over;
public:
    GAME_OVER(class GAME2* game);
    ~GAME_OVER();
    void draw();
    void nextScene();
    void create();


};

