#pragma once
#include"../MAIN/STATE.h"
#include <math.h>

namespace GAME03 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI
	//覐΂̌�
	#define ENUM 5

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//�����ɕK�v�ȋL���ꏊ��p�ӂ���
		struct BULLET{
			int Eflag, Ex, Ey, EVy, Er;
		};
		//�v���C���[�i���@�j�̃f�[�^
		  //���W
		int Px = 960;
		int Py = 1000;
		  //�ړ����x(��)
		int PVx = 15;
		  //���a
		int Pr = 100;

		//�G(覐�)�f�[�^
		int Eflag[ENUM];
		//���W
		int Ex[ENUM];
		int Ey[ENUM];
		//�ړ����x(�c)
		int EVy[ENUM];
		//���a
		int Er = 50;

		//�e�f�[�^
		//0�Ȃ�\�����Ȃ�
		int Bflag = 0;
		//���W
		int Bx = -50;
		int By = 1180;
		//�ړ����x(�c)
		int BVx = PVx;
		int BVy = 25;
		//���a
		int Br= 5;

		//�_��
		int score = 0;
		int scoresum = 100;
		int clearline = 1500;
		int twice = 1;

		//�_���[�W
		int damage = 30;

		//HP�f�[�^
		//���W
		int hpx = 1510;
		int hpy = 100;
		//�Q�[�W��
		int hp = 300;
		//����
		int h = 60;

		//�摜�f�[�^
		int backgroundImg;
		int playerImg;
		int enemyImg;
		int bulletImg;
		int explosionImg;

		//�����f�[�^
		int bulletsoundImg;
		int explosionsound;

		const int PLAY = 0;
		const int CLEAR = 1;
		const int OVER = 2;
		int State = PLAY;

		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag=0;
	};

}

