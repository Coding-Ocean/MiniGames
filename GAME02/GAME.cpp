#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include <time.h>
#include<math.h>
namespace GAME02 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

#define mag(x, y) sqrt(x * x + y * y)

	GAME::GAME(MANAGER* manager)
	{
		//�����̎��ݒ�
		srand((unsigned)time(NULL));

		//�摜�̓ǂݍ���
		bgaImg = loadImage("../game02/assets/back.png");

		ttlImg = loadImage("../game02/assets/Space_Darts.png");
		strBttImg = loadImage("../game02/assets/Start.png");

		trgImg = loadImage("../game02/assets/target.png");

		Parr0Img = loadImage("../game02/assets/arrow0.png");
		Parr1Img = loadImage("../game02/assets/arrow1.png");
		Parr2Img = loadImage("../game02/assets/arrow2.png");
		Parr3Img = loadImage("../game02/assets/arrow3.png");
		Parr4Img = loadImage("../game02/assets/arrow4.png");
		
		Parrk0Img = loadImage("../game02/assets/arrk0.png");
		Parrk1Img = loadImage("../game02/assets/arrk1.png");
		Parrk2Img = loadImage("../game02/assets/arrk2.png");
		Parrk3Img = loadImage("../game02/assets/arrk3.png");
		Parrk4Img = loadImage("../game02/assets/arrk4.png");

		TarrImg = loadImage("../game02/assets/arrow0.png");

		RetBttImg = loadImage("../game02/assets/ReturnToTitle.png");
		RBtMBttImg = loadImage("../game02/assets/ReturnToMenu.png");
		RscrImg = loadImage("../game02/assets/Score.png");
		RtotalImg = loadImage("../game02/assets/Total.png");

		//�t���b�O
		TarrFlag = 0;
		sceneFlag = 0;

		//���W
		TttlPx = TstrPx = TctlPx = PtrgPx = RBtTPx = RBtMPx = width / 2;
		TarrPx = 1500;
		TttlPy = 180;
		TstrPy = TarrPy = 925;
		PtrgPy = height / 2;
		Plong = 146 / 2;
		RBtTPy = 875;
		RBtMPy = 1000;
		RscrPx = 1600;
		RscrPy = 250;
		RtotalPx = 1530;
		RtotalPy = 400;
		RdigitPy = 375;
		ROdigitPx = RtotalPx + 197;
		RTdigitPx = RtotalPx + 140;

		Pnarr = 0;	//���̖�
		Rscrbuf = 0;

		//��̐���
		createArr();

		//�t�F�[�h�C���i�����͂�����Ȃ��ł悢�j
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
	}

	void GAME::proc(MANAGER* manager)
	{

		//�w�i
		rectMode(CORNER);
		for (int w = 0; w < 1920; w += 388) {
			for (int h = 0; h < 1080; h += 400) {
				image(bgaImg, w, h, 0);
			}
		}

		//�V�[���t���b�O
		if (sceneFlag % 3 == 0) title();
		else if (sceneFlag % 3 == 1)play();
		else if (sceneFlag % 3 == 2) result();
			
		//�G���^�[�Ń��j���[�ֈڍs
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

	//�ϐ��̏�����
	void GAME::init()
	{
		TarrFlag = 0;
		TarrPx = 1500;
		Pnarr = 0;
		Rscrbuf = 0;
		Rtot = 0;

		createArr();
	}

	void GAME::createArr()
	{
		for (int i = 0; i < 10; i++) {
			//�����ʒu
			do {
				arr[i].X = rand() % 2321 - 200;
				arr[i].Y = rand() % 1281 - 200;
			} while (arr[i].X > -180 && arr[i].X<2100 &&
				arr[i].Y>-180 && arr[i].Y < 1260);

			//�x�N�g��
			Normalize(Abs(width / 2 - arr[i].X), Abs(height / 2 - arr[i].Y), &arr[i].VX, &arr[i].VY);
			if (arr[i].X > width / 2)arr[i].VX *= -1;
			if (arr[i].Y > height / 2)arr[i].VY *= -1;

			//�X�s�[�h
			arr[i].spd = (float)(rand() % 200 + 170) / 10;

			//�A���O��
			arr[i].ang = 180 / 3.141592f * (acos(0 * arr[i].VX + 1 * arr[i].VY / (mag(0, 1) * mag(arr[i].VX, arr[i].VY))));
			if (arr[i].X < width / 2)arr[i].ang *= -1;
		}


		//�摜
		arr[0].img = Parr0Img;
		arr[1].img = Parr0Img;
		arr[2].img = Parr1Img;
		arr[3].img = Parr1Img;
		arr[4].img = Parr2Img;
		arr[5].img = Parr2Img;
		arr[6].img = Parr3Img;
		arr[7].img = Parr3Img;
		arr[8].img = Parr4Img;
		arr[9].img = Parr4Img;
		int a, b;
		for (int i = 0; i < 5; i++) {
			do {
				a = rand() % 10;
				b = rand() % 10;
			} while (a == b);
			int buf = arr[a].img;
			arr[a].img = arr[b].img;
			arr[b].img = buf;
		}
	}

	//�X�R�A�̌v�Z
	int GAME::Score(float x, float y)
	{
		int S = 0;
		float D = 0;

		D = mag(Abs(width / 2 - x), Abs(height / 2 - y));
		if (D >= 0 && D < 50)S = 5;
		else if (D >= 50 && D < 100)S = 4;
		else if (D >= 100 && D < 150)S = 3;
		else if (D >= 150 && D < 200)S = 2;
		else if (D >= 200 && D < 250)S = 1;
		else S = 0;

		return S;
	}
	//�^�C�g�����
	void GAME::title()
	{
		
		//�摜�̕\��
		rectMode(CENTER);
		image(ttlImg, TttlPx, TttlPy, 0, 1.7);
		image(trgImg, PtrgPx, PtrgPy, 0, 1.4);
		image(strBttImg, TstrPx, TstrPy, 0, 0.8);
		image(TarrImg, TarrPx, TarrPy, 90, 0.5);
		
		//�X�^�[�g�{�^��
		if (isTrigger(KEY_SPACE)) {
			TarrFlag = 1;
		}
		if (TarrFlag) {
			TarrPx -= 25;
		}

		//�v���C��ʂւ̈ڍs
		if (TarrPx < -700) {
			sceneFlag++;
		}
	}

	//�v���C���
	void GAME::play()
	{

		//�摜�̕\��
		rectMode(CENTER);
		image(trgImg, PtrgPx, PtrgPy, 0, 1.4);

		//�X�y�[�X�{�^���Ŗ�̔���
		if (isTrigger(KEY_SPACE)) {
			if (arr[Pnarr].img == Parr0Img)arr[Pnarr].img = Parrk0Img;
			else if (arr[Pnarr].img == Parr1Img)arr[Pnarr].img = Parrk1Img;
			else if (arr[Pnarr].img == Parr2Img)arr[Pnarr].img = Parrk2Img;
			else if (arr[Pnarr].img == Parr3Img)arr[Pnarr].img = Parrk3Img;
			else if (arr[Pnarr].img == Parr4Img)arr[Pnarr].img = Parrk4Img;

			//�������̒���
			if (arr[Pnarr].VX > 0)arr[Pnarr].X += arr[Pnarr].VX * arr[Pnarr].VX * Plong;
			else arr[Pnarr].X -= arr[Pnarr].VX * arr[Pnarr].VX * Plong;
			if (arr[Pnarr].VY > 0)arr[Pnarr].Y += arr[Pnarr].VY * arr[Pnarr].VY * Plong;
			else arr[Pnarr].Y -= arr[Pnarr].VY * arr[Pnarr].VY * Plong;

			//��ɃX�R�A���������Ď��̖�Ɉȍ~
			arr[Pnarr].scr = Score(arr[Pnarr].X, arr[Pnarr].Y);
			Rtot += arr[Pnarr].scr;
			Pnarr++;
		}

		//��ʂ̊O�ɏo���玩���I�Ɏ��̖�Ɉڍs
		if (arr[Pnarr].X<-300 || arr[Pnarr].X>width + 300 || arr[Pnarr].Y<-300 || arr[Pnarr].Y>height + 300) {
			arr[Pnarr].scr = 0;
			Pnarr++;
		}

		//��̈ړ�
		if (Pnarr < 10) {
			arr[Pnarr].X += arr[Pnarr].VX * arr[Pnarr].spd;
			arr[Pnarr].Y += arr[Pnarr].VY * arr[Pnarr].spd;
		}

		//��̕\��
		for (int i = 0; i < 10; i++) {
			image(arr[i].img, arr[i].X, arr[i].Y, arr[i].ang, 0.5f);
		}

		//�X�R�A�̍��v�����Ƃɓ_���\���ɕK�v�ȉ摜��ǂݍ���
		if (Pnarr == 10) {
			sceneFlag++;
			Rscrbuf = Rtot;
			switch (Rscrbuf % 10) {
			case 0:RdigitOImg = loadImage("../game02/assets/T0.png"); Rscrbuf -= 0; break;
			case 1:RdigitOImg = loadImage("../game02/assets/T1.png"); Rscrbuf -= 1; break;
			case 2:RdigitOImg = loadImage("../game02/assets/T2.png"); Rscrbuf -= 2; break;
			case 3:RdigitOImg = loadImage("../game02/assets/T3.png"); Rscrbuf -= 3; break;
			case 4:RdigitOImg = loadImage("../game02/assets/T4.png"); Rscrbuf -= 4; break;
			case 5:RdigitOImg = loadImage("../game02/assets/T5.png"); Rscrbuf -= 5; break;
			case 6:RdigitOImg = loadImage("../game02/assets/T6.png"); Rscrbuf -= 6; break;
			case 7:RdigitOImg = loadImage("../game02/assets/T7.png"); Rscrbuf -= 7; break;
			case 8:RdigitOImg = loadImage("../game02/assets/T8.png"); Rscrbuf -= 8; break;
			case 9:RdigitOImg = loadImage("../game02/assets/T9.png"); Rscrbuf -= 9; break;
			}

			Rscrbuf /= 10;
			switch (Rscrbuf % 100) {
			case 0: RdigitTImg = loadImage("../game02/assets/T0.png"); break;
			case 1: RdigitTImg = loadImage("../game02/assets/T1.png"); break;
			case 2: RdigitTImg = loadImage("../game02/assets/T2.png"); break;
			case 3: RdigitTImg = loadImage("../game02/assets/T3.png"); break;
			case 4: RdigitTImg = loadImage("../game02/assets/T4.png"); break;
			case 5: RdigitTImg = loadImage("../game02/assets/T5.png"); break;
			case 6: RdigitTImg = loadImage("../game02/assets/T6.png"); break;
			case 7: RdigitTImg = loadImage("../game02/assets/T7.png"); break;
			case 8: RdigitTImg = loadImage("../game02/assets/T8.png"); break;
			case 9: RdigitTImg = loadImage("../game02/assets/T9.png"); break;
			}
		}
	}

	//���U���g���
	void GAME::result()
	{

		//�摜�̕\��
		rectMode(CENTER);
		image(trgImg, PtrgPx, PtrgPy, 0, 1.4);

		//��̕\��
		for (int i = 0; i < 10; i++) {
			image(arr[i].img, arr[i].X, arr[i].Y, arr[i].ang, 0.5f);
		}

		//�摜�̕\��
		image(RetBttImg, RBtTPx, RBtTPy, 0, 0.8);
		image(RBtMBttImg, RBtMPx, RBtMPy, 0, 0.8);
		image(RscrImg, RscrPx, RscrPy, 0, 0.8);
		image(RtotalImg, RtotalPx, RtotalPy, 0, 0.5);
		
		//�_���摜�̕\��
		imageColor(200);
		image(RdigitOImg, ROdigitPx, RdigitPy, 0, 0.12);
		if ((Rtot - Rtot % 10) % 100 != 0)	image(RdigitTImg, RTdigitPx, RdigitPy, 0, 0.12);
		imageColor(255);

		//�^�C�g���ֈڍs�A�ϐ��̏�����
		if (isTrigger(KEY_SPACE)) {
			sceneFlag++;
			init();
		}
	}

	//�x�N�g���̐��K��
	void GAME::Normalize(float x, float y, float* vx, float* vy)
	{
		*vx = x / mag(x, y);
		*vy = y / mag(x, y);
	}

	//���������~���b�~�߂�
	int GAME::sleep(unsigned long x)
	{
		clock_t c1 = clock(), c2 = 0;

		do {
			if ((c2 = clock()) == (clock_t)-1) {
				return 0;
			}
		} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
		return 1;
	}
}