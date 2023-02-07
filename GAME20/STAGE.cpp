#include"../libOne/inc/libOne.h"
#include"GAME.h"
#include"STAGE.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ITEMS.h"
namespace GAME20 {
	STAGE::STAGE(class GAME* game) :
		SCENE(game) {
	}
	STAGE::~STAGE() {

	}
	void STAGE::init() {
		game()->playerBullets()->init();
		game()->player()->init();
		game()->items()->init();
		game()->enemies()->init();
	}
	void STAGE::update() {
		game()->playerBullets()->update();
		game()->player()->update();
		game()->items()->update();
		game()->enemies()->update();
	}
	void STAGE::draw() {
		clear();
		game()->draw();

	}
	void STAGE::nextScene() {
		if (game()->enemies()->curNum() <= 0 && game()->items()->cnt() >= 5) {
			game()->changeScene(GAME::GAME_CLEAR_ID);
		}
		else if (game()->enemies()->cnt() == 120) {
			game()->changeScene(GAME::GAME_OVER_ID);
		}
	}
}