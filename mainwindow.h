#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdebug.h>
//Std
#include <mutex>
#include <thread>
//
#include "project.h"

namespace Ui {
class MainWindow;
}

using namespace std;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_RunMainFormFunction_clicked();
    void on_RunClassFunction_clicked();

private:
    int SumValue =0;
    Ui::MainWindow *ui;
    mutex m_mutex;
    void Run(int i);

};

#endif // MAINWINDOW_H
