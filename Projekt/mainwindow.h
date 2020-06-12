#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>         //moja biblioteka
#include <QAbstractButton>
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    void f_o1_o2_o3();
    void ChangeVol();
    void play_sound(QAbstractButton * button);

    void set_image(QString name);
    void start_the_game();
    void play_the_game();
    QString get_rand_name();
    void correct(bool correct);
    void proceed();

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

signals:
    void button_pressed(QString button_name);
    void continue_pressed(QString button_name);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
