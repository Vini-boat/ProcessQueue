#ifndef PROCESS_C
#define PROCESS_C
#include "process.hpp"

Process::Process(int pid)
{
    this->pid = pid;
}

int Process::getPid()
{
    return pid;
}


#endif