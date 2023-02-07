#pragma once
#include"../MAIN/STATE.h"

namespace GAME20 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		void init();
		//�R���e�i
	private:
		class CONTAINER* Container;
	public:
		class CONTAINER* container() { return Container; }
		//�V�[��
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
		//�L�����N�^
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
		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag=0;
	};

}

