#pragma once
class GAME2
{
//�R���e�i
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//�V�[��
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
	SCENE_ID CurSceneId; //���݂�SCENEID
public:
	void changeScene(SCENE_ID sceneId);
//�L�����N�^
private:
	class PLAYER* Player;
public:
	class PLAYER* player() { return Player; }
public:
	GAME2();
	~GAME2();
	void run();


};

