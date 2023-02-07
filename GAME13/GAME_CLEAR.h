#pragma once
#include "SCENE.h"
#include "../libOne/inc/libOne.h"


class GAME_CLEAR :
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
    DATA Game_Cler;
public:
    GAME_CLEAR(class GAME2* game);
    ~GAME_CLEAR();
    void draw();
    void nextScene();
    void create();


};

