#include "../libOne/inc/graphic.h"
#include "../libOne/inc/input.h"
#include "GAME.h"
#include "PLAYER.h"
namespace GAME00 {

	PLAYER::PLAYER(GAME* game)
		:ACTOR(game) {
	}

	PLAYER::~PLAYER() {
	}

	void PLAYER::init() {

		//�v���C���[�̍����A���A�`��J�n�n�_��X,Y

		setW(130);
		setH(15);
		setPx(GetGame()->court()->w()/2-w()/2);
		setPy(GetGame()->court()->h() - 200);
		setSp(15);
		setST(255);
		setSW(h());
	}

	void PLAYER::update() {

		//�ړ�����
		if (isPress(KEY_D)) { setPx(px() + sp()); }
		if (isPress(KEY_A)) { setPx(px() - sp()); }

		//���ړ�����
		float lim = 8;
		if (px() < lim) { setPx(lim); }
		//�E�ړ�����
		float courtW = GetGame()->court()->w();
		if (px() > courtW - w() - lim) { setPx(courtW - w() - lim); }
	}

	void PLAYER::draw() {

		//�v���C���[�̐���
		stroke(st());
		strokeWeight(sw());
		float px = GetGame()->court()->px() + this->px();
		line(px, py(), px+w(), py());
	}
}