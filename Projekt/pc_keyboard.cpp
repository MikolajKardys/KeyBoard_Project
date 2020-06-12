#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>


#include <iostream>

QString getKeyName(int key_pressed){
    QString name = "o";
    switch(key_pressed){
        case 'A': name = name + "2_C"; break;
        case 'W': name = name + "2_C_sh"; break;
        case 'S': name = name + "2_D"; break;
        case 'E': name = name + "2_D_sh"; break;
        case 'D': name = name + "2_E"; break;
        case 'F': name = name + "2_F"; break;
        case 'T': name = name + "2_F_sh"; break;
        case 'G': name = name + "2_G"; break;
        case 'Y': name = name + "2_G_sh"; break;
        case 'H': name = name + "2_A"; break;
        case 'U': name = name + "2_A_sh"; break;
        case 'J': name = name + "2_B"; break;

        case 'K': name = name + "3_C"; break;
        case 'O': name = name + "3_C_sh"; break;
        case 'L': name = name + "3_D"; break;
        case 'P': name = name + "3_D_sh"; break;
        case ';': name = name + "3_E"; break;
    };
    return name;
}
void MainWindow::keyPressEvent(QKeyEvent * event){
    QString name = getKeyName(event->key());
    if (name != "o") {
        QAbstractButton * button = centralWidget()->findChild<QAbstractButton *>(name);
        if (!event->isAutoRepeat()){
            button->setDown(true);
            play_sound(button);
        }
    }
}


void MainWindow::keyReleaseEvent(QKeyEvent * event){
    QString name = getKeyName(event->key());
    if (name != "o") {
        QAbstractButton * button = centralWidget()->findChild<QAbstractButton *>(name);
        if (!event->isAutoRepeat()){
            button->setDown(false);
            emit button->released();
        }
    }
}







