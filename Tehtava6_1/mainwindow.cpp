#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton1, &QPushButton::clicked, this, &MainWindow::count);
    connect(ui->pushButton2, &QPushButton::clicked, this, &MainWindow::reset);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::count()
{
    int number = ui->lineEdit->text().toInt();
    number++;
    ui->lineEdit->setText(QString::number(number));
}

void MainWindow::reset()
{
    ui->lineEdit->setText("0");
}



