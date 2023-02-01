#pragma once
#include"../MAIN/STATE.h"

namespace GAME18 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//画像
		int backImg = 0;

		//ブラシサイズ
		float MBsize = 0;
		float ABsize = 0;
		VECTOR2 BrectHeadPos{};
		VECTOR2 BpointHeadPos{};
		float Bofs = 0;
		float BtextPx = 0;
		float BtextPy = 0;
		float BkeyTextPx = 0;
		float BkeyTextPy = 0;
		float BkeyTextofsY = 0;
		float BairTextPx = 0;
		float BairTextPy = 0;
		float BgraTextPx = 0;
		float BgraTextPy = 0;
		//エアブラシ濃度
		char Sconcentration = 0; //1-5
		//(5 * Sconcentration * Bsize)
		float splashPx = 0;
		float splashPy = 0;
		
		/*カラーバッファー*/
		COLOR PCbuffClr{};
		COLOR RGBbuffClr{};
		COLOR currentClr{};
		//プリセットカラー
		float PCPx = 0;
		float PCPy = 0;
		float PCheadPy = 0;
		float PCofs = 0;
		float PCtextPx = 0;
		float PCtSize = 0;
		float PCtShadow = 0;
		float PCUIradius = 0;
		short PCroop = 0;
		
		//RGB表示用
		//スムースライティング
		float pastPx = 0;
		float pastPy = 0;
		char drawingFlag = 0;
		//定規ツール
		float startPx = 0;
		float startPy = 0;
		float endPx = 0;
		float endPy = 0;
		float isRuler = 0;
		//円・四角形共用
		float topPy = 0;
		float bottomPy = 0;
		float leftPx = 0;
		float rightPx = 0;
		//円ツール
		float isCircle = 0;
		float isCircleF = 0;
		//四角形ツール
		float isRect = 0;
		float isRectF = 0;

		//現在の状態の表示
		float ItSize = 0;
		float IkeyBPx = 0;
		float IkeyCPx = 0;
		float IkeyEPx = 0;
		float IkeyPy = 0;
		float IBsizePx = 0;
		float IBsizePy = 0;
		float IBsizeofsY = 0;
		float IB1stdigofsX = 0;
		float IB2nddigofsX = 0;
		float IB3rddigofsX = 0;
		float IclrRPx = 0;
		float IclrGPx = 0;
		float IclrBPx = 0;
		float IclrPy = 0;
		float IclrofsY = 0;
		float IC1stdigofsX = 0;
		float IC2nddigofsX = 0;
		float IC3rddigofsX = 0;
		int Ibuf = 0;
		//操作方法の表示
		float IopePx = 0;
		float IopePy = 0;
		float IopeToolPx = 0;
		float IopeToolPy = 0;
		float IresetPx = 0;
		float IresetPy = 0;

		/*Flags*/
		char paperFlag = 0;
		short colorFlag = 0;
		char BsizeFlag = 0;
		//マーカー・エアブラシ切替
		char MAFlag = 0;
		//ペン・消しゴム切替
		short PEFlag = 0;
		short RGBFlag = 0;
		char PCisPointerFlag = 0;
		char BselectFlag = 0;

		/*グラデーションカラー*/
		COLOR HSVClr{};
		char HSVspeed = 0;
		int HSVpseudoH = 0;
		/*preset color*/
		short preColor = 0;
		//赤
		COLOR SHU{ 239, 69, 74 };
		COLOR AZUKI{ 148, 98, 89 };
		COLOR TUTUJI{ 239, 91, 156 };
		//青
		COLOR RURI{ 42, 92, 170 }; 
		COLOR KOIAI{ 13, 42, 82 }; 
		COLOR TETSUKON{ 35, 37, 56 };
		//緑
		COLOR RYOKUSHO{ 71, 132, 94 }; 
		COLOR TOKIWA{ 53, 124, 76 }; 
		COLOR SEIJI{ 96, 180, 159 }; 
		//黄
		COLOR YAMABUKI{ 252, 175, 23 }; 
		COLOR KUTIBA{ 137, 120, 104 }; 
		COLOR IO{ 241, 226, 102 }; 
		//紫
		COLOR RINDO{ 144, 121, 173 }; 
		COLOR SUMIRE{ 109, 82, 171 };
		COLOR NASUKON{ 69, 31, 73 };
		//水色
		COLOR SHIROHANADA{ 163, 216, 246 };
		COLOR ASAGI{ 0, 135, 170 };
		COLOR WASURENAGUSA{ 146, 175, 228 };
		//黒
		COLOR SUMI{ 49, 49, 49 };
		COLOR NUREGARASU{ 0, 11, 0 };
		//白
		COLOR UNOHANA{ 247, 252, 254 }; 
		COLOR SHINJU{ 255, 244, 242 };
		COLOR TORINOKO{ 255, 246, 220 }; //背景色
		//灰
		COLOR GINNEZUMI{ 161, 163, 166 };
		COLOR NAMARI{ 121, 122, 136 };

		/*色選択*/
		unsigned char RGBr = 0;
		unsigned char RGBg = 0;
		unsigned char RGBb = 0;

		//以下はいじらないでよい
		int BackToMenuFlag=0;

	public:
		void update();
		void draw();
		void dispInfo();
		void back();
		void picClr();
		void setClr();
		void graClr();
		void setBsize();
		void reset();
	};
}

