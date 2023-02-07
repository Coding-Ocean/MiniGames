#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
namespace GAME16 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		Img = loadImage("../game16/assets/unkoWhite.png");
		Img1 = loadImage("../game16/assets/luffy.png");
		Img2 = loadImage("../game16/assets/eneru.png");
		Img3 = loadImage("../game16/assets/tyopa.png");


		Px1 = 1820;
		Py1 = 100;

		Px2 = 100;
		Py2 = height / 2;

		Px3 = 1820;
		Py3 = 1000;


		Vx1 = -20;
		Vx2 = 50;
		Vx3 = -60;

		st = 0;
		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
	
	}

	void GAME::proc(MANAGER* manager)
	{
		//更新
		stop();
		move();
		

		//描画
		clear(200);
		draw();	
		
		

		//円が右に消えたらゲームオーバーとする
		if (st == 1) {
			//うんこ表示
			//rectMode(CENTER);
			//image(Img, width / 2, height / 2);
			//文字表示
			fill(255, 0, 0);
			textSize(200);
			text("Score", 500, 100);
			textSize(60);
			text("Enterでメニューに戻る", 600, 800);
			score();
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