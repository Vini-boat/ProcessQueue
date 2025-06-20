#ifndef PRINTINGPROCESS_C
#define PRINTINGPROCESS_C
#include "../../include/processes/printingProcess.hpp"
#include "../../include/processQueue.hpp"
#include "../../include/mathExpression.hpp"

#include <iostream>

PrintingProcess::PrintingProcess(int pid, ProcessQueue* queue)
{
    this->pid = pid;
    this->queue = queue;
}

// ostream& operator<<(ostream& os, const PrintingProcess& process)
// {
//     os << "C " << process.a << " " << process.operation << " " << process.b;
//     return os;
// }

void PrintingProcess::execute()
{
    queue->printQueue();
}

string PrintingProcess::toString()
{
    return "Printing - PID: " + to_string(pid);
}

#endif
