#include "mainwindow.h"
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //状态栏
    QStatusBar *sBar = statusBar();     //初始化状态栏
    QLabel *label = new QLabel(this);       //初始化标签
    label->setText("Normal text file");     //给标签添加内容
    sBar->addWidget(label);     //从左往右添加
    sBar->addWidget(new QLabel("2",this));
    sBar->addPermanentWidget(new QLabel("3",this));     //从右往左添加内容

    //核心控件
    QTextEdit *textEdit = new QTextEdit(this);  //初始化一个核心控件
    setCentralWidget(textEdit);     //设置中心窗口控件

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);      //初始化浮动窗口
    addDockWidget(Qt::RightDockWidgetArea,dock);     //设置到右边

    QTextEdit *textEdit1 = new QTextEdit(this);     //添加一个文本框
    dock->setWidget(textEdit1);
}

MainWindow::~MainWindow()
{

}
