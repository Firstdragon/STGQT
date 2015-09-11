#include "Map.h"

map::map()
{
        srand(time(0));

        bonusCount = 0;
        moneyCount = 0;

        len = 50;
        wid = 50;
        hei = 5;

        int ii, jj, s = 0;

        int startBonusCount;
        int startMoneyCount;

        floor = new cell **[len];				//Vydelyaem pamyat pod matricu floor razmera len*wid*hei
        for (int i = 0; i < len; i++)
        {
                floor[i] = new cell *[wid];
                for (int j = 0; j < wid; j++)
                        floor[i][j] = new cell[hei];
        }
        for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
        for (int k = 0; k < hei; k++)
                floor[i][j][k] = WALL;		 //Vsyo zapolnyaetsya "stenoj"


        for (int k = 0; k < hei; k++)
        {
                int previousRoomLength;
                int previousRoomWidth;
                int blankSpace = 0;
                int roomsCount = 0;



                while ((blankSpace < ((2 * len + 2 * wid) + len*wid / 20)) && (roomsCount < 10))
                {
                        ii = (rand() % (len - 2) + 1);
                        jj = (rand() % (wid - 2) + 1);

                        if (roomsCount == 0)
                        {
                                ii = 1;
                                jj = 1;
                        }

                        int roomLength = (rand() % (len / 4) + (len / 8));
                        int roomWidth = (rand() % (wid / 4) + (wid / 8));

                        if ((ii + roomLength >= len - 2) || (jj + roomWidth >= wid - 2))
                                continue;

                        roomsCount += makeRoom(ii, jj, k, roomLength, roomWidth);

                }

                connectTheRooms(k);

                //Sozdanie "ramok"
                makeLine(0, 0, k, wid, RIGHT, WALL);
                makeLine(len - 1, 0, k, wid, RIGHT, WALL);
                makeLine(0, 0, k, len, DOWN, WALL);
                makeLine(0, wid - 1, k, len, DOWN, WALL);

                //Sozdanie nachalnoy komnati
                for (int i = 1; i < 6; i++)
                        makeLine(i, 1, k, 5, RIGHT, BLANK);

                //Rasstanovka liftov
                if (k != hei - 1)
                        makeLine(2, 1, k, 4, DOWN, LIFT_UP);
                if (k != 0)
                        makeLine(1, 2, k, 4, RIGHT, LIFT_DOWN);

                //Raskidyvanie bonusov
                startBonusCount = (rand() % 8 + 3);
                for (int r = 0; r < startBonusCount; r++)
                {
                        spawnBonus(k);
                        bonusCount -= 1;
                }

                //Raskidyvanie deneg
                startMoneyCount = (rand() % 6 + 2);
                for (int r = 0; r < startMoneyCount; r++)
                {
                        spawnMoney(k);
                        moneyCount -= 1;
                }
        }
};

map::map(int g, int h, int d)
{
        len = g; wid = h; hei = d;
        int s = 0;
        int startBonusCount;
        int startMoneyCount;
        floor = new cell **[len];				//Vydelyaem pamyat pod matricu floor razmera len*wid
        for (int i = 0; i < len; i++)
        {
                floor[i] = new cell *[wid];
                for (int j = 0; j < wid; j++)
                        floor[i][j] = new cell[hei];
        }
        for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
        for (int k = 0; k < hei; k++)
                floor[i][j][k] = BLANK;				//Zapolnyaem vsyo nulyami

        for (int k = 0; k < hei; k++)
        {
                //Sozdanie "ramok"
                makeLine(0, 0, k, wid, RIGHT, WALL);
                makeLine(len - 1, 0, k, wid, RIGHT, WALL);
                makeLine(0, 0, k, len, DOWN, WALL);
                makeLine(0, wid - 1, k, len, DOWN, WALL);

                //Sozdanie perekryostnyx koridorov
                if (len % 2 == 0)
                {

                        makeLine(0, wid / 2 + 2, k, len / 2 - 2, DOWN, WALL);
                        makeLine(0, wid / 2 - 3, k, len / 2 - 2, DOWN, WALL);
                        makeLine(len - 1, wid / 2 + 2, k, len / 2 - 2, UP, WALL);
                        makeLine(len - 1, wid / 2 - 3, k, len / 2 - 2, UP, WALL);
                        if (s != hei - 1)
                                makeLine(len / 2 - 2, 1, k, 4, DOWN, LIFT_UP);
                        if (s != 0)
                                makeLine(len / 2 - 2, wid - 2, k, 4, DOWN, LIFT_DOWN);
                }
                else {
                        makeLine(0, wid / 2 + 2, k, len / 2 - 1, DOWN, WALL);
                        makeLine(0, wid / 2 - 2, k, len / 2 - 1, DOWN, WALL);
                        makeLine(len - 1, wid / 2 + 2, k, len / 2 - 1, UP, WALL);
                        makeLine(len - 1, wid / 2 - 2, k, len / 2 - 1, UP, WALL);
                        if (s != hei - 1)
                                makeLine(len / 2 - 1, 1, k, 3, DOWN, LIFT_UP);
                        if (s != 0)
                                makeLine(len / 2 - 1, wid - 2, k, 3, DOWN, LIFT_DOWN);
                }

                if (wid % 2 == 0)
                {
                        makeLine(len / 2 + 2, 0, k, wid / 2 - 2, RIGHT, WALL);
                        makeLine(len / 2 - 3, 0, k, wid / 2 - 2, RIGHT, WALL);
                        makeLine(len / 2 + 2, wid - 1, k, wid / 2 - 2, LEFT, WALL);
                        makeLine(len / 2 - 3, wid - 1, k, wid / 2 - 2, LEFT, WALL);
                }
                else {
                        makeLine(len / 2 + 2, 0, k, wid / 2 - 1, RIGHT, WALL);
                        makeLine(len / 2 - 2, 0, k, wid / 2 - 1, RIGHT, WALL);
                        makeLine(len / 2 + 2, wid - 1, k, wid / 2 - 1, LEFT, WALL);
                        makeLine(len / 2 - 2, wid - 1, k, wid / 2 - 1, LEFT, WALL);
                }

                if (wid % 2 == 0)							//Sozdanie "dverej"
                {
                        makeLine(1, wid / 4 - 2, k, len - 2, DOWN, BLANK);
                        makeLine(1, wid / 4 - 1, k, len - 2, DOWN, BLANK);
                        makeLine(1, wid / 4 * 3, k, len - 2, DOWN, BLANK);
                        makeLine(1, wid / 4 * 3 + 1, k, len - 2, DOWN, BLANK);
                }
                else {
                        makeLine(1, wid / 4 - 2, k, len - 2, DOWN, BLANK);
                        makeLine(1, wid / 4 - 1, k, len - 2, DOWN, BLANK);
                        makeLine(1, wid / 4 * 3 + 2, k, len - 2, DOWN, BLANK);
                        makeLine(1, wid / 4 * 3 + 1, k, len - 2, DOWN, BLANK);
                }

                if (len % 2 == 0)							//Sozdanie "dverej"
                {
                        makeLine(len / 4 - 2, 1, k, wid - 2, RIGHT, BLANK);
                        makeLine(len / 4 - 1, 1, k, wid - 2, RIGHT, BLANK);
                        makeLine(len / 4 * 3, 1, k, wid - 2, RIGHT, BLANK);
                        makeLine(len / 4 * 3 + 1, 1, k, wid - 2, RIGHT, BLANK);
                }
                else {
                        makeLine(len / 4 - 2, 1, k, wid - 2, RIGHT, BLANK);
                        makeLine(len / 4 - 1, 1, k, wid - 2, RIGHT, BLANK);
                        makeLine(len / 4 * 3 + 2, 1, k, wid - 2, RIGHT, BLANK);
                        makeLine(len / 4 * 3 + 1, 1, k, wid - 2, RIGHT, BLANK);
                }

                srand(time(0));
                startBonusCount = (rand() % 8 + 3);
                for (int r = 0; r < startBonusCount; r++)
                {
                        spawnBonus(k);
                        bonusCount -= 1;
                }

                srand(time(0));
                startMoneyCount = (rand() % 6 + 2);
                for (int r = 0; r < startMoneyCount; r++)
                {
                        spawnMoney(k);
                        moneyCount -= 1;
                }
                s++;
        }
}

//Funkciya, risuyushhaya liniyu      (koord. i  | koord. j |  dlina linii |  napravlenie    |    liniya chego)
void map::makeLine(int iFrom, int jFrom, int kFrom, int lineLength, line lineWhere, cell lineOfWhat)
{
    if (lineWhere == RIGHT)
    for (int j = jFrom; j < jFrom + lineLength; j++)
            floor[iFrom][j][kFrom] = lineOfWhat;
    if (lineWhere == LEFT)
    for (int j = jFrom; j > jFrom - lineLength; j--)
            floor[iFrom][j][kFrom] = lineOfWhat;
    if (lineWhere == UP)
    for (int i = iFrom; i > iFrom - lineLength; i--)
            floor[i][jFrom][kFrom] = lineOfWhat;
    if (lineWhere == DOWN)
    for (int i = iFrom; i < iFrom + lineLength; i++)
                floor[i][jFrom][kFrom] = lineOfWhat;
}

//Funkciya, razmeshhayushhaya bonus v sluchajnom meste karty
void map::spawnBonus(int floorNumber)
{
        if (bonusCount < 15)
        {

                int i = (rand() % (len - 3) + 2);
                int j = (rand() % (wid - 3) + 2);
                if (floor[i][j][floorNumber] == BLANK)
                {
                        int c = (rand() % 3 + 1);
                        if (c == 1) floor[i][j][floorNumber] = BONUS100;
                        if (c == 2) floor[i][j][floorNumber] = BONUS200;
                        if (c == 3) floor[i][j][floorNumber] = BONUS300;
                        bonusCount += 1;
                }

        }
}

//Funkciya, razmeshhayushhaya dengi v sluchajnom meste karty
void map::spawnMoney(int floorNumber)
{
        if (moneyCount < 5)
        {

                int i = (rand() % (len - 4) + 2);
                int j = (rand() % (wid - 4) + 2);
                if (floor[i][j][floorNumber] == BLANK)
                {
                        int c = (rand() % 2 + 1);
                        if (c == 1) floor[i][j][floorNumber] = MONEY100;
                        if (c == 2) floor[i][j][floorNumber] = MONEY500;
                        moneyCount += 1;
                }

        }
}

//Funkciya, sozdayushhaya komnatu
int map::makeRoom(int iiRoom, int jjRoom, int floorNumber, int roomLenn, int roomWidd)
{
        int s = 0;
        for (int i = iiRoom - 1; i < iiRoom + roomLenn + 1; i++)
        for (int j = jjRoom - 1; j < jjRoom + roomWidd + 1; j++)
        if (floor[i][j][floorNumber] == BLANK)
                s = 1;

        if (s == 0)
        {

        for (int i = iiRoom; i < iiRoom + roomLenn; i++)
        for (int j = jjRoom; j < jjRoom + roomWidd; j++)
                floor[i][j][floorNumber] = BLANK;

        rooms tempRoom;

        tempRoom.iRoom = iiRoom;
        tempRoom.jRoom = jjRoom;
        tempRoom.roomLen = roomLenn;
        tempRoom.roomWid = roomWidd;
        tempRoom.iRoomCenter = iiRoom + roomLenn / 2;
        tempRoom.jRoomCenter = jjRoom + roomWidd / 2;

        room.push_back(tempRoom);

        return 1;
        }
        return 0;
};

//Funkciya, soedinyayuschaya komnati
void map::connectTheRooms(int k)
{
        for (int r = 0; r < room.size() - 1; r++)
        {
                if (room[r].iRoomCenter > room[r + 1].iRoomCenter)
                {
                        makeLine(room[r].iRoomCenter, room[r].jRoomCenter, k, room[r].iRoomCenter - room[r + 1].iRoomCenter + 1, UP, BLANK);
                }
                else {
                        makeLine(room[r].iRoomCenter, room[r].jRoomCenter, k, room[r + 1].iRoomCenter - room[r].iRoomCenter + 1, DOWN, BLANK);
                }


                if (room[r].jRoomCenter > room[r + 1].jRoomCenter)
                {
                        makeLine(room[r + 1].iRoomCenter, room[r].jRoomCenter, k, room[r].jRoomCenter - room[r + 1].jRoomCenter + 1, LEFT, BLANK);
                }
                else {
                        makeLine(room[r + 1].iRoomCenter, room[r].jRoomCenter, k, room[r + 1].jRoomCenter - room[r].jRoomCenter + 1, RIGHT, BLANK);
                }
        }

        if (room[0].iRoomCenter > room[room.size() - 2].iRoomCenter)
        {
                makeLine(room[0].iRoomCenter, room[0].jRoomCenter, k, room[0].iRoomCenter - room[room.size() - 1].iRoomCenter + 1, UP, BLANK);
        }
        else {
                makeLine(room[0].iRoomCenter, room[0].jRoomCenter, k, room[room.size() - 1].iRoomCenter - room[0].iRoomCenter + 1, DOWN, BLANK);
        }

        if (room[0].jRoomCenter > room[room.size() - 1].jRoomCenter)
        {
                makeLine(room[room.size() - 1].iRoomCenter, room[0].jRoomCenter, k, room[0].jRoomCenter - room[room.size() - 1].jRoomCenter + 1, LEFT, BLANK);
        }
        else {
                makeLine(room[room.size() - 1].iRoomCenter, room[0].jRoomCenter, k, room[room.size() - 1].jRoomCenter - room[0].jRoomCenter + 1, RIGHT, BLANK);
        }

}

//Proverka kletki
bool map::canYouMove(cell r)			//Funkciya, proveryayushhaya vozmozhnost peremeshheniya
{
        if ((r == WALL) || (r == PLAYER1) || (r == PLAYER2))
                return false;
        else return true;
}

bool map::isbonus(cell b)
{
        if ((b == BONUS100) || (b == BONUS200) || (b == BONUS300) || (b == MONEY100) || (b == MONEY500))
                return true;
        else return false;
}

map::~map()					//Ochistka vydelenoj pamyati
{
        for (int i = 0; i < len; i++)
       {
               for (int j = 0; j < wid; j++)
                        delete[] floor[i][j];
                delete floor[i];
        }
        delete[] floor;
}
