#pragma once
#include"../MAIN/STATE.h"

namespace GAME20 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		void init();
		//コンテナ
	private:
		class CONTAINER* Container;
	public:
		class CONTAINER* container() { return Container; }
		//シーン
	public:
		enum SCENE_ID {
			TITLE_ID,
			STAGE_ID,
			GAME_CLEAR_ID,
			GAME_OVER_ID,
			NUM_SCENES
		};
	private:
		class SCENE* Scenes[NUM_SCENES];
		SCENE_ID CurSceneId;
	public:
		void changeScene(SCENE_ID sceneId);
		//キャラクタ
	private:
		class PLAYER* Player;
		class ENEMIES* Enemies;
		class ITEMS* Items;
		class PLAYER_BULLETS* PlayerBullets;
	public:
		void draw();
		class PLAYER* player() { return Player; }
		class ENEMIES* enemies() { return Enemies; }
		class ITEMS* items() { return Items; }
		class PLAYER_BULLETS* playerBullets() {return PlayerBullets; }
		//以下はいじらないでよい
		int BackToMenuFlag=0;
	};

}

