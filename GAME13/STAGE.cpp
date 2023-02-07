#include "../libOne/inc/libOne.h"
#include "STAGE.h"
#include"GAME2.h"
#include"PLAYER.h"

STAGE::STAGE(class GAME2* game) :
	SCENE(game)
{
}
STAGE::~STAGE() {
}
void STAGE::update() {
	game()->player()->update();
}

void STAGE::draw() {
	clear();
	game()->player()->draw();
	
}
void STAGE::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME2::GAME_CLEAR_ID);
	}
	if (isTrigger(KEY_X)) {
		game()->changeScene(GAME2::GAME_OVER_ID);
	}
}