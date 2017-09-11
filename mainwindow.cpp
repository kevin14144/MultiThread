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

///
/// \brief Test the std's thread across to the ui's thread.
/// \param i
///
void MainWindow::Run(int i)
{
    //one thread in and lock
    //m_mutex.lock();
    lock_guard<mutex> mLock(m_mutex); // Auto unlock when outside the scope
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
            SumValue++;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            //Check How many CPUs free to run.
            //unsigned num_cpus = std::thread::hardware_concurrency();
            ui->label->setText(QString::number(SumValue));
        }

    }

}

void MainWindow::on_RunMainFormFunction_clicked()
{
    int i = 0;
    std::thread th(&MainWindow::Run,this,i);//1 paramenter
    if(th.joinable())
        th.detach();//Background Thread
}


Project pr;//Must be alive always ,because thread maybe be using.
void MainWindow::on_RunClassFunction_clicked()
{
    int Count = 0;
    pr.DoProjectAnsyc(Count);

    while (Count<100)
    {
      ui->label->setText(QString::number(Count));
      qApp->processEvents();//Force to process event queue
    }
    qDebug()<< "Finish";

}

///
///Return Array by reference (in / out) , Fix num
///
int (&MainWindow::fillarr( int (&arr)[5]))[5]
{
    // no decay; argument must be size 5
    for( int i=0; i< 5; i++ )
        arr[i] = i;

    return arr;
}


///
/// \brief Return Array by Pointer. Need paramenter about array length.
/// \param arr
/// \param arrayLength
///
void MainWindow::fillarr( int* arr , int arrayLength)
{
    // no decay; argument must be size 5
    for( int i=0; i< arrayLength; i++ )
      arr[i] = i;
}

