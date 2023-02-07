#pragma once
#include<vector>
#include"../MAIN/STATE.h"

namespace GAME23 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！
	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void create();
		void destroy();
		void proc(class MANAGER*manager);
		class ACTOR* court() { return Court; }
		class ACTOR* player() { return Player; }
		class ACTOR* ball() { return Ball; }
		class ACTOR* boss() { return Boss; }
		class ACTOR* ai() { return Ai; }
		class ACTOR* hp() { return Hp; }
	private:
		void Init();
		//ここに必要な記憶場所を用意する
		std::vector<class ACTOR*>Actors;
		class ACTOR* Court;
		class ACTOR* Player;
		class ACTOR* Ball;
		class ACTOR* Boss;
		class ACTOR* Ai;
		class ACTOR* Hp;
		//以下はいじらないでよい
		int BackToMenuFlag = 0;
	};
}
