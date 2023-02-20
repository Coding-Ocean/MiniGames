#include "ACTOR.h"
#include "Game.h"
namespace GAME00 {
	ACTOR::ACTOR(GAME* game)
		:Game(game)
	{
		Game->AddActor(this);
		SetState(EActive);
	}

	ACTOR::~ACTOR()
	{
		Game->RemoveActor(this);
	}
}