#pragma once
#include"../MAIN/STATE.h"

namespace GAME12 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//ここに必要な記憶場所を用意する
		int gameFlag = 0;
		int title_titleImg = 0;
		int title_startImg = 0;

		COLOR title_back;

		float title_titlePy = 0;
		float title_titlePx = 0;

		float play_top = 0;

		int play_lifeImg = 0;
		int play_lifedamageImg = 0;
		float play_lifePx = 0;
		float play_lifePy = 0;
		float play_lifeOfsX = 0;
		float play_lifeSize = 0;
		int play_ouImg = 0;
		int play_gyokuImg = 0;
		int play_hiImg = 0;
		int play_iwakuImg = 0;
		int play_sakuImg = 0;
		int play_saku1Img = 0;
		int play_inuImg = 0;
		int play_daiImg = 0;
		int play_tutiImg= 0;
		int play_siImg = 0;
		int play_miImg = 0;
		int play_matuImg = 0;
		int play_zeroImg = 0;
		int play_funImg = 0;
		int play_tyouImg = 0;
		int play_kouImg = 0;
		int play_tiImg = 0;
		int play_waImg = 0;
		int play_ko1Img = 0;
		int play_koImg = 0;
		int play_uImg = 0;
		int play_ziImg = 0;
		int play_meiImg = 0;
		int play_kakuImg = 0;
		int play_kugiImg = 0;
		int play_hariImg = 0;
		int play_kaiImg = 0;
		int play_guImg = 0;
		int play_kokoroImg = 0;
		int play_hituImg = 0;
		COLOR play_readyback;
		COLOR play_moveback;
		COLOR play_finishback;
		int play_numlv1 = 0;
		int play_numlv2 = 0;
		int play_numlv3 = 0;
		int play_currentnum = 0;


		float play_UIPx = 0;
		float play_UIPy = 0;
		float play_UIWidth = 0;
		float play_UIHeight = 0;
		COLOR play_UIColor;

		int play_Hp = 0;
		int play_HitFlag = 0;


		float play_Time = 0;
		float play_Timedamage = 0;
		float play_TimeLimit = 0;
		float play_TimeBuf = 0;
		int d1, d2, d3, d4, d5;
		int m = 0;
		int s = 0;
		int ds = 0;
		char play_TimeStr[8]{};
		char play_TimeStrbuf[3]{};
		char play_TimeRemain[19]{};
		char play_TimeRemain1[9] = "残り時間";
		char play_TimeRemain2[3] = "分";
		char play_TimeRemain3[3] = "秒";
		float play_TimePx;
		float play_TimePy;
		float play_TimeSize;
		float play_TimeRemainPx;
		float play_TimeRemainPy;
		float play_TimeRemainSize;
		COLOR play_TimeColor;
		COLOR play_TimeLimitColor;

		COLOR result_clear;
		COLOR result_fail;
		int result_SS = 0;
		int result_S = 0;
		int result_A = 0;
		int result_B = 0;
		int result_C = 0;
		float result_rankPx = 0;
		float result_rankPy = 0;
		float result_rankScale = 0;

		char result_clearTime[16]{};
		char result_clearTimebuf[2]{};
		char result_clearTimeStr1[9] = "所要時間";
		char result_clearTimeStr2[2] = ".";
		char result_clearTimeStr3[3] = "秒";
		float result_clearTimeSize = 0;
		float result_clearTimePx = 0;
		float result_clearTimePy = 0;
		COLOR result_clearTimeColor{};




		struct TEXT {
			const char* Str;
			float Size = 0;
			float Px = 0;
			float Py = 0;
			COLOR Color;
		};

		TEXT title_text[5]{};
		TEXT play_ready[4]{};
		TEXT play_dispLevel[3]{};
		TEXT play_finish[4]{};
		TEXT result_time{};
		TEXT result_gameclear{};
		TEXT result_gamefail{};
		struct BOX {
			int TextImg = 0;
			float Px = 0;
			float Py = 0;
			float Vx = 0;
			float Vy = 0;
			float Angle = 0;
			float ImgScale = 0;
			bool Hit = true;
			float ReflectDelayX = 0;
			float ReflectDelayY = 0;
		 };
		BOX* lv1 = nullptr;
		BOX* lv2 = nullptr;
		BOX* lv3 = nullptr;
		BOX* current = nullptr;

		struct BUTTON {
			const char* Str = 0; //文字列
			float Size; //文字サイズ
			float SPx; //文字X座標
			float SPy; //文字Y座標
			float RPx; //枠X座標
			float RPy; //枠Y座標
			float W; //枠幅
			float H; //枠高
			float Ofs; //枠と文字の隙間
			float FlameWeight; //枠線の太さ
			COLOR FlameColor; //枠線の色
			COLOR RectColor; //背景色
			COLOR StringsColor; //文字色
		};
		BUTTON result_info[4]{};

		enum STATE{TITLE, PLAY, RESULT};
		STATE State = TITLE;
		enum LEVEL{LV1, LV2, LV3, END};
		LEVEL Level = LV1;
		enum FASE{CREATE, READY, MOVE, FINISH, DESTROY};
		FASE Fase = CREATE;
		//以下はいじらないでよい
		int BackToMenuFlag = 0;
		
		void init();
		void title();
		void play();
		void result(int Flag);
		void createBox();
		void destroyBox();
		void cleateButton(BUTTON* btn, float numStr);
		void dispButton(BUTTON* btn);
	};
	
}

