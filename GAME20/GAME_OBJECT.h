#pragma once
namespace GAME20 {
	class GAME_OBJECT
	{
	private:
		class GAME* Game = 0;
	public:
		GAME_OBJECT(class GAME* game);
		virtual ~GAME_OBJECT();
		class GAME* game() {
			return Game;
		}

	};
}