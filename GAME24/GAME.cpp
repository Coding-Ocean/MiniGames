#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
namespace GAME24 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		Img = loadImage("../game24/assets/unkoWhite.png");

		Diameter = 200;
		Px = -100;
		Py = height / 2;
		Vx = 20;

		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
	}

	void GAME::proc(MANAGER* manager)
	{
		//更新
		Px += Vx;

		//描画
		clear(200);
		circle(Px, Py, Diameter);
		
		//円が右に消えたらゲームオーバーとする
		if (Px > 2100) {
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