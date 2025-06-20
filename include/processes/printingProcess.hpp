#ifndef PRINTINGPROCESS_H
#define PRINTINGPROCESS_H

#include "../../include/processes/process.hpp"
#include "../../include/processQueue.hpp"
#include <iostream>
#include <string>

using namespace std;
class PrintingProcess : public Process
{
    public:
        PrintingProcess(int pid, ProcessQueue* queue);
        void execute() override;
        string toString() override;

        //friend ostream& operator<<(ostream& os, const PrintingProcess& process);

    private:
    ProcessQueue* queue;
};


#endif
