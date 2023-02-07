#pragma once
class GAME2
{
//コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//シーン
public:
	enum SCENE_ID {
		TITLE_ID,	//0
		STAGE_ID,	//1
		GAME_CLEAR_ID,	//2
		GAME_OVER_ID,	//3
		NUM_SCENES	//4
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId; //現在のSCENEID
public:
	void changeScene(SCENE_ID sceneId);
//キャラクタ
private:
	class PLAYER* Player;
public:
	class PLAYER* player() { return Player; }
public:
	GAME2();
	~GAME2();
	void run();


};

