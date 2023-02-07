#pragma once
#include"../MAIN/STATE.h"

namespace GAME16 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	public:
		//ここに必要な記憶場所を用意する
		//画像表示用
		int Img;
		int Img1;
		int Img2;
		int Img3;
		//
		float Px;
		float Py;


		float Px1, Px2, Px3;
		float Py1, Py2, Py3;
		float Vx1=1, Vx2=1, Vx3=1;

		int st = 0;
		int sr = 0;
		//以下はいじらないでよい
		int BackToMenuFlag = 0;
	public:
		void move() {
			Px1 += Vx1;
			Px2 += Vx2;
			Px3 += Vx3;
			if (Px1 < 0) {
				Px1 = 1820;
			}
			if (Px2 > 1920) {
				Px2 = 0;
			}
			if (Px3 < 0) {
				Px3 = 1820;
			}
		}
		void stop() {
			if (isTrigger(KEY_A))Vx1 = 0;
		    if (isTrigger(KEY_S))Vx2 = 0;
			if (isTrigger(KEY_D))Vx3 = 0;

			if (Vx1==0&&Vx2 == 0&&Vx3==0) {
				st = 1;
			}
		}
		void draw() {
			rectMode(CENTER);
			image(Img1, Px1, Py1, 0, 2);
			image(Img2, Px2, Py2, 0,2);
			image(Img3, Px3, Py3, 0,2);
			//rect( Px1, Py1, 350, 350);
			//rect( Px2, Py2, 350, 350);
			//rect( Px3, Py3, 350, 350);
		}
		void score() {
			int s;
			if (st == 1) {
					int i, j;
					int num[3] = {Px1,Px2,Px3};
					int tmp;

					//	降順ソートのプログラム
					for (i = 0; i < 3; i++)
					{
						for (j = i + 1; j < 3; j++)
						{
							if (num[i] < num[j])
							{
								tmp = num[i];
								num[i] = num[j];
								num[j] = tmp;
							}
						}
					}
					s = 2000 - (num[0] - num[2]);

			}
				text(s, 600, 300);
		}
	};
}

