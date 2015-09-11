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
int player::playerMoving(int caughtKey, map &mapp, map::cell r, bool &needWalls)
{
    needWalls=false;
        if (caughtKey == moveUp)
        {
                if (mapp.canYouMove(mapp.floor[ii - 1][jj][kk]))
                {
                        if (mapp.floor[ii - 1][jj][kk] == map::LIFT_UP)
                        {
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                kk++;
                                needWalls=true;
                                mapp.floor[ii][jj][kk] = r;
                        }
                        else if (mapp.floor[ii - 1][jj][kk] == map::LIFT_DOWN)
                        {
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                kk--;
                                needWalls=true;
                                mapp.floor[ii][jj][kk] = r;
                        }
                        else {
                                if (mapp.floor[ii - 1][jj][kk] == map::BONUS100)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 100;
                                        playerMoney -= 10;
                                        playerStamina -= 10;
                                }

                                if (mapp.floor[ii - 1][jj][kk] == map::BONUS200)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 200;
                                        playerMoney -= 20;
                                        playerStamina -= 20;
                                }

                                if (mapp.floor[ii - 1][jj][kk] == map::BONUS300)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 300;
                                        playerMoney -= 30;
                                        playerStamina -= 30;
                                }

                                if (mapp.floor[ii - 1][jj][kk] == map::MONEY100)
                                {
                                        mapp.moneyCount -= 1;
                                        playerMoney += 100;
                                }

                                if (mapp.floor[ii - 1][jj][kk] == map::MONEY500)
                                {
                                        mapp.moneyCount -= 1;
                                        playerMoney += 500;
                                }
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                ii--;
                                mapp.floor[ii][jj][kk] = r;
                        }
                }
        }


        if (caughtKey == moveDown)
        {
                if (mapp.canYouMove(mapp.floor[ii + 1][jj][kk]))
                {
                        if (mapp.floor[ii + 1][jj][kk] == map::LIFT_UP)
                        {
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                kk++;
                                needWalls=true;
                                mapp.floor[ii][jj][kk] = r;
                        }
                        else if (mapp.floor[ii + 1][jj][kk] == map::LIFT_DOWN)
                        {
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                kk--;
                                needWalls=true;
                                mapp.floor[ii][jj][kk] = r;
                        }
                        else {
                                if (mapp.floor[ii + 1][jj][kk] == map::BONUS100)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 100;
                                        playerMoney -= 10;
                                        playerStamina -= 10;
                                }

                                if (mapp.floor[ii + 1][jj][kk] == map::BONUS200)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 200;
                                        playerMoney -= 20;
                                        playerStamina -= 20;
                                }

                                if (mapp.floor[ii + 1][jj][kk] == map::BONUS300)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 300;
                                        playerMoney -= 30;
                                        playerStamina -= 30;
                                }

                                if (mapp.floor[ii + 1][jj][kk] == map::MONEY100)
                                {
                                        mapp.moneyCount -= 1;
                                        playerMoney += 100;
                                }

                                if (mapp.floor[ii + 1][jj][kk] == map::MONEY500)
                                {
                                        mapp.moneyCount -= 1;
                                        playerMoney += 500;
                                }
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                ii++;
                                mapp.floor[ii][jj][kk] = r;
                        }
                }
        }

        if (caughtKey == moveRight)
        {
                if (mapp.canYouMove(mapp.floor[ii][jj + 1][kk]))
                {
                        if (mapp.floor[ii][jj + 1][kk] == map::LIFT_UP)
                        {
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                kk++;
                                needWalls=true;
                                mapp.floor[ii][jj][kk] = r;
                        }
                        else if (mapp.floor[ii][jj + 1][kk] == map::LIFT_DOWN)
                        {
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                kk--;
                                needWalls=true;
                                mapp.floor[ii][jj][kk] = r;
                        }
                        else {
                                if (mapp.floor[ii][jj + 1][kk] == map::BONUS100)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 100;
                                        playerMoney -= 10;
                                        playerStamina -= 10;
                                }

                                if (mapp.floor[ii][jj + 1][kk] == map::BONUS200)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 200;
                                        playerMoney -= 20;
                                        playerStamina -= 20;
                                }

                                if (mapp.floor[ii][jj + 1][kk] == map::BONUS300)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 300;
                                        playerMoney -= 30;
                                        playerStamina -= 30;
                                }

                                if (mapp.floor[ii][jj + 1][kk] == map::MONEY100)
                                {
                                        mapp.moneyCount -= 1;
                                        playerMoney += 100;
                                }

                                if (mapp.floor[ii][jj + 1][kk] == map::MONEY500)
                                {
                                        mapp.moneyCount -= 1;
                                        playerMoney += 500;
                                }
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                jj++;
                                mapp.floor[ii][jj][kk] = r;
                        }
                }
        }

        if (caughtKey == moveLeft)
        {
                if (mapp.canYouMove(mapp.floor[ii][jj - 1][kk]))
                {

                        if (mapp.floor[ii][jj - 1][kk] == map::LIFT_UP)
                        {
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                kk++;
                                needWalls=true;
                                mapp.floor[ii][jj][kk] = r;
                        }
                        else if (mapp.floor[ii][jj - 1][kk] == map::LIFT_DOWN)
                        {
                                mapp.floor[ii][jj][kk] = map::BLANK;
                                kk--;
                                needWalls=true;
                                mapp.floor[ii][jj][kk] = r;
                        }
                        else {
                                if (mapp.floor[ii][jj - 1][kk] == map::BONUS100)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 100;
                                        playerMoney -= 10;
                                        playerStamina -= 10;
                                }

                                if (mapp.floor[ii][jj - 1][kk] == map::BONUS200)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 200;
                                        playerMoney -= 20;
                                        playerStamina -= 20;
                                }

                                if (mapp.floor[ii][jj - 1][kk] == map::BONUS300)
                                {
                                        mapp.bonusCount -= 1;
                                        playerHappiness += 300;
                                        playerMoney -= 30;
                                        playerStamina -= 30;
                                }

                                if (mapp.floor[ii][jj - 1][kk] == map::MONEY100)
                                {
                                        mapp.moneyCount -= 1;
                                        playerMoney += 100;
                                }

                                if (mapp.floor[ii][jj - 1][kk] == map::MONEY500)
                                {
                                        mapp.moneyCount -= 1;
                                        playerMoney += 500;
                                }

                                mapp.floor[ii][jj][kk] = map::BLANK;
                                jj--;
                                mapp.floor[ii][jj][kk] = r;
                        }


                }
        }

        if ((caughtKey != moveUp) && (caughtKey != moveDown) && (caughtKey != moveLeft) && (caughtKey != moveRight))
                return -33;
        playerStamina -= 1;
        return 0;
}

player::~player()
{};
