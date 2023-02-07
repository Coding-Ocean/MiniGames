#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
namespace GAME01 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	GAME::GAME(MANAGER* manager)
	{
		init();
		load();
		sound();
		
		//�t�F�[�h�C���i�����͂�����Ȃ��ł悢�j
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
		
	}

	void GAME::proc(MANAGER* manager)
	{
		//playSound(bgm);

		if (isTrigger(KEY_SPACE)) {
			init();
			roll();
		}
		//�Q�[���I�[�o�[�̏���
		if (nowHp == 0 && roading == 0) {
			over = 1;
			if (bgmFlag = 0) {
				stopSound(bgm);
				bgmFlag = 1;
			}
		}



		if (roading == 1) {
			int counter = 0;
			counter++;
			if (isTrigger(KEY_A)) {
				playSound(osu);
				roal1 = 0;
			}

			if (roal1 == 1) {
				++counter1 %= 9 * interval;
				no1 = counter1 / interval;

			}

			if (isTrigger(KEY_S)) {
				playSound(osu);
				roal2 = 0;
			}

			if (roal2 == 1) {
				++counter2 %= 9 * interval;
				no2 = counter2 / interval;
			}

			if (isTrigger(KEY_D)) {
				playSound(osu);
				roal3 = 0;
			}

			if (roal3 == 1) {
				++counter3 %= 9 * interval;
				no3 = counter3 / interval;
				

			}
			if (roal1 == 0 && roal2 == 0 && roal3 == 0) {
				
				roading = 0;
				if (no1 != no2 && no2 != no3 && no1 != no3) {
					bgmFlag = 0;
					nowHp = 0;
				}
			}
		}
		
		


		clear();

		image(back, 237, 0, 0);
		//playSound(bgm);
		image(Imgs[no1], width / 4 - 10, height / 3, 0, 3);
		image(Imgs[no2], width / 2 - 150, height / 3, 0, 3);
		image(Imgs[no3], width / 2 + 200, height / 3, 0, 3);



		//�X�V
		//Px += Vx;
		//Py += Vy;
		//�`��
		//circle(Px, Py, Diameter);

	
		if (over) {
			stopSound(bgm);
			//playSound(game_over_music);
			//rectMode(CENTER);
			image(game_over, 500, 0, 0, 5);
			//�����\��
			fill(0, 0, 0);
			textSize(200);
			text("�j�Y ^^ ", 500, 100);
			textSize(60);
			text("Enter�Ń��j���[�ɖ߂�", 600, 800);
			//���j���[�ɖ߂�
			if (isTrigger(KEY_ENTER)) {
				BackToMenuFlag = 1;
			}
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