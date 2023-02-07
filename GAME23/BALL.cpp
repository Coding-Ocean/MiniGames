#include "../libOne/inc/graphic.h"
#include "../libOne/inc/mathUtil.h"
#include "../libOne/inc/libOne.h"
#include "GAME.h"
#include "BALL.h"
#include "PLAYER.h"
namespace GAME23
{
	BALL::BALL(GAME* game)
		:ACTOR(game)
	{

	}
	BALL::~BALL()
	{

	}
	void BALL::init()
	{
		Img = loadImage("../game23/assets/e.png");
		setR(10);
		setPx(game()->court()->w() / 2);
		setPy(320);
		setSp(10);
		setVx(0);
		setVy(sp());
	}
	void BALL::update()
	{
		Wall();
		Collision();
		Move();
	}
	void BALL::draw()
	{
		//fill(255, 0, 0);
		//strokeWeight(0);
		float courtPx = game()->court()->px();
		//circle(courtPx + px(), py(), r() * 2);
		rectMode(CENTER);
		image(Img,courtPx + px(), py(), r() * 2,0.2f);
	}
	void BALL::Wall()
	{
		float courtW = game()->court()->w();
		float courtH = game()->court()->h();
		if (px() < r() && vx() < 0) {
			setVx(-vx());
		}
		if (px() > courtW - r() && vx() > 0) {
			setVx(-vx());
		}
		if (py() < -600) {
			init();
			setVy(sp());
		}
		if (py() > courtH + 600) {
			init();
		}
	}
	void BALL::Collision()
	{
		BALL* ball = this;
		ACTOR* pad = 0;
		float halfH = game()->court()->h() / 2;
		if (ball->py() > halfH) {
			pad = game()->player();
		}
		else {
			pad = game()->ai();
		}
		//�������ĂȂ�����
		if (ball->px() < pad->px() - 8 ||
			ball->px() > pad->px() + pad->w() + 8 ||
			ball->py() < pad->py() - ball->r() ||
			ball->py() > pad->py() + ball->r()
			) {
			return;
		}
		//�������Ă���
		float halfW = pad->w() / 2;
		float dx = ball->px() - (pad->px() + halfW);
		float angle = Map(dx, -halfW, halfW, 135, 45);
		setVx(Cos(angle) * sp());
		if (ball->py() < pad->py()) {
			setVy(-Sin(angle) * sp());
		}
		else {
			setVy(Sin(angle) * sp());
		}
	}
	void BALL::Move()
	{
		setPx(px() + vx());
		setPy(py() + vy());
	}
}