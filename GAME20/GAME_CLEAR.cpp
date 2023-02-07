#include"../libOne/inc/libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include "GAME_CLEAR.h"
namespace GAME20 {
	GAME_CLEAR::GAME_CLEAR(class GAME* game) :
		SCENE(game) {
	}
	GAME_CLEAR::~GAME_CLEAR() {

	}
	void GAME_CLEAR::create() {
		Clear = game()->container()->clear();
	}
	void GAME_CLEAR::update() {
		game()->playerBullets()->update();
	}
	void GAME_CLEAR::draw() {
		clear(169, 206, 236);
		fill(Clear.textColor);
		textSize(Clear.textSize);
		text(Clear.str, Clear.pos.x, Clear.pos.y);
		rectMode(CENTER);
		image(Clear.img, width / 2, height / 2 + 100);
		
	}
	void GAME_CLEAR::nextScene() {
		if (isTrigger(KEY_Z)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}