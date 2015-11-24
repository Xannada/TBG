#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->HPBar->setValue(100);
    ui->DownArrow->setHidden(true);
    ui->DownLabel->setHidden(true);


//    pic.load(":/pics/images/arrowLeft.png");
//    ui->PDisplay->setPixmap(pic);
//    ui->PDisplay->clear();


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

void MainWindow::rollReward(){
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

    ui->description->setText(s);
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

    setCombat();;
}

void MainWindow::setCombat(){
    //disable movement
    ui->UpArrow->setEnabled(false);
    ui->UpLabel->setEnabled(false);
    ui->RightArrow->setEnabled(false);
    ui->RightLabel->setEnabled(false);
    ui->LeftArrow->setEnabled(false);
    ui->LeftLabel->setEnabled(false);

    //enable actions
    ui->rangeButton->setText(player.rangeWeapon());
    ui->meleeButton->setText(player.meleeWeapon());
    if(player.rangeWeapon() != "No ranged weapon")
     ui->rangeButton->setEnabled(true);
    if(player.meleeWeapon() != "No melee weapon")
        ui->meleeButton->setEnabled(true);
    ui->bitchout->setEnabled(true);
    ui->noactions->setHidden(true);

    //set pic
    pic.scaledToHeight(ui->PDisplay->height());
    if(pic.width() > ui->PDisplay->width()){
        pic.scaledToWidth(ui->PDisplay->width());
    }
    ui->PDisplay->setPixmap(pic);

}

void MainWindow::exitCombat(){
    //enable movement
    ui->UpArrow->setEnabled(true);
    ui->UpLabel->setEnabled(true);
    ui->RightArrow->setEnabled(true);
    ui->RightLabel->setEnabled(true);
    ui->LeftArrow->setEnabled(true);
    ui->LeftLabel->setEnabled(true);

    //disable actions
    ui->rangeButton->setEnabled(false);
    ui->bitchout->setEnabled(false);
    ui->meleeButton->setEnabled(false);
    ui->noactions->setHidden(false);

    //clear pic
    ui->PDisplay->clear();
    player.hpUp();
    updateHealth();
}

void MainWindow::on_UpArrow_clicked()
{
    findNextThing();
    GameOver();
}

void MainWindow::on_bitchout_clicked()
{
    int roll = qrand() % 5;

    if(roll == 0){
        ui->description->setText("You try to run away...\n\nYou get away!");
        exitCombat();
    }
    else{
        QString temp;
        desc = "You try to run away...\n\nCan't Escape!\n\nThe " + enemy.getName()
                + " " + enemy.atkDes() + " for "
                + temp.setNum(enemy.attack()) + " damage";
        player.takedamage(enemy.attack());
        ui->description->setText(desc);
    }
}

void MainWindow::on_meleeButton_clicked()
{
   if(enemy.takeDamage(player.meleeAttack(desc))){
       QString temp;
       desc += "\n\nThe " + enemy.getName() + " is still alive\n\n"
            + "It " + enemy.atkDes() + " for " + temp.setNum(enemy.attack()) + " damage";
       player.takedamage(enemy.attack());
   }
   else{
       desc += "\n\nYou have killed the " + enemy.getName();
       exitCombat();
   }
   ui->description->setText(desc);
}

void MainWindow::on_rangeButton_clicked()
{

}

void MainWindow::GameOver(){
    QMessageBox::critical(this,"Game Over","You have died!",QMessageBox::Ok);
    QApplication::quit();
}
