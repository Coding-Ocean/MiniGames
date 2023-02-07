#include "../libOne/inc/libOne.h"
#include "GAME_OVER.h"
#include"GAME2.h"
#include"CONTAINER.h"

GAME_OVER::GAME_OVER(class GAME2* game) :
	SCENE(game)
{
}
GAME_OVER::~GAME_OVER() {
}
void GAME_OVER::create() {
	Game_Over = game()->container()->game_over();

}
void GAME_OVER::draw() {
	clear(Game_Over.backColor);
	fill(Game_Over.textColor);
	textSize(Game_Over.textSize);
	text(Game_Over.str, Game_Over.pos.x, Game_Over.pos.y);

	//print("  Game Over");
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME2::TITLE_ID);
	}
}