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
namespace GAME00 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

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
		//����actor��mActors�ɂ��邩�T��
		auto iter = std::find(Actors.begin(), Actors.end(), actor);
		if (iter != Actors.end())
		{
			//����Actor�ƃP�c��Actor�����ւ���(������R�s�[����������邽��)
			std::iter_swap(iter, Actors.end() - 1);
			Actors.pop_back();
		}
	}

	void GAME::AddBalls(class BALL* ball) {
		Balls.emplace_back(ball);
	}

	void GAME::RemoveBalls(class BALL* ball) {
		//����actor��mActors�ɂ��邩�T��
		auto iter = std::find(Balls.begin(), Balls.end(), ball);
		if (iter != Balls.end())
		{
			//����Actor�ƃP�c��Actor�����ւ���(������R�s�[����������邽��)
			std::iter_swap(iter, Balls.end() - 1);
			Balls.pop_back();
		}
	}

	void GAME::create()
	{
		hideCursor();
		//Actor�̒ǉ�
		Court = new COURT(this);
		Player = new PLAYER(this);
		new BALL(this);
		Score = new SCORE(this);

		Init(); //�e�평���������s������
	}


	void GAME::destroy()
	{
		//�e�m�ۗ̈�̊J��
		while(!Actors.empty()) {
			delete Actors.back();
		}
		showCursor();
	}

	void GAME::Init() {

		//�eActor�̏�����
		for (ACTOR* actor : Actors) {
			actor->init();
		}
	}

	void GAME::proc(class MANAGER* manager) {

		clear(50);

		UpdatingActors = true;
		if (Gstate == G_play) {
			//�eActor�̍X�V����
			for (auto actor : Actors) {
				actor->update();
			}
		}
		//�eActor�̕`�揈��
		for (auto actor : Actors) {
			actor->draw();
		}
		if (Gstate==G_end) {
			Actors[3]->draw();
		}
		UpdatingActors = false;


		// �ǉ�����������Actor��mActors�ɒǉ�����
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

		// deadActors����������(mActors�������菜�����)
		for (auto actor : deadActors)
		{
			delete actor;
		}
		
		for (int i = 1; i < Balls.size(); i++) {
			if (Balls[i]->py()>height) {
				Balls[i]->SetState(ACTOR::EDead);
			}
		}
		//���j���[�ɖ߂�
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