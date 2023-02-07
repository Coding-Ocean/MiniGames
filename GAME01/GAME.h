#pragma once
#include"../MAIN/STATE.h"

namespace GAME01 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	public:
		//ここに必要な記憶場所を用意する
		//画像表示用
		int Img;
		int num = 9;
		int Imgs[9];
		int back;
		int game_over;
		int bgm;
		int game_over_music;
		int osu;

		int bgmFlag;


		int no;
		int counter1;
		int counter2;
		int counter3;
		int no1;
		int no2;
		int no3;

		int interval;

		int roal1;
		int roal2;
		int roal3;
		int roading;


		
		int nowHp;

		int over;


		//int stop;

		//円表示用
		float Diameter;//直径
		float Px;
		float Py;
		float Vx;
		float Vy;
		//以下はいじらないでよい
		int BackToMenuFlag = 0;

		void load() {
			Img = loadImage("../game01/assets/unkoWhite.png");
			Imgs[0] = loadImage("../game01/assets/aka.png");
			Imgs[1] = loadImage("../game01/assets/ao.png");
			Imgs[2] = loadImage("../game01/assets/number_3.png");
			Imgs[3] = loadImage("../game01/assets/number_4.png");
			Imgs[4] = loadImage("../game01/assets/number_5.png");
			Imgs[5] = loadImage("../game01/assets/number_6.png");
			Imgs[6] = loadImage("../game01/assets/number_7.png");
			Imgs[7] = loadImage("../game01/assets/number_8.png");
			Imgs[8] = loadImage("../game01/assets/number_9.png");
			back = loadImage("../game01/assets/back.png");
			game_over = loadImage("../game01/assets/game_over.png");
			bgm = loadSound("../game01/assets/bgm.wav");
			game_over_music = loadSound("../game01/assets/game_over.wav");
			osu = loadSound("../game01/assets/osu.wav");
		}

		void init() {
			
			bgmFlag = 1;



			counter1 = 0;
			counter2 = 6;
			counter3 = 9;

			over = 0;

			interval = 3;

			roal1 = 1;
			roal2 = 1;
			roal3 = 1;

			no1 = 0;
			no2 = 0;
			no3 = 0;

			roading = 0;



			nowHp = 1;

			
		}
		void roll() {
			roading = 1;
			roal1 = 1;
			roal2 = 1;
			roal3 = 1;
		}
		void sound() {
			playSound(bgm);
		}
	};
}

