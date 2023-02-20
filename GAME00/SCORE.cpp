#include "../libOne/inc/graphic.h"
#include "../libOne/inc/input.h"
#include "GAME.h"
#include "SCORE.h"
#include "BALL.h"
namespace GAME00 {

	SCORE::SCORE(GAME* game)
		:ACTOR(game) {

	}

	SCORE::~SCORE() {
	}

	void SCORE::addScore(int score) {
		PlayerScore += score;
	}

	void SCORE::init() {
		PlayerScore = 0;
		BolladdScore = 1000;

	}
	void SCORE::update() {
		if (PlayerScore >= BolladdScore) {
			auto b = new BALL(GetGame());
			b->init();
			BolladdScore += 1000;
		}
	}

	void SCORE::draw() {
		float px = GetGame()->court()->w()+ GetGame()->court()->px()+100;
		float py = GetGame()->court()->h();

		textSize(100);
		textMode(BCENTER);
		text("SCORE", px, 170);
		text(PlayerScore, px, 270);
		text("NextBall", px, 370);
		text(BolladdScore, px, 470);
		if (GetGame()->GetGstate() == GAME::G_state::G_end) {
			float EndPx = GetGame()->court()->px();
			float EndPy =GetGame()->court()->h()/2;

			fill(255, 0, 0);
			textSize(300);
			textMode(MBCENTER);
			text("GameOver", EndPx, EndPy);
		}
	}
}