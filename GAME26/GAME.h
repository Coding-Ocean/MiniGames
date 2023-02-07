#pragma once

#include"../MAIN/STATE.h" 
namespace GAME26 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//ここに必要な記憶場所を用意する
		//画像表示用
		int Img;

		//円表示用
	    //描画
		struct TEXT {
			const char* str;
			float Px, Py, Size;
			COLOR Color;
		};
		TEXT Title[5]{};
		TEXT Result[5]{};

		struct CIRCLE {
			float Px, Py, Diameter, Vx, Vy,Angle;
		};
		CIRCLE TS[6]{};
		CIRCLE C[4]{};
		CIRCLE S[8]{};

		struct LINE {
			float Sx, Sy, Ex, Ey;
		};
		struct LINE l1;
		LINE l2;
		LINE l3;
		LINE l4;
		LINE l5;
		LINE l6;

		struct RECT {
			float Px, Py, W, H;
		};
		RECT r1;
		RECT r2;

		int currentStone = 0;
		float throwPower = 0;
		int powerFlag = 0;
		float powerRectPx = 0;
		float powerRectPy = 0;
		int throwFlag = 0;
		float attenuation = 0;
		float powerLimit = 0;
		int remaining = 0;
		int Scnt = 0;
		float sweepPx = 0;
		float sweepLong = 0;
		int sweepPower = 0;
		float MtSVx = 0;
		float MtSVy = 0;
		float distance = 0;
		int NCstone = 0;
		float magbuf = 0;
		int BCflag = 0;
		float CollisionTime[8]{};
		float CollisionDelay = 0;

		int collisionSnd = 0;

		//ゲームのタイトル画面->プレイ中画面->結果画面
		enum STATE {TITLE,PLAY,RESULT};
		STATE State = TITLE;

	public:
		void init();
		void title();
		void play();
		void result();
		void collision(int idx1, int idx2);
		int isMove();
		int sleep(unsigned long x);

		//以下はいじらないでよい
		int BackToMenuFlag=0;
	};
}

