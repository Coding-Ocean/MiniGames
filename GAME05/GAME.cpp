#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
//210209
namespace GAME05 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！
	MYCIRCLE *c1 = new MYCIRCLE;
	EBALL *b1 = new EBALL[10];
	int sd;
	GAME::GAME(MANAGER* manager)
	{
		sound();
		//ボール初期
		strokeWeight(1);
		c1->init();
		for (int i = 0; i < 10; i++) {
			b1[i].init();
		}
		
		hideCursor();


		Img = loadImage("../game05/assets/unkoWhite.png");
		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
		showCursor();
	}

	void GAME::proc(MANAGER* manager)
	{
		//更新
		c1->move();
		c1->collsionWall();
		c1->scoreCounter();
		if (c1->hp() > 0) {
			for (int i = 0; i < 10; i++) {
				b1[i].move();
			}
		}
		for (int i = 0; i < 10; i++) {
			b1[i].collisionWall();
		}
		
		for (int i = 0; i < 10; i++) {
			c1->collisionBall(b1[i].px(), b1[i].py(), b1[i].diameter());
		}
		
		//描画
		clear(200);
		for (int i = 0; i < 10; i++) {
			b1[i].draw();
		}
		fill(220, 220, 220);
		c1->draw();
		fill(40, 40, 40);
		
		//ゲームオーバーとする
		if (c1->hp() <= 0) {
			//うんこ表示
			dsound();
			rectMode(CENTER);
			image(Img, width / 2, height / 2);
			//文字表示
			c1->scoredraw();
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
