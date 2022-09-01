#include"STATE.h"
class MANAGER;

class MENU : public STATE{
public:
    MENU( MANAGER* manager );
    ~MENU();
    void proc( MANAGER* manager );
private:
    int ClearImg;
    int RectImg[ 16 ];
    float RectX;
    float RectY;
    float RectWidth;
    float RectHeight;
    int NumGames;
    int Yoko;
    int Tate;
    float Hue;
    float Satu;
    float Valu;
    float Angle;
};
