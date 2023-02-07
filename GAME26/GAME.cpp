#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include<time.h>
#include<random>
namespace GAME26 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！
#define __mag(x,y)sqrt(x*x+y*y)
#define __normalize(x, y, vx, vy) vx = x / __mag(x, y); vy = y / __mag(x, y)

	GAME::GAME(MANAGER* manager) {
		hideCursor();
		srand((unsigned)time(NULL));
		Title[0].Px = width / 2 - 500;
		Title[1].Px = width / 2 - 525;
		Title[2].Px = width / 2 - 245;
		Title[3].Px = width / 2 - 245;
		Title[4].Px = width / 2 - 192;
		Title[0].Py = 200;
		Title[1].Py = 480;
		Title[2].Py = 700;
		Title[3].Py = 800;
		Title[4].Py = 900;

		Title[0].Size = 200;
		Title[1].Size = 140;
		Title[2].Size = Title[3].Size = Title[4].Size = 70;

		Title[0].Color.r = 255;
		Title[0].Color.g = 167;
		Title[0].Color.b = 16;

		Title[1].Color.r = Title[2].Color.r = Title[3].Color.r = Title[4].Color.r = 220;
		Title[1].Color.g = Title[2].Color.g = Title[3].Color.g = Title[4].Color.g = 220;
		Title[1].Color.b = Title[2].Color.b = Title[3].Color.b = Title[4].Color.b = 220;

		Title[0].str = "カーリング";
		Title[1].str = "Enterでスタート";
		Title[2].str = "W・Sで上下移動";
		Title[3].str = "A・Dで角度調整";
		Title[4].str = "Spaceで放つ";

		Result[0].Px = Result[1].Px = width / 2 - 600;
		Result[2].Px = width / 2 - 725;
		Result[3].Px = width / 2 + 125;
		Result[4].Px = width / 2- 500;


		Result[0].Py = Result[1].Py = Result[4].Py=300;

		Result[2].Py = Result[3].Py = 900;

		Result[0].Size = Result[1].Size = Result[4].Size=200;
		Result[2].Size = Result[3].Size = 70;

		Result[0].Color.r = 255;
		Result[0].Color.g = 0;
		Result[0].Color.b = 0;

		Result[1].Color.r = 255;
		Result[1].Color.g = 215;
		Result[1].Color.b = 0;

		Result[2].Color.r = Result[3].Color.r = 220;
		Result[2].Color.g = Result[3].Color.g = 220;
		Result[2].Color.b = Result[3].Color.b = 220;

		Result[4].Color.r = 255;
		Result[4].Color.g = 100;
		Result[4].Color.b = 0;

		Result[0].str = "先攻の勝ち！";
		Result[1].str = "後攻の勝ち！";
		Result[2].str = "Spaceでもう一戦";
		Result[3].str = "Enterでメニューに戻る";
		Result[4].str = "引き分け！";

		powerRectPx = width / 2 - 300;
		powerRectPy = height - 100;
		attenuation = 0.005f;
		powerLimit = 0.025f;
		sweepLong = 100;
		sweepPower = 10;
		MtSVx = 0;
		MtSVy = 0;

		for (int i = 0; i < 6; i++) {
			TS[i].Px = rand() % 1920;
			TS[i].Py = rand() % 1080;
			TS[i].Diameter = 70;
		}
		for (int i = 0; i < 4; i++) {
			C[i].Px = 1650;
			C[i].Py = height / 2;
			C[i].Diameter = 480 - 120 * i;
		}

		l1.Sx = 120;
		l1.Sy = 0;
		l1.Ex = 120;
		l1.Ey = height;
		l2.Sx = 1300;
		l2.Sy = 0;
		l2.Ex = 1300;
		l2.Ey = height;

		l3.Sx = 0;
		l3.Sy = height / 2;
		l3.Ex = width;
		l3.Ey = height / 2;
		l4.Sx = 1650;
		l4.Sy = 0;
		l4.Ex = 1650;
		l4.Ey = height;

		l5.Sx = 0;
		l5.Sy = 200;
		l5.Ex = width;
		l5.Ey = 200;
		l6.Sx = 0;
		l6.Sy = height - 200;
		l6.Ex = width;
		l6.Ey = height - 200;

		r1.Px = 0;
		r1.Py = 0;
		r1.W = width;
		r1.H = 200;
		r2.Px = 0;
		r2.Py = height - 200;
		r2.W = width;
		r2.H = 200;

		CollisionDelay = 0.08f;
		collisionSnd = loadSound("../game26/assets/collisionSND.wav");

		init();
		angleMode(DEGREES);

		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
		showCursor();
		angleMode(DEGREES);
		stroke(0);
	}

	void GAME::proc(MANAGER* manager) {
		setDeltaTime();

		if (State == TITLE)title();
		if (State == PLAY)play();
		if (State == RESULT)result();

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
		initDeltaTime();

		currentStone = 0;
		throwPower = 0;
		powerFlag = 1;
		throwFlag = 0;
		remaining = 3;
		Scnt = 0;
		sweepPx = 0;
		S[0].Px = 40;
		S[0].Py = height / 2;
		S[0].Diameter = 70;
		S[0].Vx = 0;
		S[0].Vy = 0;
		S[0].Angle = 0;

		for (int i = 1; i < 8; i++) {
			S[i].Px =90+ 120 * i;
			S[i].Py = 260;
			S[i].Diameter = 70;
			S[i].Vx = 0;
			S[i].Vy = 0;
			S[i].Angle = 0;
			CollisionTime[i] = 0;
		}
		BCflag = 0;
	}

	void GAME::title()
	{
		clear(0, 135, 170);
		for (int i = 0; i < 6; i++) {
			strokeWeight(15);
			stroke(128);
			if (i % 2 == 1)fill(255, 215, 0);
			if (i % 2 == 0)fill(255, 0, 0);
			circle(TS[i].Px, TS[i].Py, TS[i].Diameter);

			strokeWeight(6);
			stroke(0);
			line(TS[i].Px, TS[i].Py, TS[i].Px - 30, TS[i].Py);
		}

		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				textSize(Title[0].Size);
			}
			else {
				if (i == 1)textSize(Title[1].Size);
				else textSize(Title[2].Size);
			}
			fill(0);
			text(Title[i].str, Title[i].Px + Title[i].Size / 14, Title[i].Py + Title[i].Size / 14);

		}

		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				textSize(Title[0].Size);
				fill(Title[0].Color);
			}
			else {
				if (i == 1)textSize(Title[1].Size);
				else textSize(Title[2].Size);
				fill(Title[1].Color);
			}
			text(Title[i].str, Title[i].Px, Title[i].Py);

			if (isTrigger(KEY_ENTER))State = PLAY;
		}
	}

	void GAME::play()
	{
		if (isTrigger(KEY_J)) {
			S[currentStone].Vx = S[currentStone].Vy = 0;
			S[currentStone].Px = -200 * ++Scnt;
			S[currentStone].Py = -100;
			currentStone++;
			throwPower = 0;
			remaining = 3;
			sweepPx = 0;
			throwFlag = 3;
		}

		//計算・フラッグ管理
		//パワー
		if (throwFlag == 1 && isPress(KEY_SPACE) && powerFlag == 1) {
			throwPower += 0.01f;
			if (throwPower > 1) powerFlag *= -1;
		}
		if (throwFlag == 1 && isPress(KEY_SPACE) && powerFlag == -1) {
			throwPower -= 0.01f;
			if (throwPower < 0) powerFlag *= -1;
		}
		//上下移動
		if (throwFlag == 0) {
			if (isPress(KEY_W) && S[currentStone].Py > height / 2 - 200) {
				if (S[currentStone].Py < height / 2 - 200)S[currentStone].Py = height / 2 - 200;
				S[currentStone].Py -= 0.5f;
			}
			if (isPress(KEY_S) && S[currentStone].Py < height / 2 + 200) {
				if (S[currentStone].Py > height / 2 + 200)S[currentStone].Py = height / 2 + 200;
				S[currentStone].Py += 0.5f;
			}
			//角度調整
			if (isPress(KEY_A) && S[currentStone].Angle < 30) {
				if (S[currentStone].Angle > 30) S[currentStone].Angle = 30;
				S[currentStone].Angle += 0.25f;
			}
			if (isPress(KEY_D) && S[currentStone].Angle > -30) {
				if (S[currentStone].Angle < -30) S[currentStone].Angle = -30;
				S[currentStone].Angle -= 0.25f;
			}
		}

		//初期位置移動
		if (throwFlag == -1) {
			if (S[currentStone].Px == 40) throwFlag = 0;
			S[currentStone].Px += MtSVx;
			S[currentStone].Py += MtSVy;
			if (S[currentStone].Px < 40) S[currentStone].Px = 40;
			if (S[currentStone].Py > height / 2) S[currentStone].Py = height / 2;
		}
		//投擲操作
		if (throwFlag == 0 && isPress(KEY_SPACE)) throwFlag = 1;
		if (throwFlag == 1 && !isPress(KEY_SPACE)) {
			if (throwPower < 0.05f) throwPower = 0.05f;
			S[currentStone].Vx = Cos(S[currentStone].Angle) * throwPower * 10;
			S[currentStone].Vy = -(Sin(S[currentStone].Angle) * throwPower * 10);
			throwFlag = 2;
		}
		if (throwFlag == 2 && !isMove()) {
			currentStone++;
			//共通で使用する変数は初期値に戻す
			throwPower = 0;
			remaining = 3;
			sweepPx = 0;
			throwFlag = 3;
		}
		if (throwFlag == 3) {
			//バグ防止
			for (int i = 0; i < currentStone; i++) {
				//有効ライン前
				if (S[i].Px < 1300 || S[currentStone].Px == NAN || S[currentStone].Py == NAN) {
					S[i].Px = -200 * ++Scnt;
					S[i].Vx = S[i].Vy = 0;
				}
			}
			if (!isMove()) {
				if (currentStone < 8) {
					//初期位置への移動のためのベクトルを求める
					throwFlag = -1;
					MtSVx = (40 - S[currentStone].Px) / 60;
					MtSVy = (height / 2 - S[currentStone].Py) / 60;
				}
				else {
					//リザルト
					NCstone = 0;
					magbuf = __mag(abs(1650 - S[0].Px), abs(height / 2 - S[0].Py));
					for (int i = 1; i < 8; i++) {
						if (magbuf > __mag(abs(1650 - S[i].Px), abs(height / 2 - S[i].Py))) {
							magbuf = __mag(abs(1650 - S[i].Px), abs(height / 2 - S[i].Py));
							NCstone = i;
						}
					}

					sleep(2000);
					State = RESULT;

				}
			}
		}
		//スイープ
		if (throwFlag == 2 && isTrigger(KEY_SHIFT) && remaining &&
			S[currentStone].Px > 200 && S[currentStone].Px < width) {
			if (sweepPx != 0 && S[currentStone].Px < sweepPx) sweepPx += sweepLong;
			sweepPx = S[currentStone].Px + sweepLong;
			remaining--;
		}

		//移動
		if (throwFlag == 2) {
			for (int i = 0; i < 8; i++) {
				S[i].Px += S[i].Vx;
				S[i].Py += S[i].Vy;
				//上下壁/右画面外
				if (S[i].Py < 250 || S[i].Py>height - 250 || S[i].Px > width + 100) {
					S[i].Px = -200 * ++Scnt;
					S[i].Vx = S[i].Vy = 0;
				}
				//現在の石
				if (i == currentStone) {
					if (S[i].Px < sweepPx) {
						S[i].Vx -= S[i].Vx * attenuation / sweepPower;
						S[i].Vy -= S[i].Vy * attenuation / sweepPower;
					}
					else {
						S[i].Vx -= S[i].Vx * attenuation;
						S[i].Vy -= S[i].Vy * attenuation;
					}
				}
				//その他の石
				else {
					S[i].Vx -= S[i].Vx * attenuation;
					S[i].Vy -= S[i].Vy * attenuation;
				}
				if (S[i].Vx < powerLimit && S[i].Vy < powerLimit)S[i].Vx = S[i].Vy = 0;
			}
		}

		for (int i = 0; i < 8; i++) {
			if (CollisionTime[i] > 0) {
				CollisionTime[i] -= delta;
				if (CollisionTime[i] < 0) CollisionTime[i] = 0;
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < i; j++) {
				distance = __mag(abs(S[i].Px - S[j].Px), abs(S[i].Py - S[j].Py));
				if (distance < 85) {
					//めり込む前に戻す
					float rollback = (85 - distance) / 2;
					float Ang = Acos(abs(S[i].Px - S[j].Px) / distance);
					//iが左上
					if (S[i].Px < S[j].Px && S[i].Py < S[j].Py) {
						S[i].Px -= rollback * Cos(Ang);
						S[j].Px += rollback * Cos(Ang);
						S[i].Py -= rollback * Sin(Ang);
						S[j].Py += rollback * Sin(Ang);
					}
					//iが左下
					else if (S[i].Px < S[j].Px && S[i].Py > S[j].Py) {
						S[i].Px -= rollback * Cos(Ang);
						S[j].Px += rollback * Cos(Ang);
						S[i].Py += rollback * Sin(Ang);
						S[j].Py -= rollback * Sin(Ang);
					}
					//iが右上
					else if (S[i].Px > S[j].Px && S[i].Py < S[j].Py) {
						S[i].Px += rollback * Cos(Ang);
						S[j].Px -= rollback * Cos(Ang);
						S[i].Py -= rollback * Sin(Ang);
						S[j].Py += rollback * Sin(Ang);
					}
					//iが右下
					else if (S[i].Px > S[j].Px && S[i].Py > S[j].Py) {
						S[i].Px += rollback * Cos(Ang);
						S[j].Px -= rollback * Cos(Ang);
						S[i].Py += rollback * Sin(Ang);
						S[j].Py -= rollback * Sin(Ang);
					}

					if (CollisionTime[i] != 0 && CollisionTime[j] != 0) break;
					collision(i, j);
					CollisionTime[i] = CollisionTime[j] = CollisionDelay;
					playSound(collisionSnd);
				}
			}

			//表示
			//背景色
			clear(176, 224, 230);

			//ライン
			strokeWeight(4);
			stroke(100, 100, 100, 95);
			line(l3.Sx, l3.Sy, l3.Ex, l3.Ey);
			line(l4.Sx, l4.Sy, l4.Ex, l4.Ey);
			strokeWeight(8);
			stroke(255, 20, 20, 192);
			line(l1.Sx, l1.Sy, l1.Ex, l1.Ey);
			line(l2.Sx, l2.Sy, l2.Ex, l2.Ey);

			//場外
			rectMode(CORNER);
			stroke(0, 0, 0, 0);
			fill(50, 50, 255);
			rect(r1.Px, r1.Py, r1.W, r1.H);
			rect(r2.Px, r2.Py, r2.W, r2.H);
			strokeWeight(20);
			stroke(100);
			line(l5.Sx, l5.Sy, l5.Ex, l5.Ey);
			line(l6.Sx, l6.Sy, l6.Ex, l6.Ey);

			//サークル
			stroke(0, 0, 255);
			fill(0, 0, 255);
			circle(C[0].Px, C[0].Py, C[0].Diameter);
			stroke(255, 255, 255);
			fill(255, 255, 255);
			circle(C[1].Px, C[1].Py, C[1].Diameter);
			stroke(255, 0, 0);
			fill(255, 0, 0);
			circle(C[2].Px, C[2].Py, C[2].Diameter);
			stroke(255);
			fill(255);
			circle(C[3].Px, C[3].Py, C[3].Diameter);

			//ストーン	
			for (int i = 0; i < 8; i++) {
				strokeWeight(15);
				stroke(128);
				if (i % 2 == 1)fill(255, 215, 0);
				if (i % 2 == 0)fill(255, 0, 0);
				circle(S[i].Px, S[i].Py, S[i].Diameter);

				strokeWeight(6);
				stroke(0);
				line(S[i].Px, S[i].Py, S[i].Px - 30 * Cos(S[i].Angle), S[i].Py + 30 * Sin(S[i].Angle));
			}
			//パワー
			strokeWeight(1);
			stroke(0);
			fill(0, 0, 0, 0);
			rect(powerRectPx, powerRectPy, 600, 50);
			stroke(0, 0, 0, 0);
			fill(throwPower * 100 * 2.56, throwPower * 100 * 0.32, 0);
			rect(powerRectPx, powerRectPy, throwPower * 100 * 6, 50);
		}
	}
	void GAME::result()
	{
		if (BCflag == 0) {
			fill(112, 149, 180, 192);
			stroke(0, 0, 0, 0);
			rect(0, 0, width, height);
			BCflag++;
		}

		if (magbuf > 480) {
			//引き分け
			fill(Result[4].Color);
			textSize(Result[4].Size);
			text(Result[4].str, Result[4].Px, Result[4].Py);
		}
		else	if (NCstone % 2 == 0) {
			fill(Result[0].Color);
			textSize(Result[0].Size);
			text(Result[0].str, Result[0].Px, Result[0].Py);
		}
		else	if (NCstone % 2 == 1) {
			fill(Result[1].Color);
			textSize(Result[1].Size);
			text(Result[1].str, Result[1].Px, Result[1].Py);
		}

		fill(Result[2].Color);
		textSize(Result[2].Size);
		text(Result[2].str, Result[2].Px, Result[2].Py);
		text(Result[3].str, Result[3].Px, Result[3].Py);

		if (isTrigger(KEY_ENTER)) BackToMenuFlag = 1;
		if (isTrigger(KEY_SPACE)) {
			State = TITLE;
			init();
		}
	}

	void GAME::collision(int idx1, int idx2)
	{
		//総エネルギー量
		float M1 = __mag(S[idx1].Vx, S[idx1].Vy);
		float M2 = __mag(S[idx2].Vx, S[idx2].Vy);
		if (M1 < M2) {
			int Itemp = idx2;
			idx2 = idx1;
			idx1 = Itemp;
		}

		//角度
		float AC = 0;
		//衝突角
		AC = Acos(abs(S[idx1].Px - S[idx2].Px) / distance);

		S[idx2].Vx += S[idx1].Vx * Cos(AC) + S[idx1].Vy * (1 - Sin(AC));
		if (S[idx1].Py <= S[idx2].Py) {
			S[idx2].Vy += S[idx1].Vy * Sin(AC) + S[idx1].Vx * (1 - Cos(AC));
		}
		else {
			S[idx2].Vy -= S[idx1].Vy * Sin(AC) + S[idx1].Vx * (1 - Cos(AC));
		}
		S[idx1].Vx -= S[idx2].Vx;
		S[idx1].Vy -= S[idx2].Vy;
	}

	int GAME::isMove()
	{
		for (int i = 0; i < 8; i++) {
			if (S[i].Vx != 0 || S[i].Vy != 0)return 1;
		}
		return 0;
	}

	int GAME::sleep(unsigned long x)
	{
		clock_t c1 = clock(), c2 = 0;
		do {
			if ((c2 = clock()) == (clock_t)-1) {
				return 0;
			}
		} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
		return 1;
	}
}