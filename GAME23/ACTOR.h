#pragma once
namespace GAME23
{
	class ACTOR
	{
	public:
		ACTOR(class GAME* game);
		virtual ~ACTOR();
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		class GAME* game() { return Game; }
		float px() { return Px; }
		float py() { return Py; }
		float sp() { return Sp; }
		float vx() { return Vx; }
		float vy() { return Vy; }
		float w() { return W; }
		float h() { return H; }
		float r() { return W; }
		int hp() { return Hp; }
		int img() { return Img; }
		void setPx(float px) { Px = px; }
		void setPy(float py) { Py = py; }
		void setSp(float sp) { Sp = sp; }
		void setVx(float vx) { Vx = vx; }
		void setVy(float vy) { Vy = vy; }
		void setW(float w) { W = w; }
		void setH(float h) { H = h; }
		void setR(float r) { W = r; }
		void setHp(int hp) { Hp = hp; }
		void setImg(int img) { Img = img; }
	private:
		class GAME* Game;
		float Px, Py;
		float Sp, Vx, Vy;
		float W, H;
		int Hp;
		int Img;
	};
}
