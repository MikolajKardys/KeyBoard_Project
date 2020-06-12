#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

#include <QRandomGenerator>
#include <QPixmap>
#include <iostream>

#include <stdlib.h>
#include <time.h>

void MainWindow::proceed(){
    QObject * sender = QObject::sender();
    emit continue_pressed(sender->objectName());
}
void MainWindow::correct(bool correct){
    if (correct) set_image("correct/correct");
    else {
        set_image("correct/incorrect");
    }
    ui->push_label->setEnabled(true);
    QEventLoop loop;
    QObject button;
    button.setObjectName("X");
    connect(this, &MainWindow::continue_pressed, &loop, &QEventLoop::quit);
    connect(this, &MainWindow::continue_pressed, &button, &QObject::setObjectName);
    connect(ui->start_game, &QAbstractButton::pressed, &loop, &QEventLoop::quit);
    loop.exec();
    ui->push_label->setEnabled(false);
    if (button.objectName() != "X"){
        if (correct) play_the_game();
        else {
            start_the_game();
        }
    }
}

QString MainWindow::get_rand_name(){
    QString name = "o";
    srand (time(NULL));
    char octave = (char)(rand() % 3 + '1');
    char key;
    if (octave != '3') key = (char)(rand() % 7 + 'A');
    else key = (char)(rand() % 3 + 'C');
    name = name + octave + "_" + key;
    if (rand() % 2 == 0) {
        if (key != 'E' and key != 'B')
            name = name + "_sh";
    }
    return name;
}

void MainWindow::set_image(QString name){
    QString path = PROJECT_PATH;
    path = path + "/notes/" + name + ".png";
    QPixmap pm(path);
    ui->pictures->setPixmap(pm);
    ui->pictures->setScaledContents(true);


}

void MainWindow::play_the_game(){
    QString name = get_rand_name();
    set_image(name);
    QEventLoop loop;
    QObject button_name_new;
    button_name_new.setObjectName("X");
    connect(this, &MainWindow::button_pressed, &button_name_new, &QObject::setObjectName);
    connect(this, &MainWindow::button_pressed, &loop, &QEventLoop::quit);
    connect(ui->start_game, &QAbstractButton::pressed, &loop, &QEventLoop::quit);
    loop.exec();
    QString button_name = button_name_new.objectName();
    if (button_name == name){
        ui->score->setNum(ui->score->text().toInt() + 1);
        correct(true);
    }
    else if (button_name != "X"){
        correct(false);
    }

}
void MainWindow::start_the_game(){
    if (ui->start_game->text() == "Start the game"){
        ui->start_game->setText("Forfeit the game");
        play_the_game();
    }
    else {
        set_image("start_screen");
        if (ui->score->text().toInt() > ui->high_score->text().toInt()){
            ui->high_score->setNum(ui->score->text().toInt());
        }
        ui->score->setNum(0);
        ui->start_game->setText("Start the game");
    }
}




