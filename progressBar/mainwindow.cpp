#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QThread"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setValue(1);
    ui->horizontalSlider->setValue(1);
    ui->autoLabel->setText("");
    ui->startOverButton->setDisabled(true);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
    connect(ui->dial,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
    connect(ui->dial,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->dial,SLOT(setValue(int)));
    //connect(ui->horizontalSlider,SIGNAl(valueChange(int)),ui->progressBar,SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->horizontalSlider->setDisabled(true);
    ui->autoLabel->setText("Please Wait !! Auto Progress going on");
    ui->pushButton->setDisabled(true);
    ui->startOverButton->setDisabled(true);
    for(int i =0 ;i<101;i++){
        ui->progressBar->setValue(i);
        QThread::sleep(1);
    }
    QThread::sleep(2);
    ui->startOverButton->setDisabled(false);
    on_startOverButton_clicked();
}

void MainWindow::on_startOverButton_clicked()
{
    ui->horizontalSlider->setDisabled(false);
    ui->pushButton->setDisabled(false);
    ui->startOverButton->setDisabled(true);
    ui->progressBar->setValue(1);
    ui->horizontalSlider->setValue(1);
    ui->autoLabel->setText("");
}

void MainWindow::on_progressBar_valueChanged(int value)
{
    if(value ==100)
    {
        ui->showLabel->setText("Completed !! ");
        ui->startOverButton->setDisabled(false);
    }
    else{
        ui->showLabel->setText("");
        ui->startOverButton->setDisabled(true);
    }
}
