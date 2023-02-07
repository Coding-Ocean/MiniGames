#include "../libOne/inc/libOne.h"
#include "GAME_CLEAR.h"
#include"GAME2.h"
#include"CONTAINER.h"

GAME_CLEAR::GAME_CLEAR(class GAME2* game) :
	SCENE(game)
{
}
GAME_CLEAR::~GAME_CLEAR() {
};

void GAME_CLEAR::create() {
	Game_Cler = game()->container()->game_clear();
}
void GAME_CLEAR::draw() {
	clear(Game_Cler.backColor);
	fill(Game_Cler.textColor);
	textSize(Game_Cler.textSize);
	text(Game_Cler.str, Game_Cler.pos.x, Game_Cler.pos.y);
	//print("	Game Clear");
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME2::TITLE_ID);
	}
}