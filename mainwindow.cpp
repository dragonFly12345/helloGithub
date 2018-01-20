#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)     //构造函数，动作添加在了一个窗口的构造函数里面
    : QMainWindow(parent)
{
    setWindowTitle("Dragonfly123");

    /*************************/
    /*定义了一个动作*/
    /*************************/
    //定义动作的图标和名字。openAction是MainWindow类中的一个成员。
    openAction = new QAction(QIcon(":images/doc-open"),tr("&open..."),this);
//    openAction = new QAction(QIcon("D:\\software\\Qt\\5.9.3\\projects\\HelloQt\\document_open"),tr("&open..."),this);
    //定义动作的快捷键，此处即为Open的通用快捷键QKeySequence::Open（Ctrl+O）
    openAction->setShortcut(QKeySequence::Open);
    //定义动作的状态栏提示
    openAction->setStatusTip(tr("Open an existing file"));
    //定义动作触发的行为，此处即为调用open函数
    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    /*************************/
    /*定义了一个菜单*/
    /*************************/
    //函数menuBar()创建一个菜单栏对象并返回，名为File。注意Qmenu类在QMenuBar.h中，而menuBar()在QMainWindow类中。
    QMenu *file = menuBar()->addMenu(tr("&File"));
    //在创建的菜单中加入了动作open，动作的名字和快捷键将会显示
    file->addAction(openAction);

    /*************************/
    /*定义了一个工具条*/
    /*************************/
    //
    QToolBar *toolBar = addToolBar(tr("&File"));
    //在工具条中加入了动作
    toolBar->addAction(openAction);

//    QToolBar *toolBar2 = addToolBar(tr("Tool Bar 2"));
//    toolBar2->addAction(openAction);

    //一个动作可以加到菜单同时也可以加到工具条，具有一样的功能

    /*************************/
    /*定义了一个状态栏*/
    /*************************/
    //状态栏提示将会显示在状态栏上
    statusBar();
}

MainWindow::~MainWindow()
{

}

/*************************/
/*
 * 定义了一个对话框
 * 感觉还有一个比较大的收获，即变量建立在堆上和栈上的区别。
 * 临时变量等建立在栈上，使用和数据结构栈差不多的方式，退出有效区域即由系统自动析构
 * 而程序员分配的变量建立在堆上，不会被自动析构，如用new建立的变量
 * 不用exec()显示窗口，程序不会阻塞当前进程，因此如果窗口变量在栈上，show()和open()显示的窗口会立马退出程序进行析构，窗口只能停留一会
*/
/*************************/
void MainWindow::open()
{
    /**********************/
    /*建立一个对话框*/
    /**********************/
/*//    QMessageBox::information(this,tr("Information"),tr("Open"));
    QDialog *dialog = new QDialog; //未指定父指针的情况，建立主窗口，在任务栏会显示
//    QDialog dialog(this);   //指定了父指针
    dialog->setAttribute(Qt::WA_DeleteOnClose); //防止内存泄露
    dialog->setWindowTitle(tr("Hello Qt!"));
//    dialog->exec();  //应用程序级别的模式对话框
//    dialog->open();  //窗口级别的模式对话框
    dialog->show();  //非模式对话框
//    if(dialog->exec() == QDialog::Accepted){      //确定不确定的不同输出
//        qDebug() << "Accepted";
//    }
//    else{
//        qDebug() << "Failed";
//    }*/

    /**********************/
    /*建立一个message box*/
    /**********************/
    //建立一个Yes和No的对话框，其中第四个参数QMessageBox::Yes|QMessageBox::No指定对话框出现的按钮
    //这里类似用构造函数来构建对话框，不灵活
//    if(QMessageBox::Yes == QMessageBox::question(this,
//                                                 tr("Question"),
//                                                 tr("Are you OK?"),
//                                                 QMessageBox::No|QMessageBox::Yes,
//                                                 QMessageBox::Yes))
//    {
//        QMessageBox::information(this,tr("Hmmm..."),tr("I am glad to hear that"));
//    }
//    else
//    {
//        QMessageBox::information(this,tr("Hmmm..."),tr("I am sorry!"));
//    }

    /**********************/
    /*建立一个message box,询问是否保存*/
    /**********************/
    //采用成员函数一步步构建，更加灵活
    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
//    msgBox.setText(tr("文件已经被更改."));
    msgBox.setInformativeText(tr("Do you want to save your change?"));
    msgBox.setDetailedText(tr("Differences here..."));
    msgBox.setStandardButtons(QMessageBox::Save
                              |QMessageBox::Discard
                              |QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        qDebug() << "保存文件.";
        break;
    case QMessageBox::Discard:
        qDebug() << "Discard document.";
        break;
    case QMessageBox::Cancel:
        qDebug() << "Cancel document.";
        break;
    default:
        break;
    }
}
