#pragma once
#include "GAME_OBJECT.h"
#include"../libOne/inc/libOne.h"
namespace GAME20 {
    class ITEMS :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img;
            int cnt;
            int totalNum;
            int curNum;
            //collision
            float bcRadius;
            int inithp;

        };
    private:
        DATA Item;
        struct ITEM {
            VECTOR2 pos;
            int hp;

        };
        ITEM* Items;
    public:
        ITEMS(class GAME* game);
        ~ITEMS();
        void create();
        void init();
        void update();
        void collision();
        void draw();

        //getter
        int curNum() { return Item.curNum; }
        int cnt() { return Item.cnt; }
    };
}
