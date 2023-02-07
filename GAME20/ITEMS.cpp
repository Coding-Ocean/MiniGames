#include "ITEMS.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
namespace GAME20 {
	ITEMS::ITEMS(class GAME* game) :
		GAME_OBJECT(game) {

	}
	ITEMS::~ITEMS() {
		delete[] Items;
	}
	void ITEMS::create() {
		Item = game()->container()->item();
		Items = new ITEM[Item.totalNum];
	}
	void ITEMS::init() {
		for (int i = 0; i < Item.totalNum; i++) {
			Items[i].pos.x = random() % ((int)width - 100);
			Items[i].pos.y = random() % ((int)height - 100);
			while (Items[i].pos.x <50 || Items[i].pos.x>width - 100 ||
				Items[i].pos.y<50 || Items[i].pos.y>height - 100) {
				Items[i].pos.x = random() % ((int)width - 100);
				Items[i].pos.y = random() % ((int)height - 100);
			}
		}
	}
	void ITEMS::update() {
		collision();
	}
	void ITEMS::collision() {
		PLAYER* player = game()->player();
		float distance = Item.bcRadius + game()->playerBullets()->bcRadius();
		float sqDistance = distance * distance;
		for (int i = Item.curNum - 1; i >= 0; i--) {
			VECTOR2 vec = Items[i].pos - player->pos();
			if (sqLength(vec) < sqDistance) {
				Items[i].hp--;
				Item.cnt++;
				if (Items[i].hp <= 0) {
					Item.curNum--;
					Items[i] = Items[Item.curNum];
				}
			}
		}
	}
	void ITEMS::draw() {
		for (int i = 0; i < Item.curNum; i++) {
			rectMode(CENTER);
			image(Item.img, Items[i].pos.x, Items[i].pos.y);
		}
	}
}