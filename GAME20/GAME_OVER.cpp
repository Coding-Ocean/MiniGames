#include"../libOne/inc/libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include "GAME_OVER.h"
#include"CONTAINER.h"
namespace GAME20 {
	GAME_OVER::GAME_OVER(class GAME* game) :
		SCENE(game) {
	}
	GAME_OVER::~GAME_OVER() {

	}
	void GAME_OVER::create() {
		Over = game()->container()->over();
	}
	void GAME_OVER::update() {
		game()->playerBullets()->update();
		game()->enemies()->move();


	}
	void GAME_OVER::draw() {
		clear(169, 206, 236);
		fill(Over.textColor);
		textSize(Over.textSize);
		text(Over.str, Over.pos.x, Over.pos.y);
		rectMode(CENTER);
		image(Over.img, width / 2 , height / 2 + 200);
	}
	void GAME_OVER::nextScene() {
		if (isTrigger(KEY_Z)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}