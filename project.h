#ifndef PROJECT_H
#define PROJECT_H

#include <QDebug>

#include <thread>
#include <mutex>
#include <iostream>
#include "projectmanager.h"

using namespace std;

class Project
{
public:
    Project();
    ~Project();
    void DoProjectAnsyc(int &Count);
private:
    mutex m_mutex;//A lock to avoid mutil-thread race condition.
    //It'll check who's lock. If Lock twice by same Thread,it's will pass laster lock.
    //Maybe we can change program design to not use recursive mutex.
    recursive_mutex m_recursiveMutex;



    void PlanA(int &Count);
    void PlanAPlus(int *Count);
    void PrePlanB();
    void PlanB();
};

#endif // PROJECT_H
