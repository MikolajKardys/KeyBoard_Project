#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <iostream>

void MainWindow::play_sound(QAbstractButton * button){
    emit button_pressed(button->objectName());

    QString sound = button->objectName() + ".wav";

    QString vol_text = ui->vol->text();
    long vol = vol_text.toLong();

    QString path = PROJECT_PATH;
    QString sample = "sounds/";
    sample = sample + ui->sample->currentText();
    sample = sample + "/";
    sound = path + sample + sound;

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(sound));
    player->setVolume(vol);
    player->play();

    QEventLoop loop;
    connect(button, &QAbstractButton::released, &loop, &QEventLoop::quit);
    loop.exec();

    _sleep(50);
    if (!ui->sustain->isChecked()){
        player->pause();
    }
}

void MainWindow::f_o1_o2_o3(){
    QObject * sender = QObject::sender();
    QAbstractButton * button = centralWidget()->findChild<QAbstractButton *>(sender->objectName());
    if (button->objectName() != "push_label") play_sound( button );
}
