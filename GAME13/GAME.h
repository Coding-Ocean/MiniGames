#pragma once
#include"../MAIN/STATE.h"
#include "GAME_OBJECT.h"
#include "../libOne/inc/libOne.h"

namespace GAME13 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！



	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//ここに必要な記憶場所を用意する
		//画像表示用
		int Img;
		int playerImg[6];
		int enemyImg[6];
		//円表示用
		float Diameter;//直径
		int hpMax = 300;

		float Px[6];
		float Py[6];
		float Pvx[6];
		float Pvy[6];
		float initvy;
		float limmitPy;
		float limmitPx;

		int Php[6];
		float phpx = 200;
		float phpy = 100;
		float phph = 60;

		float ehpx = width - 200;
		float ehpy = 100;
		float ehph = 60;

		float PimgW = 256;
		float PimgH = 256;

		int Pattack = 50;
		int Eattack = 100;


		float Pdx = 0;
		float Pdy = 0;
		float Pw = 0;
		float Ph = 0;

		float Pleft = 0;
		float Pright = 0;
		float Ptop = 0;
		float Pbottom = 0;

		float Pdx2 = 0;
		float Pdy2 = 0;
		float Pw2 = 0;
		float Ph2 = 0;

		float Pleft2 = 0;
		float Pright2 = 0;
		float Ptop2 = 0;
		float Pbottom2 = 0;

		int pawnFlag = 0;


		float Ex[6];
		float Ey[6];
		float Evx[6];
		float Evy[6];
		int Ehp;
		float EimgW = 256;
		float EimgH = 256;

		float Edx = 0;
		float Edy = 0;
		float Ew = 0;
		float Eh = 0;

		float Edx2 = 0;
		float Edy2 = 0;
		float Ew2 = 0;
		float Eh2 = 0;

		float Eleft = 0;
		float Eright = 0;
		float Etop = 0;
		float Ebottom = 0;

		float Eleft2 = 0;
		float Eright2 = 0;
		float Etop2 = 0;
		float Ebottom2 = 0;

		float gravity;
		int jumpFlag;
		

		

		//int bullet;
		float bx;
		float by;
		int bhp;
		int bw;
		int bh;
		float bvx;

		/*
		int pawnHp;
		int bishopHp;
		int rookHp;
		int knightHp;
		int queenHp;
		*/
		int shotNUM ;
		int bflag;

		//enemybullet
		int eFlag;
		float ebx;
		float eby;
		int ebw;
		int ebh;
		float evx;
		float evx2;

		int ecount;

		int e_pattern;
		int eb_pattern;
		int estype;

		int edeadflag;

		int sflag;
		int scount;

		int time = 0;


		//当たり判定
		//p
		float playerX;
		float playerY;
		float playerW;
		float playerH;
		//p b
		float playerbX;
		float playerbY;
		float playerbW;
		float playerbH;

		//e
		float enemyX;
		float enemyY;
		float enemyW;
		float enemyH;

		//e b
		float enemybX;
		float enemybY;
		float enemybW;
		float enemybH;

		//当たり判定用
		float playerbL;
		float playerbR;
		float playerbT;
		float playerbB;
		float enemyL;
		float enemyR;
		float enemyT;
		float enemyB;
		int EdameFlag = 0;


		float playerL;
		float playerR;
		float playerT;
		float playerB;
		float enemybL;
		float enemybR;
		float enemybT;
		float enemybB;
		int PdameFlag = 0;

		
		float invincibleTime;
		float invincibleRrestTime;

		//以下はいじらないでよい
		int BackToMenuFlag=0;
	};

	

}

