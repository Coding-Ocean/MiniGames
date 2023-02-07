#pragma once
#include<vector>
#include"../MAIN/STATE.h"

namespace GAME23 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI
	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();
		void create();
		void destroy();
		void proc(class MANAGER*manager);
		class ACTOR* court() { return Court; }
		class ACTOR* player() { return Player; }
		class ACTOR* ball() { return Ball; }
		class ACTOR* boss() { return Boss; }
		class ACTOR* ai() { return Ai; }
		class ACTOR* hp() { return Hp; }
	private:
		void Init();
		//�����ɕK�v�ȋL���ꏊ��p�ӂ���
		std::vector<class ACTOR*>Actors;
		class ACTOR* Court;
		class ACTOR* Player;
		class ACTOR* Ball;
		class ACTOR* Boss;
		class ACTOR* Ai;
		class ACTOR* Hp;
		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag = 0;
	};
}
