#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "../libOne/inc/mathUtil.h"
#include "GAME.h"
#define WIDTH 1920
#define HEIGHT 1080
namespace GAME11 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		//バー
		barpx = 900;
		barpy = 1000;
		barW = 170;
		barH = 25;
		barL = 0;
		barR = 0;
		barT = 0;
		barB = 0;
		barvx = 18;

		//ボール
		ballpx = 980;
		ballpy = 990;
		ballW = 7;
		ballH = 7;
		ballL = 0;
		ballR = 0;
		ballT = 0;
		ballB = 0;
		ballvx = 6;
		ballvy = -9;
		startflag = 0;

		//ブロック
		blockpx = 60;
		blockpy = 50;
		blockW = 180;
		blockH = 30;
		blockL = 0;
		blockR = 0;
		blockT = 0;
		blockB = 0;

		blockpx1 = 240;
		blockpy1 = 50;
		blockW1 = 180;
		blockH1 = 30;
		blockL1 = 0;
		blockR1 = 0;
		blockT1 = 0;
		blockB1 = 0;

		blockpx2 = 420;
		blockpy2 = 50;
		blockW2 = 180;
		blockH2 = 30;
		blockL2 = 0;
		blockR2 = 0;
		blockT2 = 0;
		blockB2 = 0;

		blockpx3 = 600;
		blockpy3 = 50;
		blockW3 = 180;
		blockH3 = 30;
		blockL3 = 0;
		blockR3 = 0;
		blockT3 = 0;
		blockB3 = 0;

		blockpx4 = 780;
		blockpy4 = 50;
		blockW4 = 180;
		blockH4 = 30;
		blockL4 = 0;
		blockR4 = 0;
		blockT4 = 0;
		blockB4 = 0;

		blockpx5 = 960;
		blockpy5 = 50;
		blockW5 = 180;
		blockH5 = 30;
		blockL5 = 0;
		blockR5 = 0;
		blockT5 = 0;
		blockB5 = 0;

		blockpx6 = 1140;
		blockpy6 = 50;
		blockW6 = 180;
		blockH6 = 30;
		blockL6 = 0;
		blockR6 = 0;
		blockT6 = 0;
		blockB6 = 0;

		blockpx7 = 1320;
		blockpy7 = 50;
		blockW7 = 180;
		blockH7 = 30;
		blockL7 = 0;
		blockR7 = 0;
		blockT7 = 0;
		blockB7 = 0;

		blockpx8 = 1500;
		blockpy8 = 50;
		blockW8 = 180;
		blockH8 = 30;
		blockL8 = 0;
		blockR8 = 0;
		blockT8 = 0;
		blockB8 = 0;

		blockpx9 = 1680;
		blockpy9 = 50;
		blockW9 = 180;
		blockH9 = 30;
		blockL9 = 0;
		blockR9 = 0;
		blockT9 = 0;
		blockB9 = 0;

		blockpx10 = 60;
		blockpy10 = 170;
		blockW10 = 180;
		blockH10 = 30;
		blockL10 = 0;
		blockR10 = 0;
		blockT10 = 0;
		blockB10 = 0;

		blockpx11 = 240;
		blockpy11 = 170;
		blockW11 = 180;
		blockH11 = 30;
		blockL11 = 0;
		blockR11 = 0;
		blockT11 = 0;
		blockB11 = 0;

		blockpx12 = 420;
		blockpy12 = 170;
		blockW12 = 180;
		blockH12 = 30;
		blockL12 = 0;
		blockR12 = 0;
		blockT12 = 0;
		blockB12 = 0;

		blockpx13 = 600;
		blockpy13 = 170;
		blockW13 = 180;
		blockH13 = 30;
		blockL13 = 0;
		blockR13 = 0;
		blockT13 = 0;
		blockB13 = 0;

		blockpx14 = 780;
		blockpy14 = 170;
		blockW14 = 180;
		blockH14 = 30;
		blockL14 = 0;
		blockR14 = 0;
		blockT14 = 0;
		blockB14 = 0;

		blockpx15 = 960;
		blockpy15 = 170;
		blockW15 = 180;
		blockH15 = 30;
		blockL15 = 0;
		blockR15 = 0;
		blockT15 = 0;
		blockB15 = 0;

		blockpx16 = 1140;
		blockpy16 = 170;
		blockW16 = 180;
		blockH16 = 30;
		blockL16 = 0;
		blockR16 = 0;
		blockT16 = 0;
		blockB16 = 0;

		blockpx17 = 1320;
		blockpy17 = 170;
		blockW17 = 180;
		blockH17 = 30;
		blockL17 = 0;
		blockR17 = 0;
		blockT17 = 0;
		blockB17 = 0;

		blockpx18 = 1500;
		blockpy18 = 170;
		blockW18 = 180;
		blockH18 = 30;
		blockL18 = 0;
		blockR18 = 0;
		blockT18 = 0;
		blockB18 = 0;

		blockpx19 = 1680;
		blockpy19 = 170;
		blockW19 = 180;
		blockH19 = 30;
		blockL19 = 0;
		blockR19 = 0;
		blockT19 = 0;
		blockB19 = 0;

		blockpx20 = 60;
		blockpy20 = 290;
		blockW20 = 180;
		blockH20 = 30;
		blockL20 = 0;
		blockR20 = 0;
		blockT20 = 0;
		blockB20 = 0;

		blockpx21 = 240;
		blockpy21 = 290;
		blockW21 = 180;
		blockH21 = 30;
		blockL21 = 0;
		blockR21 = 0;
		blockT21 = 0;
		blockB21 = 0;

		blockpx22 = 420;
		blockpy22 = 290;
		blockW22 = 180;
		blockH22 = 30;
		blockL22 = 0;
		blockR22= 0;
		blockT22 = 0;
		blockB22 = 0;

		blockpx23 = 600;
		blockpy23 = 290;
		blockW23 = 180;
		blockH23 = 30;
		blockL23 = 0;
		blockR23 = 0;
		blockT23 = 0;
		blockB23 = 0;

		blockpx24 = 780;
		blockpy24 = 290;
		blockW24= 180;
		blockH24 = 30;
		blockL24 = 0;
		blockR24 = 0;
		blockT24 = 0;
		blockB24 = 0;

		blockpx25 = 960;
		blockpy25 = 290;
		blockW25 = 180;
		blockH25 = 30;
		blockL25 = 0;
		blockR25 = 0;
		blockT25 = 0;
		blockB25 = 0;

		blockpx26 = 1140;
		blockpy26 = 290;
		blockW26 = 180;
		blockH26 = 30;
		blockL26 = 0;
		blockR26 = 0;
		blockT26 = 0;
		blockB26 = 0;

		blockpx27 = 1320;
		blockpy27 = 290;
		blockW27 = 180;
		blockH27 = 30;
		blockL27 = 0;
		blockR27 = 0;
		blockT27 = 0;
		blockB27 = 0;

		blockpx28 = 1500;
		blockpy28 = 290;
		blockW28 = 180;
		blockH28 = 30;
		blockL28 = 0;
		blockR28 = 0;
		blockT28 = 0;
		blockB28 = 0;

		blockpx29 = 1680;
		blockpy29 = 290;
		blockW29 = 180;
		blockH29 = 30;
		blockL29 = 0;
		blockR29 = 0;
		blockT29 = 0;
		blockB29 = 0;

		endflag = false;
		endflag1 = false;
		endflag2 = false;
		endflag3 = false;
		endflag4 = false;
		endflag5 = false;
		endflag6 = false;
		endflag7 = false;
		endflag8 = false;
		endflag9 = false;
		endflag10 = false;
		endflag11 = false;
		endflag12 = false;
		endflag13 = false;
		endflag14 = false;
		endflag15 = false;
		endflag16 = false;
		endflag17 = false;
		endflag18 = false;
		endflag19 = false;
		endflag20 = false;
		endflag21 = false;
		endflag22 = false;
		endflag23 = false;
		endflag24 = false;
		endflag25 = false;
		endflag26 = false;
		endflag27 = false;
		endflag28 = false;
		endflag29 = false;

		clearflag = 0;

		alltrue = 0;
		hideCursor();

		//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
		showCursor();
	}

	void GAME::proc(MANAGER* manager)
	{
		colorMode(HSV);
		float Satu = 200;
		float Value = 255;
		float Alpha = 255;

		struct COLOR Color[7] = {
			COLOR(0,Satu,Value,Alpha),
			COLOR(30,Satu,Value,Alpha),
			COLOR(60,Satu,Value,Alpha),
			COLOR(120,Satu,Value,Alpha),
			COLOR(180,Satu,Value,Alpha),
			COLOR(240,Satu,Value,Alpha),
			COLOR(300,Satu,Value,Alpha),
		};

		if (ballB < HEIGHT + 100) {

			clear(0);

			if (startflag == 0)
			{
				fill(255);
				textSize(100);
				text("スペースキーで開始", 500, 500);
			}

			if (isTrigger(KEY_SPACE))
			{
				startflag = 1;
			}

			if (clearflag == 1)
			{
				startflag = 2;
			}

			if (isTrigger(KEY_W)) 
			{
				ballvx += 1;
			}

			if (isTrigger(KEY_S))
			{
				ballvx -= 1;
			}

			if (isTrigger(KEY_Z))
			{
				alltrue = 1;
			}
			if (alltrue == 1) 
			{
				endflag = true;
				endflag1 = true;
				endflag2 = true;
				endflag3 = true;
				endflag4 = true;
				endflag5 = true;
				endflag6 = true;
				endflag7 = true;
				endflag8 = true;
				endflag9 = true;
				endflag10 = true;
				endflag11 = true;
				endflag12 = true;
				endflag13 = true;
				endflag14 = true;
				endflag15 = true;
				endflag16 = true;
				endflag17 = true;
				endflag18 = true;
				endflag19 = true;
				endflag20 = true;
				endflag21 = true;
				endflag22 = true;
				endflag23 = true;
				endflag24 = true;
				endflag25 = true;
				endflag26 = true;
				endflag27 = true;
				endflag28 = true;
				endflag29 = true;
			}

			//バー
			stroke(0);
			fill(Color[5]);
			rect(barpx, barpy, barW, barH);
			if (startflag == 1)
			{
				if (barL > 1){
					if (isPress(KEY_A))
					{
						barpx -= barvx;
					}
			    }
				if (barR < WIDTH - 1) {
					if (isPress(KEY_D))
					{
						barpx += barvx;
					}
				}
			}

			//ボール
			strokeWeight(10);
			stroke(Color[3]);
			rect(ballpx, ballpy, ballW, ballH);
			if (startflag == 1)
			{
				ballpx += ballvx;
				ballpy += ballvy;
			}

			if (startflag == 2)
			{
				stroke(0);
				fill(Color[2]);
				textSize(200);
				text("Game Clear",500, 400);
			}

			//バーの当たり判定用
			barL = barpx;
			barR = barpx + barW;
			barT = barpy;
			barB = barpy + barH;
			//ボール当たり判定用
			ballL = ballpx;
			ballR = ballpx + ballW;
			ballT = ballpy;
			ballB = ballpy + ballH;
			//ブロック当たり判定用
			blockL = blockpx;
			blockR = blockpx + blockW;
			blockT = blockpy;
			blockB = blockpy + blockH;

			blockL1 = blockpx1;
			blockR1 = blockpx1 + blockW1;
			blockT1 = blockpy1;
			blockB1 = blockpy1 + blockH1;

			blockL2 = blockpx2;
			blockR2 = blockpx2 + blockW2;
			blockT2 = blockpy2;
			blockB2 = blockpy2 + blockH2;

			blockL3 = blockpx3;
			blockR3 = blockpx3 + blockW3;
			blockT3 = blockpy3;
			blockB3 = blockpy3 + blockH3;

			blockL4 = blockpx4;
			blockR4 = blockpx4 + blockW4;
			blockT4 = blockpy4;
			blockB4 = blockpy4 + blockH4;

			blockL5 = blockpx5;
			blockR5 = blockpx5 + blockW5;
			blockT5 = blockpy5;
			blockB5 = blockpy5 + blockH5;

			blockL6 = blockpx6;
			blockR6 = blockpx6 + blockW6;
			blockT6 = blockpy6;
			blockB6 = blockpy6 + blockH6;

			blockL7 = blockpx7;
			blockR7 = blockpx7 + blockW7;
			blockT7 = blockpy7;
			blockB7 = blockpy7 + blockH7;

			blockL8 = blockpx8;
			blockR8 = blockpx8 + blockW8;
			blockT8 = blockpy8;
			blockB8 = blockpy8 + blockH8;

			blockL9 = blockpx9;
			blockR9 = blockpx9 + blockW9;
			blockT9 = blockpy9;
			blockB9 = blockpy9 + blockH9;

			blockL10 = blockpx10;
			blockR10 = blockpx10 + blockW10;
			blockT10 = blockpy10;
			blockB10 = blockpy10 + blockH10;

			blockL11 = blockpx11;
			blockR11 = blockpx11 + blockW11;
			blockT11 = blockpy11;
			blockB11 = blockpy11 + blockH11;

			blockL12 = blockpx12;
			blockR12 = blockpx12 + blockW12;
			blockT12 = blockpy12;
			blockB12 = blockpy12 + blockH12;

			blockL13 = blockpx13;
			blockR13 = blockpx13 + blockW13;
			blockT13 = blockpy13;
			blockB13 = blockpy13 + blockH13;

			blockL14 = blockpx14;
			blockR14 = blockpx14 + blockW14;
			blockT14 = blockpy14;
			blockB14 = blockpy14 + blockH14;

			blockL15 = blockpx15;
			blockR15 = blockpx15 + blockW15;
			blockT15 = blockpy15;
			blockB15 = blockpy15 + blockH15;

			blockL16 = blockpx16;
			blockR16 = blockpx16 + blockW16;
			blockT16 = blockpy16;
			blockB16 = blockpy16 + blockH16;

			blockL17 = blockpx17;
			blockR17 = blockpx17 + blockW17;
			blockT17 = blockpy17;
			blockB17 = blockpy17 + blockH17;

			blockL18 = blockpx18;
			blockR18 = blockpx18 + blockW18;
			blockT18 = blockpy18;
			blockB18 = blockpy18 + blockH18;

			blockL19 = blockpx19;
			blockR19 = blockpx19 + blockW19;
			blockT19 = blockpy19;
			blockB19 = blockpy19 + blockH19;

			blockL20 = blockpx20;
			blockR20 = blockpx20 + blockW20;
			blockT20 = blockpy20;
			blockB20 = blockpy20 + blockH20;

			blockL21 = blockpx21;
			blockR21 = blockpx21 + blockW21;
			blockT21 = blockpy21;
			blockB21 = blockpy21 + blockH21;

			blockL22 = blockpx22;
			blockR22 = blockpx22 + blockW22;
			blockT22 = blockpy22;
			blockB22 = blockpy22 + blockH22;

			blockL23 = blockpx23;
			blockR23 = blockpx23 + blockW23;
			blockT23 = blockpy23;
			blockB23 = blockpy23 + blockH23;

			blockL24 = blockpx24;
			blockR24 = blockpx24 + blockW24;
			blockT24 = blockpy24;
			blockB24 = blockpy24 + blockH24;

			blockL25 = blockpx25;
			blockR25 = blockpx25 + blockW25;
			blockT25 = blockpy25;
			blockB25 = blockpy25 + blockH25;

			blockL26 = blockpx26;
			blockR26 = blockpx26 + blockW26;
			blockT26 = blockpy26;
			blockB26 = blockpy26 + blockH26;

			blockL27 = blockpx27;
			blockR27 = blockpx27 + blockW27;
			blockT27 = blockpy27;
			blockB27 = blockpy27+ blockH27;

			blockL28 = blockpx28;
			blockR28 = blockpx28+ blockW28;
			blockT28 = blockpy28;
			blockB28 = blockpy28+ blockH28;

			blockL29 = blockpx29;
			blockR29 = blockpx29 + blockW29;
			blockT29 = blockpy29;
			blockB29 = blockpy29 + blockH29;

			//ボール当たり判定
			if (ballL < ballW / 2)
			{
				ballL = ballW / 2;
				ballvx *= -1;
			}
			if (ballL > WIDTH - ballW / 2)
			{
				ballL = WIDTH - ballW / 2;
				ballvx *= -1;
			}
			if (ballT < ballH / 2) {
				ballT = ballH / 2;
				ballvy *= -1;
			}

			//ボールとバーの当たり判定			
			if (ballB > barT &&
				ballL < barR &&
				ballR > barL &&
				ballT < barB)
			{
				if (barpx + barW / 2 > ballpx)
				{ 
					ballvx *= -1;
					ballvy *= -1;
				}
				else
				{
					ballvx *= 1;
					ballvy *= -1;
				}
				if (barL > ballR)
			    if (barR < ballL)
				{
					ballvy *= -1;
				}
			}

			//ボールとブロックの当たり判定
			if (endflag == false)
			{
				//ブロック下
				if (blockB >= ballT &&
					blockL < ballR &&
					blockR > ballL)
				{
				//ブロック上
				if (blockT <= ballB &&
					blockL < ballR &&
					blockR > ballL)
				{
				//ブロック右
				if (blockR > ballL)
				{
				//ブロック左
	            if (blockL < ballR)
				{
     				ballvy *= -1;
					endflag = true;
				}
				}
		     	}
				}
			}
			if (endflag1 == false)
			{
				if (blockB1 >= ballT &&
					blockL1 < ballR &&
					blockR1 > ballL)
				{
					if (blockT1 <= ballB &&
						blockL1 < ballR &&
						blockR1 > ballL)
					{
						if (blockR1 > ballL)
						{
							if (blockL1 < ballR)
							{
								ballvy *= -1;
								endflag1 = true;
							}
						}
					}
				}
			}
			if (endflag2 == false)
			{
				if (blockB2 >= ballT &&
					blockL2 < ballR &&
					blockR2 > ballL)
				{
					if (blockT2 <= ballB &&
						blockL2 < ballR &&
						blockR2 > ballL)
					{
						if (blockR2 > ballL)
						{
							if (blockL2 < ballR)
							{
								ballvy *= -1;
								endflag2 = true;
							}
						}
					}
				}
			}
			if (endflag3 == false)
			{
				if (blockB3 >= ballT &&
					blockL3 < ballR &&
					blockR3 > ballL)
				{
					if (blockT3 <= ballB &&
						blockL3 < ballR &&
						blockR3 > ballL)
					{
						if (blockR3 > ballL)
						{
							if (blockL3 < ballR)
							{
								ballvy *= -1;
								endflag3 = true;
							}
						}
					}
				}
			}
			if (endflag4 == false)
			{
				if (blockB4 >= ballT &&
					blockL4 < ballR &&
					blockR4 > ballL)
				{
					if (blockT4 <= ballB &&
						blockL4 < ballR &&
						blockR4 > ballL)
					{
						if (blockR4 > ballL)
						{
							if (blockL4 < ballR)
							{
								ballvy *= -1;
								endflag4 = true;
							}
						}
					}
				}
			}
			if (endflag5 == false)
			{
				if (blockB5 >= ballT &&
					blockL5 < ballR &&
					blockR5 > ballL)
				{
					if (blockT5 <= ballB &&
						blockL5 < ballR &&
						blockR5 > ballL)
					{
						if (blockR5 > ballL)
						{
							if (blockL5 < ballR)
							{
								ballvy *= -1;
								endflag5 = true;
							}
						}
					}
				}
			}
			if (endflag6 == false)
			{
				if (blockB6 >= ballT &&
					blockL6 < ballR &&
					blockR6 > ballL)
				{
					if (blockT6 <= ballB &&
						blockL6 < ballR &&
						blockR6 > ballL)
					{
						if (blockR6 > ballL)
						{
							if (blockL6 < ballR)
							{
								ballvy *= -1;
								endflag6 = true;
							}
						}
					}
				}
			}
			if (endflag7 == false)
			{
				if (blockB7 >= ballT &&
					blockL7 < ballR &&
					blockR7 > ballL)
				{
					if (blockT7 <= ballB &&
						blockL7 < ballR &&
						blockR7 > ballL)
					{
						if (blockR7 > ballL)
						{
							if (blockL7 < ballR)
							{
								ballvy *= -1;
								endflag7 = true;
							}
						}
					}
				}
			}
			if (endflag8 == false)
			{
				if (blockB8 >= ballT &&
					blockL8 < ballR &&
					blockR8 > ballL)
				{
					if (blockT8 <= ballB &&
						blockL8 < ballR &&
						blockR8 > ballL)
					{
						if (blockR8 > ballL)
						{
							if (blockL8 < ballR)
							{
								ballvy *= -1;
								endflag8 = true;
							}
						}
					}
				}
			}
			if (endflag9 == false)
			{
				if (blockB9 >= ballT &&
					blockL9 < ballR &&
					blockR9 > ballL)
				{
					if (blockT9 <= ballB &&
						blockL9 < ballR &&
						blockR9 > ballL)
					{
						if (blockR9 > ballL)
						{
							if (blockL9 < ballR)
							{
								ballvy *= -1;
								endflag9 = true;
							}
						}
					}
				}
			}
			if (endflag10 == false)
			{
				if (blockB10 >= ballT &&
					blockL10 < ballR &&
					blockR10 > ballL)
				{
					if (blockT10 <= ballB &&
						blockL10 < ballR &&
						blockR10 > ballL)
					{
						if (blockR10 > ballL)
						{
							if (blockL10 < ballR)
							{
								ballvy *= -1;
								endflag10 = true;
							}
						}
					}
				}
			}
			if (endflag11 == false)
			{
				if (blockB11 >= ballT &&
					blockL11 < ballR &&
					blockR11 > ballL)
				{
					if (blockT11 <= ballB &&
						blockL11 < ballR &&
						blockR11 > ballL)
					{
						if (blockR11 > ballL)
						{
							if (blockL11 < ballR)
							{
								ballvy *= -1;
								endflag11 = true;
							}
						}
					}
				}
			}
			if (endflag12 == false)
			{
				if (blockB12 >= ballT &&
					blockL12 < ballR &&
					blockR12 > ballL)
				{
					if (blockT12 <= ballB &&
						blockL12 < ballR &&
						blockR12 > ballL)
					{
						if (blockR12 > ballL)
						{
							if (blockL12 < ballR)
							{
								ballvy *= -1;
								endflag12 = true;
							}
						}
					}
				}
			}
			if (endflag13 == false)
			{
				if (blockB13 >= ballT &&
					blockL13 < ballR &&
					blockR13 > ballL)
				{
					if (blockT13 <= ballB &&
						blockL13 < ballR &&
						blockR13 > ballL)
					{
						if (blockR13 > ballL)
						{
							if (blockL13 < ballR)
							{
								ballvy *= -1;
								endflag13 = true;
							}
						}
					}
				}
			}
			if (endflag14 == false)
			{
				if (blockB14 >= ballT &&
					blockL14 < ballR &&
					blockR14 > ballL)
				{
					if (blockT14 <= ballB &&
						blockL14 < ballR &&
						blockR14 > ballL)
					{
						if (blockR14 > ballL)
						{
							if (blockL14 < ballR)
							{
								ballvy *= -1;
								endflag14 = true;
							}
						}
					}
				}
			}
			if (endflag15 == false)
			{
				if (blockB15 >= ballT &&
					blockL15 < ballR &&
					blockR15 > ballL)
				{
					if (blockT15 <= ballB &&
						blockL15 < ballR &&
						blockR15 > ballL)
					{
						if (blockR15 > ballL)
						{
							if (blockL15 < ballR)
							{
								ballvy *= -1;
								endflag15 = true;
							}
						}
					}
				}
			}
			if (endflag16 == false)
			{
				if (blockB16 >= ballT &&
					blockL16 < ballR &&
					blockR16 > ballL)
				{
					if (blockT16 <= ballB &&
						blockL16 < ballR &&
						blockR16 > ballL)
					{
						if (blockR16 > ballL)
						{
							if (blockL16 < ballR)
							{
								ballvy *= -1;
								endflag16 = true;
							}
						}
					}
				}
			}
			if (endflag17 == false)
			{
				if (blockB17 >= ballT &&
					blockL17 < ballR &&
					blockR17 > ballL)
				{
					if (blockT17 <= ballB &&
						blockL17 < ballR &&
						blockR17 > ballL)
					{
						if (blockR17 > ballL)
						{
							if (blockL17 < ballR)
							{
								ballvy *= -1;
								endflag17 = true;
							}
						}
					}
				}
			}
			if (endflag18 == false)
			{
				if (blockB18 >= ballT &&
					blockL18 < ballR &&
					blockR18 > ballL)
				{
					if (blockT18 <= ballB &&
						blockL18 < ballR &&
						blockR18 > ballL)
					{
						if (blockR18 > ballL)
						{
							if (blockL18 < ballR)
							{
								ballvy *= -1;
								endflag18 = true;
							}
						}
					}
				}
			}
			if (endflag19 == false)
			{
				if (blockB19 >= ballT &&
					blockL19 < ballR &&
					blockR19 > ballL)
				{
					if (blockT19 <= ballB &&
						blockL19 < ballR &&
						blockR19 > ballL)
					{
						if (blockR19 > ballL)
						{
							if (blockL19 < ballR)
							{
								ballvy *= -1;
								endflag19 = true;
							}
						}
					}
				}
			}
			if (endflag20 == false)
			{
				if (blockB20 >= ballT &&
					blockL20 < ballR &&
					blockR20 > ballL)
				{
					if (blockT20 <= ballB &&
						blockL20 < ballR &&
						blockR20 > ballL)
					{
						if (blockR20 > ballL)
						{
							if (blockL20 < ballR)
							{
								ballvy *= -1;
								endflag20 = true;
							}
						}
					}
				}
			}
			if (endflag21 == false)
			{
				if (blockB21 >= ballT &&
					blockL21 < ballR &&
					blockR21 > ballL)
				{
					if (blockT21 <= ballB &&
						blockL21 < ballR &&
						blockR21 > ballL)
					{
						if (blockR21 > ballL)
						{
							if (blockL21 < ballR)
							{
								ballvy *= -1;
								endflag21 = true;
							}
						}
					}
				}
			}
			if (endflag22 == false)
			{
				if (blockB22 >= ballT &&
					blockL22 < ballR &&
					blockR22 > ballL)
				{
					if (blockT22 <= ballB &&
						blockL22 < ballR &&
						blockR22 > ballL)
					{
						if (blockR22 > ballL)
						{
							if (blockL22 < ballR)
							{
								ballvy *= -1;
								endflag22 = true;
							}
						}
					}
				}
			}
			if (endflag23 == false)
			{
				if (blockB23 >= ballT &&
					blockL23 < ballR &&
					blockR23 > ballL)
				{
					if (blockT23 <= ballB &&
						blockL23 < ballR &&
						blockR23 > ballL)
					{
						if (blockR23 > ballL)
						{
							if (blockL23 < ballR)
							{
								ballvy *= -1;
								endflag23 = true;
							}
						}
					}
				}
			}
			if (endflag24 == false)
			{
				if (blockB24 >= ballT &&
					blockL24 < ballR &&
					blockR24 > ballL)
				{
					if (blockT24 <= ballB &&
						blockL24 < ballR &&
						blockR24 > ballL)
					{
						if (blockR24 > ballL)
						{
							if (blockL24 < ballR)
							{
								ballvy *= -1;
								endflag24 = true;
							}
						}
					}
				}
			}
			if (endflag25 == false)
			{
				if (blockB25 >= ballT &&
					blockL25 < ballR &&
					blockR25 > ballL)
				{
					if (blockT25 <= ballB &&
						blockL25 < ballR &&
						blockR25 > ballL)
					{
						if (blockR25 > ballL)
						{
							if (blockL25 < ballR)
							{
								ballvy *= -1;
								endflag25 = true;
							}
						}
					}
				}
			}
			if (endflag26 == false)
			{
				if (blockB26 >= ballT &&
					blockL26 < ballR &&
					blockR26 > ballL)
				{
					if (blockT26 <= ballB &&
						blockL26 < ballR &&
						blockR26 > ballL)
					{
						if (blockR26 > ballL)
						{
							if (blockL26 < ballR)
							{
								ballvy *= -1;
								endflag26 = true;
							}
						}
					}
				}
			}
			if (endflag27 == false)
			{
				if (blockB27 >= ballT &&
					blockL27 < ballR &&
					blockR27 > ballL)
				{
					if (blockT27 <= ballB &&
						blockL27 < ballR &&
						blockR27 > ballL)
					{
						if (blockR27 > ballL)
						{
							if (blockL27 < ballR)
							{
								ballvy *= -1;
								endflag27 = true;
							}
						}
					}
				}
			}
			if (endflag28 == false)
			{
				if (blockB28 >= ballT &&
					blockL28 < ballR &&
					blockR28 > ballL)
				{
					if (blockT28 <= ballB &&
						blockL28 < ballR &&
						blockR28 > ballL)
					{
						if (blockR28 > ballL)
						{
							if (blockL28 < ballR)
							{
								ballvy *= -1;
								endflag28 = true;
							}
						}
					}
				}
			}
			if (endflag29 == false)
			{ 
				if (blockB29 >= ballT &&
					blockL29 < ballR &&
					blockR29 > ballL)
				{
					if (blockT29 <= ballB &&
						blockL29 < ballR &&
						blockR29 > ballL)
					{
						if (blockR29 > ballL)
						{
							if (blockL29 < ballR)
							{
								ballvy *= -1;
								endflag29 = true;
							}
						}
					}
				}
			}
			
			//ブロック
			stroke(0);
			fill(Color[0]);
			if (!endflag)
			{
				rect(blockpx, blockpy, blockW, blockH, false);
			}
			if (!endflag1)
			{
				rect(blockpx1, blockpy1, blockW1, blockH1, false);
			}
			if (!endflag2)
			{
				rect(blockpx2, blockpy2, blockW2, blockH2, false);
			}
			if (!endflag3)
			{
				rect(blockpx3, blockpy3, blockW3, blockH3, false);
			}
			if (!endflag4)
			{
				rect(blockpx4, blockpy4, blockW4, blockH4, false);
			}
			if (!endflag5)
			{
				rect(blockpx5, blockpy5, blockW5, blockH5, false);
			}
			if (!endflag6)
			{
				rect(blockpx6, blockpy6, blockW6, blockH6, false);
			}
			if (!endflag7)
			{
				rect(blockpx7, blockpy7, blockW7, blockH7, false);
			}
			if (!endflag8)
			{
				rect(blockpx8, blockpy8, blockW8, blockH8, false);
			}
			if (!endflag9)
			{
				rect(blockpx9, blockpy9, blockW9, blockH9, false);
			}
			fill(Color[1]);
			if (!endflag10)
			{
				rect(blockpx10, blockpy10, blockW10, blockH10, false);
			}
			if (!endflag11)
			{
				rect(blockpx11, blockpy11, blockW11, blockH11, false);
			}
			if (!endflag12)
			{
				rect(blockpx12, blockpy12, blockW12, blockH12, false);
			}
			if (!endflag13)
			{
				rect(blockpx13, blockpy13, blockW13, blockH13, false);
			}
			if (!endflag14)
			{
				rect(blockpx14, blockpy14, blockW14, blockH14, false);
			}
			if (!endflag15)
			{
				rect(blockpx15, blockpy15, blockW15, blockH15, false);
			}
			if (!endflag16)
			{
				rect(blockpx16, blockpy16, blockW16, blockH16, false);
			}
			if (!endflag17)
			{
				rect(blockpx17, blockpy17, blockW17, blockH17, false);
			}
			if (!endflag18)
			{
				rect(blockpx18, blockpy18, blockW18, blockH18, false);
			}
			if (!endflag19)
			{
				rect(blockpx19, blockpy19, blockW19, blockH19, false);
			}
			fill(Color[2]);
			if (!endflag20)
			{
				rect(blockpx20, blockpy20, blockW20, blockH20, false);
			}
			if (!endflag21)
			{
				rect(blockpx21, blockpy21, blockW21, blockH21, false);
			}
			if (!endflag22)
			{
				rect(blockpx22, blockpy22, blockW22, blockH22, false);
			}
			if (!endflag23)
			{
				rect(blockpx23, blockpy23, blockW23, blockH23, false);
			}
			if (!endflag24)
			{
				rect(blockpx24, blockpy24, blockW24, blockH24, false);
			}
			if (!endflag25)
			{
				rect(blockpx25, blockpy25, blockW25, blockH25, false);
			}
			if (!endflag26)
			{
				rect(blockpx26, blockpy26, blockW26, blockH26, false);
			}
			if (!endflag27)
			{
				rect(blockpx27, blockpy27, blockW27, blockH27, false);
			}
			if (!endflag28)
			{
				rect(blockpx28, blockpy28, blockW28, blockH28, false);
			}
			if (!endflag29)
			{
				rect(blockpx29, blockpy29, blockW29, blockH29, false);
			}

			if (endflag == true &&
				endflag1 == true &&
				endflag2 == true &&
				endflag3 == true &&
				endflag4 == true &&
				endflag5 == true &&
				endflag6 == true &&
				endflag7 == true &&
				endflag8 == true &&
				endflag9 == true &&
				endflag10 == true &&
				endflag11 == true &&
				endflag12 == true &&
				endflag13 == true &&
				endflag14 == true &&
				endflag15 == true &&
				endflag16 == true &&
				endflag17 == true &&
				endflag18 == true &&
				endflag19 == true &&
				endflag20 == true &&
				endflag21 == true &&
				endflag22 == true &&
				endflag23 == true &&
				endflag24 == true &&
				endflag25 == true &&
				endflag26 == true &&
				endflag27 == true &&
				endflag28 == true &&
				endflag29 == true
				)
			{
				clearflag = 1;
			}
		}

		if (ballT > HEIGHT) {
			fill(Color[0]);
			textSize(170);
			text("Game Over", 600, 400);
			textSize(80);
			text("Enterでメニューに戻る", 600, 700);
		}

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