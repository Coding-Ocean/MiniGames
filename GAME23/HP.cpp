#include "../libOne/inc/graphic.h"
#include "../libOne/inc/input.h"
#include "GAME.h"
#include "HP.h"
namespace GAME23
{
	HP::HP(GAME* game)
		:ACTOR(game)
	{

	}
	HP::~HP()
	{

	}
	void HP::init()
	{
		Creaimg = loadImage("../GAME23/assets/crea.jpg");
		setImg(Creaimg);
		setW(40);
		setH(20);
		PlayerHp = 3;
		BossHp = 5;
		HpFlag = false;
		WinHp = 1;
	}
	void HP::update()
	{
		float courtH = game()->court()->h();
		float ballPy = game()->ball()->py();
		if (ballPy > 0 && ballPy < courtH) {
			HpFlag = false;
		}
		if (HpFlag == false) {
			if (ballPy < 0) {
				BossHp--;
				HpFlag = true;
			}
			else if (ballPy > courtH) {
				PlayerHp--;
				HpFlag = true;
			}
		}
	}
	void HP::draw()
	{
		fill(255);
		float px = game()->court()->px() - 300;
		float py = game()->court()->h();
		textSize(50);
		textMode(BCENTER);
		stroke(255);
		rectMode(CORNER);
		strokeWeight(2);
		fill(20);
		rect(px - 65, 250, (w() * 5) + 65, h() + 20);
		rect(px - 65, py - 290, (w() * 3) + 65, h() + 20);
		fill(255);
		text("HP", px - 50, 270);
		text("HP", px - 50, py - 270);
		fill(50, 50, 50);
		rect(px, py - 270, w() * 3, h());
		rect(px, 270, w() * 5, h());
		if (PlayerHp <= 1) {
			fill(255, 0, 0);
		}
		else {
			fill(0, 255, 0);
		}
		rect(px, py - 270, w() * PlayerHp, h());
		if (BossHp <= 1) {
			fill(255, 0, 0);
		}
		else {
			fill(0, 255, 0);
		}
		rect(px, 270, w() * BossHp, h());
		if (PlayerHp <= 0) {
			game()->ball()->setSp(0);
			fill(150, 0, 0);
			rect(0, 0, width, height);
			textSize(200);
			textMode(BCENTER);
			fill(200);
			text("GAME OVER", width / 2, 300);
		}
		if (BossHp <= 0) {
			game()->ball()->setSp(0);
			fill(255);
			rectMode(CENTER);
			imageColor(255);
			image(img(), width / 2, height / 2, 0, 1.6f);
			textSize(200);
			textMode(BCENTER);
			fill(200);
			text("GAME CLEAR", width / 2, 300);
		}
	}
}