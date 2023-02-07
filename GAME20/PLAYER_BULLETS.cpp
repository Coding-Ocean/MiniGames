#include"CONTAINER.h"
#include"GAME.h"
#include "PLAYER_BULLETS.h"
namespace GAME20 {
	PLAYER_BULLETS::PLAYER_BULLETS(class GAME* game) :
		BULLETS(game) {
	}
	void PLAYER_BULLETS::create() {
		SetBullets(game()->container()->playerBullet());
	}
}