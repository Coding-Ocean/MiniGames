#pragma once
#include<stdio.h>
namespace GAME27 {
	//カード単体データ
	struct CARD {
		int posNo; //場所
		bool state; //裏表
		bool getFlag; //取得
		float x;
		float y;
	};
	//文字データ
	struct STR {
		const char* Str;
		float Size = 0;
		float Px = 0;
		float Py = 0;
		COLOR Color;
	};
	//操作State
	enum FASE { THINK, FIRST, GET, FAIL };
	//シーン移動
	enum SCENE { TITLE, PLAY, RESULT };

}