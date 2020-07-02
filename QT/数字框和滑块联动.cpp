#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    void (QSpinBox::*sigValueChange)(int) = &QSpinBox::valueChanged;    //只要数字改变
    connect(ui->spinBox,sigValueChange,ui->horizontalSlider,&QSlider::setValue);    //数字表改变，滑块也改变
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);   //滑块改变，数字表也改变
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetValue(int value){
    if(value>0 && value<100){
        ui->spinBox->setValue(value);
    }
}

int MainWindow::getValue(){
    return ui->spinBox->value();
}
