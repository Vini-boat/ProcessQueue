#ifndef PROCESS_H
#define PROCESS_H

class Process
{
    public:
    Process(int pid);
    int getPid();
    virtual void execute() = 0;
    
    private:
    int pid;
};

#endif