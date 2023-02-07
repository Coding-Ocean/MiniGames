#pragma once
#include"../MAIN/STATE.h"
#include"27Utilitys.h"
namespace GAME27 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//�J�[�h�摜
		int cardImg[53]{};
		//���ʉ�
		int getSE = 0;
		int failSE = 0;
		int turnSE = 0;
		//BGM
		int playBGM = 0;
		
		//�f�[�^�Ǘ�
		bool RWdata = false;
		FILE* fp = nullptr;
		int P1 = 0;
		int P2 = 0;

		//�^�C�g��
		bool toStartAFlag = false;
		STR gameName{
			"�_�o����",
			180,
			width / 2 - 180 * 2,
			120,
			COLOR(30, 30, 30)
		};
		STR comp0{
			"- �V�ѕ� -",
			60,
			width / 2 - 60 * 2.5f,
			400,
			COLOR(50, 50, 50)
		};
		STR comp1{
			"�E2�l�v���C(�`�[�������)",
			50,
			width / 2 - 50 * 6.75f,
			520,
			COLOR(50, 50, 50)
		};
		STR comp2{
			"�E�E�N���b�N�ŃJ�[�h��I��",
			50,
			width / 2 - 50 * 6.75f,
			590,
			COLOR(50, 50, 50)
		};
		STR comp3{
			"�E�l���y�A���������ق��̏���",
			50,
			width / 2 - 50 * 6.75f,
			660,
			COLOR(50, 50, 50)
		};
		STR toPlay{
			"SPACE�ŃX�^�[�g",
			75,
			width / 2 - 75 * 3.75f,
			900,
			COLOR(230, 230, 230)
		};
		STR toMenu{
			"M�Ń��j���[��",
			75,
			width / 2 - 75 * 3.25f,
			990,
			COLOR(230, 230, 230)
		};
		STR lastData{
			"�O��̐��",
			50,
			width - 7 * 50,
			height - 120,
			COLOR(0, 0, 0)
		};
		STR hyphen{
			"-",
			50,
			width - 4.75f * 50,
			height - 60,
			COLOR(0, 0, 0)
		};
		

		//�v���C��ʃ��C�A�E�g
		VECTOR2 LTpos{}; 
		VECTOR2 RBpos{}; 
		VECTOR2 offset{};
		float cardScale = 0;

		//�v���C
		int no1 = 0;
		int no2 = 0;
		int fstsnd = 1;
		float dispLimit = 0;
		STR Player1{
			"��U",
			50,
			20,
			10,
			COLOR(255, 200, 200)
		};
		STR Player2{
			"��U",
			50,
			width - 120,
			10,
			COLOR(50, 50, 105)
		};
		char P1buf[3]{};
		char P2buf[3]{};

		//�J�[�h�̃f�[�^
		CARD cards[52]{};
		//�J�[�h�\���̈�
		VECTOR2 startPos{};
		VECTOR2 endPos{};

		//���U���g
		bool toTitleAFlag = false;
		STR Ssave{
			"��т�ۑ����܂����B",
			50,
			width - 11 * 50,
			1000,
			COLOR(0, 0, 0)
		};
		STR Fsave{
			"��т�ۑ��ł��܂���ł����B",
			50,
			width - 7.5f * 50,
			1000,
			COLOR(255, 50, 50)
		};
		STR P1Win{
			"��U�̏����I",
			150,
			width / 2 - 450,
			400,
			COLOR(255, 200, 200)
		};
		STR P2Win{
			"��U�̏����I",
			150,
			width / 2 - 450,
			400,
			COLOR(200, 200, 255)
		};
		STR tieGame{
			"��������",
			150,
			width / 2 - 300,
			400,
			COLOR(175, 175, 175)
		};
		STR toTiTLE{
			"SPACE�Ń^�C�g���ɖ߂�",
			75,
			width / 2 - 5.25f * 75,
			height - 250,
			COLOR(230, 230, 230)
		};

		//����State
		FASE fase = THINK;
		//�V�[���Ǘ�
		SCENE scene = TITLE;
		

		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag=0;

		void init();
		bool roadData();
		void play();
		void title();
		void result();
		bool saveData();

		void dispSTR(STR s);
		bool onCard(float Cx, float Cy);
	};

}

