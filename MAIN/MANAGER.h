#pragma once
class STATE;
class FADE;

class MANAGER {
public:
    MANAGER();
    ~MANAGER();
    void proc();
    //各ステートにthisポインタを渡すことによって、以下のオブジェクトが使用可能となる
    int selectIdx; //MENUクラスで選んだゲームインデックスとして使用
    char clearFlags[30]; //全クラスで使用
    STATE* state;
    FADE* fade;
};
