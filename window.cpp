#include "window.h"
#include "ui_window.h"
#include "GameEngine.h"
#include <QTimer>
#include <QKeyEvent>

#define private public

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);    
}

Window::~Window()
{
    delete ui;
}

 //Upravlenie
//void Window::keyPressEvent(QKeyEvent * keyEvent)
//{
//    QPointF np;
//    np.setX(0);
//    np.setY(0);
//    switch (keyEvent->key())
//    {
//        case Qt::Key_Left:
//          movedirection=1;
//        case Qt::Key_Right:
//          movedirection=2;
//        case Qt::Key_Up:
//          movedirection=3;
//        case Qt::Key_Down:
//          movedirection=4;
//        case Qt::Key_A:
//         movedirection=5;
//        case Qt::Key_D:
//         movedirection=6;
//        case Qt::Key_W:
//         movedirection=7;
//        case Qt::Key_S:
//         movedirection=8;
//    }
//}

void Window::on_ExitButton_clicked()
{
    close();
}

void Window::on_PlayerVSPlayer_clicked()
{
    scene = new Visual(0);
    scene2 = new Visual(0);
    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene2);
    game.startGame(0,scene,scene2);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    timer->start(30);
}

void Window::on_PlayerVSComputer_clicked()
{
    scene = new Visual(0);
    scene2 = new Visual(0);
    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene2);
    game.startGame(1,scene,scene2);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    timer->start(30);
}

void Window::on_ComputerVSComputer_clicked()
{
    scene = new Visual(0);
    scene2 = new Visual(0);
    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene2);
    game.startGame(2,scene,scene2);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    timer->start(30);
}

void Window::updater()
{
    game.playGame(2,scene,scene2);
    movedirection=0;
}
