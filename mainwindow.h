#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmetaobject.h"

#include "qdebug.h"
#include <mutex>
#include <thread>
#include <condition_variable>

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
    void on_pushButton_clicked();

private:
    int AddValue =0;
    Ui::MainWindow *ui;
    mutex m_mutex;
    void Run(int i);
};

#endif // MAINWINDOW_H
