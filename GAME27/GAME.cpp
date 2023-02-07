#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include <time.h>
#include <math.h>
namespace GAME27 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		initDeltaTime();
		srand((unsigned)time(NULL));
		RWdata = roadData();


		//カード領域始点
		LTpos.x = 50;
		LTpos.y = 200;
		//カード領域終点
		RBpos.x = width - 50;
		RBpos.y = height - 80;
		//カード領域オフセット(両端)
		offset.x = 10;
		offset.y = 10;

		init();

		cardImg[0] = loadImage("../game27/assets/S1.png");
		cardImg[1] = loadImage("../game27/assets/S2.png");
		cardImg[2] = loadImage("../game27/assets/S3.png");
		cardImg[3] = loadImage("../game27/assets/S4.png");
		cardImg[4] = loadImage("../game27/assets/S5.png");
		cardImg[5] = loadImage("../game27/assets/S6.png");
		cardImg[6] = loadImage("../game27/assets/S7.png");
		cardImg[7] = loadImage("../game27/assets/S8.png");
		cardImg[8] = loadImage("../game27/assets/S9.png");
		cardImg[9] = loadImage("../game27/assets/S10.png");
		cardImg[10] = loadImage("../game27/assets/S11.png");
		cardImg[11] = loadImage("../game27/assets/S12.png");
		cardImg[12] = loadImage("../game27/assets/S13.png");

		cardImg[13] = loadImage("../game27/assets/C1.png");
		cardImg[14] = loadImage("../game27/assets/C2.png");
		cardImg[15] = loadImage("../game27/assets/C3.png");
		cardImg[16] = loadImage("../game27/assets/C4.png");
		cardImg[17] = loadImage("../game27/assets/C5.png");
		cardImg[18] = loadImage("../game27/assets/C6.png");
		cardImg[19] = loadImage("../game27/assets/C7.png");
		cardImg[20] = loadImage("../game27/assets/C8.png");
		cardImg[21] = loadImage("../game27/assets/C9.png");
		cardImg[22] = loadImage("../game27/assets/C10.png");
		cardImg[23] = loadImage("../game27/assets/C11.png");
		cardImg[24] = loadImage("../game27/assets/C12.png");
		cardImg[25] = loadImage("../game27/assets/C13.png");

		cardImg[26] = loadImage("../game27/assets/D1.png");
		cardImg[27] = loadImage("../game27/assets/D2.png");
		cardImg[28] = loadImage("../game27/assets/D3.png");
		cardImg[29] = loadImage("../game27/assets/D4.png");
		cardImg[30] = loadImage("../game27/assets/D5.png");
		cardImg[31] = loadImage("../game27/assets/D6.png");
		cardImg[32] = loadImage("../game27/assets/D7.png");
		cardImg[33] = loadImage("../game27/assets/D8.png");
		cardImg[34] = loadImage("../game27/assets/D9.png");
		cardImg[35] = loadImage("../game27/assets/D10.png");
		cardImg[36] = loadImage("../game27/assets/D11.png");
		cardImg[37] = loadImage("../game27/assets/D12.png");
		cardImg[38] = loadImage("../game27/assets/D13.png");

		cardImg[39] = loadImage("../game27/assets/H1.png");
		cardImg[40] = loadImage("../game27/assets/H2.png");
		cardImg[41] = loadImage("../game27/assets/H3.png");
		cardImg[42] = loadImage("../game27/assets/H4.png");
		cardImg[43] = loadImage("../game27/assets/H5.png");
		cardImg[44] = loadImage("../game27/assets/H6.png");
		cardImg[45] = loadImage("../game27/assets/H7.png");
		cardImg[46] = loadImage("../game27/assets/H8.png");
		cardImg[47] = loadImage("../game27/assets/H9.png");
		cardImg[48] = loadImage("../game27/assets/H10.png");
		cardImg[49] = loadImage("../game27/assets/H11.png");
		cardImg[50] = loadImage("../game27/assets/H12.png");
		cardImg[51] = loadImage("../game27/assets/H13.png");

		cardImg[52] = loadImage("../game27/assets/BACK.png");

		getSE = loadSound("../game27/assets/get.wav");
		failSE = loadSound("../game27/assets/fail.wav");
		turnSE = loadSound("../game27/assets/turn.wav");
		playBGM = loadSound("../game27/assets/BGM.wav");
		setVolume(playBGM, -500);

		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
	}

	void GAME::proc(MANAGER* manager)
	{
		setDeltaTime();

		switch (scene) {
		case TITLE: title(); break;
		case PLAY: play(); break;
		case RESULT: result(); break;
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

	void GAME::init() 
	{
		roadData();

	}
	
	bool GAME::roadData()
	{
		fopen_s(&fp, "../game27/Datas.txt", "r");
		if (fp != NULL) {
			fscanf_s(fp, "%d%d", &P1, &P2);
			if (P1 + P2 <= 26) {
				fclose(fp);
				return true;
			}
			else fclose(fp);
		}
		return false;
	}

	void GAME::title() 
	{
		if (toPlay.Color.a < 100) toStartAFlag = true;
		if (toPlay.Color.a > 250) toStartAFlag = false;
		if (toStartAFlag) toPlay.Color.a++;
		else toPlay.Color.a--;
		//描画
		clear(23, 94, 56);
		dispSTR(gameName);
		dispSTR(comp0);
		dispSTR(comp1);
		dispSTR(comp2);
		dispSTR(comp3);
		dispSTR(toPlay);
		dispSTR(toMenu);

		//戦績
		if (RWdata) {
			if (P1 < 10) { P1buf[0] = ' ';	P1buf[1] = 48 + P1;	P1buf[2] = '\0'; }
			else if (P1 < 20) { P1buf[0] = '1';	P1buf[1] = 48 + P1 % 10; P1buf[2] = '\0'; }
			else { P1buf[0] = '2';	P1buf[1] = 48 + P1 % 10;	P1buf[2] = '\0'; }
			if (P2 < 10) { P2buf[0] = ' ';	P2buf[1] = 48 + P2;	P2buf[2] = '\0'; }
			else if (P2 < 20) { P2buf[0] = '1';	P2buf[1] = 48 + P2 % 10; P2buf[2] = '\0'; }
			else { P2buf[0] = '2';	P2buf[1] = 48 + P2 % 10; P2buf[2] = '\0'; }
			
			dispSTR(lastData);
			dispSTR(hyphen);
			textSize(50);
			fill(255, 200, 200);
			text(P1buf, width - 7 * 50, height - 60);
			fill(200, 200, 255);
			text(P2buf, width - 3 * 50, height - 60);
		}

		//PLAYへ
		if (isTrigger(KEY_SPACE)) {
			//戦績リセット
			P1 = P2 = 0;
			P1buf[0] = P2buf[0] = ' ';
			P1buf[1] = P2buf[1] = '0';
			P1buf[2] = P2buf[2] = '\0';
			fstsnd = 1;
			//カードの位置決め
			int i = 0, j = 0, val = 0;
			for (i = 0; i < 52; i++) {
				do {
					val = rand() % 52;
					for (j = 0; j < i; j++)
						if (val == cards[j].posNo) break;
				} while (j < i);
				cards[i].posNo = val;
				cards[i].state = true; //裏
				cards[i].getFlag = true; //未取得
			}
			//座標の代入
			float w = RBpos.x - LTpos.x - offset.x * 2;
			float h = RBpos.y - LTpos.y - offset.y * 2;
			cardScale = (w - offset.x * 12) / 13 / 280;
			if (415 * cardScale > h) cardScale = (h - offset.y * 3) / 4 / 415;
			float intervalX = (w - offset.x * 12) / 13;
			float intervalY = (h - offset.y * 3) / 4;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 13; j++) {
					cards[i * 13 + j].x = LTpos.x + intervalX * j + offset.x * (j + 1);
					cards[i * 13 + j].y = LTpos.y + intervalY * i + offset.y * (i + 1);
				}
			}

			//シーン切り替え
			scene = PLAY;
			playLoopSound(playBGM);
		}
		//Menuへ
		if (isTrigger(KEY_M)) {
			BackToMenuFlag = 1;
		}
	}

	void GAME::play() 
	{
		//操作
		switch (fase) {
		case THINK:
			for (int i = 0; i < 52; i++) {
				if (onCard(cards[i].x, cards[i].y) && cards[i].getFlag && isTrigger(MOUSE_LBUTTON)) {
					playSound(turnSE);
					cards[i].state = false;
					no1 = cardImg[i];
					fase = FIRST;
				}
			}
			break;
		case FIRST:
			if (isTrigger(KEY_F)) {
				int i = 0;
				while (i < 52) {
					if (cards[i].getFlag && cards[i].state && cardImg[cards[no1].posNo] % 13 == cardImg[cards[i].posNo] % 13) {
						cards[i].state = false;
						no2 = cardImg[i];
						dispLimit = 3.5f;
						if (fstsnd == 1) {
							P1++;
							if (P1 < 10) { P1buf[0] = ' ';	P1buf[1] = 48 + P1;	P1buf[2] = '\0'; }
							else if (P1 < 20) { P1buf[0] = '1';	P1buf[1] = 48 + P1 % 10; P1buf[2] = '\0'; }
							else { P1buf[0] = '2';	P1buf[1] = 48 + P1 % 10;	P1buf[2] = '\0'; }
						}
						else {
							P2++;
							if (P2 < 10) { P2buf[0] = ' ';	P2buf[1] = 48 + P2;	P2buf[2] = '\0'; }
							else if (P2 < 20) { P2buf[0] = '1';	P2buf[1] = 48 + P2 % 10; P2buf[2] = '\0'; }
							else { P2buf[0] = '2';	P2buf[1] = 48 + P2 % 10; P2buf[2] = '\0'; }
						}
						fase = GET;
						break;
					}
					i++;
				}
			}
			for (int i = 0; i < 52; i++) {
				if (onCard(cards[i].x, cards[i].y) && cards[i].getFlag && cards[i].state && isTrigger(MOUSE_LBUTTON)) {
					playSound(turnSE);
					cards[i].state = false;
					no2 = cardImg[i];
					dispLimit = 3.5f;
					if (cardImg[cards[no1].posNo] % 13 == cardImg[cards[no2].posNo] % 13) {
						if (fstsnd == 1) {
							P1++;
							if (P1 < 10) { P1buf[0] = ' ';	P1buf[1] = 48 + P1;	P1buf[2] = '\0'; }
							else if (P1 < 20) { P1buf[0] = '1';	P1buf[1] = 48 + P1 % 10; P1buf[2] = '\0'; }
							else { P1buf[0] = '2';	P1buf[1] = 48 + P1 % 10;	P1buf[2] = '\0'; }
						}
						else {
							P2++;
							if (P2 < 10) { P2buf[0] = ' ';	P2buf[1] = 48 + P2;	P2buf[2] = '\0'; }
							else if (P2 < 20) { P2buf[0] = '1';	P2buf[1] = 48 + P2 % 10; P2buf[2] = '\0'; }
							else { P2buf[0] = '2';	P2buf[1] = 48 + P2 % 10; P2buf[2] = '\0'; }
						}
						playSound(getSE);
						fase = GET;
					}
					else {
						playSound(failSE);
						fase = FAIL;
					}
				}
			}
			break;
		case GET:
			cards[no1].getFlag = cards[no2].getFlag = false;
			if (P1 + P2 == 26) {
				if (dispLimit > 0) { dispLimit -= delta; break; }
				else {
					RWdata = saveData();
					scene = RESULT;
				}
			}
			fase = THINK;
			break;
		case FAIL:
			if (dispLimit > 0) dispLimit -= delta;
			else {
				fstsnd *= -1;
				if (fstsnd == 1) { Player1.Color = COLOR(255, 200, 200); Player2.Color = COLOR(50, 50, 105); }
				else { Player1.Color = COLOR(105, 50, 50); Player2.Color = COLOR(200, 200, 255); }
				fase = THINK;
				cards[no1].state = cards[no2].state = true;
			}
			break;
		}
		//描画
		clear(23, 94, 56);
		dispSTR(Player1);
		dispSTR(Player2);
		textSize(75);
		fill(0);
		text(P1buf, 80, 85);
		text(P2buf, width - 160, 85);
		for (int i = 0; i < 52; i++) {
			if(cards[i].state)image(cardImg[52], cards[i].x, cards[i].y, 0, cardScale);
			else image(cardImg[cards[i].posNo], cards[i].x, cards[i].y, 0, cardScale);
		}
		
	}

	void GAME::result() 
	{
		if (toTiTLE.Color.a < 100) toTitleAFlag = true;
		if (toTiTLE.Color.a > 250) toTitleAFlag = false;
		if (toTitleAFlag) toTiTLE.Color.a++;
		else toTiTLE.Color.a--;

		if (isTrigger(KEY_SPACE)) {scene = TITLE; stopSound(playBGM);}

		//描画
		clear(23, 94, 56);
		if (P1 > P2) dispSTR(P1Win);
		else if (P1 < P2) dispSTR(P2Win);
		else dispSTR(tieGame);
		dispSTR(toTiTLE);
		if (RWdata) {
			dispSTR(Ssave);
		}
		else dispSTR(Fsave);
	}

	bool GAME::saveData()
	{
		fopen_s(&fp, "../game27/Datas.txt", "w");
		if (fp != NULL) {
			fprintf_s(fp, "%d %d", P1, P2);
			fclose(fp);
			return true;
		}
		return false;
	}

	void GAME::dispSTR(STR s)
	{
		textSize(s.Size);
		fill(s.Color);
		text(s.Str, s.Px, s.Py);
	}

	bool GAME::onCard(float Cx, float Cy)
	{
		if (MouseX >= Cx && MouseX <= Cx + 280 * cardScale) {
			if (MouseY >= Cy && MouseY <= Cy + 415 * cardScale) {
				return true;
			}
		}
		return false;
	}
}