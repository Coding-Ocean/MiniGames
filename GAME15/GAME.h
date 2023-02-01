#pragma once
#include"../MAIN/STATE.h"

namespace GAME15 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:

		char name[17] = "�҂�����Ⴞ���";
		float namepx = 0;
		float namepy = 0;
		float namesize = 0;
		char Name[19] = "�X�y�[�X�ŃX�^�[�g";
		float Namepx = 0;
		float Namepy = 0;
		float Namesize = 0;
		//��~�p
		bool stopflag = true;
		//�v���C�֐�
		bool play_init = true;
		int score = 0;
		char scoretext[3]{};
		int numplay = 0;
		int counter = 0;
		float interval = 0;
		float remain = 0;
		//���U���g�֐�
		int totalscore = 0;
		float scoresize = 0;
		char totalStr[15] = "���Ȃ��̍��v�_";
		float totalStrPx = 0;
		float totalStrPy = 0;
		char scoreStr[4]{};
		float scoreStrPx = 0;
		float scoreStrPy = 0;
		float infosize = 0;
		char titleStr[19] = "�X�y�[�X�Ń^�C�g��";
		float titleStrPx = 0;
		float titleStrPy = 0;
		char menuStr[19] = "�G���^�[�Ń��j���[";
		float menuStrPx = 0;
		float menuStrPy = 0;
		//�`�[�g
		float stopPx = 0;
		bool cheatFlag = true;
		//�~�\���p
		struct CIRCLE {
			float Diameter;//���a
			float Px;
			float Py;
			float Vx;
			float Vy;
		};
		struct CIRCLE c1, c2, c3, c4, c5, c6, c7;
		struct LINE {
			float Sx;
			float Sy;
			float Ex;
			float Ey;
		};
		struct LINE l1, l2, l3, l4, l5, l6;
		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag = 0;
		enum SCENE {
			title,
			play,
			result,
		};
		SCENE scene = title;
	public:
		void Init();
		void Initposition();
		void Title();
		void Play();
		void Result();
	};

}

