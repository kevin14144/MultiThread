#include "project.h"
#include <future>
Project::Project()
{

}

Project::~Project()
{

}

///
/// \brief Do something.
///
void Project::DoProjectAnsyc(int& Count)
{

    std::thread th(&Project::PlanA,this,std::ref(Count));//Pass by reference
    if(th.joinable())
        th.detach();//Background Thread
    std::thread th2(&Project::PlanAPlus,this,&Count);//Pass by Pointer
    if(th2.joinable())
        th2.detach();//Background Thread
    //
    // auto handle = std::async(std::launch::async, &Project::PlanA, this);
}


void Project::PlanA(int& Count)
{
    m_mutex.lock();
    qDebug() << "PlanA Start";
    for(int i=0;i<50;i++)
    {
        Count++;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Thread ID:" <<this_thread::get_id() << " Say " << i << "\n";
    }
    m_mutex.unlock();
}

void Project::PlanAPlus(int *Count)
{

    m_mutex.lock();
    qDebug() << "PlanAPlus Start";
    for(int i=0;i<50;i++)
    {
        (*Count)++;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Thread ID:" << this_thread::get_id() << " Say " << i << "\n";
    }
    m_mutex.unlock();
}



void Project::PrePlanB()
{
    lock_guard<recursive_mutex> mLock(m_recursiveMutex);
    PlanB();
}

void Project::PlanB()
{
    lock_guard<recursive_mutex> mLock(m_recursiveMutex);
    qDebug() << "Start";
    for(int i=0;i<5;i++)
    {

        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Thread ID:" <<this_thread::get_id() << " Say " << i << "\n";

    }
}
