#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include "Windows.h"

namespace GAME03 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	GAME::GAME(MANAGER* manager)
	{
		//�摜�f�[�^
		backgroundImg = loadImage("../game03/assets/�w�i.png");
		playerImg = loadImage("../game03/assets/���@.png");
		enemyImg = loadImage("../game03/assets/覐�.png");
		bulletImg = loadImage("../game03/assets/�e.png");
		explosionImg = loadImage("../game03/assets/�����G�t�F�N�g.png");
		//�����f�[�^
		bulletsoundImg = loadSound("../game03/assets/���ˉ�.wav");
		explosionsound = loadSound("../game03/assets/����.wav");
		playSound(bulletsoundImg);

		for (int i = 0; i < ENUM; i++) {
			Eflag[i] = 1;
			Ex[i] = random(100, 1350);
			Ey[i] = -random(10, 1000);
			EVy[i] = random(5, 10);
		}
		//�t�F�[�h�C���i�����͂�����Ȃ��ł悢�j
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
	}

	void GAME::proc(MANAGER* manager)
	{

		if (State == PLAY) {
			//�v���C���[�ړ�
			if (isPress(KEY_D)) { Px += PVx; }//�E�ړ�
			if (isPress(KEY_A)) { Px -= PVx; }//���ړ�
			//�v���C���[�̉�ʊO�̔���
			if (1400 < Px) { Px = 1400; }
			else if (0 > Px) { Px = 0; }
			//�G
			for (int i = 0; i < ENUM; i++) {
				if (Eflag[i] == 1) {
					Ey[i] += EVy[i];
					//circle(Ex[i], Ey[i], Er*2);
					//���܂ōs������
					if (1080 + Er < Ey[i]) {
						//�����_��
						Ex[i] = random(100, 1320);
						Ey[i] = -random(10, 1000);
						EVy[i] = random(5, 10);
						//hp��0�ɂȂ�����Q�[�W���~�߂�
						if (hp > 0) {
							hp -= damage;
						}
					}
				}
			}
			//�e����KEY�������ꂽ�Ƃ�
			if (Bflag == 0) {
				if (isTrigger(KEY_SPACE)) {
					playSound(bulletsoundImg);
					Bx = Px;
					By = Py - 70;
					Bflag = 1;
				}
			}
			//�e�ړ�
			if (Bflag != 0) {
				//circle(Bx, By, Br*2);
				By -= BVy;
				//�E�B���h�E�̊O�ɏo����
				if (By <= 0) {
					//Bx = Px;
					//By = Py - 70;
					Bflag = 0;
				}
			}
			//�����@����������flag��0�ɂ���
			//�~�̒��S�_�𑪂�
			if (Bflag == 1) {
				for (int i = 0; i < ENUM; i++) {
					int distance = sqrt(pow(Bx - Ex[i], 2) + pow(By - Ey[i], 2));
					if (distance < Er + Br) {
						playSound(explosionsound);
						score += scoresum;
						By = -10;
						Bflag = 0;
						//���������烉���_���ɗ��Ƃ�
						Ey[i] = -random(10, 1000);
						Ex[i] = random(200, 1350);
					}
				}
			}

			if (score >= clearline) {
				State = CLEAR;
			}
			if (hp <= 0) {
				State = OVER;
			}
		}

		//�w�i�F
		clear(255);
		//���̑���
		strokeWeight(3);
		//�w�i
		image(backgroundImg, 0, 0);
		//�v���C���[
		image(playerImg, Px - 40, Py - 45);
		//�e
		if(Bflag)image(bulletImg, Bx - 11, By - 10);
		//�G�\��
		for (int i = 0; i < ENUM; i++) {
			if (Eflag[i] == 1) {
				image(enemyImg, Ex[i]-60, Ey[i]-105);
			}
		}


		//�N���A���
		if(State==CLEAR){
			textSize(200);
			text("GAME CLEAR", 200, 400);
		}

		//�Q�[���I�[�o�[���
		if(State==OVER){
			textSize(200);
			text("GAME OVER", 200, 400);
		}


		fill(100, 100, 100);
		//�X�R�A�\��,���������ɐF��t����ɂ́H
		rect(hpx, hpy, hp, h);
		textSize(60);
		text("�n���̖�", 1500, 30);
		text("�X�R�A", 1500, 200);
		text(score, 1500, 300);
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