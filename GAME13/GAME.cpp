#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include"player.h"
#include"GAME2.h"
//#include<random>
//#include"DxLibFile/DxLib.h"
#define ENEMY_SNUM 50

namespace GAME13 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！
	GAME::GAME(MANAGER* manager)
	{
		/*
		GAME2 game;
		game.run();
		*/

		window(1920, 1080);
		
		Img = loadImage("../game13/assets/unkoWhite.png");
		playerImg[0] = loadImage("../game13/assets/King_w.png");
		playerImg[1] = loadImage("../game13/assets/Pawn_w.png");
		playerImg[2] = loadImage("../game13/assets/Rook_w.png");
		playerImg[3] = loadImage("../game13/assets/Knight_w.png");
		playerImg[4] = loadImage("../game13/assets/Bishop_w.png");
		playerImg[5] = loadImage("../game13/assets/Queen_w.png");


		enemyImg[0] = loadImage("../game13/assets/King_b.png");
		enemyImg[1] = loadImage("../game13/assets/Pawn_b.png");
		enemyImg[2] = loadImage("../game13/assets/Rook_b.png");
		enemyImg[3] = loadImage("../game13/assets/Knight_b.png");
		enemyImg[4] = loadImage("../game13/assets/Bishop_b.png");
		enemyImg[5] = loadImage("../game13/assets/Queen_b.png");

		

		Diameter = 200;

		Px[0] = 128;
		Px[1] = 256;
		for (int i = 0; i < 6; i++) {
			Py[i] = height - 128;
		}
		limmitPy = Py[0];
		Pvx[0] = 20;
		Pvx[1] = 1;
		initvy = -50;
		gravity = 2;
		jumpFlag = 0;
		Php[0] = hpMax;
		limmitPx = 0;;

		Pdx = 0;
		Pdy = 0;
		Pw = PimgW /  2;
		Ph = PimgH;

		Pdx2 = 0;
		Pdy2 = 0;
		Pw2 = PimgW / 2;
		Ph2 = PimgH;


		



		//当たり判定用
		Pleft = Px[0] + Pdx;
		Pright = Pleft + Pw;
		Ptop = Py[0] + Pdy;
		Pbottom = Ptop + Ph;

		Pleft2 = Px[1] + Pdx2;
		Pright2 = Pleft2 + Pw2;
		Ptop2 = Py[1] + Pdy2;
		Pbottom2 = Ptop2 + Ph2;

		Eleft = Ex[0] + Edx;
		Eright = Eleft + Ew;
		Etop = Ey[0] + Edy;
		Ebottom = Etop + Eh;

		Eleft2 = Ex[1] + Edx2;
		Eright2 = Eleft2 + Ew2;
		Etop2 = Ey[1] + Edy2;
		Ebottom2 = Etop2 + Eh2;



		//bullet
		bx = Px[0];
		by = Py[0];
		bflag = 0;
		bhp = 0;
		bw = 40;
		bh = 20;
		bvx = 5;
		shotNUM = 20;


		/*
		pawnHp = 10;
		bishopHp = 30;
		rookHp = 80;
		knightHp = 50;
		queenHp = 100;
		*/

		//Ex[0] = 800;
		//Ey[0] = 0;
		Ex[0] = width - 256;
		Ey[0] = height -128;
		Evx[0] = 20;
		Ehp = hpMax;
		
		Ex[1] = Ex[0];
		Ey[1] = Ey[0];
		//ebullet
		eFlag = 0;
		ebx = Ex[0];
		eby = Ey[0];
		ebw = 60;
		ebh = 30;
		evx = 10;
		evx2 = 25;

		Edx = 0;
		Edy = 0;
		Ew = EimgW / 2;
		Eh = EimgH;

		Edx2 = 15;
		Edy2 = 0;
		Ew2 = EimgW /2;
		Eh2 = EimgH;




		ecount = 0;
		scount = 0;

		edeadflag = 0;
		sflag = 0;

		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();


	}
		
	GAME::~GAME()
	{
		


	}

	void GAME::proc(MANAGER* manager)
	{
		



			//更新

			if (Px[0] > limmitPx && isPress(KEY_A)) {
				Px[0] -= Pvx[0];
			}

			if (Px[0] < width / 2 - 256 / 2 && isPress(KEY_D)) {

				Px[0] += Pvx[0];
			}
			if (jumpFlag == 0) {
				if (isTrigger(KEY_SPACE)) {
					Pvy[0] = initvy;
					jumpFlag = 1;
				}
			}
			if (jumpFlag == 1) {
				Py[0] += Pvy[0];
				Pvy[0] += gravity;
				if (Py[0] > limmitPy) {
					Py[0] = limmitPy;
					jumpFlag = 0;
				}
			}

			

			//Ex[0] += Evx[0];



			//damege
			if (Pright > Eleft2 && Eright2 > Pleft && Pbottom < Etop2 && Ebottom2 < Ptop) {
				//Php[0] -= 0;
				Php[0] -= Eattack;
				clear(255, 0, 0);
			}
			/*
			else {
				Php[0] -= Eattack;
				clear(255, 0, 0);
			}
			*/


			//描画
			/*
			if (isTrigger(KEY_B)) {
				if (bhp == 0) {
					bhp = 1;
					bx = Px[0];
					by = Py[0];
				}
			}
			if (bhp > 0) {
				bx += bvx;
			}

			if (isTrigger(KEY_B)) {
				for (int i = 0; shotNUM; ++i) {
					if (bflag == 0) {
						bflag = 1;
						bx = Px[0];
						by = Py[0];
						break;
					}

				}
			}
			*/


			if (isTrigger(KEY_V)) {
				for (int i = 0; shotNUM; ++i) {
					if (pawnFlag == 0) {
						pawnFlag = 1;
						Px[1] = Px[0];
						Py[1] = Py[0];
						break;
					}

				}
			}

			/*
			int flag = 0;
			int rex = 500;
			int rey = 500;
			int rew = 100;
			int reh = 100;
			if (isTrigger(KEY_R)) {
				if (flag == 0) {
					for (int i = rex; i < 1980; i = rex) {
						fill(125);
						rect(rex, rey, rew, reh);
						rex += 30;
					}
				}
			}
			if (bhp > 0) {
				fill(125);
				rect(bx, by, bw, bh);
			}
			*/

			//弾移動
			/*
			for (int i = 0; i < shotNUM; ++i) {
				if (bflag) {
					bx += bvx;
					if (bx > 1980) {
						bflag = 0;
					}
				}
			}
			*/
			//弾移動
			for (int i = 0; i < shotNUM; ++i) {
				if (pawnFlag) {
					Px[1] += Pvx[1];
					if (Px[1] > 1980) {
						pawnFlag = 0;
					}
				}
			}
			/*
			for (int i = 0; i < ENEMY_SNUM; ++i) {
				if (eFlag) {
					ebx -= evx;
					if (evx < 0) {
						eFlag = 0;
					}
				}
			}
			*/

			for (int i = 0; i < shotNUM; ++i) {
				if (pawnFlag) {
					
					image(playerImg[1], Px[1], Py[1]);
				}
			}
			/*
			for (int i = 0; i < shotNUM; ++i) {
				if (bflag) {
					rect(bx, by, bw, bh);
					//image(playerImg[1], bx, by);
				}
			}

			for (int i = 0; i < ENEMY_SNUM; ++i) {
				if (eFlag == 1) {
					image(enemyImg[1], Ex[1], Ey[1]);
				}
			}
			*/

			playerbX = Px[1];
			playerbY = Py[1];
			playerbW = PimgW;
			playerbH = PimgH;

			enemyX = Ex[0];
			enemyY = Ey[0];
			enemyW = EimgW;
			enemyH = EimgH;


			if (((Px[1] > Ex[0] && Px[1] < Ex[0] + enemyW) ||
				(Ex[0] > Px[1] && Ex[0] < Px[1] + playerbW)) &&
				((Py[1] > Ey[0] && Py[1] < Ey[0] + enemyH) ||
					(Ey[0] > Py[1] && Ey[0] < Py[1] + playerbH))) {

				clear(255, 0, 0);
			}

			/*
			if (((playerbX > enemyX && playerbX < enemyX + enemyW) ||
				(enemyX > playerbX && enemyX < playerbX + playerbW)) &&
				((playerbY > enemyY && playerbY < enemyY + enemybH) ||
					(enemyY > playerbY && enemyY < playerbY + playerH))) {

				clear(255, 0, 0);
			}
			*/
			float distance = PimgW / 2 + EimgW;
			float sqDistance = distance * distance;

			int Pcount = 0;

			playerbL = Px[1];
			playerbR = Px[1] + playerW;
			playerbT = Py[1];
			playerbB = Py[1] + playerH;
			enemyL = Ex[0];
			enemyR = Ex[0] + enemyW;
			enemyT = Ey[0];
			enemyB = Ey[0] + enemyH;

			if (playerbB > enemyT &&
				playerbL < enemyR &&
				playerbR > enemyL &&
				playerbT < enemyB)
			{
				
				if (EdameFlag ==0 && Pcount == 0) {

					EdameFlag = 1;
				}
				/*
				if (EdameFlag == 0)
					EdameFlag = 1;
					Ehp -= Pattack;
				if(EdameFlag == 1)
				clear(255, 0, 0);
				Ehp -= Pattack;
				if (pawnFlag == 0) {
					EdameFlag = 0;
				}
				*/
			

			}
			else {
				EdameFlag = 0;
			}

			if (EdameFlag == 1) {
				Pcount = 30;
				Ehp -= Pattack;
				EdameFlag = 2;
				
			}
			if (Pcount > 0) {
				--Pcount;
				if (Pcount <= 0) {
					Pcount = 0;
					EdameFlag = 0;

				}
			}

			int Ecount = 0;
			 
			playerL = Px[0];
			playerR = Px[0] + playerW;
			playerT = Py[0];
			playerB = Py[0] + playerH;
			enemybL = Ex[1];
			enemybR = Ex[1] + enemyW;
			enemybT = Ey[1];
			enemybB = Ey[1] + enemyH;

			if (playerB > enemybT &&
				playerL < enemybR &&
				playerR > enemybL &&
				playerT < enemybB)
			{
				if (PdameFlag == 0 && Ecount == 0) {

					PdameFlag = 1;
				}
				
			}
			else {
				PdameFlag = 0;
			}

			if (PdameFlag == 1) {
				Ecount = 30;
				Php[0] -= Eattack;
				PdameFlag = 2;

			}
			if (Ecount > 0) {
				--Ecount;
				if (Ecount <= 0) {
					Ecount = 0;
					PdameFlag = 0;

				}
			}





			if (isTrigger(KEY_P)) {
				Php[0] -= Eattack;
			}
			if (isTrigger(KEY_E)) {
				Ehp -= Pattack;
			}


			
			playerX = Px[0];
			playerY = Py[0];
			playerW = PimgW;
			playerH = PimgH;

			enemybX = Ex[1];
			enemybY = Ey[1];
			enemybW = EimgW;
			enemybH = EimgH;


			
				

			/*

			//当たり判定
			if (((playerX < enemybX && playerX > enemybX + enemybW) ||
				(enemybX < playerX && enemybX > playerX + playerW)) &&
				((playerY < enemybY && playerY > enemybY + enemybH) ||
					(enemybY< playerY && enemybY > playerX + playerH))) {
				//当たり
				Php[0] -= Eattack;
				clear(255, 0, 0);
			}
			

			x*/


			
			/*
			for (int i = 0; i < ENEMY_SNUM; ++i) {
				if (eFlag) {
					rect(ebx, eby, ebw, ebh);
				}
			}
			*/
			

			clear(25);
			rectMode(CENTER);
			printf("%d",Php[0]);

			image(playerImg[0], Px[0], Py[0]);
		
			
			//image(playerImg[1], Px[1], Py[1]);
			image(enemyImg[1], Ex[1], Ey[1]);
			//image(enemyImg[2], Ex[2], Ey[2]);
			if (pawnFlag == 1) {
				image(playerImg[1], Px[1], Py[1]);
			}
			/*
			int eJcount = 0;
			int eJFlag = 0;
			if (eJcount < 10000) {
				eJcount++;
				if (eJcount % 50 == 0) {
					Evy[1] = initvy;
					eJFlag = 1;
				}
				if (eJFlag == 1) {
					Ey[1] += Evy[1];
					Evy[1] += gravity;
					if (Ey[1] > limmitPy) {
						Ey[1] = limmitPy;
						eJFlag = 0;
					}
				}

			}

			*/
				Ex[1] -= evx2;
				if (Php[0] > 0 || Ehp > 0) {

					if (Ex[1] < -256) {
						Ex[1] = 1980;
						if (Php[0] <= 0 || Ehp <= 0) {
							Ex[1] = 0 - EimgW;
						}

					}
				}
			
			image(enemyImg[0], Ex[0], Ey[0]);

			//fill(68, 42, 129,128);
			//rect(Px[0]  + Pdx, Py[0] + Pdy, Pw,Ph);
			//fill(0,255,0,128);
			//rect(Px[1] + Pdx2, Py[1] + Pdy2, Pw2, Ph2);

			//rect(Ex[0] + Edx, Ey[0] + Edy, Ew, Eh);
			//rect(Ex[1] + Edx2, Ey[1] + Edy2, Ew2, Eh2);

			//HP表示
			fill(0, 255, 0, 128);
			rect(phpx, phpy, Php[0], phph);

			//enemyHP表示
			fill(255, 0, 0, 128);
			rect(ehpx, ehpy, Ehp, ehph);

			
			 
			 
			

			

			//円が右に消えたらゲームオーバーとする
			if (Php[0] <=  0 || Ehp <=  0) {

				//表示
				rectMode(CENTER);
				//image(Img, width / 2, height / 2);

				if (Ehp <=  0) {
					fill(255, 255, 0);
					textSize(200);
					text("Game Clear", 500, 100);
					textSize(60);
					text("Enterでメニューに戻る", 600, 800);
				}
				if (Php[0] <=  0) {
					//文字表示
					//fill(255, 0, 0);
					fill(255, 0, 0);

					textSize(200);
					text("Game Over", 500, 100);
					textSize(60);
					text("Enterでメニューに戻る", 600, 800);
				}
				//メニューに戻る
				if (isTrigger(KEY_ENTER)) {
					BackToMenuFlag = 1;
				}
			}
		
		//メニューに戻る (基本的に以下はいじらなくてよい)
		manager->fade->draw();
		if (BackToMenuFlag == 1) {
			manager->fade->fadeOutTrigger();
			if (manager->fade->fadeOutEndFlag()) {
				delete manager->state;
				manager->state = new MENU(manager);
			}
		}
	}
}

