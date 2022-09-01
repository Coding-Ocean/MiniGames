#include<stdio.h>
#include"MANAGER.h"
#include"FADE.h"
#include"MENU.h"
//#include"../GAME00/GAME.h"
MANAGER::MANAGER() {
    //-----------------------------------------------------------------------------------
    //�S�X�e�[�g���ʎg�p�́u�f�[�^�A�܂��́A�I�u�W�F�N�g�v����
    //-----------------------------------------------------------------------------------

    //�I������Q�[���̃C���f�b�N�X
    selectIdx = 0;

    //�N���A�ς݃Q�[���t���b�O��ǂ݂���
    FILE* fp = 0;
    fopen_s(&fp, "data/data.txt", "rb");
    if (fp) {
        fread(clearFlags, 1, 30, fp);
        fclose(fp);
    }
    else {
        for (int i = 0; i < 30; i++) {
            clearFlags[i] = 0;
        }
    }

    //�t�F�[�h�C���A�t�F�[�h�A�E�g����N���X
    fade = new FADE;

    //-----------------------------------------------------------------------------------
    //������ςȂ̃X�e�[�g���Z�b�g
    //-----------------------------------------------------------------------------------
    state = new MENU(this);
}

MANAGER::~MANAGER() {
    //�N���A�����Q�[���̏�Ԃ��Z�[�u
    FILE* fp = 0;
    fopen_s(&fp, "data/data.txt", "wb");
    if (fp) {
        fwrite(clearFlags, 1, 16, fp);
        fclose(fp);
    }
    delete state;
    delete fade;
}

void MANAGER::proc() {
    state->proc(this);
}

