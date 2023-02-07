#pragma once
#include"../MAIN/STATE.h"

namespace GAME11 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//ここに必要な記憶場所を用意する
		//バー
		int barpx;
		int barpy;
		int barvx;
		int barW, barH;
		int barL;
		int barR;
		int barT;
		int barB;
		//ボール
		int ballpx;
		int ballpy;
		int ballvx;
		int ballvy;
		int ballW, ballH;
		int ballL;
		int ballR;
		int ballT;
		int ballB;
		int startflag;
		//ブロック
		int blockpx;
		int blockpy;
		int blockW, blockH;
		int blockL;
		int blockR;
		int blockT;
		int blockB;

		int blockpx1;
		int blockpy1;
		int blockW1, blockH1;
		int blockL1;
		int blockR1;
		int blockT1;
		int blockB1;

		int blockpx2;
		int blockpy2;
		int blockW2, blockH2;
		int blockL2;
		int blockR2;
		int blockT2;
		int blockB2;

		int blockpx3;
		int blockpy3;
		int blockW3, blockH3;
		int blockL3;
		int blockR3;
		int blockT3;
		int blockB3;

		int blockpx4;
		int blockpy4;
		int blockW4, blockH4;
		int blockL4;
		int blockR4;
		int blockT4;
		int blockB4;

		int blockpx5;
		int blockpy5;
		int blockW5, blockH5;
		int blockL5;
		int blockR5;
		int blockT5;
		int blockB5;

		int blockpx6;
		int blockpy6;
		int blockW6, blockH6;
		int blockL6;
		int blockR6;
		int blockT6;
		int blockB6;

		int blockpx7;
		int blockpy7;
		int blockW7, blockH7;
		int blockL7;
		int blockR7;
		int blockT7;
		int blockB7;

		int blockpx8;
		int blockpy8;
		int blockW8, blockH8;
		int blockL8;
		int blockR8;
		int blockT8;
		int blockB8;

		int blockpx9;
		int blockpy9;
		int blockW9, blockH9;
		int blockL9;
		int blockR9;
		int blockT9;
		int blockB9;

		int blockpx10;
		int blockpy10;
		int blockW10, blockH10;
		int blockL10;
		int blockR10;
		int blockT10;
		int blockB10;

		int blockpx11;
		int blockpy11;
		int blockW11, blockH11;
		int blockL11;
		int blockR11;
		int blockT11;
		int blockB11;

		int blockpx12;
		int blockpy12;
		int blockW12, blockH12;
		int blockL12;
		int blockR12;
		int blockT12;
		int blockB12;

		int blockpx13;
		int blockpy13;
		int blockW13, blockH13;
		int blockL13;
		int blockR13;
		int blockT13;
		int blockB13;

		int blockpx14;
		int blockpy14;
		int blockW14, blockH14;
		int blockL14;
		int blockR14;
		int blockT14;
		int blockB14;

		int blockpx15;
		int blockpy15;
		int blockW15, blockH15;
		int blockL15;
		int blockR15;
		int blockT15;
		int blockB15;

		int blockpx16;
		int blockpy16;
		int blockW16, blockH16;
		int blockL16;
		int blockR16;
		int blockT16;
		int blockB16;

		int blockpx17;
		int blockpy17;
		int blockW17, blockH17;
		int blockL17;
		int blockR17;
		int blockT17;
		int blockB17;

		int blockpx18;
		int blockpy18;
		int blockW18, blockH18;
		int blockL18;
		int blockR18;
		int blockT18;
		int blockB18;

		int blockpx19;
		int blockpy19;
		int blockW19, blockH19;
		int blockL19;
		int blockR19;
		int blockT19;
		int blockB19;

		int blockpx20;
		int blockpy20;
		int blockW20, blockH20;
		int blockL20;
		int blockR20;
		int blockT20;
		int blockB20;

		int blockpx21;
		int blockpy21;
		int blockW21, blockH21;
		int blockL21;
		int blockR21;
		int blockT21;
		int blockB21;

		int blockpx22;
		int blockpy22;
		int blockW22, blockH22;
		int blockL22;
		int blockR22;
		int blockT22;
		int blockB22;

		int blockpx23;
		int blockpy23;
		int blockW23, blockH23;
		int blockL23;
		int blockR23;
		int blockT23;
		int blockB23;

		int blockpx24;
		int blockpy24;
		int blockW24, blockH24;
		int blockL24;
		int blockR24;
		int blockT24;
		int blockB24;

		int blockpx25;
		int blockpy25;
		int blockW25, blockH25;
		int blockL25;
		int blockR25;
		int blockT25;
		int blockB25;

		int blockpx26;
		int blockpy26;
		int blockW26, blockH26;
		int blockL26;
		int blockR26;
		int blockT26;
		int blockB26;

		int blockpx27;
		int blockpy27;
		int blockW27, blockH27;
		int blockL27;
		int blockR27;
		int blockT27;
		int blockB27;

		int blockpx28;
		int blockpy28;
		int blockW28, blockH28;
		int blockL28;
		int blockR28;
		int blockT28;
		int blockB28;

		int blockpx29;
		int blockpy29;
		int blockW29, blockH29;
		int blockL29;
		int blockR29;
		int blockT29;
		int blockB29;

		bool endflag;
		bool endflag1;
		bool endflag2;
		bool endflag3;
		bool endflag4;
		bool endflag5;
		bool endflag6;
		bool endflag7;
		bool endflag8;
		bool endflag9;
		bool endflag10;
		bool endflag11;
		bool endflag12;
		bool endflag13;
		bool endflag14;
		bool endflag15;
		bool endflag16;
		bool endflag17;
		bool endflag18;
		bool endflag19;
		bool endflag20;
		bool endflag21;
		bool endflag22;
		bool endflag23;
		bool endflag24;
		bool endflag25;
		bool endflag26;
		bool endflag27;
		bool endflag28;
		bool endflag29;

		int clearflag;

		bool alltrue;
		//以下はいじらないでよい
		int BackToMenuFlag = 0;
	};

}

