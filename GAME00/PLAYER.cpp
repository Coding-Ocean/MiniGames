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

		//プレイヤーの高さ、幅、描画開始地点のX,Y

		setW(130);
		setH(15);
		setPx(GetGame()->court()->w()/2-w()/2);
		setPy(GetGame()->court()->h() - 200);
		setSp(15);
		setST(255);
		setSW(h());
	}

	void PLAYER::update() {

		//移動入力
		if (isPress(KEY_D)) { setPx(px() + sp()); }
		if (isPress(KEY_A)) { setPx(px() - sp()); }

		//左移動制限
		float lim = 8;
		if (px() < lim) { setPx(lim); }
		//右移動制限
		float courtW = GetGame()->court()->w();
		if (px() > courtW - w() - lim) { setPx(courtW - w() - lim); }
	}

	void PLAYER::draw() {

		//プレイヤーの生成
		stroke(st());
		strokeWeight(sw());
		float px = GetGame()->court()->px() + this->px();
		line(px, py(), px+w(), py());
	}
}