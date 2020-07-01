#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");
    QAction *p1 = menu->addAction("模态对话框");     //必须先处理完当前窗口才能继续操作其他窗口
    connect(p1,&QAction::triggered,[=](){
        QDialog dlg;
        dlg.exec();
        qDebug()<<"11111";
    });

    QAction *p2 = menu->addAction("非模态对话框");    //当前窗口和其他窗口都能动作
    connect(p2,&QAction::triggered,[=](){
       dlg.show();              //因为这里的变量是全局变量，不会被局部回收，所以不会出现没有对话框的情况
       qDebug()<<"222222";
    });

    QAction *p3 = menu->addAction("非模态对话框2");    //当前窗口和其他窗口都能动作
    connect(p3,&QAction::triggered,[=](){
       QDialog *p = new QDialog;
       p->setAttribute(Qt::WA_DeleteOnClose);   //关闭窗口的时候才才释放*p，所以能显示出对话框
       p->show();
    });

}

MainWindow::~MainWindow()
{

}
