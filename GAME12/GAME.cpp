#include "../libOne/inc/libOne.h"
#include "../MAIN/MANAGER.h"
#include "../MAIN/FADE.h"
#include "../MAIN/MENU.h"
#include "GAME.h"
#include <time.h>
#include <random>
namespace GAME12 { //自分でなにかファイルを追加したらincludeの後にこの行を追加すること。　ファイルの最後に“ } ”も忘れずに！

	GAME::GAME(MANAGER* manager)
	{
		srand((unsigned)time(NULL));
		initDeltaTime();
		init();

		title_titleImg = loadImage("../game12/assets/title.png");
		title_startImg = loadImage("../game12/assets/start.png");
		title_titlePx = width / 2;
		title_titlePy = 300;
		title_back.r = 146;
		title_back.g = 175;
		title_back.b = 228;

		title_text[0].Str = "Fキーで操作方法";
		title_text[1].Str = "動き続ける大量の漢字の中から間違いを探そう";
		title_text[2].Str = "一度間違えるとライフと時間が減るので注意";
		title_text[3].Str = "左クリックで選択";
		title_text[4].Str = "制限時間内に３ステージ突破でクリア";


		title_text[0].Size = 60;
		title_text[1].Size = title_text[2].Size = title_text[3].Size = title_text[4].Size = 80;

		title_text[0].Px = width - 120 - title_text[0].Size * 7.5f;
		title_text[1].Px = width / 2 - title_text[1].Size * 21 / 2;
		title_text[2].Px = width / 2 - title_text[2].Size * 20 / 2;
		title_text[3].Px = width / 2 - title_text[3].Size * 8 / 2;
		title_text[4].Px = width / 2 - title_text[4].Size * 17 / 2;
		title_text[0].Py = height - 50 - title_text[0].Size * 1;
		title_text[1].Py = height / 2 - title_text[1].Size * 2.25f;
		title_text[2].Py = height / 2 - title_text[2].Size * 0.75f;
		title_text[3].Py = height / 2 + title_text[3].Size * 0.75f;
		title_text[4].Py = height / 2 + title_text[4].Size * 2.25f;

		title_text[0].Color.r = title_text[1].Color.r = title_text[2].Color.r = title_text[3].Color.r = title_text[4].Color.r = 247;
		title_text[0].Color.g = title_text[1].Color.g = title_text[2].Color.g = title_text[3].Color.g = title_text[4].Color.g = 252;
		title_text[0].Color.b = title_text[1].Color.b = title_text[2].Color.b = title_text[3].Color.b = title_text[4].Color.b = 254;

		play_top = 130;
		play_lifeImg = loadImage("../game12/assets/Life.png");
		play_lifedamageImg = loadImage("../game12/assets/Life_damage.png");
		play_ouImg = loadImage("../game12/assets/ou.png");
		play_gyokuImg = loadImage("../game12/assets/gyoku.png");
		play_hiImg = loadImage("../game12/assets/hi.png");
		play_iwakuImg = loadImage("../game12/assets/iwaku.png");
		play_saku1Img = loadImage("../game12/assets/saku1.png");
		play_sakuImg = loadImage("../game12/assets/saku.png");
		play_inuImg = loadImage("../game12/assets/inu.png");
		play_daiImg = loadImage("../game12/assets/dai.png");
		play_tutiImg = loadImage("../game12/assets/tuti.png");
		play_siImg = loadImage("../game12/assets/si.png");
		play_miImg = loadImage("../game12/assets/mi.png");
		play_matuImg = loadImage("../game12/assets/matu.png");
		play_zeroImg = loadImage("../game12/assets/zero.png");
		play_funImg = loadImage("../game12/assets/fun.png");
		play_tyouImg = loadImage("../game12/assets/tyou.png");
		play_kouImg = loadImage("../game12/assets/kou.png");
		play_tiImg = loadImage("../game12/assets/ti.png");
		play_waImg = loadImage("../game12/assets/wa.png");
		play_ko1Img = loadImage("../game12/assets/ko1.png");
		play_koImg = loadImage("../game12/assets/ko.png");
		play_uImg = loadImage("../game12/assets/u.png");
		play_ziImg = loadImage("../game12/assets/zi.png");
		play_kakuImg = loadImage("../game12/assets/kaku.png");
		play_meiImg = loadImage("../game12/assets/mei.png");
		play_hariImg = loadImage("../game12/assets/hari.png");
		play_kugiImg = loadImage("../game12/assets/kugi.png");
		play_kaiImg = loadImage("../game12/assets/kai.png");
		play_guImg = loadImage("../game12/assets/gu.png");
		play_kokoroImg = loadImage("../game12/assets/kokoro.png");
		play_hituImg = loadImage("../game12/assets/hitu.png");
		play_ready[0].Str = "右クリックでスタート";
		play_ready[1].Str = "L v 1";
		play_ready[2].Str = "L v 2";
		play_ready[3].Str = "L v 3";
		play_ready[0].Size = 50;
		play_ready[1].Size = play_ready[2].Size = play_ready[3].Size = 200;
		play_ready[0].Px = width / 2 - 250;
		play_ready[1].Px = play_ready[2].Px = play_ready[3].Px = width / 2 - 250;
		play_ready[0].Py = height - 250;
		play_ready[1].Py = play_ready[2].Py = play_ready[3].Py = height / 2 - 200;
		play_ready[0].Color.r = play_ready[0].Color.g = play_ready[0].Color.b = 80;
		play_ready[1].Color.r = play_ready[2].Color.r = play_ready[3].Color.r = 255;
		play_ready[1].Color.g = 255;
		play_ready[2].Color.g = 191;
		play_ready[3].Color.g = 50;
		play_ready[1].Color.b = play_ready[2].Color.b = play_ready[3].Color.b = 20;
		play_dispLevel[0].Size = play_dispLevel[1].Size = play_dispLevel[2].Size = 100;
		play_dispLevel[0].Str = "Level 1";
		play_dispLevel[1].Str = "Level 2";
		play_dispLevel[2].Str = "Level 3";
		play_dispLevel[0].Px = play_dispLevel[1].Px = play_dispLevel[2].Px = play_dispLevel[0].Size;
		play_dispLevel[0].Py = play_dispLevel[1].Py = play_dispLevel[2].Py = (play_top - play_dispLevel[0].Size) / 2;
		play_dispLevel[0].Color.r = play_dispLevel[0].Color.g = play_dispLevel[0].Color.b = 20;
		play_dispLevel[1].Color.r = play_dispLevel[1].Color.g = play_dispLevel[1].Color.b = 20;
		play_dispLevel[2].Color.r = play_dispLevel[2].Color.g = play_dispLevel[2].Color.b = 20;
		play_finish[0].Size = play_finish[1].Size = play_finish[2].Size = 150;
		play_finish[3].Size = 80;
		play_finish[0].Str = "LV1クリア";
		play_finish[1].Str = "LV2クリア";
		play_finish[2].Str = "LV3クリア";
		play_finish[3].Str = "左クリックで次へ";
		play_finish[0].Px = play_finish[1].Px = play_finish[2].Px = width / 2 - play_finish[0].Size * 4.5f / 2;
		play_finish[3].Px = width / 2 - play_finish[3].Size * 8 / 2;
		play_finish[0].Py = play_finish[1].Py = play_finish[2].Py = height / 6;
		play_finish[3].Py = height - play_finish[3].Size * 4;



		play_readyback.r = 121;
		play_readyback.g = 241;
		play_readyback.b = 242;
		play_moveback.r = 210;
		play_moveback.g = 210;
		play_moveback.b = 210;
		play_finishback.r = 255;
		play_finishback.g = 255;
		play_finishback.b = 138;

		play_numlv1 = 45;
		play_numlv2 = 45;
		play_numlv3 = 45;

		play_UIPx = 0;
		play_UIPy = 0;
		play_UIWidth = width;
		play_UIHeight = play_top;
		play_UIColor.r = 163;
		play_UIColor.g = 216;
		play_UIColor.b = 246;

		play_lifePx = 860;
		play_lifeOfsX = 100;
		play_lifePy = play_top / 2;
		play_lifeSize = 0.166f;

		play_Timedamage = 20;
		play_TimeLimit = 10;
		play_TimeSize = 90;
		play_TimePx = width - 100 - 7 * play_TimeSize / 2;
		play_TimePy = (play_top - play_TimeSize) / 2;
		play_TimeRemainSize = 100;
		play_TimeRemainPy = height / 2;
		play_TimeColor.r = play_TimeColor.g = play_TimeColor.b = 20;
		play_TimeLimitColor.r = 255;
		play_TimeLimitColor.g = 0;
		play_TimeLimitColor.b = 0;

		result_SS = loadImage("../game12/assets/rank_SS.png");
		result_S = loadImage("../game12/assets/rank_S.png");
		result_A = loadImage("../game12/assets/rank_A.png");
		result_B = loadImage("../game12/assets/rank_B.png");
		result_C = loadImage("../game12/assets/rank_C.png");
		result_rankPx = 600;
		result_rankPy = height - 300;
		result_rankScale = 0.8f;

		result_clear.r = 98;
		result_clear.g = 184;
		result_clear.b = 230;
		result_fail.r = result_fail.b = result_fail.g = 0;
		result_time.Color.r = result_time.Color.g = result_time.Color.b = 0;
		result_time.Size = 100;
		result_time.Py = height / 6 * 5;
		result_gameclear.Str = "ゲームクリア";
		result_gameclear.Size = 200;
		result_gameclear.Px = width / 2 - result_gameclear.Size * 3;
		result_gameclear.Py = 80;
		result_gameclear.Color.r = 240;
		result_gameclear.Color.g = 131;
		result_gameclear.Color.b = 0;
		result_gamefail.Str = "ゲームオーバー";
		result_gamefail.Size = 200;
		result_gamefail.Px = width / 2 - result_gameclear.Size * 3.5f;
		result_gamefail.Py = 80;
		result_gamefail.Color.r = 200;
		result_gamefail.Color.g = 30;
		result_gamefail.Color.b = 30;
		result_info[0].Str = "タイトルに戻る";
		result_info[0].Size = 60;
		result_info[0].RPx = width / 2 + 300;
		result_info[0].RPy = height / 2 + 50;
		result_info[0].Ofs = 10;
		result_info[0].StringsColor.r = result_info[0].StringsColor.g = result_info[0].StringsColor.b = 10;
		result_info[0].FlameColor.r = result_info[0].FlameColor.g = result_info[0].FlameColor.b = 0;
		result_info[0].RectColor.r = result_info[0].RectColor.g = result_info[0].RectColor.b = 225;
		result_info[0].FlameWeight = 5;
		cleateButton(&result_info[0], 7);

		result_info[1].Str = "メニューに戻る";
		result_info[1].Size = 60;
		result_info[1].RPx = width / 2 + 300;
		result_info[1].RPy = height / 2 + 300;
		result_info[1].Ofs = 10;
		result_info[1].StringsColor.r = result_info[1].StringsColor.g = result_info[1].StringsColor.b = 10;
		result_info[1].FlameColor.r = result_info[1].FlameColor.g = result_info[1].FlameColor.b = 0;
		result_info[1].RectColor.r = result_info[1].RectColor.g = result_info[1].RectColor.b = 225;
		result_info[1].FlameWeight = 5;
		cleateButton(&result_info[1], 7); 

		result_info[2].Str = "タイトルに戻る";
		result_info[2].Size = 60;
		result_info[2].RPx = 300;
		result_info[2].RPy = height / 2 + 100;
		result_info[2].Ofs = 10;
		result_info[2].StringsColor.r = 225;
		result_info[2].StringsColor.g = result_info[2].StringsColor.b = 30;
		result_info[2].FlameColor.r = result_info[2].FlameColor.g = result_info[2].FlameColor.b = 70;
		result_info[2].RectColor.r = result_info[2].RectColor.g = result_info[2].RectColor.b = 100;
		result_info[2].FlameWeight = 5;
		cleateButton(& result_info[2], 7);
					
		result_info[3].Str = "メニューに戻る";
		result_info[3].Size = 60;
		result_info[3].RPx = width / 2 + 300;
		result_info[3].RPy = height / 2 +100;
		result_info[3].Ofs = 10;
		result_info[3].StringsColor.r = 255;
		result_info[3].StringsColor.g = result_info[3].StringsColor.b = 30;
		result_info[3].FlameColor.r = result_info[3].FlameColor.g = result_info[3].FlameColor.b = 70;
		result_info[3].RectColor.r = result_info[3].RectColor.g = result_info[3].RectColor.b = 100;
		result_info[3].FlameWeight = 5;
		cleateButton(&result_info[3], 7);

		result_clearTimeSize = 80;
		result_clearTimePy = 400;
		result_clearTimeColor.r = result_clearTimeColor.g = result_clearTimeColor.b = 0;


			//フェードイン（ここはいじらないでよい）
		manager->fade->fadeInTrigger();
	}

	GAME::~GAME()
	{
		destroyBox();
		stroke(0);
	}

	void GAME::proc(MANAGER* manager)
	{
		setDeltaTime();
		if (State == TITLE)title();
		if (State == PLAY)play();
		if (State == RESULT)result(gameFlag);
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

	void GAME::init() {
		play_Hp = 3;
		play_Time = 120;
		play_HitFlag = 0;
		gameFlag = 0;
		State = TITLE;
		Level = LV1;
		Fase = CREATE;
	}

	void GAME::title() {
		clear(title_back);
		rectMode(CENTER);
		image(title_titleImg, title_titlePx, title_titlePy, 0, 1.45f);
		image(title_startImg, title_titlePx, title_titlePy + 400, 0, 1.2f);
		textSize(title_text[0].Size);
		fill(0);
		text(title_text[0].Str, title_text[0].Px + title_text[0].Size / 16, title_text[0].Py + title_text[0].Size / 16);
		fill(title_text[0].Color);
		text(title_text[0].Str, title_text[0].Px, title_text[0].Py);



		//操作方法表示
		if (isPress(KEY_F)) {
			clear(title_back);
			textSize(title_text[1].Size);
			for (int i = 1; i < 5; i++) {
				fill(0);
				text(title_text[i].Str, title_text[i].Px + title_text[i].Size / 16, title_text[i].Py + title_text[i].Size / 16);
				fill(title_text[1].Color);
				text(title_text[i].Str, title_text[i].Px, title_text[i].Py);
			}
		}

		//スタート
		if (isTrigger(MOUSE_LBUTTON)) {
			State = PLAY;

		}
	}

	void GAME::play() {
		rectMode(CENTER);
		if (Fase == CREATE) {
			createBox();
			Fase = READY;
		}
		if (Fase == READY) {
			clear(play_readyback);
			textSize(play_ready[0].Size);
			fill(play_ready[0].Color);
			text(play_ready[0].Str, play_ready[0].Px, play_ready[0].Py);
			textSize(play_ready[1].Size);
			switch (Level) {
			case LV1:
				fill(play_ready[1].Color);
				text(play_ready[1].Str, play_ready[1].Px, play_ready[1].Py);
				break;
			case LV2:
				fill(play_ready[2].Color);
				text(play_ready[2].Str, play_ready[2].Px, play_ready[2].Py);
				break;
			case LV3:
				fill(play_ready[3].Color);
				text(play_ready[3].Str, play_ready[3].Px, play_ready[3].Py);
				break;
			default:
				break;
			}
			if (isTrigger(MOUSE_RBUTTON)) {
				Fase = MOVE;
			}
		}
		if (Fase == MOVE) {
			if (isTrigger(MOUSE_LBUTTON)) {
				play_HitFlag = 2;
				float mag = 0;
				float mx = MouseX;
				float my = MouseY;
				for (int i = 0; i < play_currentnum; i++) {
					mag = sqrt(abs((mx - current[i].Px) * (mx - current[i].Px) + abs((my - current[i].Py) * (my - current[i].Py))));
					if (mag < 100) {
						if (current[i].Hit)play_HitFlag = 1;
					}

				}

			}
			if (play_HitFlag == 1) {
				Fase = FINISH;
				play_TimeRemain[0] = '\0';
				strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeRemain1);
				if (d1) {
					play_TimeRemainPx = width / 2 - play_TimeRemainSize * 8.5f / 2;
					play_TimeStrbuf[0] = '0' + d1;
					strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
					strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeRemain2);
					play_TimeStrbuf[0] = '0' + d2;
					strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
					play_TimeStrbuf[0] = '0' + d3;
					strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
					strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeRemain3);
					play_TimeStrbuf[0] = '0' + d4;
					strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
					play_TimeStrbuf[0] = '0' + d5;
					strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
				}
				else {
					if (d2) {
						play_TimeRemainPx = width / 2 - play_TimeRemainSize * 7 / 2;
						play_TimeStrbuf[0] = '0' + d2;
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
						play_TimeStrbuf[0] = '0' + d3;
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeRemain3);
						play_TimeStrbuf[0] = '0' + d4;
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
						play_TimeStrbuf[0] = '0' + d5;
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);

					}
					else {
						play_TimeRemainPx = width / 2 - play_TimeRemainSize * 6.5f / 2;
						play_TimeStrbuf[0] = '0' + d3;
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeRemain3);
						play_TimeStrbuf[0] = '0' + d4;
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
						play_TimeStrbuf[0] = '0' + d5;
						strcat_s(play_TimeRemain, sizeof(play_TimeRemain), play_TimeStrbuf);
					}
				}
				play_HitFlag = 0;
			}
			if (play_HitFlag == 2) {
				play_Time -= play_Timedamage;
				play_Hp--;
				play_HitFlag = 0;
				if (play_Hp == 0) {
					Fase = DESTROY;
					State = RESULT;
					gameFlag = 0;
				}
			}
			if (play_Time > 0) play_Time -= delta;
			if (play_Time < 0) {
				play_Time = 0;
				State = RESULT;
				gameFlag = 0;
			}
			play_TimeBuf = play_Time;
			m = 0;
			while (play_TimeBuf >= 60.0f) {
				m++;
				play_TimeBuf -= 60;
			}
			s = (int)play_TimeBuf;

			while (play_TimeBuf > 1) {
				play_TimeBuf -= 1;
			}
			play_TimeBuf *= 100;
			ds = (int)play_TimeBuf;

			d1 = m;
			d3 = s % 10;
			s -= d3;
			if (s != 0) {
				s /= 10;
				d2 = s % 10;
			}
			else d2 = 0;
			d5 = ds % 10;
			ds -= d5;
			if (ds != 0) {
				ds /= 10;
				d4 = ds % 10;
			}
			else d4 = 0;

			play_TimeStr[0] = '0' + d1;
			play_TimeStr[1] = ':';
			play_TimeStr[2] = '0' + d2;
			play_TimeStr[3] = '0' + d3;
			play_TimeStr[4] = ':';
			play_TimeStr[5] = '0' + d4;
			play_TimeStr[6] = '0' + d5;
			play_TimeStr[7] = '\0';









			//描画
			clear(play_moveback);
			rectMode(CORNER);
			strokeWeight(0);
			fill(play_UIColor);
			rect(play_UIPx, play_UIPy, play_UIWidth, play_UIHeight);
			textSize(play_dispLevel[0].Size);
			fill(play_dispLevel[0].Color);
			if (Level == LV1) text(play_dispLevel[0].Str, play_dispLevel[0].Px, play_dispLevel[0].Py);
			if (Level == LV2) text(play_dispLevel[1].Str, play_dispLevel[1].Px, play_dispLevel[1].Py);
			if (Level == LV3) text(play_dispLevel[2].Str, play_dispLevel[2].Px, play_dispLevel[2].Py);
			rectMode(CENTER);
			for (int i = 0; i < 3; i++) {
				if (play_Hp <= i) {
					image(play_lifedamageImg, play_lifePx + play_lifeOfsX * i, play_lifePy, 0, play_lifeSize);
				}
				else {
					image(play_lifeImg, play_lifePx + play_lifeOfsX * i, play_lifePy, 0, play_lifeSize);
				}
			}
			textSize(play_TimeSize);
			if (play_Time >= play_TimeLimit)fill(play_TimeColor);
			else fill(play_TimeLimitColor);
			text(play_TimeStr, play_TimePx, play_TimePy);




			rectMode(CENTER);
			for (int i = 0; i < play_currentnum; i++) {
				current[i].Px += current[i].Vx;
				current[i].Py += current[i].Vy;
				if (current[i].ReflectDelayX > 0) {
					current[i].ReflectDelayX -= delta;
					if (current[i].ReflectDelayX < 0) {
						current[i].ReflectDelayX = 0;
					}
				}
				if (current[i].ReflectDelayY > 0) {
					current[i].ReflectDelayY -= delta;
					if (current[i].ReflectDelayY < 0) {
						current[i].ReflectDelayY = 0;
					}
				}
				if ((current[i].Px < 90 || current[i].Px > width - 90) && current[i].ReflectDelayX == 0) {
					current[i].Vx *= -1;
					current[i].ReflectDelayX += 1.0f;
				}
				if ((current[i].Py < 220 || current[i].Py > height - 90) && current[i].ReflectDelayY == 0) {
					current[i].Vy *= -1;
					current[i].ReflectDelayY += 1.0f;
				}
				image(current[i].TextImg, current[i].Px, current[i].Py, 0, 0.3f);
			}
		}
		if (Fase == FINISH) {
			if (isTrigger(MOUSE_LBUTTON)) {
				if (Level == LV3) gameFlag = 1;
				Fase = DESTROY;
			}
			play_TimeBuf = play_Time;
			while (play_TimeBuf >= 60.0f) {
				m++;
				play_TimeBuf -= 60;
			}
			s = (int)play_TimeBuf;

			while (play_TimeBuf > 1) {
				play_TimeBuf -= 1;
			}
			play_TimeBuf *= 100;
			ds = (int)play_TimeBuf;

			d1 = m;
			d3 = s % 10;
			s -= d3;
			if (s != 0) {
				s /= 10;
				d2 = s % 10;
			}
			else d2 = 0;
			d5 = ds % 10;
			ds -= d5;
			if (ds != 0) {
				ds /= 10;
				d4 = ds % 10;
			}
			else d4 = 0;
			
			clear(play_finishback);
			fill(0);
			textSize(play_finish[0].Size);
			if (Level == LV1) text(play_finish[0].Str, play_finish[0].Px, play_finish[0].Py);
			if (Level == LV2) text(play_finish[1].Str, play_finish[1].Px, play_finish[1].Py);
			if (Level == LV3) text(play_finish[2].Str, play_finish[2].Px, play_finish[2].Py);
			if (play_Time >= play_TimeLimit)fill(play_TimeColor);
			else fill(play_TimeLimitColor);
			textSize(play_TimeRemainSize);
			text(play_TimeRemain, play_TimeRemainPx, play_TimeRemainPy);
			fill(0);
			textSize(play_finish[3].Size);
			text(play_finish[3].Str, play_finish[3].Px, play_finish[3].Py);


			if (gameFlag == 1) {
				play_TimeBuf = play_Time;
				play_TimeBuf -= 120;
				if (play_TimeBuf <= 0)play_TimeBuf *= -1;
				s = 0;
				while (play_TimeBuf > 1) {
					play_TimeBuf--;
					s++;
				}

				float A = 0, B = 0, C = 0;
				if (s > 100) {
					C = (float)(s % 10);
					s /= 10;
					B = (float)(s % 10);
					s /= 10;
					A = (float)(s % 10);
				}
				else if (s > 10) {
					C = (float)(s % 10);
					s /= 10;
					B = (float)(s % 10);
				}
				else C = (float)(s % 10);

				play_TimeBuf *= 10;
				ds = (int)play_TimeBuf;
				result_clearTime[0] = '\0';
				strcat_s(result_clearTime, sizeof(result_clearTime), result_clearTimeStr1);
				if (A) {
					result_clearTimePx = 600 - result_clearTimeSize * 3.75f;
					result_clearTimebuf[0] = '0' + (int)A;
					result_clearTimebuf[1] = '\0';
					strcat_s(result_clearTime, sizeof(result_clearTime), result_clearTimebuf);
				}
				if (B) {
					result_clearTimePx = 600 - result_clearTimeSize * 3.5f;
					result_clearTimebuf[0] = '0' +(int) B;
					result_clearTimebuf[1] = '\0';
					strcat_s(result_clearTime, sizeof(result_clearTime), result_clearTimebuf);
				}
				result_clearTimePx = 600 - result_clearTimeSize * 3.25f;
				result_clearTimebuf[0] = '0' + (int)C;
				result_clearTimebuf[1] = '\0';
				strcat_s(result_clearTime, sizeof(result_clearTime), result_clearTimebuf);
				strcat_s(result_clearTime, sizeof(result_clearTime), result_clearTimeStr2);
				result_clearTimebuf[0] = '0' + (int)ds;
				result_clearTimebuf[1] = '\0';
				strcat_s(result_clearTime, sizeof(result_clearTime), result_clearTimebuf);
				strcat_s(result_clearTime, sizeof(result_clearTime), result_clearTimeStr3);
			}
			
		
		}
		if (Fase == DESTROY) {
			delete current;
			if (Level == LV1) {
				//delete lv1;
				Level = LV2;
			}
			else if (Level == LV2) {
				//delete lv2;
				Level = LV3;
			}
			else if (Level == LV3) {
				//delete lv3;
				State = RESULT;
			}
			Fase = CREATE;
		}
	}

	void GAME::result(int Flag) {
		if (Flag) {
			if (MouseX > result_info[0].RPx && MouseX < result_info[0].RPx + result_info[0].W &&
				MouseY >result_info[0].RPy && MouseY < result_info[0].RPy + result_info[0].H &&
				isTrigger(MOUSE_LBUTTON)) {
				init();
			}
			if (MouseX > result_info[1].RPx && MouseX < result_info[1].RPx + result_info[1].W &&
				MouseY >result_info[1].RPy && MouseY < result_info[1].RPy + result_info[1].H &&
				isTrigger(MOUSE_LBUTTON)) {
				BackToMenuFlag = 1;
			}

			clear(result_clear);
			fill(result_gameclear.Color);
			textSize(result_gameclear.Size);
			text(result_gameclear.Str, result_gameclear.Px, result_gameclear.Py);
			fill(result_clearTimeColor);
			textSize(result_clearTimeSize);
			text(result_clearTime, result_clearTimePx, result_clearTimePy);

			rectMode(CENTER);
			//SS
			if (play_Hp == 3 && play_Time >= 90) {
				image(result_SS, result_rankPx, result_rankPy, 0, result_rankScale);
			}
			//S
			else if (play_Hp == 3 && play_Time >= 60) {
				image(result_S, result_rankPx, result_rankPy, 0, result_rankScale);
			}
			//A
			else if (play_Hp >= 2 && play_Time >= 45) {
				image(result_A, result_rankPx, result_rankPy, 0, result_rankScale);
			}
			//B
			else if (play_Hp >= 2 ) {
				image(result_B, result_rankPx, result_rankPy, 0, result_rankScale);
			}
			//C
			else  {
				image(result_C, result_rankPx, result_rankPy, 0, result_rankScale);
			}
			dispButton(&result_info[0]);
			dispButton(&result_info[1]);
		}
		else {
			if (MouseX > result_info[2].RPx && MouseX < result_info[2].RPx + result_info[2].W &&
				MouseY >result_info[2].RPy && MouseY < result_info[2].RPy + result_info[2].H &&
				isTrigger(MOUSE_LBUTTON)) {
				init();
			}
			if (MouseX > result_info[3].RPx && MouseX < result_info[3].RPx + result_info[3].W &&
				MouseY >result_info[3].RPy && MouseY < result_info[3].RPy + result_info[3].H &&
				isTrigger(MOUSE_LBUTTON)) {
				BackToMenuFlag = 1;
			}

			clear(result_fail);
			fill(result_gamefail.Color);
			textSize(result_gamefail.Size);
			text(result_gamefail.Str, result_gamefail.Px, result_gamefail.Py);
			dispButton(&result_info[2]);
			dispButton(&result_info[3]);

		}

	}
	void GAME::createBox() {
		int ImgA = 0;
		int ImgB = 0;
		switch (Level) {
		case LV1:
			if (rand() % 5 == 0) {
				ImgA = play_gyokuImg;
				ImgB = play_ouImg;
			}
			else if(rand() % 5 == 1) {
			ImgA = play_daiImg;
			ImgB = play_inuImg;
			}
			else if(rand() % 5 == 2) {
				ImgA = play_zeroImg;
				ImgB = play_funImg;
			}
			else if(rand() % 5 == 3) {
				ImgA = play_koImg;
				ImgB = play_ko1Img;
			}
			else {
				ImgA = play_hariImg;
				ImgB = play_kugiImg;
			}

			lv1 = new BOX[play_numlv1]{};
			current = lv1;
			play_currentnum = play_numlv1;
			for (int i = 0; i < play_numlv1 - 1; i++) {
				lv1[i].TextImg = ImgA;
				lv1[i].Hit = false;
				
			}
			lv1[play_numlv1 - 1].TextImg = ImgB;
			lv1[play_numlv1 - 1].Hit = true;
			for (int i = 0; i < play_numlv1; i++) {
				lv1[i].Px = (float)(rand() % ((int)width + 1 - 240) + 120);
				lv1[i].Py = (float)(rand() % ((int)height + 1 - 340) + 250);
				lv1[i].Vx = (float)(rand() % 25)* delta * 60 / 10 + 0.5f;
				if (rand() % 2)lv1[i].Vx *= -1;
				lv1[i].Vy = (float)(rand() % 15)* delta *60 / 10 + 0.5f;
				if (rand() % 2)lv1[i].Vy *= -1;
				lv1[i].ReflectDelayX = 0;
				lv1[i].ReflectDelayY = 0;
			
			}

			break;
		case LV2:
			if (rand() % 5 == 0) {
				ImgA = play_iwakuImg;
				ImgB = play_hiImg;
			}
			else if (rand() % 5 == 1) {
				ImgA = play_tutiImg;
				ImgB = play_siImg;
			}
			else if(rand() % 5 == 2) {
				ImgA = play_tyouImg;
				ImgB = play_kouImg;
			}
			else if (rand() % 5 == 3) {
				ImgA = play_hituImg;
				ImgB = play_kokoroImg;
			}
			else {
				ImgA = play_uImg;
				ImgB = play_ziImg;
			}
			lv2 = new BOX[play_numlv2]{};
			current = lv2;
			play_currentnum = play_numlv2;
			for (int i = 0; i < play_numlv2 - 1; i++) {
				lv2[i].TextImg = ImgA;
				lv2[i].Hit = false;
			}
			lv2[play_numlv2 - 1].TextImg = ImgB;
			lv2[play_numlv2 - 1].Hit = true;
			for (int i = 0; i < play_numlv2; i++) {
				lv2[i].Px = (float)(rand() % ((int)width + 1 - 240) + 120);
				lv2[i].Py = (float)(rand() % ((int)height + 1 - 340) + 250);
				lv2[i].Vx = (float)(rand() % 25)* delta * 60 / 5 + 0.5f;
				if (rand() % 2)lv2[i].Vx *= -1;
				lv2[i].Vy = (float)(rand() % 15)* delta * 60 / 5 + 0.5f;
				if (rand() % 2)lv2[i].Vy *= -1;
				lv2[i].ReflectDelayX = 0;
				lv2[i].ReflectDelayY = 0;

			}

			break;
		case LV3:
			if (rand() % 5 == 0) {
				ImgA = play_sakuImg;
				ImgB = play_saku1Img;
			}
			else if(rand() % 5 == 1) {
				ImgA = play_miImg;
				ImgB = play_matuImg;
			}
			else if(rand() % 5 == 2) {
				ImgA = play_tiImg;
				ImgB = play_waImg;
			}
			else if (rand() % 5 == 3) {
				ImgA = play_guImg;
				ImgB = play_kaiImg;
			}
			else {
				ImgA = play_meiImg;
				ImgB = play_kakuImg;
			}
			lv3 = new BOX[play_numlv3]{};
			current = lv3;
			for (int i = 0; i < play_numlv3 - 1; i++) {
				lv3[i].TextImg = ImgA;
				lv3[i].Hit = false;
			}
			lv3[play_numlv3 - 1].TextImg = ImgB;
			lv3[play_numlv3 - 1].Hit = true;
			for (int i = 0; i < play_numlv3; i++) {
				lv3[i].Px = (float)(rand() % ((int)width + 1 - 240) + 120);
				lv3[i].Py = (float)(rand() % ((int)height + 1 - 340) + 250);
				lv3[i].Vx = (float)(rand() % 25)* delta * 60 / 3 + 0.5f;
				if (rand() % 2)lv3[i].Vx *= -1;
				lv3[i].Vy = (float)(rand() % 15)* delta * 60 / 3 + 0.5f;
				if (rand() % 2)lv3[i].Vy *= -1;
				lv3[i].ReflectDelayX = 0;
				lv3[i].ReflectDelayY = 0;
				
			}
			play_currentnum = play_numlv3;
			break;
			default:
			break;

		}
	}
	void GAME::destroyBox() {
	}
	void GAME::cleateButton(BUTTON* btn, float numStr)
	{
		btn->SPx = btn->RPx + btn->Ofs;
		btn->SPy = btn->RPy + btn->Ofs;
		btn->W = btn->Ofs * 2 + btn->Size * numStr;
		btn->H = btn->Ofs * 2 + btn->Size;
	}
	void GAME::dispButton(BUTTON* btn)
	{
		rectMode(CORNER);
		strokeWeight(btn->FlameWeight);
		stroke(btn->FlameColor);
		fill(btn->RectColor);
		rect(btn->RPx, btn->RPy, btn->W, btn->H);
		textSize(btn->Size);
		fill(btn->StringsColor);
		text(btn->Str, btn->SPx, btn->SPy);
	}
}


