#pragma once
#include"../MAIN/STATE.h"
#include<stdio.h>
namespace GAME06 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//�����ɕK�v�ȋL���ꏊ��p�ӂ���
		//�摜�\���p
		int Img;
		//�~�\���p
		float Diameter;//���a
		float Px;
		float Py;
		float Vx;
		float Vy;

		float PastPx = 0;
		float PastPy = 0;
		bool drawing = true;
	    
		COLOR color;

		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag=0;
	};

}