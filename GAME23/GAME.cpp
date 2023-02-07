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
namespace GAME23 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	GAME::GAME(MANAGER* manager){
		create();
		//�t�F�[�h�C���i�����͂�����Ȃ��ł悢�j
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
}