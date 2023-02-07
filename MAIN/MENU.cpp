#include<stdio.h>
#include"libOne.h"
#include"MANAGER.h"
#include"FADE.h"
#include"MENU.h"
#include"../GAME00/GAME.h"
#include"../GAME01/GAME.h"
#include"../GAME02/GAME.h"
#include"../GAME03/GAME.h"
#include"../GAME04/GAME.h"
#include"../GAME05/GAME.h"
#include"../GAME06/GAME.h"
#include"../GAME07/GAME.h"
#include"../GAME08/GAME.h"
#include"../GAME09/GAME.h"
#include"../GAME10/GAME.h"
#include"../GAME11/GAME.h"
#include"../GAME12/GAME.h"
#include"../GAME13/GAME.h"
#include"../GAME14/GAME.h"
#include"../GAME15/GAME.h"
#include"../GAME16/GAME.h"
#include"../GAME17/GAME.h"
#include"../GAME18/GAME.h"
#include"../GAME19/GAME.h"
#include"../GAME20/GAME.h"
#include"../GAME21/GAME.h"
#include"../GAME22/GAME.h"
#include"../GAME23/GAME.h"
#include"../GAME24/GAME.h"
#include"../GAME25/GAME.h"
#include"../GAME26/GAME.h"
#include"../GAME27/GAME.h"
#include"../GAME28/GAME.h"
#include"../GAME29/GAME.h"

MENU::MENU( MANAGER *manager ){
    ClearImg = loadImage( "data/2dgraphics/clear.png" );

    Tate = 5;
    Yoko = 6;
    NumGames = Tate * Yoko;

    RectWidth = 200.0f;
    RectHeight = 100.0f;
    RectX = (width - RectWidth*Yoko)/2;
    RectY = (height - RectHeight*Tate)/2;
 
    Hue = 360.0f / NumGames;
    Satu = 50;
    Valu = 100;

    //manager->fade->setSpeed( 15 );
    manager->fade->fadeInTrigger();
}

MENU::~MENU(){
}

void MENU::proc( MANAGER *manager ){
    int& selectIdx = manager->selectIdx; //名前を短くする

    //WASDキーでゲームを選択する
    if( isTrigger( KEY_D ) ){
        selectIdx++;
        if( selectIdx >= NumGames ){
            selectIdx = 0;
        }
    }
    if( isTrigger( KEY_A ) ){
        selectIdx--;
        if( selectIdx < 0 ){
            selectIdx = NumGames - 1;
        }
    }
    if( isTrigger( KEY_S ) ){
        selectIdx += Yoko;
        if( selectIdx >= NumGames ){
            selectIdx = selectIdx - ( NumGames - 1 );
            if( selectIdx == Yoko ){
                selectIdx = 0;
            }
        }
    }
    if( isTrigger( KEY_W ) ){
        selectIdx -= Yoko;
        if( selectIdx < 0 ){
            selectIdx = selectIdx + ( NumGames - 1 );
            if( selectIdx == ( NumGames - 1 ) - Yoko ){
                selectIdx = ( NumGames - 1 );
            }
        }
    }

    //メニュータイル表示。選択されているところは明るく
    clear(0,0,0);
    colorMode(HSV,100);
    angleMode(DEGREES);
    rectMode(CORNER);
    textMode(TOP);
    textSize(80);
    stroke(0,0,0);
    for( int i = 0; i < Tate; i++ ){
        for( int j = 0; j < Yoko; j++ ){
            int k = i * Yoko + j;
            Valu = 60;
            if( k == selectIdx ){
                Valu = 100;
            }
            strokeWeight(10);
            fill(Hue*k,Satu,Valu);
            rect( RectX + RectWidth * j, RectY + RectHeight * i,RectWidth,RectHeight);
            fill(0, 0, 100);
            text(k, RectX +10+ RectWidth * j, RectY + 10+RectHeight * i);
            if( manager->clearFlags[ k ] ){
                image( ClearImg, RectX + RectWidth * j, RectY + RectHeight * i);
            }
        }
    }

    manager->fade->draw();

    //選択されたゲームを呼び出す
    if( isTrigger( KEY_ENTER ) ){
        manager->fade->fadeOutTrigger();
    }
    if( manager->fade->fadeOutEndFlag() ){
        switch( selectIdx ){
        case 0:
            delete manager->state;
            manager->state = new GAME00::GAME( manager );
            break;
        case 1:
            delete manager->state;
            manager->state = new GAME01::GAME( manager );
            break;
        case 2:
            delete manager->state;
            manager->state = new GAME02::GAME( manager );
            break;
        case 3:
            delete manager->state;
            manager->state = new GAME03::GAME( manager );
            break;
        case 4:
            delete manager->state;
            manager->state = new GAME04::GAME( manager );
            break;
        case 5:
            delete manager->state;
            manager->state = new GAME05::GAME( manager );
            break;
        case 6:
            delete manager->state;
            manager->state = new GAME06::GAME( manager );
            break;
        case 7:
            delete manager->state;
            manager->state = new GAME07::GAME( manager );
            break;
        case 8:
            delete manager->state;
            manager->state = new GAME08::GAME( manager );
            break;
        case 9:
            delete manager->state;
            manager->state = new GAME09::GAME( manager );
            break;
        case 10:
            delete manager->state;
            manager->state = new GAME10::GAME( manager );
            break;
        case 11:
            delete manager->state;
            manager->state = new GAME11::GAME( manager );
            break;
        case 12:
            delete manager->state;
            manager->state = new GAME12::GAME( manager );
            break;
        case 13:
            delete manager->state;
            manager->state = new GAME13::GAME( manager );
            break;
        case 14:
            delete manager->state;
            manager->state = new GAME14::GAME( manager );
            break;
        case 15:
            delete manager->state;
            manager->state = new GAME15::GAME( manager );
            break;
        case 16:
            delete manager->state;
            manager->state = new GAME16::GAME(manager);
            break;
        case 17:
            delete manager->state;
            manager->state = new GAME17::GAME(manager);
            break;
        case 18:
            delete manager->state;
            manager->state = new GAME18::GAME(manager);
            break;
        case 19:
            delete manager->state;
            manager->state = new GAME19::GAME(manager);
            break;
        case 20:
            delete manager->state;
            manager->state = new GAME20::GAME(manager);
            break;
        case 21:
            delete manager->state;
            manager->state = new GAME21::GAME(manager);
            break;
        case 22:
            delete manager->state;
            manager->state = new GAME22::GAME(manager);
            break;
        case 23:
            delete manager->state;
            manager->state = new GAME23::GAME(manager);
            break;
        case 24:
            delete manager->state;
            manager->state = new GAME24::GAME(manager);
            break;
        case 25:
            delete manager->state;
            manager->state = new GAME25::GAME(manager);
            break;
        case 26:
            delete manager->state;
            manager->state = new GAME26::GAME(manager);
            break;
        case 27:
            delete manager->state;
            manager->state = new GAME27::GAME(manager);
            break;
        case 28:
            delete manager->state;
            manager->state = new GAME28::GAME(manager);
            break;
        case 29:
            delete manager->state;
            manager->state = new GAME29::GAME(manager);
            break;
        }
    }
}