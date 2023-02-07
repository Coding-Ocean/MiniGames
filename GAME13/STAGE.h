#pragma once
#include "SCENE.h"
class STAGE :
    public SCENE
{
public:
    STAGE(class GAME2* game);
    ~STAGE();
    void update();
    void draw();
    void nextScene();


};

