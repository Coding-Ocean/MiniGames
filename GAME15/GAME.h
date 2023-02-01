#pragma once
#include"../MAIN/STATE.h"

namespace GAME15 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:

		char name[17] = "ぴったり雪だるま";
		float namepx = 0;
		float namepy = 0;
		float namesize = 0;
		char Name[19] = "スペースでスタート";
		float Namepx = 0;
		float Namepy = 0;
		float Namesize = 0;
		//停止用
		bool stopflag = true;
		//プレイ関数
		bool play_init = true;
		int score = 0;
		char scoretext[3]{};
		int numplay = 0;
		int counter = 0;
		float interval = 0;
		float remain = 0;
		//リザルト関数
		int totalscore = 0;
		float scoresize = 0;
		char totalStr[15] = "あなたの合計点";
		float totalStrPx = 0;
		float totalStrPy = 0;
		char scoreStr[4]{};
		float scoreStrPx = 0;
		float scoreStrPy = 0;
		float infosize = 0;
		char titleStr[19] = "スペースでタイトル";
		float titleStrPx = 0;
		float titleStrPy = 0;
		char menuStr[19] = "エンターでメニュー";
		float menuStrPx = 0;
		float menuStrPy = 0;
		//チート
		float stopPx = 0;
		bool cheatFlag = true;
		//円表示用
		struct CIRCLE {
			float Diameter;//直径
			float Px;
			float Py;
			float Vx;
			float Vy;
		};
		struct CIRCLE c1, c2, c3, c4, c5, c6, c7;
		struct LINE {
			float Sx;
			float Sy;
			float Ex;
			float Ey;
		};
		struct LINE l1, l2, l3, l4, l5, l6;
		//以下はいじらないでよい
		int BackToMenuFlag = 0;
		enum SCENE {
			title,
			play,
			result,
		};
		SCENE scene = title;
	public:
		void Init();
		void Initposition();
		void Title();
		void Play();
		void Result();
	};

}

