#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->HPBar->setValue(100-10);
    QString test;
    player.rangeAttack(test);
    ui->PDisplay->setText(test);
}

MainWindow::~MainWindow()
{
    delete ui;
}
