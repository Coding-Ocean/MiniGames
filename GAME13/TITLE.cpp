#include "../libOne/inc/libOne.h"
#include "TITLE.h"
#include"CONTAINER.h"
#include"GAME2.h"
TITLE::TITLE(class GAME2* game):
	SCENE(game)
{
}
TITLE::~TITLE(){
}
void TITLE::create() {
	Title = game()->container()->title();
}

void TITLE::draw(){
	clear(Title.backColor);
	fill(Title.textColor);
	textSize(Title.textSize);
	text(Title.str, Title.pos.x, Title.pos.y);
	//printSize(300);
	//print("Title");
}
void TITLE::nextScene(){
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME2::STAGE_ID);
	}
}