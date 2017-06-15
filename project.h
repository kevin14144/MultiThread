#ifndef PROJECT_H
#define PROJECT_H

#include <thread>
#include <mutex>
using namespace std;

class Project
{
public:
    Project();
    void DoProject();
private:
    mutex m_mutex;
    void PlanA();
};

#endif // PROJECT_H
