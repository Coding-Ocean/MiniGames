#include"../libOne/inc/libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include "TITLE.h"
namespace GAME20 {
	TITLE::TITLE(class GAME* game) :
		SCENE(game) {
	}
	TITLE::~TITLE() {

	}
	void TITLE::create() {
		Title = game()->container()->title();
	}
	void TITLE::draw() {
		clear(169, 206, 236);
		fill(Title.textColor);
		textSize(Title.textSize);
		text(Title.str, Title.pos.x, Title.pos.y);
		rectMode(CENTER);
		image(Title.img, width / 2, height / 2 + 200);
	}
	void TITLE::nextScene() {
		if (isTrigger(KEY_Z)) {
			game()->changeScene(GAME::STAGE_ID);
		}
	}
}