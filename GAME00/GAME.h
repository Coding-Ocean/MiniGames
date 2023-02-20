#pragma once
#include <vector>
#include"../MAIN/STATE.h"

namespace GAME00 { //�����łȂɂ��t�@�C����ǉ�������include�̌�ɂ��̍s��ǉ����邱�ƁB�@�t�@�C���̍Ō�Ɂg } �h���Y�ꂸ�ɁI

	class GAME : public STATE {
	public:
		GAME(class MANAGER* manager);
		~GAME();

		enum G_state{
			G_play,
			G_end
		};

		void create();  //�I����ʂ���̐؂�ւ�
		void destroy(); //���̃Q�[���̏I������
		void proc(class MANAGER* manager);    //���C�����[�v

		void AddActor(class ACTOR* actor);
		void RemoveActor(class ACTOR* actor);
		void AddBalls(class BALL* ball);
		void RemoveBalls(class BALL* ball);

		void SetGstate(G_state state) { Gstate = state; }
		G_state GetGstate() { return Gstate; }

		//Getter
		class ACTOR* court() { return Court; }
		class ACTOR* player() { return Player; }
		class ACTOR* score() { return Score; }

		std::vector<class BALL*> Getballs() { return Balls; }
	private:

		void Init(); //������

		G_state Gstate = G_play;

		//�����ɕK�v�ȋL���ꏊ��p�ӂ���
		std::vector<class ACTOR*>Actors;
		std::vector<class BALL*> Balls;

		class ACTOR* Court;
		class ACTOR* Player;
		class ACTOR* Score;

		// Update���t���b�O
		bool UpdatingActors=false;
		std::vector<class ACTOR*> PendingActors;

		//�ȉ��͂�����Ȃ��ł悢
		int BackToMenuFlag = 0;
	};

}
