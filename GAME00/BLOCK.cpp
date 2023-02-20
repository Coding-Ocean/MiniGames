#include "../libOne/inc/graphic.h"
#include "../libOne/inc/mathUtil.h"
#include "GAME.h"
#include "BLOCK.h"
#include "COURT.h"
namespace GAME00 {

	BLOCK::BLOCK(GAME* game )
		:ACTOR(game)
	{
		init();
	}

	BLOCK::~BLOCK() {
		auto court = static_cast<class COURT*>(GetGame()->court());
		court->RemoveBlocks(this);
	}

	void BLOCK::init() {
		//BLOCK�̍����A���A�`��J�n�n�_��X,Y
		setH(15);
		setST(255);
		
	}

	void BLOCK::update() {

	}

	void BLOCK::draw() {

		//BLOCK�̐���
		stroke(255);
		strokeWeight(h());
		line(px(), py(), px() + w(), py());
	}
}