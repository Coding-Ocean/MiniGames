#pragma once
#include"../MAIN/STATE.h"

namespace GAME04 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
		void roundFace(float px, float py);
		void squareFace(float px, float py);
	private:
		//ここに必要な記憶場所を用意する
		//画像表示用
		int Img;
		//円表示用
		float Diameter;//直径
		float Px;
		float Py;
		float Vx;
		float Vy;
		float Eiameter;//直径
		float Ex;
		float Ey;
		float EVx;
		float EVy;
		float Aiameter;//直径
		float Ax;
		float Ay;
		float AVx;
		float AVy;
		float Biameter;//直径
		float Bx;
		float By;
		float BVx;
		float BVy;
		float a; 
		float b; 
		float c;
		float d;
		float e;
		float f;

		float distance1;
		float distance2;
		float distance3;
		//以下はいじらないでよい
		int BackToMenuFlag = 0;
	};
};

