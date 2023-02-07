#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include<stdio.h>
#include<stdlib.h>
namespace GAME06 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		Img = loadImage("../game06/assets/unkoWhite.png");




		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
		clear(200);
	}


	GAME::~GAME()
	{
	}

	void GAME::proc(MANAGER* manager)
	{
		//更新
		VECTOR2 mousePos = VECTOR2(mouseX, mouseY);
		
		if (isPress(KEY_UP)) {
			color.r += 1; color.g += 1;color.b += 1;
		}
		if (isPress(KEY_DOWN)) color.r -= 1;
		//描画
		strokeWeight(10);
		if (isPress(KEY_SPACE)) {
			clear(0);
		}
	
		rectMode(CENTER);
		//fill(0);
		//rect(width / 2, height / 2, width, height);
		circle(Px, Py, Diameter);
		strokeWeight(10);//線の太さ
		//fill(0);//線の色
		
		
		
		
		//fill(0);
		line(width - 420, 400, width - 500, 460);
		
		line( width - 400, 580, width - 500, 580);
		
		line(width - 420, 760, width - 500, 700);
				
		line(420, 400, 500, 460);

		line(400, 580, 500, 580);

		line(420, 760, 500, 700);

		circle(960, 580, 1000);
		circle(960, 900, 200);
		circle(960, 580, 10);
		fill(0, 0, 0, 0);
		rect(1130, 350, 100, 350);
		rect(790, 350, 100, 350);


		stroke(255);
		if (isPress(MOUSE_LBUTTON)) {
			if (drawing) {
				PastPx = MouseX;
				PastPy = MouseY;
				drawing = false;
			}
			else {
				stroke(color);
				line(PastPx, PastPy, MouseX, MouseY);
				PastPx = MouseX;
				PastPy = MouseY;
			}
		}
		else drawing = true;
		
		//メニューに戻る
		if (isTrigger(KEY_ENTER)) {
			BackToMenuFlag = 1;
		}

		//メニューに戻る (基本的に以下はいじらなくてよい)
		manager->fade->draw();
		if (BackToMenuFlag == 1) {
			manager->fade->fadeOutTrigger();
			if (manager->fade->fadeOutEndFlag()) {
				delete manager->state;
				manager->state = new MENU(manager);
			}
		}
	}
}