#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "Visual.h"
#include "Map.h"
#include "GameEngine.h"


namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
protected:

//    virtual void keyPressEvent(QKeyEvent * keyEvent);

public slots:
    void updater();

private slots:

    void on_ExitButton_clicked();

    void on_PlayerVSPlayer_clicked();

    void on_PlayerVSComputer_clicked();

    void on_ComputerVSComputer_clicked();

private:

    Visual * scene;

    Visual *scene2;

    Ui::Window *ui;

    int movedirection;

    gameEngine game;
    QTimer *timer;



};


#endif // WINDOW_H
