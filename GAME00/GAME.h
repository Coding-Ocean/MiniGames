#pragma once
#include <vector>
#include"../MAIN/STATE.h"

namespace GAME00 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();

		enum G_state{
			G_play,
			G_end
		};

		void create();  //選択画面からの切り替え
		void destroy(); //このゲームの終了処理
		void proc(class MANAGER* manager);    //メインループ

		void AddActor(class ACTOR* actor);
		void RemoveActor(class ACTOR* actor);
		void AddBalls(class BALL* ball);
		void RemoveBalls(class BALL* ball);

		void SetGstate(G_state state) { Gstate = state; }
		G_state GetGstate() { return Gstate; }

		//Getter
		class ACTOR* court() { return Court; }
		class ACTOR* player() { return Player; }
		class ACTOR* score() { return Score; }

		std::vector<class BALL*> Getballs() { return Balls; }
	private:

		void Init(); //初期化

		G_state Gstate = G_play;

		//ここに必要な記憶場所を用意する
		std::vector<class ACTOR*>Actors;
		std::vector<class BALL*> Balls;

		class ACTOR* Court;
		class ACTOR* Player;
		class ACTOR* Score;

		// Update中フラッグ
		bool UpdatingActors=false;
		std::vector<class ACTOR*> PendingActors;

		//以下はいじらないでよい
		int BackToMenuFlag = 0;
	};

}
