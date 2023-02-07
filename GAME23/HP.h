#pragma once
#include "ACTOR.h"
namespace GAME23
{
    class HP :
        public ACTOR
    {
    public:
        HP(class GAME* game);
        ~HP();
        void init();
        void update();
        void draw();
    private:
        int PlayerHp;
        int BossHp;
        int HpFlag;
        int WinHp;
        int Creaimg;
    };
}



