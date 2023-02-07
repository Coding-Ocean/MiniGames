#include "ACTOR.h"
namespace GAME23
{
	ACTOR::ACTOR(GAME* game)
		:Game(game)
	{
	}
	ACTOR::~ACTOR()
	{
		Game = 0;
	}
}