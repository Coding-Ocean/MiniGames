#pragma once
#include"../MAIN/STATE.h"
#include"math.h"
namespace GAME05 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！
	class MYCIRCLE {
	private:
		float Px = 0;
		float Py = 0;
		int Hp = 0;
		float diameter = 0;
		int s = 0;
	public:
		MYCIRCLE() {
		}
		~MYCIRCLE() {}
		void init() {
			Px = random(100, 1800);
			Py = random(100, 900);
			Hp = 1;
			diameter = 40;
			s = 0;
			
		
		}
		void move() {
			if (Hp > 0) {
				Px = MouseX;
				Py = MouseY;
			}
		}
		void draw() {
			circle(Px, Py, diameter);
		}
		void collsionWall() {
			if (Px + diameter / 2 > 1920) { Px = 1918 - diameter / 2;}
			if (Px - diameter / 2 < 0) { Px = diameter / 2 + 2;}
			if (Py + diameter / 2 > 1080) { Py = 1078 - diameter / 2;}
			if (Py - diameter / 2 < 0) { Py = diameter / 2 + 2; }
		}
		void collisionBall(float x,float y,float dia) {
			float a = Px - x;
			float b = Py - y;
			float hypotenuse = sqrt(a * a + b * b);
			if (hypotenuse <= dia/2 + diameter/2) {
				fill(255, 0, 0);
				Hp--;
			}
		}
		void scoreCounter() {
			if (Hp > 0) {
				s++;
			}
		}
		void scoredraw() {
			textSize(300);
			text(s, 500, 500);
		}
		int hp() { return Hp; }
	};
	class EBALL {
	public:
		float Px=0;
		float Py=0;
		float Vx=0;
		float Vy=0;
		float Diameter;
		int r, g, b;
		EBALL() {}
		~EBALL() {}
		void init() {
			Px = random(100, 1800);
			Py = random(100, 900);
			Vx = random(-10.0f, 10.0f);
			Vy = random(-10.0f, 10.0f);
			Diameter = random(60, 180);
			r = random(0, 255);
			g = random(0, 255);
			b = random(0, 255);
		}
		void move() {
			Px += Vx;
			Py += Vy;
		}
		void draw() {
			fill(r, g, b);
			circle(Px, Py, Diameter);
		}
		void collisionWall() {
			if (Px + Diameter / 2 > 1920) { Px = 1918 - Diameter/2; Vx *= -1.01f; }
			if (Px - Diameter / 2 < 0 ) { Px = Diameter/2 + 2; Vx *= -1.01f; }
			if (Py + Diameter / 2 > 1080) { Py = 1078 - Diameter/2; Vy *= -1.01f; }
			if (Py - Diameter / 2 < 0) { Py = Diameter/2+2; Vy *= -1.01f; }
		}
		float px() { return Px; }
		float py() { return Py; }
		float diameter() { return Diameter; }
	};
	
	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	public:
		int sd;
		void sound() {
			sd = loadSound("../game05/assets/mainBGM.wav");
			playSound(sd);
		}
		void dsound() {
			stopSound(sd);
		}
	private:
		//ここに必要な記憶場所を用意する
		//画像表示用
		int Img;

		//以下はいじらないでよい
		int BackToMenuFlag=0;
	};
}

