#include"../libOne/inc/graphic.h"
#include"../libOne/inc/input.h"
#include"../libOne/inc/window.h"
#include "COURT.h"
#include "BLOCK.h"
#include "BALL.h"
#include "GAME.h"
namespace GAME00 {
	COURT::COURT(GAME* game)
		:ACTOR(game){
	}

	COURT::~COURT(){
	}

	void COURT::GeneBlocks() {
		for (float c = 0; c < col(); c++) {
			for (float l = 0; l < len(); l++) {
				auto b= new BLOCK(GetGame());
				float harfR = b->h() / 2.0f;
				float ballTR = GetGame()->Getballs()[0]->r() * 4;

				b->setW((w() - (b->h() * len() + ballTR * 2.0f)) / len());
				b->setPx(px() + harfR + ballTR + (b->w() * l + b->h() * l));
				b->setPy(harfR+sw());
				Blocks.emplace_back( b);
			}
			DawnBlocks();
		}
	}

	void COURT::DawnBlocks() {
		if(!Blocks.empty()) {
			for (auto b : Blocks) {
				b->setPy(b->py() + b->h()+1.0f);//1.0f�͗�̌��Ԃ��J���邽�߂̕�
				if (b->py() >= CortHarf_H) {
					GetGame()->SetGstate(GAME::G_state::G_end);
				}

			}
		}
	}
	void COURT::AddBlocks() {
		DawnBlocks();
		GeneBlocks();
	}
	void COURT::init(){

		//�R�[�g�̍����A���A�`��J�n�n�_��X,Y
		setW(800);
		setH(1080);
		setPx((1920 - w()) / 2);
		setPy(0);
		setST(255);
		setSW(5);

		//�u���b�N�����̏c����
		setLen(7);
		setCol(3);

		CountTime = 0.0f;
		GeneTime = 9.0f;

		B_MostLow_py=0.0f;

		CortHarf_H =h()/2.0;
		BallUPside = false;
		Dathside=false;
		initDeltaTime();

	}

	void COURT::update(){

		setDeltaTime();
		CountTime += delta;

		if (GetGame()->Getballs()[0]->py() < CortHarf_H) {
			BallUPside = true;
		}
		else {
			BallUPside = false;
		}

		if (Blocks.empty()) { GeneBlocks(); }

		if (CountTime >= GeneTime && BallUPside == false) {
			CountTime =0.0f;
			AddBlocks();
		}
	}

	void COURT::draw(){

		//�R�[�g�̐���
		fill(0);
		stroke(st());
		strokeWeight(sw());
		rect(px(), py(), w(), h());
		stroke(255,0,0);
		line(px(), CortHarf_H, px() + w(), CortHarf_H);
	}
	void COURT::RemoveBlocks(BLOCK* block)
	{
		//����actor��mActors�ɂ��邩�T��
		auto iter = std::find(Blocks.begin(), Blocks.end(), block);
		if (iter != Blocks.end())
		{
			//����Actor�ƃP�c��Actor�����ւ���(������R�s�[����������邽��)
			std::iter_swap(iter, Blocks.end() - 1);
			Blocks.pop_back();
		}
	}
}