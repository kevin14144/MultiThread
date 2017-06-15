#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Run(int i)
{
    //one thread in and lock
    //m_mutex.lock();
    lock_guard<mutex> mLock( m_mutex ); // Auto unlock
    while(true)
    {

        i++;
        if(i>100)
        {
            //Finish and unlock to let other thread in
            //m_mutex.unlock();
            break;
        }
        else
        {
            AddValue++;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            //unsigned num_cpus = std::thread::hardware_concurrency();
            ui->label->setText(QString::number(AddValue));
        }


    }


}


void MainWindow::on_pushButton_clicked()
{
    int i =0;
    std::thread th(&MainWindow::Run,this,i);

    if(th.joinable())
        th.detach();
}
