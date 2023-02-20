#pragma once
namespace GAME00 {

	class ACTOR{

	public:
		ACTOR(class GAME* game);
		virtual ~ACTOR();
		enum State
		{
			EActive, EPause, EDead
		};

		//各処理関数
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;

	
		//Getter
		class GAME* GetGame() { return Game; }

		float px() { return Px; }
		float py() { return Py; }
		float sp() { return Sp; }
		float vx() { return Vx; }
		float vy() { return Vy; }
		float w() { return W; }
		float h() { return H; }
		float r() { return W; } //Wを幅として扱わず、半径として扱う時に使用
		float st() { return STROKE; }
		float sw() { return STROKE_W; }
		float len() { return Len; }
		float col() { return Col; }

		//Setter
		void setPx(float px) { Px = px; }
		void setPy(float py) { Py = py; }
		void setSp(float sp) { Sp = sp; }
		void setVx(float vx) { Vx = vx; }
		void setVy(float vy) { Vy = vy; }
		void setW(float w) { W = w; }
		void setH(float h) { H = h; }
		void setR(float r) { W = r; } //Wを幅として扱わず、半径として扱う時に使用
		void setST(float st) { STROKE = st; };
		void setSW(float sw) { STROKE_W = sw; };
		void setLen(float len) { Len = len; }
		void setCol(float col) { Col = col; }

		State GetState() { return mState; }
		void SetState(State state) { mState = state; }

	private:
		class GAME* Game;
		State mState;
		float Px = 0.0f, Py = 0.0f;
		float Sp = 0.0f, Vx = 0.0f, Vy = 0.0f;
		float W = 0.0f, H = 0.0f;
		float STROKE = 0.0f, STROKE_W = 0.0f;
		float Len = 0.0f, Col = 0.0f;
	};

}

