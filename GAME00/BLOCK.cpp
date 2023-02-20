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
		//BLOCKの高さ、幅、描画開始地点のX,Y
		setH(15);
		setST(255);
		
	}

	void BLOCK::update() {

	}

	void BLOCK::draw() {

		//BLOCKの生成
		stroke(255);
		strokeWeight(h());
		line(px(), py(), px() + w(), py());
	}
}