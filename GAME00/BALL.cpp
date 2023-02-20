#include "../libOne/inc/graphic.h"
#include "../libOne/inc/mathUtil.h"
#include "BALL.h"
#include "BLOCK.h"
#include "PLAYER.h"
#include "COURT.h"
#include "SCORE.h"
#include "GAME.h"

namespace GAME00 {

	BALL::BALL(GAME* game)
		:ACTOR(game) {
		GetGame()->AddBalls(this);
	}

	BALL::~BALL() {
		GetGame()->RemoveBalls(this);

	}

	void BALL::init() {

		//ボールの高さ、幅、描画開始地点のX,Y
		setR(10);
		setPx(GetGame()->court()->w() / 2);
		setPy(GetGame()->court()->h() / 2);
		setSp(15);
		setVx(0);
		setVy(sp());
	}

	void BALL::update()
	{
		Wall();
		Collision();
		Move();
	}

	void BALL::draw() {

		//ボールの生成
		fill(255);
		strokeWeight(0);
		float courtPx = GetGame()->court()->px();
		circle(courtPx + px(), py(), r() * 2);
	}

	/*---privateな関数たち---*/
	void BALL::Wall()
	{
		float courtW = GetGame()->court()->w();
		float courtH = GetGame()->court()->h();

		//壁反射
		if (px() < r() && vx()<0) { setVx(-vx()); }
		if (px() > courtW- r() && vx()>0) { setVx(-vx()); }
		if (py() < 0) {setVy(-vy());}	
		
		if (py() > courtH +600) {
			init();
		}
	}

	void BALL::Pad_Coli(BALL* ball){

		ACTOR* pad = GetGame()->player();
		float halfH = GetGame()->court()->h() / 2;

		//当たっていないとき
		if (ball->px() < pad->px() - pad->h() ||
			ball->px() > pad->px() + pad->w() + pad->h() ||
			ball->py() < pad->py() - ball->r() ||
			ball->py() > pad->py() + ball->r())
		{
			return;
		}

		//当たっている
		float halfW = pad->w() / 2;
		float dx = ball->px() - (pad->px() + halfW);
		float angle = Map(dx, -halfW, halfW, 135, 45);
		setVx(Cos(angle) * sp());
		setVy(-Sin(angle) * sp());
	}

	void BALL::Block_Coli(BALL* ball){
		auto blocks = static_cast<class COURT*>(GetGame()->court());
		auto score = static_cast<class SCORE*>(GetGame()->score());
		for (auto  b: blocks->Getblocks()) {
		//四角形で判定する為に変換作業

			float blockhh = b->h() / 2;
			float blockUp = b->py() - blockhh;
			float blockDp = blockUp + b->h();
			float blockLp = b->px();
			float blockRp = blockLp + b->w();

			float courtPx = GetGame()->court()->px();

			float ballUp = ball->py() - ball->r();
			float ballDp = ballUp + ball->r() * 2;
			float ballLp = courtPx + ball->px() - ball->r();
			float ballRp = ballLp + ball->r() * 2;

			if (blockUp < ballDp &&
				blockDp > ballUp &&
				blockRp > ballLp &&
				blockLp < ballRp )
			{
				//if (ball->vx() > 0 && b->px() > ballPx ||
				//	ball->vx() < 0 && b->px() + b->w() < ballPx + ball->r() * 2)
				//{
				//ball->setVx(ball->vx() * -1);
				//}
				ball->setVy(ball->vy() * -1);
				score->addScore(100);
				b->SetState(EDead);
			}

		}

	}

	void BALL::Collision()
	{
		Pad_Coli(this);
		Block_Coli(this);

	}

	void BALL::Move()
	{
		setPx(px() + vx());
		setPy(py() + vy());
	}
}