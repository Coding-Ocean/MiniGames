#pragma once
#include"../MAIN/STATE.h"

namespace GAME09 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

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

		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag=0;
	};

}
