#include "SCENE.h"
SCENE::SCENE(class GAME2* game):
	GAME_OBJECT(game){


}
SCENE::~SCENE() {

}
void SCENE::create() {

}
void SCENE::init() {

}
void SCENE::proc() {
	updata();
	draw();
	nextScene();
}
void SCENE::updata() {

}
void SCENE::draw() {

}
void SCENE::nextScene() {

}