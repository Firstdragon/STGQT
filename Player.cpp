#include "player.h"
#include <QKeyEvent>

player::player()
{}

// Upravlenie
//void player::keyPressEvent(QKeyEvent * keyEvent)
//{
//    QPointF np;
//    np.setX(0);
//    np.setY(0);
//    switch (keyEvent->key())
//    {
//        case Qt::Key_Left:
//            break;
//        case Qt::Key_Right:
//            break;
//        case Qt::Key_Up:
//            break;
//        case Qt::Key_Down:
//            break;
//    }
//}

// Dvizhenie igroka
int player::playerMoving(int caughtKey, map &map, map::cell r)
{
        if (caughtKey == moveUp)
        {
                if (map.canYouMove(map.floor[ii - 1][jj][kk]))
                {
                        if (map.floor[ii - 1][jj][kk] == map::LIFT_UP)
                        {
                                map.floor[ii][jj][kk] = map::BLANK;
                                kk++;
                                map.floor[ii][jj][kk] = r;
                        }
                        else if (map.floor[ii - 1][jj][kk] == map::LIFT_DOWN)
                        {
                                map.floor[ii][jj][kk] = map::BLANK;
                                kk--;
                                map.floor[ii][jj][kk] = r;
                        }
                        else {
                                if (map.floor[ii - 1][jj][kk] == map::BONUS100)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 100;
                                        playerMoney -= 10;
                                        playerStamina -= 10;
                                }

                                if (map.floor[ii - 1][jj][kk] == map::BONUS200)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 200;
                                        playerMoney -= 20;
                                        playerStamina -= 20;
                                }

                                if (map.floor[ii - 1][jj][kk] == map::BONUS300)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 300;
                                        playerMoney -= 30;
                                        playerStamina -= 30;
                                }

                                if (map.floor[ii - 1][jj][kk] == map::MONEY100)
                                {
                                        map.moneyCount -= 1;
                                        playerMoney += 100;
                                }

                                if (map.floor[ii - 1][jj][kk] == map::MONEY500)
                                {
                                        map.moneyCount -= 1;
                                        playerMoney += 500;
                                }
                                map.floor[ii][jj][kk] = map::BLANK;
                                ii--;
                                map.floor[ii][jj][kk] = r;
                        }
                }
        }


        if (caughtKey == moveDown)
        {
                if (map.canYouMove(map.floor[ii + 1][jj][kk]))
                {
                        if (map.floor[ii + 1][jj][kk] == map::LIFT_UP)
                        {
                                map.floor[ii][jj][kk] = map::BLANK;
                                kk++;
                                map.floor[ii][jj][kk] = r;
                        }
                        else if (map.floor[ii + 1][jj][kk] == map::LIFT_DOWN)
                        {
                                map.floor[ii][jj][kk] = map::BLANK;
                                kk--;
                                map.floor[ii][jj][kk] = r;
                        }
                        else {
                                if (map.floor[ii + 1][jj][kk] == map::BONUS100)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 100;
                                        playerMoney -= 10;
                                        playerStamina -= 10;
                                }

                                if (map.floor[ii + 1][jj][kk] == map::BONUS200)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 200;
                                        playerMoney -= 20;
                                        playerStamina -= 20;
                                }

                                if (map.floor[ii + 1][jj][kk] == map::BONUS300)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 300;
                                        playerMoney -= 30;
                                        playerStamina -= 30;
                                }

                                if (map.floor[ii + 1][jj][kk] == map::MONEY100)
                                {
                                        map.moneyCount -= 1;
                                        playerMoney += 100;
                                }

                                if (map.floor[ii + 1][jj][kk] == map::MONEY500)
                                {
                                        map.moneyCount -= 1;
                                        playerMoney += 500;
                                }
                                map.floor[ii][jj][kk] = map::BLANK;
                                ii++;
                                map.floor[ii][jj][kk] = r;
                        }
                }
        }

        if (caughtKey == moveRight)
        {
                if (map.canYouMove(map.floor[ii][jj + 1][kk]))
                {
                        if (map.floor[ii][jj + 1][kk] == map::LIFT_UP)
                        {
                                map.floor[ii][jj][kk] = map::BLANK;
                                kk++;
                                map.floor[ii][jj][kk] = r;
                        }
                        else if (map.floor[ii][jj + 1][kk] == map::LIFT_DOWN)
                        {
                                map.floor[ii][jj][kk] = map::BLANK;
                                kk--;
                                map.floor[ii][jj][kk] = r;
                        }
                        else {
                                if (map.floor[ii][jj + 1][kk] == map::BONUS100)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 100;
                                        playerMoney -= 10;
                                        playerStamina -= 10;
                                }

                                if (map.floor[ii][jj + 1][kk] == map::BONUS200)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 200;
                                        playerMoney -= 20;
                                        playerStamina -= 20;
                                }

                                if (map.floor[ii][jj + 1][kk] == map::BONUS300)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 300;
                                        playerMoney -= 30;
                                        playerStamina -= 30;
                                }

                                if (map.floor[ii][jj + 1][kk] == map::MONEY100)
                                {
                                        map.moneyCount -= 1;
                                        playerMoney += 100;
                                }

                                if (map.floor[ii][jj + 1][kk] == map::MONEY500)
                                {
                                        map.moneyCount -= 1;
                                        playerMoney += 500;
                                }
                                map.floor[ii][jj][kk] = map::BLANK;
                                jj++;
                                map.floor[ii][jj][kk] = r;
                        }
                }
        }

        if (caughtKey == moveLeft)
        {
                if (map.canYouMove(map.floor[ii][jj - 1][kk]))
                {

                        if (map.floor[ii][jj - 1][kk] == map::LIFT_UP)
                        {
                                map.floor[ii][jj][kk] = map::BLANK;
                                kk++;
                                map.floor[ii][jj][kk] = r;
                        }
                        else if (map.floor[ii][jj - 1][kk] == map::LIFT_DOWN)
                        {
                                map.floor[ii][jj][kk] = map::BLANK;
                                kk--;
                                map.floor[ii][jj][kk] = r;
                        }
                        else {
                                if (map.floor[ii][jj - 1][kk] == map::BONUS100)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 100;
                                        playerMoney -= 10;
                                        playerStamina -= 10;
                                }

                                if (map.floor[ii][jj - 1][kk] == map::BONUS200)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 200;
                                        playerMoney -= 20;
                                        playerStamina -= 20;
                                }

                                if (map.floor[ii][jj - 1][kk] == map::BONUS300)
                                {
                                        map.bonusCount -= 1;
                                        playerHappiness += 300;
                                        playerMoney -= 30;
                                        playerStamina -= 30;
                                }

                                if (map.floor[ii][jj - 1][kk] == map::MONEY100)
                                {
                                        map.moneyCount -= 1;
                                        playerMoney += 100;
                                }

                                if (map.floor[ii][jj - 1][kk] == map::MONEY500)
                                {
                                        map.moneyCount -= 1;
                                        playerMoney += 500;
                                }

                                map.floor[ii][jj][kk] = map::BLANK;
                                jj--;
                                map.floor[ii][jj][kk] = r;
                        }


                }
        }

        if ((caughtKey != moveUp) && (caughtKey != moveDown) && (caughtKey != moveLeft) && (caughtKey != moveRight))
                return -33;

        return 0;
}

player::~player()
{};
