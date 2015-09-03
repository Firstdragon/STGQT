#include "GameEngine.h"


void gameEngine::gameMode(int n, player &player1, player &player2)
{
        if (n == 1)
        {
                player1.botMode = false;
                player2.botMode = false;
        };
        if (n == 0)
        {
                player1.botMode = false;
                player2.botMode = true;
                player2.moveUp = 105;
                player2.moveLeft = 106;
                player2.moveDown = 107;
                player2.moveRight = 108;
        };
        if (n == 2)
        {
                player1.botMode = true;
                player2.botMode = true;
        };
}

void gameEngine::startGame(int n, Visual *scene, Visual *scene2)
{
        gameMode(n, player1, player2);


        player1.ii = 2;
        player1.jj = 2;
        player1.kk = 0;
        player2.ii = 4;
        player2.jj = 4;
        player2.kk = 1;
        mapp.floor[player1.ii][player1.jj][player1.kk] = map::PLAYER1;
        mapp.floor[player2.ii][player2.jj][player2.kk] = map::PLAYER2;

        player1.playerHappiness = 0;
        player2.playerHappiness = 0;

        player1.playerMoney = 1000;
        player2.playerMoney = 1000;

        player1.playerStamina = 1000;
        player2.playerStamina = 1000;

        scene->makeWalls(mapp,player1.kk);
        scene2->makeWalls(mapp,player2.kk);
        scene->paintplayer(mapp,player1.kk);
        scene2->paintplayer(mapp,player2.kk);
}

void gameEngine::playGame(int n, Visual *scene, Visual *scene2)
{
        int b;
        int k;
        int caughtKey = 0;
        //while (player1.playerStamina > 0 && player2.playerStamina > 0 && player1.playerMoney > 0 && player2.playerMoney > 0)

        {
                //vis.gameOut(mapp, player1, player2);
                if (!player1.botMode || !player2.botMode)
                {
                        caughtKey = _getch();
                        if (caughtKey == 0)
                                caughtKey = _getch();
                }
                else Sleep(10);
                if (player1.botMode == false && player2.botMode == false)
                {
                        if ((player1.playerMoving(caughtKey, mapp, map::PLAYER1)) == -33)
                                player2.playerMoving(caughtKey, mapp, map::PLAYER2);
                }
                if (player1.botMode == false && player2.botMode == true)
                {
                        player1.playerMoving(caughtKey, mapp, map::PLAYER1);
                        player2.playerMoving(bot2.move(mapp, player2, player2.kk, mapp.len, mapp.wid), mapp, map::PLAYER2);
                }
                if (player1.botMode == true && player2.botMode == false)
                {
                        player1.playerMoving(bot1.move(mapp, player1, player1.kk, mapp.len, mapp.wid), mapp, map::PLAYER1);
                        player2.playerMoving(caughtKey, mapp, map::PLAYER2);
                }
                if (player1.botMode == true && player2.botMode == true)
                {
                        player1.playerMoving(bot1.move(mapp, player1, player1.kk, mapp.len, mapp.wid), mapp, map::PLAYER1);
                        player2.playerMoving(bot2.move(mapp, player2, player2.kk, mapp.len, mapp.wid), mapp, map::PLAYER2);
                }

                b = (rand() % 2 + 1);
                k = (rand() % 2);
                if (b == 2)
                        mapp.spawnBonus(k);

                b = (rand() % 5);
                k = (rand() % 2);
                if (b == 2)
                        mapp.spawnMoney(k);
                scene->paintplayer(mapp,player1.kk);
                scene2->paintplayer(mapp,player2.kk);

}}
