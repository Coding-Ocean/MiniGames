#pragma once
#include "ACTOR.h"
namespace GAME00 {
    class SCORE :
        public ACTOR {
    public:
        SCORE(class GAME* game);
        ~SCORE();
        void init();
        void update();
        void draw();

        void addScore(int score);
    private:
        int PlayerScore;

        int BolladdScore;
    };
}
