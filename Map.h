#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <vector>


class map
{
protected:
public:


    enum cell {
            BLANK = 0,  // 0	pustota
            WALL,       // 1	stena
            BONUS100,   // 2	bonus na 100 xeppenesa
            BONUS200,   // 3	bonus na 200 xeppenesa
            BONUS300,   // 4	bonus na 300 xeppenesa
            MONEY100,   // 5	100 deneg
            MONEY500,   // 6	500 deneg
            PLAYER1,    // 7	igrok 1
            PLAYER2,    // 8	igrok 2
            BOT1,       // 9	bot 1
            BOT2,       // 10	bot 2
            LIFT_UP,    // 11	lift vverx
            LIFT_DOWN   // 12	lift vniz
    };

    enum line {
            UP = 0,   // 0 vverx
            LEFT,     // 1 vlevo
            RIGHT,    // 2 vpravo
            DOWN	  // 3 vniz
    };


	struct rooms
	{
		int iRoom;
		int jRoom;
		int roomLen;
		int roomWid;
		int iRoomCenter;
		int jRoomCenter;
	};

	std::vector <rooms> room;

	int len;		 //dlina
	int wid;		 //shirina
	int hei;		 //vysota
	cell ***floor;	 //karta
        int bonusCount;  //kolichestvo bonusov
        int moneyCount;	 //kolichestvo deneg

	map();

	map(int g, int h, int d);

	//Funkciya, risuyushhaya liniyu      (koord. i  | koord. j |  dlina linii |  napravlenie    |    liniya chego)
	void makeLine(int iFrom, int jFrom, int kFrom, int lineLength, line lineWhere, cell lineOfWhat);

	//Funkciya, razmeshhayushhaya bonus v sluchajnom meste karty
	void spawnBonus(int floorNumber);

	//Funkciya, razmeshhayushhaya dengi v sluchajnom meste karty
	void spawnMoney(int floorNumber);

	//Funkciya, sozdayushhaya komnatu s chetyrmya dveryami
	int makeRoom(int iiRoom, int jjRoom, int floorNumber, int roomLenn, int roomWidd);

	void connectTheRooms(int k);

	//Proverka kletki
	bool canYouMove(cell r);

	bool isbonus(cell b);

	~map();
};
