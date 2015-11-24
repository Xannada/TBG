#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->HPBar->setValue(100);
    QString test;
//    player.findMusket();
//    player.findBayonet();
//    player.rangeAttack(test);
//    ui->testlabel->setText(test);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::rollReward(){
    int roll;
    roll = qrand() % 100 + 1;
    QString s;

    if     ( roll > 90){player.findKnife(); s = "You found a knife!";}
    else if( roll > 80){player.findHatchet(); s = "You found a hatchet!";}
    else if( roll > 70){player.findFlintlock(); s = "You found a flintlock pistol and 10 ammo!";}
    else if( roll > 60){player.findMusket(); s = "You found a musket and 10 ammo!";}
    else if( roll > 40){player.findAmmoBag(); s = "You found 5 musket ammo and 5 flintlock ammo!";}
    else if( roll > 15){player.hpUp(5); s = "You found bandages and heal for 5 hp!";}
    else if( roll > 10){player.maxUp(); s = "Your hunting has made you healthier, you gain more hp!";}
    else if( roll > 5){player.accUp(); s = "Your hunting has improved your aim, bonus damage with guns!";}
    else {player.atkUp(); s = "Your hunting has improved your combat skill, you attack more times!";}

    return s;
}

void MainWindow::updateHealth(){
    ui->HPBar->setValue(player.getHpBar());
    ui->healthValue->setText(player.health());
}

void MainWindow::findNextThing(){
    int roll;
    roll = qrand() % 20;

    if(roll == 0){/*monster*/}
    else if(roll < 4){/*indian*/}
    else if(roll < 10){/*animal*/}
    else{/*scenery*/}

}

void MainWindow::nextAnimal(){
    int roll;
    roll = qrand() % 20;

    if(roll == 0){/*monster*/}
    else if(roll < 4){/*indian*/}
    else if(roll < 10){/*animal*/}
    else{/*scenery*/}
}

void MainWindow::nextIndian(){
    int roll;
    roll = qrand() % 20;

    if(roll == 0){/*monster*/}
    else if(roll < 4){/*indian*/}
    else if(roll < 10){/*animal*/}
    else{/*scenery*/}
}

void MainWindow::nextScenery(){
    int roll;
    roll = qrand() % 20;

    if(roll < 5){/*4-Xroad*/}
    else if(roll < 10){/*3-Xroad*/}
    else{/*scenery*/}
}

void MainWindow::nextMonster(){
    int roll;
    roll = qrand() % 40;

    switch (roll) {
    case 0: //headless horseman
        break;
    case 1: //zombie
        break;
    case 2: //werewolf
        break;
    case 3: //vampire
        break;
    case 4: //bigfoot
        break;
    default: //witch
        break;
    }
}
