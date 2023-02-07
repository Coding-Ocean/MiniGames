#pragma once
#include"../MAIN/STATE.h"
#include"27Utilitys.h"
namespace GAME27 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void proc(class MANAGER* manager);
	private:
		//カード画像
		int cardImg[53]{};
		//効果音
		int getSE = 0;
		int failSE = 0;
		int turnSE = 0;
		//BGM
		int playBGM = 0;
		
		//データ管理
		bool RWdata = false;
		FILE* fp = nullptr;
		int P1 = 0;
		int P2 = 0;

		//タイトル
		bool toStartAFlag = false;
		STR gameName{
			"神経衰弱",
			180,
			width / 2 - 180 * 2,
			120,
			COLOR(30, 30, 30)
		};
		STR comp0{
			"- 遊び方 -",
			60,
			width / 2 - 60 * 2.5f,
			400,
			COLOR(50, 50, 50)
		};
		STR comp1{
			"・2人プレイ(チーム戦も可)",
			50,
			width / 2 - 50 * 6.75f,
			520,
			COLOR(50, 50, 50)
		};
		STR comp2{
			"・右クリックでカードを選択",
			50,
			width / 2 - 50 * 6.75f,
			590,
			COLOR(50, 50, 50)
		};
		STR comp3{
			"・獲得ペア数が多いほうの勝ち",
			50,
			width / 2 - 50 * 6.75f,
			660,
			COLOR(50, 50, 50)
		};
		STR toPlay{
			"SPACEでスタート",
			75,
			width / 2 - 75 * 3.75f,
			900,
			COLOR(230, 230, 230)
		};
		STR toMenu{
			"Mでメニューへ",
			75,
			width / 2 - 75 * 3.25f,
			990,
			COLOR(230, 230, 230)
		};
		STR lastData{
			"前回の戦績",
			50,
			width - 7 * 50,
			height - 120,
			COLOR(0, 0, 0)
		};
		STR hyphen{
			"-",
			50,
			width - 4.75f * 50,
			height - 60,
			COLOR(0, 0, 0)
		};
		

		//プレイ画面レイアウト
		VECTOR2 LTpos{}; 
		VECTOR2 RBpos{}; 
		VECTOR2 offset{};
		float cardScale = 0;

		//プレイ
		int no1 = 0;
		int no2 = 0;
		int fstsnd = 1;
		float dispLimit = 0;
		STR Player1{
			"先攻",
			50,
			20,
			10,
			COLOR(255, 200, 200)
		};
		STR Player2{
			"後攻",
			50,
			width - 120,
			10,
			COLOR(50, 50, 105)
		};
		char P1buf[3]{};
		char P2buf[3]{};

		//カード個体データ
		CARD cards[52]{};
		//カード表示領域
		VECTOR2 startPos{};
		VECTOR2 endPos{};

		//リザルト
		bool toTitleAFlag = false;
		STR Ssave{
			"戦績を保存しました。",
			50,
			width - 11 * 50,
			1000,
			COLOR(0, 0, 0)
		};
		STR Fsave{
			"戦績を保存できませんでした。",
			50,
			width - 7.5f * 50,
			1000,
			COLOR(255, 50, 50)
		};
		STR P1Win{
			"先攻の勝ち！",
			150,
			width / 2 - 450,
			400,
			COLOR(255, 200, 200)
		};
		STR P2Win{
			"後攻の勝ち！",
			150,
			width / 2 - 450,
			400,
			COLOR(200, 200, 255)
		};
		STR tieGame{
			"引き分け",
			150,
			width / 2 - 300,
			400,
			COLOR(175, 175, 175)
		};
		STR toTiTLE{
			"SPACEでタイトルに戻る",
			75,
			width / 2 - 5.25f * 75,
			height - 250,
			COLOR(230, 230, 230)
		};

		//操作State
		FASE fase = THINK;
		//シーン管理
		SCENE scene = TITLE;
		

		//以下はいじらないでよい
		int BackToMenuFlag=0;

		void init();
		bool roadData();
		void play();
		void title();
		void result();
		bool saveData();

		void dispSTR(STR s);
		bool onCard(float Cx, float Cy);
	};

}

