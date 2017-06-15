#include "project.h"

Project::Project()
{

}

void Project::DoProject()
{
    thread th(&Project::PlanA,this);
    if(th.joinable())
        th.detach();
}

void Project::PlanA()
{
    int i = 0;
    while(true)
    {
        i++;
        if(i>5000)
            i=0;
        m_mutex.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        m_mutex.unlock();
    }

}
