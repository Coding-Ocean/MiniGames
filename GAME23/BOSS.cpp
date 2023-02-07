#include "../libOne/inc/graphic.h"
#include "../libOne/inc/input.h"
#include "GAME.h"
#include "BOSS.h"
namespace GAME23
{
	BOSS::BOSS(GAME* game)
		:ACTOR(game)
	{

	}
	BOSS::~BOSS()
	{

	}
	void BOSS::init()
	{
		bossImg = loadImage("../GAME23/assets/enemy.png");
		setImg(bossImg);
		setW(150);
		setH(15);
		setPx(1920 / 2);
		setPy(150);
		setSp(5);
	}
	void BOSS::update()
	{

	}
	void BOSS::draw()
	{
		stroke(255);
		strokeWeight(h());
		float px = game()->court()->px() - this->px();
		rectMode(CENTER);
		if (game()->ball()->py() < 0) {
			imageColor(255, 0, 0, 150);
		}
		else {
			imageColor(255);
		}
		image(img(), this->px(), py(), 0, 0.5f);
	}
}