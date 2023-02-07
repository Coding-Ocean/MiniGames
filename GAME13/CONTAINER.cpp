#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	Data.title.backColor = COLOR(0, 20, 0);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.textSize = 400;
	Data.title.pos.x = 180;
	Data.title.pos.y = 700;
	strcpy_s(Data.title.str, "CHESS");

	Data.game_clear.backColor = COLOR(0, 20, 0);
	Data.game_clear.textColor = COLOR(0, 255, 0);
	Data.game_clear.textSize = 400;
	Data.game_clear.pos.x = 100;
	Data.game_clear.pos.y = 700;
	strcpy_s(Data.game_clear.str, "GAME CLEAR");

	Data.game_over.backColor = COLOR(0, 20, 0);
	Data.game_over.textColor = COLOR(0, 255, 0);
	Data.game_over.textSize = 400;
	Data.game_over.pos.x = 100;
	Data.game_over.pos.y = 700;
	strcpy_s(Data.game_over.str, "GAME OVER");

	Data.player.angle = 0;
	Data.player.advSpeed = 300;
	Data.player.pos.x = 960;
	Data.player.pos.y = 970;
	Data.player.limmitW = 100;


	}

void CONTAINER::loadGraphic() {

	Data.player.img = loadImage(("../game13/assets/King_w.png"));


}


