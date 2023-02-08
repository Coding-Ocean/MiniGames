#include<stdio.h>
#include"MANAGER.h"
#include"FADE.h"
#include"MENU.h"
//#include"../GAME00/GAME.h"
MANAGER::MANAGER() {
    //-----------------------------------------------------------------------------------
    //全ステート共通使用の「データ、または、オブジェクト」準備
    //-----------------------------------------------------------------------------------

    //選択するゲームのインデックス
    selectIdx = 0;

    //クリア済みゲームフラッグを読みこむ
    FILE* fp = 0;
    fopen_s(&fp, "data/data.txt", "rb");
    if (fp) {
        fread(clearFlags, 1, 30, fp);
        fclose(fp);
    }
    else {
        for (int i = 0; i < 30; i++) {
            clearFlags[i] = 0;
        }
    }
    //発表用にクリアフラッグを立てる
    int flag[30] = {1,
        0,0,0,0,0,
        0,1,1,1,1,
        0,0,0,1,0,
        0,1,0,1,0,
        0,1,0,1,1,
        0,0,1,1
    };
    for (int i = 0; i < 30; i++) {
        clearFlags[i] = flag[i];
    }

    
    //フェードイン、フェードアウト制御クラス
    fade = new FADE;

    //-----------------------------------------------------------------------------------
    //しょっぱなのステートをセット
    //-----------------------------------------------------------------------------------
    state = new MENU(this);
}

MANAGER::~MANAGER() {
    //クリアしたゲームの状態をセーブ
    FILE* fp = 0;
    fopen_s(&fp, "data/data.txt", "wb");
    if (fp) {
        fwrite(clearFlags, 1, 16, fp);
        fclose(fp);
    }
    delete state;
    delete fade;
}

void MANAGER::proc() {
    state->proc(this);
}

