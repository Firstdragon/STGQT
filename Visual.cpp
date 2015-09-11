#include "Visual.h"
#include "GameEngine.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QtCore>

Visual::Visual(QObject *parent) : QGraphicsScene(parent)
{
}



void Visual::makeWalls(map &mapp,int k)
{
    QGraphicsScene::clear();
    QBrush wall(QColor(255, 255, 255), QPixmap(":resource/images/wall.png"));
    QPen pen(Qt::NoPen);
    QBrush liftup  (QColor(255, 255, 255), QPixmap(":resource/images/Liftup.png"));
    QBrush liftdown(QColor(255, 255, 255), QPixmap(":resource/images/Liftdown.png"));
    for (int i = 0; i < mapp.len; i++)
        {
            for (int j = 0; j < mapp.wid; j++)
            {
                if (mapp.floor[i][j][k] == map::WALL)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, wall);
                    item->setData(0, map::WALL);
                }
                if (mapp.floor[i][j][k] == map::LIFT_UP)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, liftup);
                    item->setData(0, map::LIFT_UP);
                }
                if (mapp.floor[i][j][k] == map::LIFT_DOWN)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, liftdown);
                    item->setData(0, map::LIFT_DOWN);
                }
             }
         }
}
void Visual::paintplayer(map &mapp,int k)
{
    QPen pen(Qt::NoPen);
    QBrush bonus100(QColor(255, 255, 255), QPixmap(":resource/images/player11.png"));
    QBrush bonus200(QColor(255, 255, 255), QPixmap(":resource/images/player22.png"));
    QBrush bonus300(QColor(255, 255, 255), QPixmap(":resource/images/palyer33.png"));
    QBrush money100(QColor(255, 255, 255), QPixmap(":resource/images/Money100.png"));
    QBrush money500(QColor(255, 255, 255), QPixmap(":resource/images/Money500.png"));
    QBrush player1 (QColor(255, 255, 255), QPixmap(":resource/images/player1.png"));
    QBrush player2 (QColor(255, 255, 255), QPixmap(":resource/images/player2.png"));

        for (int i = 0; i < mapp.len; i++)
        {
            for (int j = 0; j < mapp.wid; j++)
            {
                //QGraphicsItem * item = QGraphicsScene.items(i*10,j*10,10,10);
                QList <QGraphicsItem*>item;
                  item=items(QRectF(i*10, j*10, 10, 10));
                if (item.size()>0 && item[0]->data(0) != map::WALL && item[0]->data(0) != map::LIFT_UP && item[0]->data(0) != map::LIFT_DOWN)
                 removeItem(item[0]);
                if (mapp.floor[i][j][k] == map::BONUS100)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, bonus100);
                    item->setData(0, map::BONUS100);
                }
                if (mapp.floor[i][j][k] == map::BONUS200)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, bonus200);
                    item->setData(0, map::BONUS200);
                }
                if (mapp.floor[i][j][k] == map::BONUS300)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, bonus300);
                    item->setData(0, map::BONUS300);
                }
                if (mapp.floor[i][j][k] == map::MONEY100)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, money100);
                    item->setData(0, map::MONEY100);
                }
                if (mapp.floor[i][j][k] == map::MONEY500)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, money500);
                    item->setData(0, map::MONEY500);
                }
                if (mapp.floor[i][j][k] == map::PLAYER1)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, player1);
                    item->setData(0, map::PLAYER1);
                }
                if (mapp.floor[i][j][k] == map::PLAYER2)
                {
                    QGraphicsItem * item =
                    addRect(QRectF(i*10, j*10, 10, 10), pen, player2);
                    item->setData(0, map::PLAYER2);
                }
            }
        }
}
