#pragma once
class GAME_OBJECT
{
private:
	class GAME2* Game = 0;
public:
	GAME_OBJECT(class GAME2* game);
	virtual ~GAME_OBJECT();
	class GAME2* game() {
		return Game;
	}

};

