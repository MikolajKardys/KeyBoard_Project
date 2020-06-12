#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->o1_C, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_C_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_D, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_D_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_E, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_F, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_F_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_G, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_G_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_A, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_A_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o1_B, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);

    connect(ui->o2_C, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_C_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_D, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_D_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_E, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_F, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_F_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_G, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_G_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_A, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_A_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o2_B, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);

    connect(ui->o3_C, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o3_C_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o3_D, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o3_D_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);
    connect(ui->o3_E, &QAbstractButton::pressed, this, &MainWindow::f_o1_o2_o3);

    connect(ui->vol_dial, &QDial::valueChanged, this, &MainWindow::ChangeVol);

    connect(ui->start_game, &QAbstractButton::pressed, this, &MainWindow::start_the_game);

    connect(ui->push_label, &QAbstractButton::pressed, this, &MainWindow::proceed);
}


void MainWindow::ChangeVol(){
    QLabel * label = ui->vol;
    qreal dial_val = ui->vol_dial->value();
    label->setNum(dial_val);
}

MainWindow::~MainWindow(){
    delete ui;
}

