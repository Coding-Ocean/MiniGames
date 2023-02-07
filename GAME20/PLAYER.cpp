#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"GAME.h"
#include"CONTAINER.h"
namespace GAME20 {
	PLAYER::PLAYER(class GAME* game) :
		GAME_OBJECT(game) {

	}

	void PLAYER::create() {
		Player = game()->container()->player();
	}
	void PLAYER::init() {
		Player.pos = game()->container()->player().pos;


	}
	void PLAYER::update() {
		move();
		lanch();
		
	}
	void PLAYER::move() {
		if (Player.pos.x >= Player.limmitW && isPress(KEY_A)) {
			Player.pos.x += -Player.advSpeed * delta;
		}
		else if (Player.pos.x <= width - Player.limmitW &&isPress(KEY_D)) {
			Player.pos.x += Player.advSpeed * delta;
		}
		if (Player.pos.y <= height - Player.limmitH && isPress(KEY_S)) {
			Player.pos.y += Player.advSpeed * delta;
		}
		else if (Player.pos.y >= Player.limmitH && isPress(KEY_W)) {
			Player.pos.y += -Player.advSpeed * delta;
		}

	}
	void PLAYER::lanch() {
		if (isTrigger(KEY_SPACE)) {
			Player.triggerErapsedTime += delta;
			if (Player.triggerErapsedTime >= Player.triggerInterval) {
				VECTOR2 pos = Player.pos + Player.launchVec * Player.ofstLaunchDist;
				game()->playerBullets()->launch(Player.pos, Player.launchVec);
				Player.triggerErapsedTime = 0;
			}
		}
		else {
			Player.triggerErapsedTime = Player.triggerInterval;
		}
	}
	
	void PLAYER::draw() {
		rectMode(CENTER);
		image(Player.img, Player.pos.x, Player.pos.y, Player.angle);


	}
}