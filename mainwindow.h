#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "pilgrim.h"
#include "encounter.h"
//using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void rollReward();
    void updateHealth();
    void findNextThing();
    void nextAnimal();
    void nextIndian();
    void nextScenery();
    void nextMonster();
    void setCombat();
    void exitCombat();
    void GameOver();

private slots:
    void on_UpArrow_clicked();

    void on_bitchout_clicked();

    void on_meleeButton_clicked();

    void on_rangeButton_clicked();

private:
    Ui::MainWindow *ui;
    Pilgrim player;
    Encounter enemy;
    QPixmap pic;
    QString desc;
};

#endif // MAINWINDOW_H
