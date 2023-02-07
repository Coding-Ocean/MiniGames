#include "PLAYER.h"
#include"CONTAINER.h"
#include"GAME2.h"

PLAYER::PLAYER(class GAME2* game):
GAME_OBJECT(game) {
}
void PLAYER::create(){
	Player = game()->container()->player();

}
void PLAYER::init(){
}
void PLAYER::update(){
	if (Player.pos.x > Player.limmitW && isPress(KEY_A)) {
		Player.pos.x +=  -Player.advSpeed * delta;
	}
	else if (Player.pos.x < width - Player.limmitW&& isPress(KEY_D)) {
		Player.pos.x += Player.advSpeed * delta;
	}

}
void PLAYER::draw(){
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle);
}