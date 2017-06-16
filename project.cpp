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
void Project::DoProjectAnsyc()
{
    std::thread th(&Project::PlanA,this);
    if(th.joinable())
        th.detach();//Background Thread
    //
    // auto handle = std::async(std::launch::async, &Project::PlanA, this);
}


void Project::PlanA()
{
    m_mutex.lock();
    qDebug() << "Start";
    for(int i=0;i<5;i++)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Thread ID:" <<this_thread::get_id() << " Say " << i << "\n";

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
