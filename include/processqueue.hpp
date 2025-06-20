#ifndef PROCESSQUEUE_H
#define PROCESSQUEUE_H
#include "datastructures/queue.hpp"
#include "processes/process.hpp"
#include "mathExpression.hpp"
#include <string>

using namespace std;
class ProcessQueue
{
    public:
        ProcessQueue();
        ~ProcessQueue();
        
        void addComputingProcess(MathExpression);
        void addWritingProcess(MathExpression);
        void addReadingProcess();
        void addPrintingProcess();
        
        void executeNext();
        void executeByPID(int pid);

        void saveToFile(const string& filename);
        void loadFromFile(const string& filename);
        void printQueue();
    private:
        Queue<Process*> queue;
        int current_pid;

};

#endif