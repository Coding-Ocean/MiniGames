#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
namespace GAME16 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	GAME::GAME(MANAGER* manager)
	{
		Img = loadImage("../game16/assets/unkoWhite.png");
		Img1 = loadImage("../game16/assets/luffy.png");
		Img2 = loadImage("../game16/assets/eneru.png");
		Img3 = loadImage("../game16/assets/tyopa.png");


		Px1 = 1820;
		Py1 = 100;

		Px2 = 100;
		Py2 = height / 2;

		Px3 = 1820;
		Py3 = 1000;


		Vx1 = -20;
		Vx2 = 50;
		Vx3 = -60;

		st = 0;
		//�t�F�[�h�C���i�����͂�����Ȃ��ł悢�j
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
	
	}

	void GAME::proc(MANAGER* manager)
	{
		//�X�V
		stop();
		move();
		

		//�`��
		clear(200);
		draw();	
		
		

		//�~���E�ɏ�������Q�[���I�[�o�[�Ƃ���
		if (st == 1) {
			//���񂱕\��
			//rectMode(CENTER);
			//image(Img, width / 2, height / 2);
			//�����\��
			fill(255, 0, 0);
			textSize(200);
			text("Score", 500, 100);
			textSize(60);
			text("Enter�Ń��j���[�ɖ߂�", 600, 800);
			score();
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