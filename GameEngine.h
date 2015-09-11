#pragma once

#include <ctime>


#include "map.h"
#include "player.h"
#include "visual.h"
#include "bot.h"

class gameEngine
{
protected:
public:
    player player1;		// Igrok 1
    player player2;		// Igrok 2

    map mapp;
    int caughtKey;		// Nomer zaxvachennoj s klaviatury klavishi

    bot bot1;
    bot bot2;
    //visual vis;			// Obekt klassa visual

    gameEngine()
    {}

    ~gameEngine()
    {}
    // Rezhim igry
    void gameMode(int n, player &player1, player &player2);

    // Nachalnye ustanovki
    void startGame(int n, Visual *scene, Visual *scene2);

    // Process igry
    void playGame(Visual *scene, Visual *scene2, int caughtKey);

};
