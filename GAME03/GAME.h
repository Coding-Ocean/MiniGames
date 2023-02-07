#pragma once
#include"../MAIN/STATE.h"
#include <math.h>

namespace GAME03 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！
	//隕石の個数
	#define ENUM 5

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//ここに必要な記憶場所を用意する
		struct BULLET{
			int Eflag, Ex, Ey, EVy, Er;
		};
		//プレイヤー（自機）のデータ
		  //座標
		int Px = 960;
		int Py = 1000;
		  //移動速度(横)
		int PVx = 15;
		  //半径
		int Pr = 100;

		//敵(隕石)データ
		int Eflag[ENUM];
		//座標
		int Ex[ENUM];
		int Ey[ENUM];
		//移動速度(縦)
		int EVy[ENUM];
		//半径
		int Er = 50;

		//弾データ
		//0なら表示しない
		int Bflag = 0;
		//座標
		int Bx = -50;
		int By = 1180;
		//移動速度(縦)
		int BVx = PVx;
		int BVy = 25;
		//半径
		int Br= 5;

		//点数
		int score = 0;
		int scoresum = 100;
		int clearline = 1500;
		int twice = 1;

		//ダメージ
		int damage = 30;

		//HPデータ
		//座標
		int hpx = 1510;
		int hpy = 100;
		//ゲージ量
		int hp = 300;
		//高さ
		int h = 60;

		//画像データ
		int backgroundImg;
		int playerImg;
		int enemyImg;
		int bulletImg;
		int explosionImg;

		//音声データ
		int bulletsoundImg;
		int explosionsound;

		const int PLAY = 0;
		const int CLEAR = 1;
		const int OVER = 2;
		int State = PLAY;

		//以下はいじらないでよい
		int BackToMenuFlag=0;
	};

}

