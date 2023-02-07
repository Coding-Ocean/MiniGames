#pragma once
#include"TITLE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"

class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		GAME_CLEAR::DATA game_clear;
		GAME_OVER::DATA game_over;
		PLAYER::DATA player;
	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	const TITLE::DATA& title() { return Data.title; }
	const GAME_CLEAR::DATA& game_clear() { return Data.game_clear; }
	const GAME_OVER::DATA& game_over() { return Data.game_over; }

	const PLAYER::DATA& player() { return Data.player; }


};

