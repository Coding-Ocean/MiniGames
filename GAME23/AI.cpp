#include "../libOne/inc/graphic.h"
#include "../libOne/inc/input.h"
#include "../libOne/inc/mathUtil.h"
#include "GAME.h"
#include "AI.h"
namespace GAME23
{
	AI::AI(GAME* game)
		:ACTOR(game)
	{

	}
	AI::~AI()
	{

	}
	void AI::init()
	{
		setW(150);
		setH(15);
		setPx(game()->court()->w() / 2 - w() / 2);
		setPy(300);
		setSp(1.5f);
	}
	void AI::update()
	{
		float ballPx = game()->ball()->px();
		float dx = ballPx - (px() + w() / 2);
		dx *= 0.25f;
		if (Abs(dx) > sp()) {
			setVx(dx / Abs(dx) * sp());
		}
		else {
			setVx(dx);
		}
		setPx(px() + vx());


		float lim = 8;
		if (px() < lim) {
			setPx(lim);
		}
		float courtW = game()->court()->w();
		if (px() > courtW - w() - lim) {
			setPx(courtW - w() - lim);
		}
	}
	void AI::draw()
	{

		stroke(100, 0, 100);
		strokeWeight(h());
		float px = game()->court()->px() + this->px();
		line(px, py(), px + w(), py());
	}
}