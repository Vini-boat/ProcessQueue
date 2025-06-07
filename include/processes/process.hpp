#ifndef PROCESS_H
#define PROCESS_H

class Process
{
    public:
    int getPid();
    virtual void execute() = 0;
    
    protected:
    int pid;
};

#endif