#include "../libOne/inc/libOne.h"
#include "time.h"
#include "math.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
namespace GAME18 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！
#define mag18(x, y) sqrt(x * x + y * y)
	GAME::GAME(MANAGER* manager)
	{
		srand((unsigned)time(NULL));
		backImg = loadImage("../game18/assets/back.png");
		/*ブラシ*/
		MBsize = 3;
		ABsize = 30;
		BrectHeadPos.x = 0;
		BrectHeadPos.y = 160;
		BpointHeadPos.x = 60;
		BpointHeadPos.y = 220;
		Bofs = 120;
		BtextPx = 51;
		BtextPy = 127;
		BkeyTextPx = 40;
		BkeyTextPy = 805;
		BkeyTextofsY = 25;
		BairTextPx = 40;
		BairTextPy = 962;
		BgraTextPx = 40;
		BgraTextPy = 1047;
		Sconcentration = 1;
		/*グラデーション*/
		HSVClr.r = 0;
		HSVClr.g = 0;
		HSVClr.b = 0;
		HSVspeed = 1;
		HSVpseudoH = 0;
		/*プリセットカラー*/
		PCPx = 1700;
		PCPy = 0;
		PCheadPy = 165;
		PCofs = 30;
		PCtextPx = PCPx + PCofs;
		PCtSize = 20;
		PCtShadow = (float)PCtSize / PCtSize;
		PCUIradius = 20;
		PCroop = 0;
		/*RGB色選択*/
		RGBr = RGBg = RGBb = 0;
		/*Flags*/
		paperFlag = 0;
		colorFlag = 0;
		MAFlag = 1;
		PEFlag = 0;
		RGBFlag = 0;
		PCisPointerFlag = 0;
		/*info*/
		ItSize = 20;
		IkeyBPx = 20;
		IkeyCPx = 250;
		IkeyEPx = 600;
		IkeyPy = 80;
		IBsizePx = 1100;
		IBsizePy = 80;
		IBsizeofsY = ItSize / 5;
		IB1stdigofsX = ItSize * 11;
		IB2nddigofsX = ItSize * 12;
		IB3rddigofsX = ItSize * 13;
		IclrRPx = 1470;
		IclrGPx = 1620;
		IclrBPx = 1770;
		IclrPy = 80;
		IclrofsY = ItSize / 5;
		IC1stdigofsX = ItSize * 3;
		IC2nddigofsX = ItSize * 4;
		IC3rddigofsX = ItSize * 5;
		IopePx = 400;
		IopePy = 150;
		IopeToolPx = 1150;
		IopeToolPy = 135;
		IresetPx = 1350;
		IresetPy = 1040;

		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();

	}

	GAME::~GAME()
	{
		stroke(0);
	}

	void GAME::proc(MANAGER* manager)
	{
		draw();
		update();
		if (BackToMenuFlag == 1) {
			manager->fade->draw();
			reset();
			stroke(0);
			manager->fade->fadeOutTrigger();
			if (manager->fade->fadeOutEndFlag()) {
				delete manager->state;
				manager->state = new MENU(manager);
			}
		}
	}

	void GAME::update()
	{
		//フラッグ管理
		if (BackToMenuFlag != 1) {
			back();
			//ブラシ選択
			if (isTrigger(KEY_B)) MAFlag *= -1;
			if (MouseX > 20 && MouseX < 230 && MouseY > 80 && MouseY < 110 && isTrigger(MOUSE_LBUTTON)) MAFlag *= -1;
			//ペン色選択
			if (isTrigger(KEY_C)) colorFlag++;
			if (MouseX > 250 && MouseX < 560 && MouseY > 80 && MouseY < 110 && isTrigger(MOUSE_LBUTTON)) colorFlag++;
			if (colorFlag % 3 == 0) picClr();
			else if (colorFlag % 3 == 1) setClr();
			else if (colorFlag % 3 == 2) graClr();
			//ペン・消しゴム選択
			if (isTrigger(KEY_E)) PEFlag++;
			if (MouseX > 600 && MouseX < 830 && MouseY > 80 && MouseY < 110 && isTrigger(MOUSE_LBUTTON)) PEFlag++;
			//ブラシサイズ選択
			setBsize();
			//エアブラシ濃度変更
			if (isTrigger(KEY_D)) Sconcentration++;
			if (MouseX > 30 && MouseX < 210 && MouseY > 962 && MouseY < 985 && isTrigger(MOUSE_LBUTTON)) Sconcentration++;
			if (Sconcentration > 5) Sconcentration = 1;
			//グラデーション速度
			if (isTrigger(KEY_G)) HSVspeed++;
			if (MouseX > 30 && MouseX < 210 && MouseY > 1047 && MouseY < 1070 && isTrigger(MOUSE_LBUTTON)) HSVspeed++;
			if (HSVspeed > 10) HSVspeed = 1;
			
			//メニューに戻る
			if (MouseX > 1885 && MouseY < 35 && isTrigger(MOUSE_LBUTTON)) {
				BackToMenuFlag = 1;
			}

			//画面
			dispInfo();
			//リセット
			if (isPress(KEY_R) && isTrigger(KEY_ENTER)) reset();
		}
	}
	void GAME::draw()
	{
		if (MouseX > 280 && MouseX < 1640 && MouseY > 255 && MouseY < 1025) {
			//消しゴム
			if (PEFlag % 5 == 0 && colorFlag % 3 == 0) currentClr = PCbuffClr;
			else if (PEFlag % 5 == 0 && colorFlag % 3 == 1) currentClr = RGBbuffClr;
			else if (PEFlag % 5 == 1) currentClr = TORINOKO;
			else if (PEFlag % 5 == 2) {
				currentClr.r = TORINOKO.r;
				currentClr.g = TORINOKO.g;
				currentClr.b = TORINOKO.b;
				currentClr.a = 63;
			}
			else if (PEFlag % 5 == 3) {
				currentClr.r = TORINOKO.r;
				currentClr.g = TORINOKO.g;
				currentClr.b = TORINOKO.b;
				currentClr.a = 127;
			}
			else if (PEFlag % 5 == 4) {
				currentClr.r = TORINOKO.r;
				currentClr.g = TORINOKO.g;
				currentClr.b = TORINOKO.b;
				currentClr.a = 191;
			}
			stroke(currentClr);
			//ペン
			if (MAFlag == 1) {
				strokeWeight(MBsize);
				if (isPress(MOUSE_LBUTTON) && !isPress(KEY_SHIFT) && !isPress(KEY_R) && !isPress(KEY_T) && !isPress(KEY_F)) {
					if (drawingFlag == 0) {
						pastPx = MouseX;
						pastPy = MouseY;
						drawingFlag = 1;
					}
					else {
						line(pastPx, pastPy, MouseX, MouseY);
						pastPx = MouseX;
						pastPy = MouseY;
					}
				}
				else {
					drawingFlag = 0;
				}
				//定規
				if (isPress(KEY_R) && isPress(MOUSE_LBUTTON) && isRuler == 0) {
					isRuler += 0.0001f;
					point(MouseX, MouseY);
					startPx = MouseX;
					startPy = MouseY;
				}
				if (isPress(KEY_R) && isPress(MOUSE_LBUTTON) && isRuler != 0) isRuler += 0.0001f;
				if ((!isPress(KEY_R) || !isPress(MOUSE_LBUTTON)) && isRuler != 0) {
					isRuler = 0;
					endPx = MouseX;
					endPy = MouseY;
					line(startPx, startPy, endPx, endPy);
				}
				//円
				if (isPress(KEY_T) && isPress(MOUSE_LBUTTON) && isCircle == 0) {
					isCircle += 0.0001f;
					topPy = bottomPy = MouseY;
					rightPx = leftPx = MouseX;
				}
				if (isPress(KEY_T) && isPress(MOUSE_LBUTTON) && isCircle != 0) {
					isCircle += 0.0001f;
					if (MouseY < topPy) topPy = MouseY;
					if (MouseY > bottomPy) bottomPy = MouseY;
					if (MouseX < leftPx) leftPx = MouseX;
					if (MouseX > rightPx) rightPx = MouseX;
				}
				if ((!isPress(KEY_T) || !isPress(MOUSE_LBUTTON)) && isCircle != 0) {
					isCircle = 0;
					float Px = (leftPx + rightPx) / 2;
					float Py = (topPy + bottomPy) / 2;
					float D = ((rightPx - leftPx) + (bottomPy - topPy)) / 2.15f;
					fill(0, 0, 0, 0);
					circle(Px, Py, D);
				}
				//円(塗りつぶし)
				if (isPress(KEY_SHIFT) && isPress(KEY_T) && isPress(MOUSE_LBUTTON) && isCircleF == 0) {
					isCircleF += 0.0001f;
					topPy = bottomPy = MouseY;
					rightPx = leftPx = MouseX;
				}
				if (isPress(KEY_T) && isPress(MOUSE_LBUTTON) && isCircleF != 0) {
					isCircleF += 0.0001f;
					if (MouseY < topPy) topPy = MouseY;
					if (MouseY > bottomPy) bottomPy = MouseY;
					if (MouseX < leftPx) leftPx = MouseX;
					if (MouseX > rightPx) rightPx = MouseX;
				}
				if ((!isPress(KEY_T) || !isPress(MOUSE_LBUTTON)) && isCircleF != 0) {
					isCircleF = 0;
					float Px = (leftPx + rightPx) / 2;
					float Py = (topPy + bottomPy) / 2;
					float D = ((rightPx - leftPx) + (bottomPy - topPy)) / 2.15f;
					fill(currentClr);
					circle(Px, Py, D);
				}
				//四角形
				if (isPress(KEY_F) && isPress(MOUSE_LBUTTON) && isRect == 0) {
					isRect += 0.0001f;
					topPy = bottomPy = MouseY;
					rightPx = leftPx = MouseX;
				}
				if (isPress(KEY_F) && isPress(MOUSE_LBUTTON) && isRect != 0) {
					isRect += 0.0001f;
					if (MouseY < topPy) topPy = MouseY;
					if (MouseY > bottomPy) bottomPy = MouseY;
					if (MouseX < leftPx) leftPx = MouseX;
					if (MouseX > rightPx) rightPx = MouseX;
				}
				if ((!isPress(KEY_F) || !isPress(MOUSE_LBUTTON)) && isRect != 0) {
					isRect = 0;
					float Px = leftPx + (rightPx - leftPx) * 0.025f;
					float Py = topPy + (bottomPy - topPy) * 0.025f;
					float W = (rightPx - leftPx) * 0.95f;
					float H = (bottomPy - topPy) * 0.95f;
					fill(0, 0, 0, 0);
					rectMode(CORNER);
					rect(Px, Py, W, H);
				}
				//四角形(塗りつぶし)
				if (isPress(KEY_SHIFT) && isPress(KEY_F) && isPress(MOUSE_LBUTTON) && isRectF == 0) {
					isRectF += 0.0001f;
					topPy = bottomPy = MouseY;
					rightPx = leftPx = MouseX;
				}
				if (isPress(KEY_F) && isPress(MOUSE_LBUTTON) && isRectF != 0) {
					isRectF += 0.0001f;
					if (MouseY < topPy) topPy = MouseY;
					if (MouseY > bottomPy) bottomPy = MouseY;
					if (MouseX < leftPx) leftPx = MouseX;
					if (MouseX > rightPx) rightPx = MouseX;
				}
				if ((!isPress(KEY_F) || !isPress(MOUSE_LBUTTON)) && isRectF != 0) {
					isRectF = 0;
					float Px = leftPx + (rightPx - leftPx) * 0.025f;
					float Py = topPy + (bottomPy - topPy) * 0.025f;
					float W = (rightPx - leftPx) * 0.95f;
					float H = (bottomPy - topPy) * 0.95f;
					fill(currentClr);
					rectMode(CORNER);
					rect(Px, Py, W, H);
				}
			}
			//スプレー
			else if (MAFlag == -1) {
				strokeWeight(1);
				if (isPress(MOUSE_LBUTTON) && !isPress(KEY_R)) {
					for (int i = 0; i < 2 * Sconcentration * ABsize; i++) {
						switch (rand() % 4) {
						case 0:
							do {
								splashPx = MouseX + rand() % (int)ABsize;
								splashPy = MouseY + rand() % (int)ABsize;
							} while (Sqrt((MouseX - splashPx) * (MouseX - splashPx) + (MouseY - splashPy) * (MouseY - splashPy)) > ABsize);
							break;
						case 1:
							do {
								splashPx = MouseX - rand() % (int)ABsize;
								splashPy = MouseY - rand() % (int)ABsize;
							} while (Sqrt((MouseX - splashPx) * (MouseX - splashPx) + (MouseY - splashPy) * (MouseY - splashPy)) > ABsize);
							break;
						case 2:
							do {
								splashPx = MouseX - rand() % (int)ABsize;
								splashPy = MouseY + rand() % (int)ABsize;
							} while (Sqrt((MouseX - splashPx) * (MouseX - splashPx) + (MouseY - splashPy) * (MouseY - splashPy)) > ABsize);
							break;
						case 3:
							do {
								splashPx = MouseX + rand() % (int)ABsize;
								splashPy = MouseY - rand() % (int)ABsize;
							} while (Sqrt((MouseX - splashPx) * (MouseX - splashPx) + (MouseY - splashPy) * (MouseY - splashPy)) > ABsize);
							break;
						}
						point(splashPx, splashPy);
					}
				}
				//定規
				if (isPress(KEY_R) && isPress(MOUSE_LBUTTON) && isRuler == 0) {
					for (int i = 0; i < 2 * Sconcentration * ABsize; i++) {
						switch (rand() % 4) {
						case 0:
							do {
								splashPx = MouseX + rand() % (int)ABsize;
								splashPy = MouseY + rand() % (int)ABsize;
							} while (Sqrt((MouseX - splashPx) * (MouseX - splashPx) + (MouseY - splashPy) * (MouseY - splashPy)) > ABsize);
							break;
						case 1:
							do {
								splashPx = MouseX - rand() % (int)ABsize;
								splashPy = MouseY - rand() % (int)ABsize;
							} while (Sqrt((MouseX - splashPx) * (MouseX - splashPx) + (MouseY - splashPy) * (MouseY - splashPy)) > ABsize);
							break;
						case 2:
							do {
								splashPx = MouseX - rand() % (int)ABsize;
								splashPy = MouseY + rand() % (int)ABsize;
							} while (Sqrt((MouseX - splashPx) * (MouseX - splashPx) + (MouseY - splashPy) * (MouseY - splashPy)) > ABsize);
							break;
						case 3:
							do {
								splashPx = MouseX + rand() % (int)ABsize;
								splashPy = MouseY - rand() % (int)ABsize;
							} while (Sqrt((MouseX - splashPx) * (MouseX - splashPx) + (MouseY - splashPy) * (MouseY - splashPy)) > ABsize);
							break;
						}
						point(splashPx, splashPy);
					}
					startPx = MouseX;
					startPy = MouseY;
					isRuler += 0.0001f;
				}
				if (isPress(KEY_R) && isPress(MOUSE_LBUTTON) && isRuler != 0) isRuler += 0.0001f;
				if ((!isPress(KEY_R) || !isPress(MOUSE_LBUTTON)) && isRuler != 0) {
					isRuler = 0;
					endPx = MouseX;
					endPy = MouseY;
					float M = (float)mag18(Abs(startPx - endPx), Abs(startPy - endPy));
					int num = (int)(M / 2);
					float Px = startPx;
					float Py = startPy;
					for (int cnt = 0; cnt < num; cnt++) {
						for (int i = 0; i < 2 * Sconcentration * ABsize; i++) {
							switch (rand() % 4) {
							case 0:
								do {
									splashPx = Px + rand() % (int)ABsize;
									splashPy = Py + rand() % (int)ABsize;
								} while (Sqrt((Px - splashPx) * (Px - splashPx) + (Py - splashPy) * (Py - splashPy)) > ABsize);
								break;
							case 1:
								do {
									splashPx = Px - rand() % (int)ABsize;
									splashPy = Py - rand() % (int)ABsize;
								} while (Sqrt((Px - splashPx) * (Px - splashPx) + (Py - splashPy) * (Py - splashPy)) > ABsize);
								break;
							case 2:
								do {
									splashPx = Px - rand() % (int)ABsize;
									splashPy = Py + rand() % (int)ABsize;
								} while (Sqrt((Px - splashPx) * (Px - splashPx) + (Py - splashPy) * (Py - splashPy)) > ABsize);
								break;
							case 3:
								do {
									splashPx = Px + rand() % (int)ABsize;
									splashPy = Py - rand() % (int)ABsize;
								} while (Sqrt((Px - splashPx) * (Px - splashPx) + (Py - splashPy) * (Py - splashPy)) > ABsize);
								break;
							}
							point(splashPx, splashPy);
						}
						Px += (endPx - startPx) / num;
						Py += (endPy - startPy) / num;
					}

				}

			}
		}
		else isRuler = isCircle = 0;

	}

	void GAME::dispInfo()
	{
		//現在の情報
		fill(230);
		textSize(ItSize * 1.5f);
		if (MAFlag == 1)	text("B : マーカー", IkeyBPx, IkeyPy);
		else if (MAFlag == -1) text("B : エアブラシ", IkeyBPx, IkeyPy);
		if (colorFlag % 3 == 0) {
			text("C : プリセットカラー", IkeyCPx, IkeyPy);
			textSize(ItSize * 1.5f);
			text("↑・↓ : 色の切り替え", IopePx, IopePy);
		}
		else if (colorFlag % 3 == 1){
			text("C : RGB色選択", IkeyCPx, IkeyPy);
			textSize(ItSize * 1.5f);
			text("↑・↓ : 値の増減", IopePx, IopePy);
			text("→・← : 変更する色(R,G,B)の切り替え", IopePx, IopePy + ItSize * 2);
		}
		else if (colorFlag % 3 == 2) text("C : グラデーション", IkeyCPx, IkeyPy);
		if (PEFlag % 5 == 0) text("E : ペン", IkeyEPx, IkeyPy);
		else if (PEFlag % 5 == 1) text("E : 消しゴム", IkeyEPx, IkeyPy);
		else if (PEFlag % 5 == 2) text("E : 25%消しゴム", IkeyEPx, IkeyPy);
		else if (PEFlag % 5 == 3) text("E : 50%消しゴム", IkeyEPx, IkeyPy);
		else if (PEFlag % 5 == 4) text("E : 75%消しゴム", IkeyEPx, IkeyPy);
		text("R長押し : 定規", IopeToolPx, IopeToolPy);
		text("T長押し : 円", IopeToolPx, IopeToolPy + ItSize * 2);
		text("F長押し : 四角形", IopeToolPx, IopeToolPy + ItSize * 4);
		textSize(ItSize);
		fill(192, 100, 100);
		text("+ SHIFT : 塗りつぶし", IopeToolPx + ItSize * 13, IopeToolPy + ItSize * 3.2f);

		//リセット
		fill(255);
		textSize(ItSize * 1.5f);
		text("R + Enter : リセット", IresetPx, IresetPy);
		fill(0, 0, 0, 0);
		stroke(192);
		if (MouseX > IresetPx - ItSize * 1.5f && MouseX < IresetPx + 180 + ItSize * 1.5f * 4 &&
			MouseY > IresetPy && MouseY < IresetPy + ItSize * 1.5f && isTrigger(MOUSE_LBUTTON)) {
			reset();
		}

		//現在のブラシサイズ
		textSize(ItSize * 1.25f);
		fill(255);
		text("ブラシサイズ : ", IBsizePx, IBsizePy);
		textSize(ItSize * 1.5f);
		if (MAFlag == 1) Ibuf = (int)MBsize;
		if (MAFlag == -1) Ibuf = (int)ABsize;
		switch (Ibuf % 10) {
		case 0: text("0", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 1: Ibuf -= 1; text("1", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 2: Ibuf -= 2; text("2", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 3: Ibuf -= 3; text("3", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 4: Ibuf -= 4; text("4", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 5: Ibuf -= 5; text("5", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 6: Ibuf -= 6; text("6", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 7: Ibuf -= 7; text("7", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 8: Ibuf -= 8; text("8", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		case 9: Ibuf -= 9; text("9", IBsizePx + IB3rddigofsX, IBsizePy - IBsizeofsY); break;
		}
		Ibuf /= 10;
		switch (Ibuf % 10) {
		case 0: if (Ibuf % 100) text("0", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY);
				break;
		case 1: Ibuf -= 1; text("1", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		case 2: Ibuf -= 2; text("2", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		case 3: Ibuf -= 3; text("3", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		case 4: Ibuf -= 4; text("4", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		case 5: Ibuf -= 5; text("5", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		case 6: Ibuf -= 6; text("6", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		case 7: Ibuf -= 7; text("7", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		case 8: Ibuf -= 8; text("8", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		case 9: Ibuf -= 9; text("9", IBsizePx + IB2nddigofsX, IBsizePy - IBsizeofsY); break;
		}
		Ibuf /= 10;
		switch (Ibuf % 10) {
		case 1: Ibuf -= 1; text("1", IBsizePx + IB1stdigofsX, IBsizePy - IBsizeofsY); break;
		case 2: Ibuf -= 2; text("2", IBsizePx + IB1stdigofsX, IBsizePy - IBsizeofsY); break;
		case 3: Ibuf -= 3; text("3", IBsizePx + IB1stdigofsX, IBsizePy - IBsizeofsY); break;
		}
		//現在の色
		textSize(ItSize * 1.25f);
		fill(255);
		text("R : ", IclrRPx, IclrPy);
		text("G : ", IclrGPx, IclrPy);
		text("B : ", IclrBPx, IclrPy);
		textSize(ItSize * 1.5f);
		//R
		Ibuf = (int)currentClr.r;
		if (PEFlag % 5) Ibuf = (int)TORINOKO.r;
		switch (Ibuf % 10) {
		case 0: text("0", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 1: Ibuf -= 1; text("1", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 2: Ibuf -= 2; text("2", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 3: Ibuf -= 3; text("3", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 4: Ibuf -= 4; text("4", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 5: Ibuf -= 5; text("5", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 6: Ibuf -= 6; text("6", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 7: Ibuf -= 7; text("7", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 8: Ibuf -= 8; text("8", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 9: Ibuf -= 9; text("9", IclrRPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		}
		Ibuf /= 10;
		switch (Ibuf % 10) {
		case 0: if (Ibuf % 100) text("0", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); 
				break;
		case 1: Ibuf -= 1; text("1", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 2: Ibuf -= 2; text("2", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 3: Ibuf -= 3; text("3", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 4: Ibuf -= 4; text("4", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 5: Ibuf -= 5; text("5", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 6: Ibuf -= 6; text("6", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 7: Ibuf -= 7; text("7", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 8: Ibuf -= 8; text("8", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 9: Ibuf -= 9; text("9", IclrRPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		}
		Ibuf /= 10;
		switch (Ibuf % 10) {
		case 1: text("1", IclrRPx + IC1stdigofsX, IclrPy - IclrofsY); break;
		case 2: text("2", IclrRPx + IC1stdigofsX, IclrPy - IclrofsY); break;
		}
		//G
		Ibuf = (int)currentClr.g;
		if (PEFlag % 5) Ibuf = (int)TORINOKO.g;
		switch (Ibuf % 10) {
		case 0: text("0", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 1: Ibuf -= 1; text("1", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 2: Ibuf -= 2; text("2", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 3: Ibuf -= 3; text("3", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 4: Ibuf -= 4; text("4", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 5: Ibuf -= 5; text("5", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 6: Ibuf -= 6; text("6", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 7: Ibuf -= 7; text("7", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 8: Ibuf -= 8; text("8", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 9: Ibuf -= 9; text("9", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		}
		Ibuf /= 10;
		switch (Ibuf % 10) {
		case 0: if (Ibuf % 100) text("0", IclrGPx + IC3rddigofsX, IclrPy - IclrofsY);
				break;
		case 1: Ibuf -= 1; text("1", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 2: Ibuf -= 2; text("2", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 3: Ibuf -= 3; text("3", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 4: Ibuf -= 4; text("4", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 5: Ibuf -= 5; text("5", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 6: Ibuf -= 6; text("6", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 7: Ibuf -= 7; text("7", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 8: Ibuf -= 8; text("8", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 9: Ibuf -= 9; text("9", IclrGPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		}
		Ibuf /= 10;
		switch (Ibuf % 10) {
		case 1: text("1", IclrGPx + IC1stdigofsX, IclrPy - IclrofsY); break;
		case 2: text("2", IclrGPx + IC1stdigofsX, IclrPy - IclrofsY); break;
		}
		//B
		Ibuf = (int)currentClr.b;
		if (PEFlag % 5) Ibuf = (int)TORINOKO.b;
		switch (Ibuf % 10) {
		case 0: text("0", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 1: Ibuf -= 1; text("1", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 2: Ibuf -= 2; text("2", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 3: Ibuf -= 3; text("3", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 4: Ibuf -= 4; text("4", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 5: Ibuf -= 5; text("5", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 6: Ibuf -= 6; text("6", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 7: Ibuf -= 7; text("7", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 8: Ibuf -= 8; text("8", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		case 9: Ibuf -= 9; text("9", IclrBPx + IC3rddigofsX, IclrPy - IclrofsY); break;
		}
		Ibuf /= 10;
		switch (Ibuf % 10) {
		case 0: if (Ibuf % 100) text("0", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY);
				break;
		case 1: Ibuf -= 1; text("1", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 2: Ibuf -= 2; text("2", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 3: Ibuf -= 3; text("3", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 4: Ibuf -= 4; text("4", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 5: Ibuf -= 5; text("5", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 6: Ibuf -= 6; text("6", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 7: Ibuf -= 7; text("7", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 8: Ibuf -= 8; text("8", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		case 9: Ibuf -= 9; text("9", IclrBPx + IC2nddigofsX, IclrPy - IclrofsY); break;
		}
		Ibuf /= 10;
		switch (Ibuf % 10) {
		case 1: text("1", IclrBPx + IC1stdigofsX, IclrPy - IclrofsY); break;
		case 2: text("2", IclrBPx + IC1stdigofsX, IclrPy - IclrofsY); break;
		}

		//終了
		if (MouseX > 1884 && MouseY < 36) {
			strokeWeight(2);
			stroke(200, 50, 50);
			fill(50, 50, 50, 127);
			rectMode(CORNER);
			rect(1882, 2, 37, 37);
		}
	}

	void GAME::back()
	{
		//用紙を敷く
		if (paperFlag == 0) {
			clear(TORINOKO);
			paperFlag = 1;
		}

		//背景画像
		rectMode(CORNER);
		image(backImg, 0, 0);

		//プリセットカラー表示
		stroke(0);
		fill(127);
		strokeWeight(1);
		rect(1680, 120, 240, 28);
		textSize(23);
		fill(0);
		text("プリセットカラー", 1700, 122);

		rectMode(CORNER);
		strokeWeight(PCUIradius);
		textSize(PCtSize);
		fill(255);
		PCPy = PCheadPy;
		stroke(SHU);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 0 - 15 && MouseY < PCheadPy + PCofs * 0 + 15) {
					fill(0);
					text("しゅ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("しゅ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(AZUKI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 1 - 15 && MouseY < PCheadPy + PCofs * 1 + 15) {
					fill(0);
					text("あずき", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("あずき", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(TUTUJI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 2 - 15 && MouseY < PCheadPy + PCofs * 2 + 15) {
					fill(0);
					text("つつじ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("つつじ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(RURI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 3 - 15 && MouseY < PCheadPy + PCofs * 3 + 15) {
					fill(0);
					text("るり", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("るり", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(KOIAI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 4 - 15 && MouseY < PCheadPy + PCofs * 4 + 15) {
					fill(0);
					text("こいあい", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("こいあい", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(TETSUKON);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 5 - 15 && MouseY < PCheadPy + PCofs * 5 + 15) {
					fill(0);
					text("てつこん", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("てつこん", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(RYOKUSHO);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 6 - 15 && MouseY < PCheadPy + PCofs * 6 + 15) {
					fill(0);
					text("りょくしょう", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("りょくしょう", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(TOKIWA);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 7 - 15 && MouseY < PCheadPy + PCofs * 7 + 15) {
					fill(0);
					text("ときわ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("ときわ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(SEIJI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 8 - 15 && MouseY < PCheadPy + PCofs * 8 + 15) {
					fill(0);
					text("せいじ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("せいじ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(YAMABUKI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 9 - 15 && MouseY < PCheadPy + PCofs * 9 + 15) {
					fill(0);
					text("やまぶき", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("やまぶき", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(KUTIBA);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 10 - 15 && MouseY < PCheadPy + PCofs * 10 + 15) {
					fill(0);
					text("くちば", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("くちば", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(IO);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 11 - 15 && MouseY < PCheadPy + PCofs * 11 + 15) {
					fill(0);
					text("いおう", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("いおう", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(RINDO);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 12 - 15 && MouseY < PCheadPy + PCofs * 12 + 15) {
					fill(0);
					text("りんどう", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("りんどう", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(SUMIRE);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 13 - 15 && MouseY < PCheadPy + PCofs * 13 + 15) {
					fill(0);
					text("すみれ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("すみれ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(NASUKON);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 14 - 15 && MouseY < PCheadPy + PCofs * 14 + 15) {
					fill(0);
					text("なすこん", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("なすこん", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(SHIROHANADA);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 15 - 15 && MouseY < PCheadPy + PCofs * 15 + 15) {
					fill(0);
					text("しろはなだ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("しろはなだ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(ASAGI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 16 - 15 && MouseY < PCheadPy + PCofs * 16 + 15) {
					fill(0);
					text("あさぎ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("あさぎ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(WASURENAGUSA);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 17 - 15 && MouseY < PCheadPy + PCofs * 17 + 15) {
					fill(0);
					text("わすれなぐさ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("わすれなぐさ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(SUMI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 18 - 15 && MouseY < PCheadPy + PCofs * 18 + 15) {
					fill(0);
					text("すみ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("すみ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(NUREGARASU);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 19 - 15 && MouseY < PCheadPy + PCofs * 19 + 15) {
					fill(0);
					text("ぬれがらす", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("ぬれがらす", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(UNOHANA);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 20 - 15 && MouseY < PCheadPy + PCofs * 20 + 15) {
					fill(0);
					text("うのはな", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("うのはな", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(SHINJU);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 21 - 15 && MouseY < PCheadPy + PCofs * 21 + 15) {
					fill(0);
					text("しんじゅ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("しんじゅ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(GINNEZUMI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 22 - 15 && MouseY < PCheadPy + PCofs * 22 + 15) {
					fill(0);
					text("ぎんねずみ", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("ぎんねずみ", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy += PCofs;
		stroke(NAMARI);
		point(PCPx, PCPy);
		if (colorFlag == 0) {
			if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
				if (MouseY > PCheadPy + PCofs * 23 - 15 && MouseY < PCheadPy + PCofs * 23 + 15) {
					fill(0);
					text("なまり", PCPx + PCofs + PCtShadow, PCPy - (float)PCUIradius / 2 + PCtShadow);
					fill(255);
				}
			}
		}
		text("なまり", PCPx + PCofs, PCPy - (float)PCUIradius / 2);
		PCPy = PCheadPy;

		//RGB選択色表示
		stroke(0);
		fill(127);
		strokeWeight(1);
		rect(1680, 870, 240, 28);
		textSize(23);
		fill(0);
		text("RGB色選択", 1745, 873);
		strokeWeight(2);

		fill(255);
		rect(1700, 915, 200, 20);
		fill(RGBbuffClr.r, RGBbuffClr.g, RGBbuffClr.b);
		rect(1700, 915, 200, 20);
		stroke(0);
		fill(127);
		if (RGBFlag % 3 == 0) fill(255);
		rect(1745, 950, 128, 20);
		fill(127);
		if (RGBFlag % 3 == 1) fill(255);
		rect(1745, 990, 128, 20);
		fill(127);
		if (RGBFlag % 3 == 2) fill(255);
		rect(1745, 1030, 128, 20);
		textSize(20);
		stroke(0, 0, 0, 0);
		fill(255, 0, 0);
		text("R", 1725, 950);
		rect(1745, 950, (float)RGBr / 2, 20);
		fill(0, 255, 0);
		text("G", 1725, 990);
		rect(1745, 990, (float)RGBg / 2, 20);
		fill(0, 0, 255);
		text("B", 1725, 1030);
		rect(1745, 1030, (float)RGBb / 2, 20);

		//強調表示
		rectMode(CORNER);
		fill(50, 50, 50, 200);
		stroke(0, 0, 0, 0);
		if (colorFlag % 3 == 0)	rect(1680, 870, 240, 210);
		else if (colorFlag % 3 == 1) rect(1680, 120, 240, 750);
		else if (colorFlag % 3 == 2) {
			rect(1680, 870, 240, 210);
			rect(1680, 120, 240, 750);
		}

		//ブラシサイズ
		strokeWeight(0.5);
		stroke(0);
		fill(0, 0, 0, 0);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				rect(BrectHeadPos.x + i * Bofs, BrectHeadPos.y + j * Bofs, 120, 120);
			}
		}
		fill(240);
		strokeWeight(1); 
		circle(BpointHeadPos.x, BpointHeadPos.y, 1);
		circle(BpointHeadPos.x + Bofs, BpointHeadPos.y, 2);
		circle(BpointHeadPos.x, BpointHeadPos.y + Bofs, 3);
		circle(BpointHeadPos.x + Bofs, BpointHeadPos.y + Bofs, 5);
		circle(BpointHeadPos.x, BpointHeadPos.y + Bofs * 2, 10);
		circle(BpointHeadPos.x + Bofs, BpointHeadPos.y + Bofs * 2, 15);
		circle(BpointHeadPos.x, BpointHeadPos.y + Bofs * 3, 20);
		circle(BpointHeadPos.x + Bofs, BpointHeadPos.y + Bofs * 3, 25);
		circle(BpointHeadPos.x, BpointHeadPos.y + Bofs * 4, 50);
		circle(BpointHeadPos.x + Bofs, BpointHeadPos.y + Bofs * 4, 100);

		stroke(0);
		fill(127);
		strokeWeight(1);
		rect(0, 120, 240, 40);
		textSize(23);
		fill(0);
		text("ブラシサイズ", BtextPx, BtextPy);
		textSize(15);
		fill(0);
		text("1", BrectHeadPos.x + 2, BrectHeadPos.y + 2);
		text("2", BrectHeadPos.x + Bofs + 2, BrectHeadPos.y + 2);
		text("3", BrectHeadPos.x + 2, BrectHeadPos.y + Bofs + 2);
		text("5", BrectHeadPos.x + Bofs + 2, BrectHeadPos.y + Bofs + 2);
		text("10", BrectHeadPos.x + 2, BrectHeadPos.y + Bofs * 2 + 2);
		text("15", BrectHeadPos.x + Bofs + 2, BrectHeadPos.y + Bofs * 2 + 2);
		text("20", BrectHeadPos.x + 2, BrectHeadPos.y + Bofs * 3 + 2);
		text("25", BrectHeadPos.x + Bofs + 2, BrectHeadPos.y + Bofs * 3 + 2);
		text("50", BrectHeadPos.x + 2, BrectHeadPos.y + Bofs * 4 + 2);
		text("100", BrectHeadPos.x + Bofs + 2, BrectHeadPos.y + Bofs * 4 + 2);
		
		stroke(0);
		fill(127);
		strokeWeight(1);
		rect(0, 760, 240, 40);
		textSize(23);
		fill(0);
		text("ブラシサイズ微調整", 12, 768);
		fill(255);
		text("S + ↑ : +1", BkeyTextPx, BkeyTextPy);
		text("S + → : +10", BkeyTextPx, BkeyTextPy + BkeyTextofsY);
		text("S + ↓ : -1", BkeyTextPx, BkeyTextPy + BkeyTextofsY * 2);
		text("S + ← : -10", BkeyTextPx, BkeyTextPy + BkeyTextofsY * 3);

		stroke(0);
		fill(127);
		strokeWeight(1);
		rect(0, 910, 240, 40);
		textSize(23);
		fill(0);
		text("エアブラシ濃度", 30, 918);
		fill(255);
		switch (Sconcentration) {
		case 1: text("D : 1", BairTextPx, BairTextPy); break;
		case 2: text("D : 2", BairTextPx, BairTextPy); break;
		case 3: text("D : 3", BairTextPx, BairTextPy); break;
		case 4: text("D : 4", BairTextPx, BairTextPy); break;
		case 5: text("D : 5", BairTextPx, BairTextPy); break;
		}

		stroke(0);
		fill(127);
		strokeWeight(1);
		rect(0, 995, 240, 40);
		textSize(23);
		fill(0);
		text("グラデーション速度", 10, 1002);
		fill(255);
		switch (HSVspeed) {
		case 0: text("G : 0", BgraTextPx, BgraTextPy); break;
		case 1: text("G : 1", BgraTextPx, BgraTextPy); break;
		case 2: text("G : 2", BgraTextPx, BgraTextPy); break;
		case 3: text("G : 3", BgraTextPx, BgraTextPy); break;
		case 4: text("G : 4", BgraTextPx, BgraTextPy); break;
		case 5: text("G : 5", BgraTextPx, BgraTextPy); break;
		case 6: text("G : 6", BgraTextPx, BgraTextPy); break;
		case 7: text("G : 7", BgraTextPx, BgraTextPy); break;
		case 8: text("G : 8", BgraTextPx, BgraTextPy); break;
		case 9: text("G : 9", BgraTextPx, BgraTextPy); break;
		case 10: text("G : 10", BgraTextPx, BgraTextPy); break;
		}
}

	void GAME::picClr()
	{
		colorMode(RGB);
		//UI操作
		if (MouseX > PCPx - 20 && MouseX < PCPx + 180) {
			PCroop = 0;
			do {
				if (MouseY > PCheadPy + PCofs * PCroop - 21 && MouseY < PCheadPy + PCofs * PCroop + 21) {
					if (isTrigger(MOUSE_LBUTTON)) {
						preColor = PCroop;
					}
				}
				PCroop++;
			} while (PCroop < 24);
		}
		//キー操作
		if (!isPress(KEY_S) && isTrigger(KEY_DOWN)) preColor++;
		if (!isPress(KEY_S) && isTrigger(KEY_UP)) preColor--;
		if (preColor < 0) preColor = 23;
		//処理
		if (preColor == 4 || preColor == 5 || preColor == 14 ||
			preColor == 18 || preColor == 19) stroke(255);
		else stroke(0);
		strokeWeight(2);
		fill(0, 0, 0, 0);
		circle(PCPx, PCheadPy + PCofs * (preColor % 24), PCUIradius);
		switch (preColor % 24) {
		case  0: stroke(SHU); fill(SHU); currentClr = SHU; break;
		case  1: stroke(AZUKI); fill(AZUKI); currentClr = AZUKI;  break;
		case  2: stroke(TUTUJI); fill(TUTUJI); currentClr = TUTUJI;  break;
		case  3: stroke(RURI); fill(RURI); currentClr = RURI;  break;
		case  4: stroke(KOIAI); fill(KOIAI); currentClr = KOIAI;  break;
		case  5: stroke(TETSUKON); fill(TETSUKON); currentClr = TETSUKON;  break;
		case  6: stroke(RYOKUSHO); fill(RYOKUSHO); currentClr = RYOKUSHO;  break;
		case  7: stroke(TOKIWA); fill(TOKIWA); currentClr = TOKIWA;  break;
		case  8: stroke(SEIJI); fill(SEIJI); currentClr = SEIJI;  break;
		case  9: stroke(YAMABUKI); fill(YAMABUKI); currentClr = YAMABUKI;  break;
		case 10: stroke(KUTIBA); fill(KUTIBA); currentClr = KUTIBA;  break;
		case 11: stroke(IO); fill(IO); currentClr = IO;  break;
		case 12: stroke(RINDO); fill(RINDO); currentClr = RINDO;  break;
		case 13: stroke(SUMIRE); fill(SUMIRE); currentClr = SUMIRE;  break;
		case 14: stroke(NASUKON); fill(NASUKON); currentClr = NASUKON;  break;
		case 15: stroke(SHIROHANADA); fill(SHIROHANADA); currentClr = SHIROHANADA; break;
		case 16: stroke(ASAGI); fill(ASAGI); currentClr = ASAGI; break;
		case 17: stroke(WASURENAGUSA); fill(WASURENAGUSA); currentClr = WASURENAGUSA; break;
		case 18: stroke(SUMI); fill(SUMI); currentClr = SUMI; break;
		case 19: stroke(NUREGARASU); fill(NUREGARASU); currentClr = NUREGARASU; break;
		case 20: stroke(UNOHANA); fill(UNOHANA); currentClr = UNOHANA; break;
		case 21: stroke(SHINJU); fill(SHINJU); currentClr = SHINJU; break;
		case 22: stroke(GINNEZUMI); fill(GINNEZUMI); currentClr = GINNEZUMI; break;
		case 23: stroke(NAMARI); fill(NAMARI); currentClr = NAMARI; break;
		}
		PCbuffClr = currentClr;
	}

	void GAME::setClr()
	{
		colorMode(RGB);
		//UI操作
		if (MouseX >= 1745 && MouseX <= 1873 && MouseY >= 950 && MouseY <= 970 && isPress(MOUSE_LBUTTON)) {
			RGBFlag = 0;
			RGBr = (unsigned char)(MouseX - 1745) * 2;
		}
		if (MouseX >= 1745 && MouseX <= 1873 && MouseY >= 990 && MouseY <= 1010 && isPress(MOUSE_LBUTTON)) {
			RGBFlag = 1;
			RGBg = (unsigned char)(MouseX - 1745) * 2;
		}
		if (MouseX >= 1745 && MouseX <= 1873 && MouseY >= 1030 && MouseY <= 1050 && isPress(MOUSE_LBUTTON)) {
			RGBFlag = 2;
			RGBb = (unsigned char)(MouseX - 1745) * 2;
		}
		//キー操作
		if (!isPress(KEY_S) && isTrigger(KEY_RIGHT)) RGBFlag++;
		if (!isPress(KEY_S) && isTrigger(KEY_LEFT)) RGBFlag--;
		if (RGBFlag < 0) RGBFlag = 2;
		switch (RGBFlag % 3) {
		case 0:
			if (!isPress(KEY_S) && isPress(KEY_UP) && RGBr < 255) RGBr++;
			if (!isPress(KEY_S) && isPress(KEY_DOWN) && RGBr > 0) RGBr--;
			break;
		case 1:
			if (!isPress(KEY_S) && isPress(KEY_UP) && RGBg < 255) RGBg++;
			if (!isPress(KEY_S) && isPress(KEY_DOWN) && RGBg > 0) RGBg--;
			break;
		case 2:
			if (!isPress(KEY_S) && isPress(KEY_UP) && RGBb < 255) RGBb++;
			if (!isPress(KEY_S) && isPress(KEY_DOWN) && RGBb > 0) RGBb--;
			break;
		}
		stroke(RGBr, RGBg, RGBb);
		fill(RGBr, RGBg, RGBb);
		currentClr.r = RGBr;
		currentClr.g = RGBg;
		currentClr.b = RGBb;
		RGBbuffClr = currentClr;
	}

	void GAME::graClr()
	{
		colorMode(RGB);
		if (MouseX > 280 && MouseX < 1640 && MouseY > 255 && MouseY < 1025) {
			if (isPress(MOUSE_LBUTTON)) HSVpseudoH += HSVspeed;
		}
		if (HSVpseudoH % 1536 < 256) {
			HSVClr.r = 255;
			HSVClr.g = (float)(HSVpseudoH % 256);
			HSVClr.b = 0;
		}
		else if (HSVpseudoH % 1536 < 512) {
			HSVClr.r = 255 - (float)(HSVpseudoH % 256);
			HSVClr.g = 255;
			HSVClr.b = 0;
		}
		else if (HSVpseudoH % 1536 < 768) {
			HSVClr.r = 0;
			HSVClr.g = 255;
			HSVClr.b = (float)(HSVpseudoH % 256);
		}
		else if (HSVpseudoH % 1536 < 1024) {
			HSVClr.r = 0;
			HSVClr.g = 255 - (float)(HSVpseudoH % 256);
			HSVClr.b = 255;
		}
		else if (HSVpseudoH % 1536 < 1280) {
			HSVClr.r = (float)(HSVpseudoH % 256);
			HSVClr.g = 0;
			HSVClr.b = 255;
		}
		else if (HSVpseudoH % 1536 < 1536) {
			HSVClr.r = 255;
			HSVClr.g = 0;
			HSVClr.b = 255 - (float)(HSVpseudoH % 256);
		}
		currentClr = HSVClr;
	}

	void GAME::setBsize()
	{
		//UI操作
		if (MAFlag == 1) {
			if (MouseX > 0 && MouseX < 120 && MouseY > 160 && MouseY < 280 && isTrigger(MOUSE_LBUTTON)) MBsize = 1;
			if (MouseX > 120 && MouseX < 240 && MouseY > 160 && MouseY < 280 && isTrigger(MOUSE_LBUTTON)) MBsize = 2;
			if (MouseX > 0 && MouseX < 120 && MouseY > 280 && MouseY < 400 && isTrigger(MOUSE_LBUTTON)) MBsize = 3;
			if (MouseX > 120 && MouseX < 240 && MouseY > 280 && MouseY < 400 && isTrigger(MOUSE_LBUTTON)) MBsize = 5;
			if (MouseX > 0 && MouseX < 120 && MouseY > 400 && MouseY < 520 && isTrigger(MOUSE_LBUTTON)) MBsize = 10;
			if (MouseX > 120 && MouseX < 240 && MouseY > 400 && MouseY < 520 && isTrigger(MOUSE_LBUTTON)) MBsize = 15;
			if (MouseX > 0 && MouseX < 120 && MouseY > 520 && MouseY < 640 && isTrigger(MOUSE_LBUTTON)) MBsize = 20;
			if (MouseX > 120 && MouseX < 240 && MouseY > 520 && MouseY < 640 && isTrigger(MOUSE_LBUTTON)) MBsize = 25;
			if (MouseX > 0 && MouseX < 120 && MouseY > 640 && MouseY < 760 && isTrigger(MOUSE_LBUTTON)) MBsize = 50;
			if (MouseX > 120 && MouseX < 240 && MouseY > 640 && MouseY < 760 && isTrigger(MOUSE_LBUTTON)) MBsize = 100;

			if (MouseX > 30 && MouseX < 210 && MouseY > 805 && MouseY < 830 && isTrigger(MOUSE_LBUTTON)) MBsize++;
			if (MouseX > 30 && MouseX < 210 && MouseY > 830 && MouseY < 855 && isTrigger(MOUSE_LBUTTON)) MBsize += 10;
			if (MouseX > 30 && MouseX < 210 && MouseY > 855 && MouseY < 880 && isTrigger(MOUSE_LBUTTON)) MBsize--;
			if (MouseX > 30 && MouseX < 210 && MouseY > 880 && MouseY < 905 && isTrigger(MOUSE_LBUTTON)) MBsize -= 10;
		}
		else if (MAFlag == -1) {
			if (MouseX > 0 && MouseX < 120 && MouseY > 160 && MouseY < 280 && isTrigger(MOUSE_LBUTTON)) ABsize = 1;
			if (MouseX > 120 && MouseX < 240 && MouseY > 160 && MouseY < 280 && isTrigger(MOUSE_LBUTTON)) ABsize = 2;
			if (MouseX > 0 && MouseX < 120 && MouseY > 280 && MouseY < 400 && isTrigger(MOUSE_LBUTTON)) ABsize = 3;
			if (MouseX > 120 && MouseX < 240 && MouseY > 280 && MouseY < 400 && isTrigger(MOUSE_LBUTTON)) ABsize = 5;
			if (MouseX > 0 && MouseX < 120 && MouseY > 400 && MouseY < 520 && isTrigger(MOUSE_LBUTTON)) ABsize = 10;
			if (MouseX > 120 && MouseX < 240 && MouseY > 400 && MouseY < 520 && isTrigger(MOUSE_LBUTTON)) ABsize = 15;
			if (MouseX > 0 && MouseX < 120 && MouseY > 520 && MouseY < 640 && isTrigger(MOUSE_LBUTTON)) ABsize = 20;
			if (MouseX > 120 && MouseX < 240 && MouseY > 520 && MouseY < 640 && isTrigger(MOUSE_LBUTTON)) ABsize = 25;
			if (MouseX > 0 && MouseX < 120 && MouseY > 640 && MouseY < 760 && isTrigger(MOUSE_LBUTTON)) ABsize = 50;
			if (MouseX > 120 && MouseX < 240 && MouseY > 640 && MouseY < 760 && isTrigger(MOUSE_LBUTTON)) ABsize = 100;

			if (MouseX > 30 && MouseX < 210 && MouseY > 805 && MouseY < 830 && isTrigger(MOUSE_LBUTTON)) ABsize++;
			if (MouseX > 30 && MouseX < 210 && MouseY > 830 && MouseY < 855 && isTrigger(MOUSE_LBUTTON)) ABsize += 10;
			if (MouseX > 30 && MouseX < 210 && MouseY > 855 && MouseY < 880 && isTrigger(MOUSE_LBUTTON)) ABsize--;
			if (MouseX > 30 && MouseX < 210 && MouseY > 880 && MouseY < 905 && isTrigger(MOUSE_LBUTTON)) ABsize -= 10;
		}
		//キー操作
		if (MAFlag == 1) {
			if (isPress(KEY_S) && isTrigger(KEY_UP)) MBsize++;
			if (isPress(KEY_S) && isTrigger(KEY_RIGHT)) MBsize += 10;
			if (isPress(KEY_S) && isTrigger(KEY_DOWN)) MBsize--;
			if (isPress(KEY_S) && isTrigger(KEY_LEFT)) MBsize -= 10;
		}
		else if (MAFlag == -1) {
			if (isPress(KEY_S) && isTrigger(KEY_UP)) ABsize++;
			if (isPress(KEY_S) && isTrigger(KEY_RIGHT)) ABsize += 10;
			if (isPress(KEY_S) && isTrigger(KEY_DOWN)) ABsize--;
			if (isPress(KEY_S) && isTrigger(KEY_LEFT)) ABsize -= 10;
		}
		if (MBsize < 1) MBsize = 1;
		if (ABsize < 1) ABsize = 1;
		if (MBsize > 320) MBsize = 320;
		if (ABsize > 320) ABsize = 320;
	}

	void GAME::reset()
	{
		paperFlag = 0;
	}
}