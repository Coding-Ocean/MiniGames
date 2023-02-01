#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include <time.h>
namespace GAME21 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		initDeltaTime();
		srand((unsigned)time(NULL));

		iwaAImg = loadImage("../game21/assets/blockA.png");
		iwaBImg = loadImage("../game21/assets/blockB.png");
		iwaCImg = loadImage("../game21/assets/blockC.png");
		eftImg = loadImage("../game21/assets/efect.png");

		time0Img = loadImage("../game21/assets/0.png");
		time1Img = loadImage("../game21/assets/1.png");
		time2Img = loadImage("../game21/assets/2.png");
		time3Img = loadImage("../game21/assets/3.png");
		time4Img = loadImage("../game21/assets/4.png");
		time5Img = loadImage("../game21/assets/5.png");
		time6Img = loadImage("../game21/assets/6.png");
		time7Img = loadImage("../game21/assets/7.png");
		time8Img = loadImage("../game21/assets/8.png");
		time9Img = loadImage("../game21/assets/9.png");

		TbackImg = loadImage("../game21/assets/haikei2.png");
		PbackImg = loadImage("../game21/assets/haikei3.png"); 
		RbackImg = loadImage("../game21/assets/haikei8.png");

		toolImg = loadImage("../game21/assets/unkoZ.png");


		
		

		int r = 0;

		TbtnPx = 1600;
		TbtnEPy = 400;
		TbtnOfsY = 150;
		TbtnW = 400;
		TbtnH = 100;

	
		init();

		



		/*
		Img = loadImage("../game21/assets/unkoWhite.png");

		Diameter = 200;
		Px = width/2;
		Py = 0;
		Vx = 2;
		Vy = 2;
		*/
		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{

	}

	void GAME::proc(MANAGER* manager)
	{
		setDeltaTime();
		update();
		draw();

		/*
		//更新
		Py += Vy ;

		//描画
		clear(200);
		circle(Px, Py, Diameter);
		
		//円が右に消えたらゲームオーバーとする
		if (Py > height) {
			//うんこ表示
			rectMode(CENTER);
			image(Img, width / 2, height / 2);
			//文字表示
			fill(255, 0, 0);
			textSize(200);
			text("Game Over", 500, 100);
			textSize(60);
			text("Enterでメニューに戻る", 600, 800);
			//メニューに戻る
			if (isTrigger(KEY_ENTER)) {
				BackToMenuFlag = 1;
			}
			
		}

		//メニューに戻る (基本的に以下はいじらなくてよい)
	*/
		manager->fade->draw();
		if (BackToMenuFlag == 1) {
			stroke(0);
			manager->fade->fadeOutTrigger();
			if (manager->fade->fadeOutEndFlag()) {
				delete manager->state;
				manager->state = new MENU(manager);
			}
		}
	}

	void GAME::init()
	{
		


		PtxtASize = 150;
		PtxtAPx = width / 2;
		PtxtAPy = 700;

		PtimeE = 20;
		PtimeN = 20;
		PtimeH = 30;
		ProckE = 20;
		ProckN = 30;
		ProckH = 60;

		PtimePx = 50;
		PtimeOfsX = 100;
		PtimePy = 50;

		PtimerPx = width / 2 - 300;
		PtimerPy = height / 2;

		Prock = 0;

		Pcnt = -1;

		toolang = -90;

		ProckPx = width / 2 - 200;
		ProckPy = height - 500;
		ProckOfsY = 400;

		PeffectPx = width / 2;
		PeffectPy = height - 300;

		toolPx = 0;
		toolPy = 0;

		for (int i = 0; i < 60
			; i++) {
			ProcksPy[i] = height - 300 - 400 * i;
		}

		for (int i = 0; i < 60; i++) {
			ProcksState[i] = 'a';
		}

		startFlag = 0;

		

	}

	void GAME::update()
	{
		if (dispFlag == 0) {


			rectMode(CENTER);
			image(TbackImg, width / 2, height / 2);

			if (MouseX > TbtnPx - TbtnW / 2 && MouseX< TbtnPx + TbtnW / 2 &&
				MouseY>TbtnEPy - TbtnH / 2 && MouseY < TbtnEPy + TbtnH / 2) {

				

				if (isTrigger(MOUSE_LBUTTON)) {
					ENHFlag = 0;
					Ptime = PtimeE;
					Prock = ProckE;
					dispFlag = 1;
					startFlag = 0;
					int BUF = rand();
					if (BUF % 50 == 0) PbackImg = loadImage("../game21/assets/haikei2.png");
					else if (BUF % 50 <= 5) PbackImg = loadImage("../game21/assets/haikei3.png");
					else if (BUF % 50 <= 10) PbackImg = loadImage("../game21/assets/haikei4.png");
					else if (BUF % 50 <= 25) PbackImg = loadImage("../game21/assets/haikei5.png");
					else if (BUF % 50 <= 49) PbackImg = loadImage("../game21/assets/haikei6.png");

				}
			}
			else if (MouseX > TbtnPx - TbtnW / 2 && MouseX< TbtnPx + TbtnW / 2 &&
				MouseY>TbtnEPy + TbtnOfsY - TbtnH / 2 && MouseY < TbtnEPy + TbtnOfsY + TbtnH / 2) {
				if (isTrigger(MOUSE_LBUTTON)) {
					ENHFlag = 1;
					Ptime = PtimeN;
					Prock = ProckN;
					dispFlag = 1;
					startFlag = 0;
					int BUF = rand();
					if (BUF % 50 == 0) PbackImg = loadImage("../game21/assets/haikei2.png");
					else if (BUF % 50 <= 5) PbackImg = loadImage("../game21/assets/haikei3.png");
					else if (BUF % 50 <= 10) PbackImg = loadImage("../game21/assets/haikei4.png");
					else if (BUF % 50 <= 25) PbackImg = loadImage("../game21/assets/haikei5.png");
					else if (BUF % 50 <= 49) PbackImg = loadImage("../game21/assets/haikei6.png");

				}
			}
			else if (MouseX > TbtnPx - TbtnW / 2 && MouseX< TbtnPx + TbtnW / 2 &&
				MouseY>TbtnEPy + TbtnOfsY * 2 - TbtnH / 2 && MouseY < TbtnEPy + TbtnOfsY * 2 + TbtnH / 2) {
				if (isTrigger(MOUSE_LBUTTON)) {
					ENHFlag = 2;
					Ptime = PtimeH;
					Prock = ProckH;
					dispFlag = 1;
					startFlag = 0;
					int BUF = rand();
					if (BUF % 50 == 0) PbackImg = loadImage("../game21/assets/haikei2.png");
					else if (BUF % 50 <= 5) PbackImg = loadImage("../game21/assets/haikei3.png");
					else if (BUF % 50 <= 10) PbackImg = loadImage("../game21/assets/haikei4.png");
					else if (BUF % 50 <= 25) PbackImg = loadImage("../game21/assets/haikei5.png");
					else if (BUF % 50 <= 49) PbackImg = loadImage("../game21/assets/haikei6.png");

				}
			}
			else if (MouseX > TbtnPx - TbtnW / 2 && MouseX < TbtnPx + TbtnW / 2 &&
				MouseY>TbtnEPy + TbtnOfsY * 4 - TbtnH / 2 && MouseY < TbtnEPy + TbtnOfsY * 4 + TbtnH / 2) {
				if (isTrigger(MOUSE_LBUTTON)) {
					BackToMenuFlag = 1;
				}
			}


		}
		else if (dispFlag == 1) {



			if (isTrigger(MOUSE_LBUTTON) && Pcnt == -1) {
				startFlag = 1;
				int BUF = rand();
				if (BUF % 100 == 0) toolImg = loadImage("../game21/assets/unkoZ.png");
				else if (BUF % 100 <= 5) toolImg = loadImage("../game21/assets/zyuuzikaA.png");
				else if (BUF % 100 <= 10) toolImg = loadImage("../game21/assets/toriA.png");
				else if (BUF % 100 <= 25) toolImg = loadImage("../game21/assets/club.png");
				else if (BUF % 100 <= 50) toolImg = loadImage("../game21/assets/eda3.png");
				else if (BUF % 100 <= 99) toolImg = loadImage("../game21/assets/unkoA.png");

				rectMode(CENTER);
				image(PbackImg, width / 2, height / 2, 0);



			}
			if (startFlag == 1) {
				if (Ptime > 0 && Pcnt < Prock * 5) {
					Ptime -= delta;
				}
				else if (Pcnt > Prock * 5) {
					clearFlag = 0;
					dispFlag = 2;
				}
				if (Ptime < 0) {
					Ptime = 0;
					clearFlag = 1;
					dispFlag = 2;
				}

				if (isTrigger(MOUSE_LBUTTON)) Pcnt++;
				if (isPress(KEY_T)) Pcnt++;



				if (Pcnt % 5 < 2) {
					if (Pcnt % 5 == 0 && Pcnt / 5 != 0)ProcksState[Pcnt / 5 - 1] = 'd';
					ProcksState[Pcnt / 5] = 'a';
				}
				else if (Pcnt % 5 < 4)ProcksState[Pcnt / 5] = 'b';
				else if (Pcnt % 5 < 5)ProcksState[Pcnt / 5] = 'c';

				if (Pcnt == Prock * 5) {
					ProcksState[Prock - 1] = 'd';
				}

				if (ProcksState[Pcnt / 5 - 1] == 'd' && ProcksPy[Pcnt / 5] < height - 300) {
					for (int i = 0; i < Prock; i++) {
						ProcksPy[i] += 25;
					}
				}

				if (ProcksPy[Pcnt / 5] > height - 300) {
					ProcksPy[Pcnt / 5] = height - 300;
				}


			}

		}
		else if (dispFlag == 2) {
			if (clearFlag == 0) {
				RbackImg=loadImage("../game21/assets/haikei8.png");
				rectMode(CENTER);
				image(RbackImg, width / 2, height / 2);

				fill(236, 215,222);
				textSize(70);
				text("スペースを押してね ", width / 2 - 315, height / 2 + 200);

				Ptimebuf = (int)(Ptime * 1000);
				switch (Ptimebuf % 10) {
				case 0:
					image(time0Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					break;
				case 1:
					image(time1Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 1;
					break;
				case 2:
					image(time2Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 2;
					break;
				case 3:
					image(time3Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 3;
					break;
				case 4:
					image(time4Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 4;
					break;
				case 5:
					image(time5Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 5;
					break;
				case 6:
					image(time6Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 6;
					break;
				case 7:
					image(time7Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 7;
					break;
				case 8:
					image(time8Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 8;
					break;
				case 9:
					image(time9Img, PtimerPx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 9;
					break;
				}
				Ptimebuf /= 10;


				switch (Ptimebuf % 10) {
				case 0:
					image(time0Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					break;
				case 1:
					image(time1Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 1;
					break;
				case 2:
					image(time2Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 2;
					break;
				case 3:
					image(time3Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 3;
					break;
				case 4:
					image(time4Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 4;
					break;
				case 5:
					image(time5Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 5;
					break;
				case 6:
					image(time6Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 6;
					break;
				case 7:
					image(time7Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 7;
					break;
				case 8:
					image(time8Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 8;
					break;
				case 9:
					image(time9Img, PtimerPx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 9;
					break;
				}
				Ptimebuf /= 10;


				switch (Ptimebuf % 10) {
				case 0:
					image(time0Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					break;
				case 1:
					image(time1Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 1;
					break;
				case 2:
					image(time2Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 2;
					break;
				case 3:
					image(time3Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 3;
					break;
				case 4:
					image(time4Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 4;
					break;
				case 5:
					image(time5Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 5;
					break;
				case 6:
					image(time6Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 6;
					break;
				case 7:
					image(time7Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 7;
					break;
				case 8:
					image(time8Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 8;
					break;
				case 9:
					image(time9Img, PtimerPx + PtimeOfsX * 2 + PtimeOfsX * 0.2f, PtimerPy, 0, 4);
					Ptimebuf -= 9;
					break;
				}
				Ptimebuf /= 10;


				switch (Ptimebuf % 10) {
				case 0:
					image(time0Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					break;
				case 1:
					image(time1Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 1;
					break;
				case 2:
					image(time2Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 2;
					break;
				case 3:
					image(time3Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 3;
					break;
				case 4:
					image(time4Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 4;
					break;
				case 5:
					image(time5Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 5;
					break;
				case 6:
					image(time6Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 6;
					break;
				case 7:
					image(time7Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 7;
					break;
				case 8:
					image(time8Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 8;
					break;
				case 9:
					image(time9Img, PtimerPx + PtimeOfsX, PtimerPy, 0, 4);
					Ptimebuf -= 9;
					break;
				}
				Ptimebuf /= 10;


				switch (Ptimebuf % 10) {
				case 1:
					image(time1Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 1;
					break;
				case 2:
					image(time2Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 2;
					break;
				case 3:
					image(time3Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 3;
					break;
				case 4:
					image(time4Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 4;
					break;
				case 5:
					image(time5Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 5;
					break;
				case 6:
					image(time6Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 6;
					break;
				case 7:
					image(time7Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 7;
					break;
				case 8:
					image(time8Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 8;
					break;
				case 9:
					image(time9Img, PtimerPx, PtimerPy, 0, 4);
					Ptimebuf -= 9;
					break;
				default:
					break;
				}
				Ptimebuf /= 10;

				if (isTrigger(KEY_SPACE)) {

					clearFlag = 2;
				}
			}
			else if (clearFlag == 1) {
				RbackImg=loadImage("../game21/assets/haikei9.png");
				rectMode(CENTER);
				image(RbackImg, width / 2, height / 2);

				fill(155,34,53);
				textSize(110);
				text("スペースを押してね ", width / 2 - 495, height / 2 );

			}

			if (isTrigger(KEY_SPACE)) {
				clearFlag = 2;
			}
		}
		if (clearFlag == 2) {

			if (isTrigger(KEY_SPACE)) {
				dispFlag = 0;
				Pcnt = 0;
				init();
			}
		}
	}
	void GAME::draw(){
		rectMode(CORNER);
		
		if (dispFlag == 0) {
			//image(titleImg, 0, 0);
			rectMode(CENTER);
			image(TbackImg, width / 2, height / 2);
			rectMode(CENTER);
			strokeWeight(3);
			textSize(80);
			stroke(200);
			fill(TbtnH, 250, TbtnH);
			rect(TbtnPx, TbtnEPy, TbtnW, TbtnH);
			fill(0);
			text("EASY",TbtnPx-80,TbtnEPy-40);
			fill(TbtnH, 250, 250);
			rect(TbtnPx, TbtnEPy+TbtnOfsY , TbtnW, TbtnH);
			fill(0);
			text("NORMAL",TbtnPx-120, TbtnEPy + TbtnOfsY-40);
			fill(250, TbtnH, TbtnH);
			rect(TbtnPx, TbtnEPy+TbtnOfsY*2, TbtnW, TbtnH);
			fill(0);
			text("HARD",TbtnPx-80, TbtnEPy + TbtnOfsY * 2-40);
			fill(TbtnH);
			rect(TbtnPx, TbtnEPy+TbtnOfsY*4, TbtnW, TbtnH);
			fill(255);
			text("HOUSE!",TbtnPx-120, TbtnEPy + TbtnOfsY * 4-40);

			

		}
		else if (dispFlag == 1) {
			//image(playImg, 0, 0);

			rectMode(CENTER);
			image(PbackImg, width / 2, height / 2, 0);


			rectMode(CORNER);

			if (startFlag == 0) {
				
				image(iwaCImg, ProckPx, ProckPy, 0, 8);
				image(iwaBImg, ProckPx, ProckPy- ProckOfsY, 0, 8);
				image(iwaAImg, ProckPx, ProckPy- ProckOfsY*2, 0, 8);
				

				textSize(PtxtASize);
				fill(0);
				text("crick to start",PtxtAPx-14/2*PtxtASize/2,PtxtAPy );

			}
			else if (startFlag == 1) {
				dispTime();
				rock();

			}

		

		}
		else if (dispFlag == 2) {
			//image(resultImg, 0, 0);
		}
	}
	void GAME::dispTime()
	{
		

		Ptimebuf = (int)(Ptime * 1000);
		switch (Ptimebuf % 10) {
		case 0:
			image(time0Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			break;
		case 1:
			image(time1Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 1;
			break;
		case 2:
			image(time2Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 2;
			break;
		case 3:
			image(time3Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 3;
			break;
		case 4:
			image(time4Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 4;
			break;
		case 5:
			image(time5Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 5;
			break;
		case 6:
			image(time6Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 6;
			break;
		case 7:
			image(time7Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 7;
			break;
		case 8:
			image(time8Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 8;
			break;
		case 9:
			image(time9Img, PtimePx + PtimeOfsX * 4 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 9;
			break;
		}
		Ptimebuf /= 10;


		switch (Ptimebuf % 10) {
		case 0:
			image(time0Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			break;
		case 1:
			image(time1Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 1;
			break;
		case 2:
			image(time2Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 2;
			break;
		case 3:
			image(time3Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 3;
			break;
		case 4:
			image(time4Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 4;
			break;
		case 5:
			image(time5Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 5;
			break;
		case 6:
			image(time6Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 6;
			break;
		case 7:
			image(time7Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 7;
			break;
		case 8:
			image(time8Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 8;
			break;
		case 9:
			image(time9Img,PtimePx + PtimeOfsX * 3 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 9;
			break;
		}
		Ptimebuf /= 10;


		switch (Ptimebuf % 10) {
		case 0:
			image(time0Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			break;
		case 1:
			image(time1Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 1;
			break;
		case 2:
			image(time2Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 2;
			break;
		case 3:
			image(time3Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 3;
			break;
		case 4:
			image(time4Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 4;
			break;
		case 5:
			image(time5Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 5;
			break;
		case 6:
			image(time6Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 6;
			break;
		case 7:
			image(time7Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 7;
			break;
		case 8:
			image(time8Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 8;
			break;
		case 9:
			image(time9Img, PtimePx+PtimeOfsX*2 + PtimeOfsX * 0.2f, PtimePy,0,4);
			Ptimebuf -= 9;
			break;
		}
		Ptimebuf /= 10;


		switch (Ptimebuf % 10) {
		case 0:
			image(time0Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			break;
		case 1:
			image(time1Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 1;
			break;
		case 2:
			image(time2Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 2;
			break;
		case 3:
			image(time3Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 3;
			break;
		case 4:
			image(time4Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 4;
			break;
		case 5:
			image(time5Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 5;
			break;
		case 6:
			image(time6Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 6;
			break;
		case 7:
			image(time7Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 7;
			break;
		case 8:
			image(time8Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 8;
			break;
		case 9:
			image(time9Img, PtimePx+PtimeOfsX, PtimePy,0,4);
			Ptimebuf -= 9;
			break;
		}
		Ptimebuf /= 10;


		switch (Ptimebuf % 10) {
		case 1:
			image(time1Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 1;
			break;
		case 2:
			image(time2Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 2;
			break;
		case 3:
			image(time3Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 3;
			break;
		case 4:
			image(time4Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 4;
			break;
		case 5:
			image(time5Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 5;
			break;
		case 6:
			image(time6Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 6;
			break;
		case 7:
			image(time7Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 7;
			break;
		case 8:
			image(time8Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 8;
			break;
		case 9:
			image(time9Img, PtimePx, PtimePy,0,4);
			Ptimebuf -= 9;
			break;
		default:
			break;
		}
		Ptimebuf /= 10;

	}
	void GAME::rock()
	{
		fill(0, 255, 0);

		rectMode(CENTER);

		for (int i = Prock-1; i +1 > Pcnt/5; i--) {
			if (ProcksState[i] == 'a') {
				image(eftImg, PeffectPx,PeffectPy, 0, 8);

				image(iwaAImg, width / 2, ProcksPy[i], 0, 8);
			}
			else if (ProcksState[i] == 'b')image(iwaBImg, width/2, ProcksPy[i], 0, 8);
			else if (ProcksState[i] == 'c')image(iwaCImg, width/2, ProcksPy[i], 0, 8);
			else if (ProcksState[i] == 'd')image(eftImg, width/2, ProcksPy[i], 0, 8);
		} 

		toolPx = width / 2 - 200 - 240 * Cos(toolang + 135);
		toolPy = height / 2 - 75 + 240 * Sin(toolang + 135);

		if (isTrigger(MOUSE_LBUTTON) && Pcnt ) {
			toolang = -90;
			MFlag = 1;
		}
		if (MFlag == 1) {
			toolang -= 18;
			if (toolang <= -135)MFlag = 2;
		}
		if (MFlag == 2) {
			toolang += 18;
			if (toolang >= -90) {
				toolang = -90;
				MFlag = 0;
			}
		}
		rectMode(CORNER);
		image(toolImg, toolPx, toolPy, toolang, 4);

		if (isTrigger(KEY_SPACE)) {
			ProcksState[0]++;
		}


	}
}