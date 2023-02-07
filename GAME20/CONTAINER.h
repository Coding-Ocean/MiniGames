#pragma once
#include"TITLE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BULLETS.h"
#include"ITEMS.h"
namespace GAME20 {
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			GAME_CLEAR::DATA clear;
			GAME_OVER::DATA over;
			PLAYER::DATA player;
			ENEMIES::DATA enemy;
			BULLETS::DATA playerBullet;
			ITEMS::DATA item;

		};
		DATA Data;
	public:
		void load();
		void setData();
		void loadGraphic();
		const TITLE::DATA& title() { return Data.title; }
		const GAME_CLEAR::DATA& clear() { return Data.clear; }
		const GAME_OVER::DATA& over() { return Data.over; }
		const PLAYER::DATA& player() { return Data.player; }
		const ENEMIES::DATA& enemy() { return Data.enemy; }
		const BULLETS::DATA& playerBullet() { return Data.playerBullet; }
		const ITEMS::DATA& item() { return Data.item; }



	};
}
