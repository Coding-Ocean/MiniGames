#pragma once
#include "ACTOR.h"
#include <vector>
namespace GAME00 {
    class COURT :
        public ACTOR{
    public:
        COURT(class GAME* game);
        ~COURT();
        void init();
        void update();
        void draw();

        std::vector<class BLOCK*> Getblocks() { return Blocks; }
        void RemoveBlocks(BLOCK* block);
    private:
        
        //ブロックの生成を行う
        void GeneBlocks();
        void DawnBlocks();
        void AddBlocks();

        float CountTime;
        float GeneTime;

        float B_MostLow_py;

        float CortHarf_H;
        bool BallUPside;
        bool Dathside;
        
        //生成したブロックのアドレスを保持する
        std::vector<class BLOCK*> Blocks;
    };
}
