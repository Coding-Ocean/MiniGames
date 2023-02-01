#pragma once
#include"../MAIN/STATE.h"

namespace GAME21 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//�����ɕK�v�ȋL���ꏊ��p�ӂ���

		int iwaAImg = 0;
		int iwaBImg = 0;
		int iwaCImg = 0;
		int eftImg = 0;
		
		int titleImg = 0;
		int playImg = 0;
		int resultImg = 0;

		int PbackImg = 0;
		int TbackImg = 0;
		int RbackImg = 0;

		int randtool = 0;
		int toolImg = 0;


		int time0Img = 0;
		int time1Img = 0;
		int time2Img = 0;
		int time3Img = 0;
		int time4Img = 0;
		int time5Img = 0;
		int time6Img = 0;
		int time7Img = 0;
		int time8Img = 0;
		int time9Img = 0;

		int dispFlag = 0;
		int ENHFlag = 0;
		int startFlag = 0;
		int clearFlag = 0;
		int MFlag = 0;

		int Pcnt = 0;


		//���W
		float TbtnPx = 0;
		float TbtnEPy = 0;
		float TbtnOfsY = 0;
		float TbtnW = 0;
		float TbtnH = 0;

		float PtxtASize = 0;
		float PtxtAPx = 0;
		float PtxtAPy = 0;

		float PtimePx = 0;
		float PtimeOfsX = 0;
		float PtimePy = 0;

		float PtimerPx = 0;
		float PtimerPy = 0;


		float ProckPx = 0;
		float ProckPy = 0;
		float ProckOfsY = 0;

		float PeffectPx = 0;
		float PeffectPy = 0;

		float toolang = 0;
		float toolPx = 0;
		float toolPy = 0;

		float ProcksPy[60]{};
		char ProcksState[60]{};

		
		



		//��Փx�ݒ�
		float PtimeE = 0;
		float PtimeN = 0;
		float PtimeH = 0;
		int ProckE = 0;
		int ProckN = 0;
		int ProckH = 0;

		float Ptime = 0;
		int Ptimebuf = 0;
		int Prock = 0;



		



		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag=0;

		void init();
		void update();
		void draw();
		void dispTime();
		void rock();
		

	};


}

