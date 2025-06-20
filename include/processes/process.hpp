#ifndef PROCESS_H
#define PROCESS_H
#include <string>
using namespace std;
class Process
{
    public:
    int getPid();
    virtual void execute() = 0;
    virtual string toString() = 0;
    protected:
    int pid;
};

#endif