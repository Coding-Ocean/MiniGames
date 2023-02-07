#include "../libOne/inc/libOne.h"
#include"../libOne/inc/graphic.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"ENEMIES.h"
#include"ITEMS.h"


namespace GAME20 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	GAME::GAME(MANAGER* manager)
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
		Scenes[GAME_OVER_ID] = new GAME_OVER(this);
		CurSceneId = TITLE_ID;

		Player = new PLAYER(this);
		Enemies = new ENEMIES(this);
		Items = new ITEMS(this);
		PlayerBullets = new PLAYER_BULLETS(this);
		
		init();
		//�t�F�[�h�C���i�����͂�����Ȃ��ł悢�j
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
		delete PlayerBullets;
		delete Enemies;
		delete Items;
		delete Player;
		for (int i = 0; i < NUM_SCENES; i++) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::init() {

		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[GAME_CLEAR_ID]->create();
		Scenes[GAME_OVER_ID]->create();
		Player->create();
		Items->create();
		Enemies->create();
		PlayerBullets->create();
		
		CurSceneId = TITLE_ID;
		Scenes[CurSceneId]->init();
		initDeltaTime();
	}

	void GAME::proc(MANAGER* manager)
	{
		//while (notQuit) {
			setDeltaTime();
			Scenes[CurSceneId]->proc();
		//}
		//���j���[�ɖ߂�
		if (isTrigger(KEY_ENTER)) {
			BackToMenuFlag = 1;
		}
		//���j���[�ɖ߂� (��{�I�Ɉȉ��͂�����Ȃ��Ă悢)
		manager->fade->draw();
		if (BackToMenuFlag == 1) {
			manager->fade->fadeOutTrigger();
			if (manager->fade->fadeOutEndFlag()) {
				delete manager->state;
				manager->state = new MENU(manager);
			}
		}

	}

	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[CurSceneId]->init();
	}

	void GAME::draw() {
		clear(169, 206, 239);
		Player->draw();
		Items->draw();
		Enemies->draw();
		PlayerBullets->draw();
	}
}