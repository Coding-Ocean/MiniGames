#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include "Windows.h"

namespace GAME03 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		//画像データ
		backgroundImg = loadImage("../game03/assets/背景.png");
		playerImg = loadImage("../game03/assets/自機.png");
		enemyImg = loadImage("../game03/assets/隕石.png");
		bulletImg = loadImage("../game03/assets/弾.png");
		explosionImg = loadImage("../game03/assets/爆発エフェクト.png");
		//音声データ
		bulletsoundImg = loadSound("../game03/assets/発射音.wav");
		explosionsound = loadSound("../game03/assets/爆発.wav");
		playSound(bulletsoundImg);

		for (int i = 0; i < ENUM; i++) {
			Eflag[i] = 1;
			Ex[i] = random(100, 1350);
			Ey[i] = -random(10, 1000);
			EVy[i] = random(5, 10);
		}
		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
	}

	void GAME::proc(MANAGER* manager)
	{

		if (State == PLAY) {
			//プレイヤー移動
			if (isPress(KEY_D)) { Px += PVx; }//右移動
			if (isPress(KEY_A)) { Px -= PVx; }//左移動
			//プレイヤーの画面外の判定
			if (1400 < Px) { Px = 1400; }
			else if (0 > Px) { Px = 0; }
			//敵
			for (int i = 0; i < ENUM; i++) {
				if (Eflag[i] == 1) {
					Ey[i] += EVy[i];
					//circle(Ex[i], Ey[i], Er*2);
					//下まで行ったら
					if (1080 + Er < Ey[i]) {
						//ランダム
						Ex[i] = random(100, 1320);
						Ey[i] = -random(10, 1000);
						EVy[i] = random(5, 10);
						//hpが0になったらゲージを止める
						if (hp > 0) {
							hp -= damage;
						}
					}
				}
			}
			//弾発射KEYが押されたとき
			if (Bflag == 0) {
				if (isTrigger(KEY_SPACE)) {
					playSound(bulletsoundImg);
					Bx = Px;
					By = Py - 70;
					Bflag = 1;
				}
			}
			//弾移動
			if (Bflag != 0) {
				//circle(Bx, By, Br*2);
				By -= BVy;
				//ウィンドウの外に出たら
				if (By <= 0) {
					//Bx = Px;
					//By = Py - 70;
					Bflag = 0;
				}
			}
			//距離　当たったらflagを0にする
			//円の中心点を測る
			if (Bflag == 1) {
				for (int i = 0; i < ENUM; i++) {
					int distance = sqrt(pow(Bx - Ex[i], 2) + pow(By - Ey[i], 2));
					if (distance < Er + Br) {
						playSound(explosionsound);
						score += scoresum;
						By = -10;
						Bflag = 0;
						//当たったらランダムに落とす
						Ey[i] = -random(10, 1000);
						Ex[i] = random(200, 1350);
					}
				}
			}

			if (score >= clearline) {
				State = CLEAR;
			}
			if (hp <= 0) {
				State = OVER;
			}
		}

		//背景色
		clear(255);
		//線の太さ
		strokeWeight(3);
		//背景
		image(backgroundImg, 0, 0);
		//プレイヤー
		image(playerImg, Px - 40, Py - 45);
		//弾
		if(Bflag)image(bulletImg, Bx - 11, By - 10);
		//敵表示
		for (int i = 0; i < ENUM; i++) {
			if (Eflag[i] == 1) {
				image(enemyImg, Ex[i]-60, Ey[i]-105);
			}
		}


		//クリア画面
		if(State==CLEAR){
			textSize(200);
			text("GAME CLEAR", 200, 400);
		}

		//ゲームオーバー画面
		if(State==OVER){
			textSize(200);
			text("GAME OVER", 200, 400);
		}


		fill(100, 100, 100);
		//スコア表示,文字だけに色を付けるには？
		rect(hpx, hpy, hp, h);
		textSize(60);
		text("地球の命", 1500, 30);
		text("スコア", 1500, 200);
		text(score, 1500, 300);
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