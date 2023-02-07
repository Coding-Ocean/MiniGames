#pragma once
#include "GAME_OBJECT.h"
class SCENE :
    public GAME_OBJECT
{
public:
    SCENE(class GAME2* game);
    virtual ~SCENE();
    virtual void create();
    virtual void init();
    virtual void proc();
    virtual void updata();
    virtual void draw();
    virtual void nextScene();
};

