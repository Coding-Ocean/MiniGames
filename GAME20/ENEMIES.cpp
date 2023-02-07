#include"CONTAINER.h"
#include"GAME.h"
#include "ENEMIES.h"
#include"PLAYER_BULLETS.h"
namespace GAME20 {
	ENEMIES::ENEMIES(class GAME* game) :GAME_OBJECT(game) {

	}
	ENEMIES::~ENEMIES() {
		delete[] Enemies;
	}
	void ENEMIES::create() {
		Enemy = game()->container()->enemy();
		Enemies = new ENEMY[Enemy.totalNum];
	}
	void ENEMIES::init() {
		for (int i = 0; i < Enemy.totalNum; i++) {
			Enemies[i].pos.x = random() % ((int)width - 100);
			Enemies[i].pos.y = random() % ((int)height - 100);
			while (Enemies[i].pos.x<50 || Enemies[i].pos.x>width - 100 ||
				Enemies[i].pos.y<50 || Enemies[i].pos.y>height - 100) {
				Enemies[i].pos.x = random() % ((int)width - 100);
				Enemies[i].pos.y = random() % ((int)height - 100);
			}
			Enemies[i].levelSpeed = random(-30.0f, 30.0f);
			Enemies[i].fallSpeed = random(-30.0f, 30.0f);

		}
		Enemy.cnt = 0;
	}
	void ENEMIES::update() {
		move();
		collision();
	}
	void ENEMIES::move() {
		for (int i = 0; i < Enemy.totalNum; i++) {
			Enemies[i].pos.x += Enemies[i].levelSpeed;
			Enemies[i].pos.y += Enemies[i].fallSpeed;
			if (Enemies[i].pos.x <= 50 || Enemies[i].pos.x >= width - 50) {
				Enemies[i].levelSpeed *= -1;
				Enemy.cnt += 1;
			}
			if (Enemies[i].pos.y <= 50 || Enemies[i].pos.y >= height - 50) {
				Enemies[i].fallSpeed *= -1;
				Enemy.cnt += 1;
			}
		}
	}
	
	void ENEMIES::collision() {
		BULLETS* bullets = game()->playerBullets();
		float distance = Enemy.bcRadius + bullets->bcRadius();
		float sqDistance = distance * distance;
		for (int j = Enemy.curNum - 1; j >= 0; j--) {
			if (Enemies[j].invincibleRestTime > 0) {
				Enemies[j].invincibleRestTime -= delta;
			}
			else {
				for (int i = bullets->curNum() - 1; i >= 0; i--) {
					VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
					if (sqLength(vec) < sqDistance) {
						Enemies[j].hp--;
						Enemies[j].invincibleRestTime = Enemy.invincibleTime;
						if (Enemies[j].hp <= 0) {
							Enemy.curNum--;
							Enemies[j] = Enemies[Enemy.curNum];
						}
						bullets->kill(i);
						i = 0;
					}
				}
			}
		}
	}
	void ENEMIES::draw() {
		for (int i = 0; i < Enemy.curNum; i++) {
			rectMode(CENTER);
			image(Enemy.img, Enemies[i].pos.x, Enemies[i].pos.y);
		}
	}
}