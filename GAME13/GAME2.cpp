#include"PLAYER.h"
#include "GAME2.h"
#include "../libOne/inc/libOne.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CONTAINER.h"


GAME2::GAME2() {
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);
	CurSceneId = TITLE_ID;

	Player = new PLAYER(this);

}
GAME2::~GAME2() {
	delete Player;
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}

}
void GAME2::run() {
	window(1920, 1080, full);
	Container->load();
	Scenes[TITLE_ID]->create();
	Scenes[GAME_CLEAR_ID]->create();
	Scenes[GAME_OVER_ID]->create();

	Player->create();

	initDeltaTime();

	//Scenes[CurSceneId]->init();


	while (notQuit) {
		setDeltaTime();
		Scenes[CurSceneId]->proc();
	}
}

void GAME2::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
}