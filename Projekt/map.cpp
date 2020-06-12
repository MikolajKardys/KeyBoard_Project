#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QWidget>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->o1_C, &QAbstractButton::pressed, this, &MainWindow::f_o1_C);
    connect(ui->o1_C_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_C_sh);
    connect(ui->o1_D, &QAbstractButton::pressed, this, &MainWindow::f_o1_D);
    connect(ui->o1_D_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_D_sh);
    connect(ui->o1_E, &QAbstractButton::pressed, this, &MainWindow::f_o1_E);
    connect(ui->o1_F, &QAbstractButton::pressed, this, &MainWindow::f_o1_F);
    connect(ui->o1_F_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_F_sh);
    connect(ui->o1_G, &QAbstractButton::pressed, this, &MainWindow::f_o1_G);
    connect(ui->o1_G_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_G_sh);
    connect(ui->o1_A, &QAbstractButton::pressed, this, &MainWindow::f_o1_A);
    connect(ui->o1_A_sh, &QAbstractButton::pressed, this, &MainWindow::f_o1_A_sh);
    connect(ui->o1_B, &QAbstractButton::pressed, this, &MainWindow::f_o1_B);

    connect(ui->o2_C, &QAbstractButton::pressed, this, &MainWindow::f_o2_C);
    connect(ui->o2_C_sh, &QAbstractButton::pressed, this, &MainWindow::f_o2_C_sh);
    connect(ui->o2_D, &QAbstractButton::pressed, this, &MainWindow::f_o2_D);
    connect(ui->o2_D_sh, &QAbstractButton::pressed, this, &MainWindow::f_o2_D_sh);
    connect(ui->o2_E, &QAbstractButton::pressed, this, &MainWindow::f_o2_E);
    connect(ui->o2_F, &QAbstractButton::pressed, this, &MainWindow::f_o2_F);
    connect(ui->o2_F_sh, &QAbstractButton::pressed, this, &MainWindow::f_o2_F_sh);
    connect(ui->o2_G, &QAbstractButton::pressed, this, &MainWindow::f_o2_G);
    connect(ui->o2_G_sh, &QAbstractButton::pressed, this, &MainWindow::f_o2_G_sh);
    connect(ui->o2_A, &QAbstractButton::pressed, this, &MainWindow::f_o2_A);
    connect(ui->o2_A_sh, &QAbstractButton::pressed, this, &MainWindow::f_o2_A_sh);
    connect(ui->o2_B, &QAbstractButton::pressed, this, &MainWindow::f_o2_B);

    connect(ui->o3_C, &QAbstractButton::pressed, this, &MainWindow::f_o3_C);
    connect(ui->o3_C_sh, &QAbstractButton::pressed, this, &MainWindow::f_o3_C_sh);
    connect(ui->o3_D, &QAbstractButton::pressed, this, &MainWindow::f_o3_D);
    connect(ui->o3_D_sh, &QAbstractButton::pressed, this, &MainWindow::f_o3_D_sh);
    connect(ui->o3_E, &QAbstractButton::pressed, this, &MainWindow::f_o3_E);

    connect(ui->vol_dial, &QDial::valueChanged, this, &MainWindow::ChangeVol);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ChangeVol()
{
    QLabel * label = ui->vol;
    qreal dial_val = ui->vol_dial->value();
    label->setNum(dial_val);
}



