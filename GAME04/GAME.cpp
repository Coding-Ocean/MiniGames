#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include "MATH.h"
namespace GAME04 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		Img = loadImage("../game00/assets/unkoWhite.png");

		Diameter = 200;
		Px = width / 2;
		Py = height-Diameter / 2-100;
		Vx = 20;
		Vy = 5;

		Eiameter = 150;
		Ex = width / 2;
		Ey = Eiameter / 2;
		EVx = 20;
		EVy = 20;
		
		Aiameter = 300;
		Ax = width / 2;
		Ay = height / 2;
		AVx = -10;
		AVy = 30;

		Biameter = 200;
		Bx = width / 2 - Biameter;
		By = height / 2;
		BVx = random(20,120);
		Vy = -20;
		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}
	
	GAME::~GAME()
	{
	}
	void GAME::roundFace(float px, float py) {
		fill(255, 255, 0);
		circle(px, py, 300);
		fill(255);
		circle(px - 50, py, 80);
		circle(px + 50, py, 80);
		fill(0);
		circle(px - 50, py, 30);
		circle(px + 50, py, 30);
		fill(255, 200, 200);
		circle(px, py + 80, 80);
	}
	void GAME::squareFace(float px, float py) {
		rectMode(CENTER);
		fill(255, 255, 0);
		rect(px, py, 300, 300);
		fill(255);
		rect(px - 50, py, 80, 80);
		rect(px + 50, py, 80, 80);
		fill(0);
		rect(px - 50, py, 30, 30);
		rect(px + 50, py, 30, 30);
		fill(255, 200, 200);
		rect(px, py + 80, 80, 80);
	}
	void GAME::proc(MANAGER* manager) {
		//更新
		a = Px - Ex;
		b = Py - Ey;
		c = Ax - Ex;
		d = Ay - Ey;
		e = Bx - Ey;
		f = By - Ey;

		distance1 = sqrt(a * a + b * b);
		distance2 = sqrt(c * c + d * d);
		distance3 = sqrt(e * e + f * f);
		if (distance1 >= Diameter / 2 + Eiameter / 2 && distance2 >= Aiameter / 2 + Eiameter / 2
			&& distance3 >= Biameter / 2 + Eiameter / 2){ 

			Px += Vx;
			Py += Vy;
			Ax += AVx;
			Ay += AVy;
			Bx += BVx;
			By += BVy;
			if (Px == width - Diameter / 2 || Px == Diameter / 2)
				Vx = -Vx;
			if (Py == height - Diameter / 2 || Py== Diameter / 2)
				Vy = -Vy;

			if (Ax == width - Aiameter / 2 || Ax == Aiameter / 2)
				AVx = -AVx;
			if (Ay == height - Aiameter / 2 || Ay == Aiameter / 2)
				AVy = -AVy;

			if (Bx == width - Biameter / 2 || Bx == Biameter / 2)
				BVx = -BVx;
			if (By == height - Biameter / 2 || By == Biameter / 2)
				BVy = -BVy;

			if (isPress(KEY_A))
				Ex -= EVx;
			if (isPress(KEY_D))
				Ex += EVx;
		    if (isPress(KEY_W))
				Ey -= EVx;
			if (isPress(KEY_S))
				Ey += EVx;
			if (Ex > width - Eiameter / 2)
				Ex = width - Eiameter / 2;
			if (Ex < Eiameter / 2)
				Ex = Eiameter / 2;
			if (Ey < Eiameter / 2)
				Ey = Eiameter / 2;
			if (Ey > height - Eiameter / 2)
				Ey = height - Eiameter / 2;

		}
		
		//描画
		clear(200);
		circle(Ex, Ey, Eiameter);
		circle(Px, Py, Diameter);
		circle(Ax, Ay, Aiameter);
		circle(Bx, By, Biameter);
		

		//円が右に消えたらゲームオーバーとする
		if (distance1 <= Diameter / 2 + Eiameter / 2 || distance2 <= Aiameter / 2 + Eiameter / 2
			|| distance3 <= Biameter / 2 + Eiameter / 2) {
			//うんこ表示
			rectMode(CENTER);
			image(Img, width / 2, height / 2);
			for (int i = 0; i < 20; i++) {
				roundFace(150 + (i * 300), height / 2);
				squareFace(width / 2, 150 + (i * 300));
			}
			//文字表示
			fill(255, 0, 0);
			textSize(200);
			text("Game Over", 500, 100);
			textSize(60);
			text("Enterでメニューに戻る", 600, 800);
			//distance1 = sqrt(a * a + b * b);
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