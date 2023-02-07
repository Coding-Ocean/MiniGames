#include "CONTAINER.h"
namespace GAME20 {
	void CONTAINER::load() {
		setData();
		loadGraphic();
	}
	void CONTAINER::setData() {
		Data.title.backColor = COLOR(0, 20, 0);
		Data.title.textColor = COLOR(0, 0, 0);
		Data.title.textSize = 250;
		Data.title.pos.x = 300;
		Data.title.pos.y = 100;
		strcpy_s(Data.title.str, "HITUMABUSHI");

		Data.clear.backColor = COLOR(0, 20, 0);
		Data.clear.textColor = COLOR(0, 255, 0);
		Data.clear.textSize = 250;
		Data.clear.pos.x = 300;
		Data.clear.pos.y = 50;
		strcpy_s(Data.clear.str, "GAME_CLEAR");

		Data.over.backColor = COLOR(0, 20, 0);
		Data.over.textColor = COLOR(255, 0, 0);
		Data.over.textSize = 250;
		Data.over.pos.x = 400;
		Data.over.pos.y = 100;
		strcpy_s(Data.over.str, "GAME_OVER");

		Data.player.angle = 0;
		Data.player.advSpeed = 400;
		Data.player.pos.x = 960;
		Data.player.pos.y = 970;
		Data.player.limmitW = 50;
		Data.player.limmitH = 50;
		Data.player.launchVec = VECTOR2(0, -1);
		Data.player.triggerErapsedTime = 0;
		Data.player.triggerInterval = 0.1f;
		Data.player.ofstLaunchDist = 100;
		Data.player.bcRadius = 40;

		Data.enemy.totalNum = 10;
		Data.enemy.curNum = Data.enemy.totalNum;
		Data.enemy.triggerInterval = 0.72f;
		Data.enemy.ofstLaunchDist = 100;
		Data.enemy.bcRadius = 40;
		Data.enemy.invincibleTime = 0.05;
		Data.enemy.initHp = 1;

		Data.playerBullet.totalNum = 2;
		Data.playerBullet.curNum = 0;
		Data.playerBullet.advSpeed = 700;
		Data.playerBullet.angSpeed = 0;
		Data.playerBullet.bcRadius = 20;

		Data.item.totalNum = 10;
		Data.item.curNum = Data.item.totalNum;
		Data.item.bcRadius = 20;
		Data.item.cnt = 0;
		Data.item.inithp = 1;
	}
	void CONTAINER::loadGraphic() {
		Data.player.img = loadImage("../game20/assets/PLAYER.png");
		Data.enemy.img = loadImage("../game20/assets/UNAGI.png");
		Data.playerBullet.img = loadImage("../game20/assets/YARI.png");
		Data.item.img = loadImage("../game20/assets/KOME.png");
		Data.title.img = loadImage("../game20/assets/UTUWA.png");
		Data.clear.img = loadImage("../game20/assets/HITUMABUSI.png");
		Data.over.img = loadImage("../game20/assets/HAKUMAI.png");

	}
}