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
    scene = new Visual(0);
    scene2 = new Visual(0);
    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene2);
    ui->graphicsView->setFocusPolicy(Qt::WheelFocus);
    ui->graphicsView->setFocus(Qt::OtherFocusReason);
    game.startGame(1,scene,scene2);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    timer->start(30);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater2()));
    timer->start(30);
}

Window::~Window()
{
    delete ui;
}

// Upravlenie
void Window::keyPressEvent(QKeyEvent * keyEvent)
{
    switch (keyEvent->key())
    {

    case Qt::Key_A:
        movedirection=3;
        break;
    case Qt::Key_D:
        movedirection=4;
        break;
    case Qt::Key_W:
        movedirection=1;
        break;
    case Qt::Key_S:
        movedirection=2;
        break;
    case Qt::Key_J:
        movedirection2=7;
        break;
    case Qt::Key_L:
        movedirection2=8;
        break;
    case Qt::Key_I:
        movedirection2=5;
        break;
    case Qt::Key_K:
        movedirection2=6;
        break;
    case Qt::Key_9:
        if (game.player1.botMode==true)
        game.player1.botMode=false;
        else
        game.player1.botMode=true;
        break;
    case Qt::Key_0:
        if (game.player2.botMode==true)
        game.player2.botMode=false;
        else
        game.player2.botMode=true;
        break;
    }
}

void Window::on_ExitButton_clicked()
{
    close();
}

void Window::on_PlayerVSPlayer_clicked()
{
    game.player1.botMode=false;
    game.player2.botMode=false;
}

void Window::on_PlayerVSComputer_clicked()
{
//    scene = new Visual(0);
//    scene2 = new Visual(0);
//    ui->graphicsView->setScene(scene);
//    ui->graphicsView_2->setScene(scene2);
//    ui->graphicsView->setFocusPolicy(Qt::WheelFocus);
//    ui->graphicsView->setFocus(Qt::OtherFocusReason);
//    game.startGame(0,scene,scene2);
//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
//    timer->start(30);
    game.player1.botMode=false;
    game.player2.botMode=true;
}

void Window::on_ComputerVSComputer_clicked()
{
//    scene = new Visual(0);
//    scene2 = new Visual(0);
//    ui->graphicsView->setScene(scene);
//    ui->graphicsView_2->setScene(scene2);
//    ui->graphicsView->setFocusPolicy(Qt::WheelFocus);
//    ui->graphicsView->setFocus(Qt::OtherFocusReason);
//    game.startGame(2,scene,scene2);
//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
//    timer->start(30);
    game.player1.botMode=true;
    game.player2.botMode=true;
}

void Window::updater()
{
    if (game.player1.playerStamina>0 && game.player1.playerMoney>0)
    {
    if (movedirection<=4)
    {
    game.playGame(scene,scene2,movedirection);
    movedirection=0;
    }
    }
    else scene->clear();
    ui->Hap1->display(game.player1.playerHappiness);
    ui->Wei1->display(game.player1.playerStamina);
    ui->Money1->display(game.player1.playerMoney);
}
void Window::updater2()
{
    if (game.player2.playerStamina>0 && game.player2.playerMoney>0)
    {
    if (movedirection2>4)
    {
    game.playGame(scene,scene2,movedirection2);
    movedirection2=0;
    }
    }
    else scene2->clear();
    ui->Hap2->display(game.player2.playerHappiness);
    ui->Wei2->display(game.player2.playerStamina);
    ui->Money2->display(game.player2.playerMoney);
}
