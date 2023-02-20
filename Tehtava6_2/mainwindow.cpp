#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    state = 1;

    N1 = new QPushButton();

    connect(ui->N1, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N3, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N4, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N5, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N6, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N7, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N8, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N9, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N0, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);

    connect(ui->add, &QPushButton::clicked,
            this, &MainWindow::addSubMulDiv);
    connect(ui->sub, &QPushButton::clicked,
            this, &MainWindow::addSubMulDiv);
    connect(ui->mul, &QPushButton::clicked,
            this, &MainWindow::addSubMulDiv);
    connect(ui->div, &QPushButton::clicked,
            this, &MainWindow::addSubMulDiv);

    connect(ui->clear, &QPushButton::clicked,
            this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->enter, &QPushButton::clicked,
            this, &MainWindow::clearAndEnterClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{


    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString number = button->text();
    qDebug() << "Button name:" << number;
    if(operand == -1) {
        ui->Number1->clear();
        ui->Number2->clear();
        ui->Result->clear();
        state = 1;
    }

    if(state==1){
        Number1=number;
        ui->Number1->setText(number);
    }
    if(state==2){
        Number2=number;
        ui->Number2->setText(number);
    }

}

void MainWindow::addSubMulDiv()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString operation = button->text();
    qDebug() << "Button name:" << operation<< "operand:"<<operand;
    operand=-1;

    if(operation=="+"){
        operand=0;
        state=2;

    }else if(operation=="-"){
            operand=1;
            state=2;

    }else if(operation=="*"){
            operand=2;
            state=2;

    }else if(operation=="/"){
            operand=3;
            state=2;
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString clearAndEnter = button->text();
    qDebug() << "Button name:" << clearAndEnter << "result:" << result;

    result = 0.0;
    if(clearAndEnter=="enter"){

       float num1 = Number1.toFloat();
       qDebug() << "num1:" << num1;

       float num2 = Number2.toFloat();
       qDebug() << "num2:" << num2;

       if(operand==0){
            result = num1 + num2;
        }
       if(operand==1){
            result = num1 - num2;
        }
       if(operand==2){
            result = num1 * num2;
        }
       if(operand==3){
            result = num1 / num2;
        }

       QString resultString=QString::number(result);
       ui->Result->setText(resultString);
    }

    if(clearAndEnter=="clear"){
        operand=-1;
    }
}
