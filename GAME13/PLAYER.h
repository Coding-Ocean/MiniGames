#pragma once
#include "GAME_OBJECT.h"
#include "../libOne/inc/libOne.h"

class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
        float angle;
        float limmitW;
        float advSpeed;

    };
private:
    DATA Player;
public:
    PLAYER(class GAME2* game);
    void create();
    void init();
    void update();
    void draw();

};

