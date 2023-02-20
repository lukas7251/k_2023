#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    QString Number1,Number2;
    QPushButton *N1;

    int state;
    float result;
    short operand;

    void numberClickedHandler();
    void clearAndEnterClickHandler();
    void addSubMulDiv();

};
#endif // MAINWINDOW_H

