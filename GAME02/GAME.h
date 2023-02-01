#pragma once
#include"../MAIN/STATE.h"

namespace GAME02 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//�����ɕK�v�ȋL���ꏊ��p�ӂ���
		
		//�摜�\���p
		int bgaImg = 0;

		int ttlImg = 0;
		int strBttImg = 0;
		int trgImg = 0;
		int TarrImg = 0;
		int Parr0Img = 0;
		int Parr1Img = 0;
		int Parr2Img = 0;
		int Parr3Img = 0;
		int Parr4Img = 0;
		
		int Parrk0Img = 0;
		int Parrk1Img = 0;
		int Parrk2Img = 0;
		int Parrk3Img = 0;
		int Parrk4Img = 0;
		
		int RetBttImg = 0;
		int RBtMBttImg = 0;
		int RscrImg = 0;
		int RtotalImg = 0;

		int RdigitOImg = 0;
		int RdigitTImg = 0;

		//��̍\����
		struct ARR {
			float X;
			float Y;
			float VX;
			float VY;
			float spd;
			int img;
			float ang;
			int scr;
		};

		//�P�O�{���̖�
		ARR arr[10]{};
		
		//�t���b�O
		int TarrFlag = 0;
		int sceneFlag = 0;

		//�^�C�g�����
		float TttlPx = 0;
		float TttlPy = 0;
		float TstrPx = 0;
		float TstrPy = 0;
		float TctlPx = 0;
		float TctlPy = 0;
		float TarrPx = 0;
		float TarrPy = 0;

		//�v���C���
		float PtrgPx = 0;
		float PtrgPy = 0;
		float PscrPx = 0;
		float PscrPy = 0;
		int Pnarr = 0;
		float Plong = 0;

		//���U���g���
		float RBtTPx = 0;
		float RBtTPy = 0;
		float RBtMPx = 0;
		float RBtMPy = 0;
		float RscrPx = 0;
		float RscrPy = 0;
		float RscrOffPx = 0;
		float RprcPx = 0;
		float RprcPy = 0;
		float RprcOffPx = 0;
		float RtotalPx = 0;
		float RtotalPy = 0;
		int Rtot = 0;
		int Rscrbuf = 0;
		float RdigitPy = 0;
		float ROdigitPx = 0;
		float RTdigitPx = 0;

		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag=0;
	public:
		void init();
		void createArr();
		int Score(float x, float y);
		void title();
		void play();
		void result();
		void Normalize(float x, float y, float* vx, float* vy);
		int sleep(unsigned long x);
	};
}

