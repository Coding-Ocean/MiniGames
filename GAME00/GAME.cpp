#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "COURT.h"
#include "PLAYER.h"
#include "BALL.h"
#include "GAME.h"
#include "BLOCK.h"
#include "SCORE.h"
namespace GAME00 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager){
		create();
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME() {
		destroy();
	}

	void GAME::AddActor(class ACTOR* actor) {
		if (UpdatingActors)
		{
			PendingActors.emplace_back(actor);
		}
		else
		{
			Actors.emplace_back(actor);
		}
	}

	void GAME::RemoveActor(class ACTOR* actor) {
		//このactorがmActorsにあるか探す
		auto iter = std::find(Actors.begin(), Actors.end(), actor);
		if (iter != Actors.end())
		{
			//このActorとケツのActorを入れ替える(消去後コピー処理を避けるため)
			std::iter_swap(iter, Actors.end() - 1);
			Actors.pop_back();
		}
	}

	void GAME::AddBalls(class BALL* ball) {
		Balls.emplace_back(ball);
	}

	void GAME::RemoveBalls(class BALL* ball) {
		//このactorがmActorsにあるか探す
		auto iter = std::find(Balls.begin(), Balls.end(), ball);
		if (iter != Balls.end())
		{
			//このActorとケツのActorを入れ替える(消去後コピー処理を避けるため)
			std::iter_swap(iter, Balls.end() - 1);
			Balls.pop_back();
		}
	}

	void GAME::create()
	{
		hideCursor();
		//Actorの追加
		Court = new COURT(this);
		Player = new PLAYER(this);
		new BALL(this);
		Score = new SCORE(this);

		Init(); //各種初期化を実行させる
	}


	void GAME::destroy()
	{
		//各確保領域の開放
		while(!Actors.empty()) {
			delete Actors.back();
		}
		showCursor();
	}

	void GAME::Init() {

		//各Actorの初期化
		for (ACTOR* actor : Actors) {
			actor->init();
		}
	}

	void GAME::proc(class MANAGER* manager) {

		clear(50);

		UpdatingActors = true;
		if (Gstate == G_play) {
			//各Actorの更新処理
			for (auto actor : Actors) {
				actor->update();
			}
		}
		//各Actorの描画処理
		for (auto actor : Actors) {
			actor->draw();
		}
		if (Gstate==G_end) {
			Actors[3]->draw();
		}
		UpdatingActors = false;


		// 追加を延期したActorをmActorsに追加する
		for (auto pending : PendingActors)
		{
			Actors.emplace_back(pending);
		}
		PendingActors.clear();

		std::vector<ACTOR*> deadActors;
		for (auto actor : Actors)
		{
			if (actor->GetState() == ACTOR::EDead)
			{
				deadActors.emplace_back(actor);
			}
		}

		// deadActorsを消去する(mActorsからも取り除かれる)
		for (auto actor : deadActors)
		{
			delete actor;
		}
		
		for (int i = 1; i < Balls.size(); i++) {
			if (Balls[i]->py()>height) {
				Balls[i]->SetState(ACTOR::EDead);
			}
		}
		//メニューに戻る
		if (isTrigger(KEY_ENTER)) { BackToMenuFlag = 1; }
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