#pragma once
#include<stdio.h>
namespace GAME27 {
	//�J�[�h�P�̃f�[�^
	struct CARD {
		int posNo; //�ꏊ
		bool state; //���\
		bool getFlag; //�擾
		float x;
		float y;
	};
	//�����f�[�^
	struct STR {
		const char* Str;
		float Size = 0;
		float Px = 0;
		float Py = 0;
		COLOR Color;
	};
	//����State
	enum FASE { THINK, FIRST, GET, FAIL };
	//�V�[���ړ�
	enum SCENE { TITLE, PLAY, RESULT };

}