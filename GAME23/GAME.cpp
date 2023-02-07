#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "BOSS.h"
#include "COURT.h"
#include "PLAYER.h"
#include "BALL.h"
#include "AI.h"
#include "HP.h"
#include "GAME.h"
namespace GAME23 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager){
		create();
		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}
	GAME::~GAME() {
		destroy();
	}

	void GAME::create()
	{
		Actors.push_back(Court = new COURT(this));
		Actors.push_back(Player = new PLAYER(this));
		Actors.push_back(Ball = new BALL(this));
		Actors.push_back(Boss = new BOSS(this));
		Actors.push_back(Ai = new AI(this));
		Actors.push_back(Hp = new HP(this));
		Init();
	}

	void GAME::destroy()
	{
		for (ACTOR* actor : Actors) {
			delete actor;
		}
	}

	void GAME::Init()
	{
		for (ACTOR* actor : Actors) {
			actor->init();
		}
	}

	void GAME::proc(MANAGER*manager)
	{
		clear(60, 0, 0);

		for (ACTOR* actor : Actors) {
			actor->update();
		}
		for (ACTOR* actor : Actors) {
			actor->draw();
		}
		//メニューに戻る
		if (isTrigger(KEY_ENTER)) {
			BackToMenuFlag = 1;
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