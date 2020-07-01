//mainwindow.cpp

#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();     //初始化菜单栏
    QMenu *pFile = mBar->addMenu("文件");     //菜单栏添加具体项
    QAction *pNew = pFile->addAction("新建");     //具体项添加具体功能
    connect(pNew,&QAction::triggered,   //具体功能的具体效果
            [=](){
        qDebug()<<"新建被按下";
    });
    pFile->addSeparator();  //添加分割线
    QAction *pOpen = pFile->addAction("打开");        //在菜单栏多添加一个功能
    //工具栏，菜单项快捷方式
    QToolBar *toolBar = addToolBar("toolBar");      //添加工具栏
    toolBar->addAction(pNew);       //将具体功能添加到工具栏中

    QPushButton *b = new QPushButton(this);     //添加一个按钮
    b->setText("^-^");      //设置按钮的内容
    toolBar->addWidget(b);      //在工具栏添加这个按钮
    connect(b,&QPushButton::clicked,        //按钮的具体效果
            [=](){
        b->setText("123");
    });
}

MainWindow::~MainWindow()
{

}
