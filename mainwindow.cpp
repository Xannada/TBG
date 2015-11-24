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
    ui->meleeButton->setEnabled(false);
    ui->rangeButton->setEnabled(false);
    ui->bitchout->setEnabled(false);

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

    if(roll < 5){nextMonster();}
    else if(roll < 10){nextAnimal();}
    else{nextScenery();}

}

void MainWindow::nextAnimal(){
    int roll;
    roll = qrand() % 20;

    if(roll == 0){ //bear
        enemy.set("Bear", "claws at you", 20,5);
        pic.load(":/pics/images/bear.png");
    }
    else if(roll == 1){ //moose
        enemy.set("Moose", "claws at you", 15,4);
        pic.load(":/pics/images/moose.gif");
    }
    else if(roll < 4){ //wolf
        enemy.set("Wolf", "claws at you", 10,3);
        pic.load(":/pics/images/Wolf.png");
    }
    else{ //turkey
        enemy.set("Turkey", "Gobbles at you",3,1);
        pic.load(":/pics/images/Turkey.png");
    }
}

//void MainWindow::nextIndian(){
//    int roll;
//    roll = qrand() % 20;

//    if(roll == 0){/*monster*/}
//    else if(roll < 4){/*indian*/}
//    else if(roll < 10){/*animal*/}
//    else{/*scenery*/}

//    setCombat();
//}

void MainWindow::nextScenery(){
    int roll;
    roll = qrand() % 5;

    if(roll == 0){
        ui->description->setText("You come across a 4-way crossroad");
        ui->UpArrow->setEnabled(true);
        ui->UpLabel->setEnabled(true);
        ui->RightArrow->setEnabled(true);
        ui->RightLabel->setEnabled(true);
        ui->LeftArrow->setEnabled(true);
        ui->LeftLabel->setEnabled(true);
        pic.load(":/pics/images/4way.jpg");
    }
    else if(roll < 2){
        ui->description->setText("You come across a fork in the path");
        ui->UpArrow->setEnabled(false);
        ui->UpLabel->setEnabled(false);
        ui->RightArrow->setEnabled(true);
        ui->RightLabel->setEnabled(true);
        ui->LeftArrow->setEnabled(true);
        ui->LeftLabel->setEnabled(true);
        pic.load(":/pics/images/fork.jpg");
    }
    else{
        ui->description->setText("You progress along the path");
        pic.load(":/pics/images/path.jpg");
        ui->RightArrow->setEnabled(false);
        ui->RightLabel->setEnabled(false);
        ui->LeftArrow->setEnabled(false);
        ui->LeftLabel->setEnabled(false);
    }

    //set pic
    pic.scaledToHeight(ui->PDisplay->height());
    if(pic.width() > ui->PDisplay->width()){
        pic.scaledToWidth(ui->PDisplay->width());
    }
    ui->PDisplay->setPixmap(pic);
}

void MainWindow::nextMonster(){
    int roll;
    roll = qrand() % 100;

    switch (roll) {
    case 0: //headless horseman
            enemy.set("Headless Horseman", "rides you down", 50, 30);
            pic.load(":/pics/images/hh.jpg");
        break;
    case 1: //zombie
            enemy.set("Zombie", "shambles up and ", 20, 5);
            pic.load(":/pics/images/zombie.png");
        break;
    case 2: //werewolf
            enemy.set("Werewolf","claws at you", 15, 8);
            pic.load(":/pics/images/werewolf.png");
        break;
    case 3: //vampire
            enemy.set("Vampire","bites you", 50,20);
            pic.load(":/pics/images/vamp.png");
        break;
    case 4: //bigfoot
            enemy.set("Bigfoot", "drop kicks you", 30, 10);
            pic.load(":/pics/images/bigfoot.png");
        break;
    default: //ugh bad practice
            if(roll < 15){
                enemy.set("Witch", "casts a spell on you", 10, 5);
                pic.load(":/pics/images/witch-clipart-witch_cute.png");
            }
            else{//indian
                enemy.set("Indain","stabs you with his spear",10,2 );
                pic.load(":/pics/images/indian.jpg");
            }
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

void MainWindow::on_UpArrow_clicked(){findNextThing();}
void MainWindow::on_LeftArrow_clicked(){findNextThing();}
void MainWindow::on_RightArrow_clicked(){findNextThing();}

void MainWindow::on_bitchout_clicked()
{
    int roll = qrand() % 3;

    if(roll == 0){
        ui->description->setText("You try to run away...\n\nYou get away!");
        exitCombat();
    }
    else{
        QString temp;
        desc = "You try to run away...\n\nCan't Escape!\n\nThe " + enemy.getName()
                + " " + enemy.atkDes() + " for "
                + temp.setNum(enemy.attack()) + " damage";
        ui->description->setText(desc);
        if(!player.takedamage(enemy.attack())){
            GameOver();
        }
        updateHealth();
    }
}

void MainWindow::on_meleeButton_clicked()
{
   if(enemy.takeDamage(player.meleeAttack(desc))){
       QString temp;
       desc += "\n\nThe " + enemy.getName() + " is still alive\n\n"
            + "It " + enemy.atkDes() + " for " + temp.setNum(enemy.attack()) + " damage";
       if(!player.takedamage(enemy.attack())){
           GameOver();
       }
       updateHealth();
   }
   else{
       desc += "\n\nYou have killed the " + enemy.getName() + "\n\n" + rollReward();
       exitCombat();
       player.kill();
   }
   ui->description->setText(desc);
}

void MainWindow::on_rangeButton_clicked()
{
    if(enemy.takeDamage(player.rangeAttack(desc))){
        QString temp;
        desc += "\n\nThe " + enemy.getName() + " is still alive\n\n"
             + "It " + enemy.atkDes() + " for " + temp.setNum(enemy.attack()) + " damage";
        if(!player.takedamage(enemy.attack())){
            GameOver();
        }
        updateHealth();
    }
    else{
        desc += "\n\nYou have killed the " + enemy.getName() + "\n\n" + rollReward();
        exitCombat();
        player.kill();
    }
    ui->description->setText(desc);
}

void MainWindow::GameOver(){
    QMessageBox::critical(this,"Game Over","You have died!",QMessageBox::Ok);
    QApplication::quit();
}

