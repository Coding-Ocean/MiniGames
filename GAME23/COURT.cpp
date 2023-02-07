#include "../libOne/inc/graphic.h"
#include "GAME.h"
#include "COURT.h"
namespace GAME23
{
	COURT::COURT(GAME* game)
		:ACTOR(game)
	{

	}
	COURT::~COURT()
	{

	}
	void COURT::init()
	{
		stageImg = loadImage("../GAME23/assets/stage.jpg");
		setImg(stageImg);
		setW(810);
		setH(1080);
		setPx((1920 - w()) / 2);
		setPy(0);
	}
	void COURT::update()
	{

	}
	void COURT::draw()
	{
		fill(0, 60, 60);
		stroke(255);
		strokeWeight(5);
		rectMode(CENTER);
		if (game()->court()->h() < game()->ball()->py()) {
			imageColor(255, 0, 0, 150);
		}
		else {
			imageColor(255);
		}
		image(img(), width / 2, height / 2, 0, 2);
		rectMode(CORNER);
		rect(px(), py(), w(), h());
	}
}