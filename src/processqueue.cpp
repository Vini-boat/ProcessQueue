#ifndef PROCESSQUEUE_C
#define PROCESSQUEUE_C
#include "processqueue.hpp"
#include "datastructures/queue.hpp"
#include "processes/process.hpp"
#include "mathExpression.hpp"

#include "processes/computingProcess.hpp"
#include "processes/writingProcess.hpp"
#include "processes/readingProcess.hpp"
#include "processes/printingProcess.hpp"

#include <string>

using namespace std;
ProcessQueue::ProcessQueue()
{
    current_pid = 0;
}

ProcessQueue::~ProcessQueue()
{
    //TODO: 
}



#endif