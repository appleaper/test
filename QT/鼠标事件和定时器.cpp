#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QTimerEvent>
#include <QTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMouseTracking(true);   //设置鼠标跟踪
    id=startTimer(2000);            //2s后启动
    id1=startTimer(3000);           //3s后启动
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterEvent(QEvent *){      //鼠标进入窗口
    ui->label->setText("enter");
}

void MainWindow::leaveEvent(QEvent *){      //鼠标离开窗口
    ui->label->setText("leave");
}

void MainWindow::mousePressEvent(QMouseEvent *ev){      //鼠标按下事件
    QString btn;
    if(ev->button()==Qt::LeftButton){   //要是按下的键是左键
        btn="left_button";
    }
    else if(ev->button()==Qt::RightButton){     //要是按下的键是右键
        btn="right_button";
    }
    else if(ev->button()==Qt::MidButton){       //要是按下的键是中键
        btn="MidButton";
    }
    QString str = QString("MousePree[%3]:(%1,%2)").arg(ev->x()).arg(ev->y()).arg(btn);  //显示鼠标点击的位置x,y和左键右键中键其中一种
    ui->label_2->setText(str);
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev){   //鼠标移动事件
    QString btn;
    if(ev->button() & Qt::LeftButton){
        btn="left_button";
    }
    else if(ev->button() & Qt::RightButton){
        btn="right_button";
    }
    else if(ev->button() & Qt::MidButton){
        btn="MidButton";
    }
    QString str = QString("MouseMove[%3]:(%1,%2)").arg(ev->x()).arg(ev->y()).arg(btn);
    ui->label_3->setText(str);
}

void MainWindow::timerEvent(QTimerEvent *e){    //计时器事件
    QString str;
    if(e->timerId()==id){       //要是2s到了
        static int num = -100;  //初始化num
        str = QString("%1:%2").arg("Time out: ").arg(num++);        //让num++
        if(num>=-98){
            killTimer(id);      //计时器停止计时
        }
    }
    else if(e->timerId()==id1){     //第2个计时器，功能类似
        static int num1 = 10000;
        str = QString("%1:%2").arg("Time out: ").arg(num1++);
        if(num1>=10000+1000){
            killTimer(id1);
        }
    }
    ui->label_4->setText(str);
}
