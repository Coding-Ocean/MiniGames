#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
namespace GAME01 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		init();
		load();
		sound();
		
		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
		
	}

	void GAME::proc(MANAGER* manager)
	{
		//playSound(bgm);

		if (isTrigger(KEY_SPACE)) {
			init();
			roll();
		}
		//ゲームオーバーの条件
		if (nowHp == 0 && roading == 0) {
			over = 1;
			if (bgmFlag = 0) {
				stopSound(bgm);
				bgmFlag = 1;
			}
		}



		if (roading == 1) {
			int counter = 0;
			counter++;
			if (isTrigger(KEY_A)) {
				playSound(osu);
				roal1 = 0;
			}

			if (roal1 == 1) {
				++counter1 %= 9 * interval;
				no1 = counter1 / interval;

			}

			if (isTrigger(KEY_S)) {
				playSound(osu);
				roal2 = 0;
			}

			if (roal2 == 1) {
				++counter2 %= 9 * interval;
				no2 = counter2 / interval;
			}

			if (isTrigger(KEY_D)) {
				playSound(osu);
				roal3 = 0;
			}

			if (roal3 == 1) {
				++counter3 %= 9 * interval;
				no3 = counter3 / interval;
				

			}
			if (roal1 == 0 && roal2 == 0 && roal3 == 0) {
				
				roading = 0;
				if (no1 != no2 && no2 != no3 && no1 != no3) {
					bgmFlag = 0;
					nowHp = 0;
				}
			}
		}
		
		


		clear();

		image(back, 237, 0, 0);
		//playSound(bgm);
		image(Imgs[no1], width / 4 - 10, height / 3, 0, 3);
		image(Imgs[no2], width / 2 - 150, height / 3, 0, 3);
		image(Imgs[no3], width / 2 + 200, height / 3, 0, 3);



		//更新
		//Px += Vx;
		//Py += Vy;
		//描画
		//circle(Px, Py, Diameter);

	
		if (over) {
			stopSound(bgm);
			//playSound(game_over_music);
			//rectMode(CENTER);
			image(game_over, 500, 0, 0, 5);
			//文字表示
			fill(0, 0, 0);
			textSize(200);
			text("破産 ^^ ", 500, 100);
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