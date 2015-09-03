#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "GameEngine.h"
#include "form.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

   friend class Visual;
public:
    int ChosenGameMode=0;

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    Ui::MainWindow *ui;


private slots:

    void on_ExitButton_clicked();

    void on_PlayerVSPlayer_clicked();

    void on_PlayerVSComputer_clicked();

    void on_ComputerVSComputer_clicked();

    void on_PlayerVSPlayer_2_triggered();

    void on_PlayerVSComputer_2_triggered();

    void on_ExitButton_2_triggered();

    void on_ComputerVSComputer_2_triggered();

private:

};

#endif // MAINWINDOW_H
