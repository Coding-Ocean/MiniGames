#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
//210209
namespace GAME05 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI
	MYCIRCLE *c1 = new MYCIRCLE;
	EBALL *b1 = new EBALL[10];
	int sd;
	GAME::GAME(MANAGER* manager)
	{
		sound();
		//�{�[������
		strokeWeight(1);
		c1->init();
		for (int i = 0; i < 10; i++) {
			b1[i].init();
		}
		
		hideCursor();


		Img = loadImage("../game05/assets/unkoWhite.png");
		//�t�F�[�h�C���i�����͂�����Ȃ��ł悢�j
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
		showCursor();
	}

	void GAME::proc(MANAGER* manager)
	{
		//�X�V
		c1->move();
		c1->collsionWall();
		c1->scoreCounter();
		if (c1->hp() > 0) {
			for (int i = 0; i < 10; i++) {
				b1[i].move();
			}
		}
		for (int i = 0; i < 10; i++) {
			b1[i].collisionWall();
		}
		
		for (int i = 0; i < 10; i++) {
			c1->collisionBall(b1[i].px(), b1[i].py(), b1[i].diameter());
		}
		
		//�`��
		clear(200);
		for (int i = 0; i < 10; i++) {
			b1[i].draw();
		}
		fill(220, 220, 220);
		c1->draw();
		fill(40, 40, 40);
		
		//�Q�[���I�[�o�[�Ƃ���
		if (c1->hp() <= 0) {
			//���񂱕\��
			dsound();
			rectMode(CENTER);
			image(Img, width / 2, height / 2);
			//�����\��
			c1->scoredraw();
			fill(255, 0, 0);
			textSize(200);
			text("Game Over", 500, 100);
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
