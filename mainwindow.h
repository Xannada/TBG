#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pilgrim.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString rollReward();
    void updateHealth();
    void findNextThing();
    void nextAnimal();
    void nextIndian();
    void nextScenery();
    void nextMonster();

private:
    Ui::MainWindow *ui;
    Pilgrim player;
};

#endif // MAINWINDOW_H
