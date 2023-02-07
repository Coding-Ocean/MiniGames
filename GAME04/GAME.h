#pragma once
#include"../MAIN/STATE.h"

namespace GAME04 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
		void roundFace(float px, float py);
		void squareFace(float px, float py);
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
		float Eiameter;//���a
		float Ex;
		float Ey;
		float EVx;
		float EVy;
		float Aiameter;//���a
		float Ax;
		float Ay;
		float AVx;
		float AVy;
		float Biameter;//���a
		float Bx;
		float By;
		float BVx;
		float BVy;
		float a; 
		float b; 
		float c;
		float d;
		float e;
		float f;

		float distance1;
		float distance2;
		float distance3;
		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag = 0;
	};
};

