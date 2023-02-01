#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include<time.h>
#include<random>
#include "GAME.h"
namespace GAME15 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！
	//ゲーム内容→落ちてくる球を出来るだけ下で止める
	//必要な動作→スペースキーで球を止める、止めた球の座標を表示する、落ちるスピードをランダムにする。
	GAME::GAME(MANAGER* manager)
	{
		srand((unsigned)time(NULL));
		initDeltaTime();
		namepx = width / 2 - 800;
		namepy = 200;
		namesize = 200;
		Namepx = width / 2 - 360;
		Namepy = height / 2 + 100;
		Namesize = 80;

		scoresize = 140;
		totalStrPx = 650 - 490;
		totalStrPy = 110;
		scoreStrPx = 650 - 105;
		scoreStrPy = 400;

		infosize = 85;
		titleStrPx = menuStrPx = 650 - 382.5;
		titleStrPy = height / 2 + 150;
		menuStrPy = titleStrPy + infosize * 1.5;

		Initposition();
		manager->fade->fadeInTrigger();

		numplay = 5;
		interval = 1.5;
	}

	GAME::~GAME()
	{}
	void GAME::proc(MANAGER* manager)
	{
		setDeltaTime();
		switch (scene) {
		case title: Title(); break;
		case play: Play(); break;
		case result: Result(); break;
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
	void GAME::Init()
	{
		counter = numplay;
		stopflag = true;
		play_init = true;
	}
	void GAME::Initposition()
	{
		c1.Diameter = 250;
		c1.Px = 0;
		c1.Py = 470;
		c1.Vx = 10;
		c1.Vy = 0;

		//体
		c2.Diameter = 400;
		c2.Px = 1600;
		c2.Py = 800;
		c2.Vx = 0;
		c2.Vy = 0;

		//目
		c3.Diameter = 20;
		c3.Px = 40;
		c3.Py = 430;
		c3.Vx = 10;
		c3.Vy = 0;

		c4.Diameter = 20;
		c4.Px = -40;
		c4.Py = 430;
		c4.Vx = 10;
		c4.Vy = 0;

		//体の柄
		c5.Diameter = 40;
		c5.Px = 1600;
		c5.Py = 900;
		c5.Vx = 10;
		c5.Vy = 0;

		c6.Diameter = 40;
		c6.Px = 1600;
		c6.Py = 800;
		c6.Vx = 10;
		c6.Vy = 0;

		c7.Diameter = 40;
		c7.Px = 1600;
		c7.Py = 700;
		c7.Vx = 10;
		c7.Vy = 0;

		//腕
		l1.Sx = 1800;
		l1.Sy = 800;
		l1.Ex = 1900;
		l1.Ey = 900;

		l2.Sx = 1400;
		l2.Sy = 790;
		l2.Ex = 1300;
		l2.Ey = 900;

		//鼻
		l3.Sx = 0;
		l3.Sy = 460;
		l3.Ex = -15;
		l3.Ey = 490;

		l4.Sx = -15;
		l4.Sy = 490;
		l4.Ex = 0;
		l4.Ey = 490;

		//口
		l5.Sx = -10;
		l5.Sy = 530;
		l5.Ex = 5;
		l5.Ey = 530;
		//インターバル
		remain = interval;
		stopPx = rand() % 18 + 1589;
		cheatFlag = true;
	}
	void GAME::Title()
	{
		if (isTrigger(KEY_SPACE)) {
			scene = play;
			Init();
		}
		//描画
		clear(204, 242, 255);
		stroke(0);
		fill(255);
		circle(c2.Px, c2.Py, c2.Diameter);
		circle(c5.Px, c5.Py, c5.Diameter);
		circle(c6.Px, c6.Py, c6.Diameter);
		circle(c7.Px, c7.Py, c7.Diameter);
		fill(0);
		textSize(namesize);
		text(name, namepx, namepy);
		textSize(Namesize);
		text(Name, Namepx, Namepy);
	}
	void GAME::Play()
	{
		if (play_init) {
			counter--;
			Initposition();
			c1.Vx = (float)(rand() % 9 + 7);
			play_init = false;
		}
		if (stopflag) {
			c1.Px += c1.Vx;
			c3.Px += c1.Vx;
			c4.Px += c1.Vx;
			l3.Sx += c1.Vx;
			l3.Ex += c1.Vx;
			l4.Sx += c1.Vx;
			l4.Ex += c1.Vx;
			l5.Sx += c1.Vx;
			l5.Ex += c1.Vx;
		}
		clear(204, 242, 255);
		fill(255, 255, 255);
		line(l1.Sx, l1.Sy, l1.Ex, l1.Ey);
		line(l2.Sx, l2.Sy, l2.Ex, l2.Ey);
		//動かす円
		circle(c1.Px, c1.Py, c1.Diameter);
		circle(c2.Px, c2.Py, c2.Diameter);
		fill(0, 0, 0);
		circle(c3.Px, c3.Py, c3.Diameter);
		circle(c4.Px, c4.Py, c4.Diameter);
		//鼻
		line(l3.Sx, l3.Sy, l3.Ex, l3.Ey);
		line(l4.Sx, l4.Sy, l4.Ex, l4.Ey);
		//口
		line(l5.Sx, l5.Sy, l5.Ex, l5.Ey);
		//体の柄
		circle(c5.Px, c5.Py, c5.Diameter);
		circle(c6.Px, c6.Py, c6.Diameter);
		circle(c7.Px, c7.Py, c7.Diameter);
		if (isTrigger(KEY_SPACE)||(isPress(KEY_A)&&c1.Px>=stopPx && cheatFlag)) {
			stopflag = false;
			cheatFlag = false;
			if (c1.Px > c2.Px - 100 && c1.Px < c2.Px + 100) {
				score =100-(abs((int)(c1.Px - c2.Px)));
			}
			else score = 0;
 			totalscore += score;

			if (score <= 9) {
				switch (score) {
				case 0: scoretext[0] = '0'; break;
				case 1: scoretext[0] = '1'; break;
				case 2: scoretext[0] = '2'; break;
				case 3: scoretext[0] = '3'; break;
				case 4: scoretext[0] = '4'; break;
				case 5: scoretext[0] = '5'; break;
				case 6: scoretext[0] = '6'; break;
				case 7: scoretext[0] = '7'; break;
				case 8: scoretext[0] = '8'; break;
				case 9: scoretext[0] = '9'; break;
				}
				scoretext[1] = '\0';
			}
			else if (score >= 10 && score <= 99) {
				switch (score % 10) {
				case 0: scoretext[1] = '0'; break;
				case 1: scoretext[1] = '1'; score -= 1; break;
				case 2: scoretext[1] = '2'; score -= 2; break;
				case 3: scoretext[1] = '3'; score -= 3; break;
				case 4: scoretext[1] = '4'; score -= 4; break;
				case 5: scoretext[1] = '5'; score -= 5; break;
				case 6: scoretext[1] = '6'; score -= 6; break;
				case 7: scoretext[1] = '7'; score -= 7; break;
				case 8: scoretext[1] = '8'; score -= 8; break;
				case 9: scoretext[1] = '9'; score -= 9; break;
				}
				score /= 10;
				switch (score) {
				case 1: scoretext[0] = '1'; break;
				case 2: scoretext[0] = '2'; break;
				case 3: scoretext[0] = '3'; break;
				case 4: scoretext[0] = '4'; break;
				case 5: scoretext[0] = '5'; break;
				case 6: scoretext[0] = '6'; break;
				case 7: scoretext[0] = '7'; break;
				case 8: scoretext[0] = '8'; break;
				case 9: scoretext[0] = '9'; break;
				}
				scoretext[2] = '\0';

			}
		}
		if (!stopflag) {
			textSize(200);
			if (score == 100) {
				text("100", width / 2 - 150, height / 2 - 100);
			}
			else if (score <= 9) {
				text(scoretext, width / 2 - 50, height / 2 - 100);
			}
			else if (score >= 10 && score <= 99) {
				text(scoretext, width / 2 - 100, height / 2 - 100);
			}
			remain -= delta;
			if (remain <= 0) {
				if (counter) {
					play_init = true;
					stopflag = true;
				}
				else {
					scene = result;
					c1.Px = 1600;
					c1.Py = 470;

					c3.Px = 1640;
					c3.Py = 430;
					c4.Px = 1560;
					c4.Py = 430;

					l3.Sx = 1600;
					l3.Sy = 460;
					l3.Ex = 1585;
					l3.Ey = 490;
					l4.Sx = 1585;
					l4.Sy = 490;
					l4.Ex = 1600;
					l4.Ey = 490;

					l5.Sx = 1590;
					l5.Sy = 530;
					l5.Ex = 1605;
					l5.Ey = 530;

					if (totalscore <= 9) {
						switch (totalscore) {
						case 0: scoreStr[0] = '0'; break;
						case 1: scoreStr[0] = '1'; break;
						case 2: scoreStr[0] = '2'; break;
						case 3: scoreStr[0] = '3'; break;
						case 4: scoreStr[0] = '4'; break;
						case 5: scoreStr[0] = '5'; break;
						case 6: scoreStr[0] = '6'; break;
						case 7: scoreStr[0] = '7'; break;
						case 8: scoreStr[0] = '8'; break;
						case 9: scoreStr[0] = '9'; break;
						}
						scoreStr[1] = '\0';
					}
					else if (totalscore >= 10 && totalscore <= 99) {
						switch (totalscore % 10) {
						case 0: scoreStr[1] = '0'; break;
						case 1: scoreStr[1] = '1'; totalscore -= 1; break;
						case 2: scoreStr[1] = '2'; totalscore -= 2; break;
						case 3: scoreStr[1] = '3'; totalscore -= 3; break;
						case 4: scoreStr[1] = '4'; totalscore -= 4; break;
						case 5: scoreStr[1] = '5'; totalscore -= 5; break;
						case 6: scoreStr[1] = '6'; totalscore -= 6; break;
						case 7: scoreStr[1] = '7'; totalscore -= 7; break;
						case 8: scoreStr[1] = '8'; totalscore -= 8; break;
						case 9: scoreStr[1] = '9'; totalscore -= 9; break;
						}
						totalscore /= 10;
						switch (totalscore) {
						case 1: scoreStr[0] = '1'; break;
						case 2: scoreStr[0] = '2'; break;
						case 3: scoreStr[0] = '3'; break;
						case 4: scoreStr[0] = '4'; break;
						case 5: scoreStr[0] = '5'; break;
						case 6: scoreStr[0] = '6'; break;
						case 7: scoreStr[0] = '7'; break;
						case 8: scoreStr[0] = '8'; break;
						case 9: scoreStr[0] = '9'; break;
						}
						scoreStr[2] = '\0';
					}
					else if (totalscore >= 100) {
						switch (totalscore % 10) {
						case 0: scoreStr[2] = '0'; break;
						case 1: scoreStr[2] = '1'; totalscore -= 1; break;
						case 2: scoreStr[2] = '2'; totalscore -= 2; break;
						case 3: scoreStr[2] = '3'; totalscore -= 3; break;
						case 4: scoreStr[2] = '4'; totalscore -= 4; break;
						case 5: scoreStr[2] = '5'; totalscore -= 5; break;
						case 6: scoreStr[2] = '6'; totalscore -= 6; break;
						case 7: scoreStr[2] = '7'; totalscore -= 7; break;
						case 8: scoreStr[2] = '8'; totalscore -= 8; break;
						case 9: scoreStr[2] = '9'; totalscore -= 9; break;
						}
						totalscore /= 10;
						switch (totalscore%10) {
						case 0: scoreStr[1] = '0'; break;
						case 1: scoreStr[1] = '1'; totalscore -= 1; break;
						case 2: scoreStr[1] = '2'; totalscore -= 2; break;
						case 3: scoreStr[1] = '3'; totalscore -= 3; break;
						case 4: scoreStr[1] = '4'; totalscore -= 4; break;
						case 5: scoreStr[1] = '5'; totalscore -= 5; break;
						case 6: scoreStr[1] = '6'; totalscore -= 6; break;
						case 7: scoreStr[1] = '7'; totalscore -= 7; break;
						case 8: scoreStr[1] = '8'; totalscore -= 8; break;
						case 9: scoreStr[1] = '9'; totalscore -= 9; break;
						}
						totalscore /= 10;
						switch (totalscore) {
						case 1: scoreStr[0] = '1'; break;
						case 2: scoreStr[0] = '2'; break;
						case 3: scoreStr[0] = '3'; break;
						case 4: scoreStr[0] = '4'; break;
						case 5: scoreStr[0] = '5'; break;
						case 6: scoreStr[0] = '6'; break;
						case 7: scoreStr[0] = '7'; break;
						case 8: scoreStr[0] = '8'; break;
						case 9: scoreStr[0] = '9'; break;
						}
						scoreStr[3] = '\0';


					}
				}
			}
		}
	}
	void GAME::Result()
	{
		clear(204, 242, 255);
		//描画
		//動かす円		
		stroke(0);
		fill(255);
		circle(c1.Px, c1.Py, c1.Diameter);
		circle(c2.Px, c2.Py, c2.Diameter);
		fill(0);
		circle(c3.Px, c3.Py, c3.Diameter);
		circle(c4.Px, c4.Py, c4.Diameter);
		//鼻
		line(l3.Sx, l3.Sy, l3.Ex, l3.Ey);
		line(l4.Sx, l4.Sy, l4.Ex, l4.Ey);
		//口
		line(l5.Sx, l5.Sy, l5.Ex, l5.Ey);
		circle(c5.Px, c5.Py, c5.Diameter);
		circle(c6.Px, c6.Py, c6.Diameter);
		circle(c7.Px, c7.Py, c7.Diameter);
		line(l1.Sx, l1.Sy, l1.Ex, l1.Ey);
		line(l2.Sx, l2.Sy, l2.Ex, l2.Ey);

		textSize(scoresize);
		text(totalStr, totalStrPx, totalStrPy);
		text(scoreStr, scoreStrPx, scoreStrPy);
		textSize(infosize);
		text(titleStr, titleStrPx, titleStrPy);
		text(menuStr, menuStrPx, menuStrPy);

		if (isTrigger(KEY_SPACE)) {
			scene = title;
		}
		if (isTrigger(KEY_ENTER)) {
			BackToMenuFlag = 1;
		}
	}
}