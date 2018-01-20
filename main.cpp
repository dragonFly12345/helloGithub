/***********************************/
/*
 * 练习工程
 * 1.添加动作
 * 2.菜单栏、工具栏和状态栏
 * 3.对话框：分为模式和非模式两种，模式对话框阻塞同一应用程序中其他窗口的输入
*/
/***********************************/
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    MainWindow w;
//    QLabel label("Hello,Qt!");
//    label.show();

//    QPushButton button("Quit");
//    QObject::connect(&button,&QPushButton::clicked,&QApplication::quit);
//    button.show();

//    QPushButton button("Quit");
//    QObject::connect(&button,&QPushButton::clicked,[](bool){qDebug() << "You clicked me!";});
//    button.show();

    return a.exec();
}
