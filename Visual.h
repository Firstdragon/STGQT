#pragma once
#include <QGraphicsScene>
#include "Map.h"
class Visual : public QGraphicsScene
{
    Q_OBJECT
public:
    Visual(QObject *parent = 0);
    void makeWalls(map &mapp, int k);
    void paintplayer(map &mapp, int k);
protected:
private:
    QGraphicsPixmapItem * worker;
    QGraphicsItem * itemCollidesWith(QGraphicsItem * item);
    void placeBox(float x, float y);
    void setBoxes();

};
