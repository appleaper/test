#include "mainwindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");

    QAction *p3 = menu->addAction("关于对话框");
    connect(p3,&QAction::triggered,[=](){
        QMessageBox::about(this,"about","关于");
    });

    QAction *p4 = menu->addAction("问答对话框");
    connect(p4,&QAction::triggered,[=](){
        int ret = QMessageBox::question(this,"question","Are you ok?");
        switch (ret) {
        case QMessageBox::Yes:
            qDebug()<<"i am ok";
            break;
        case QMessageBox::No:
            qDebug()<<"i am bad";
            break;
        default:
            break;
        }
    });

    QAction *p5 = menu->addAction("文件对话框");
    connect(p5,&QAction::triggered,[=](){
        QString path = QFileDialog::getOpenFileName(this,"open","./","souce(*.cpp *.h);;Text(*.txt);;all(*.*)");
        qDebug()<<path;
    });
}

MainWindow::~MainWindow()
{

}
