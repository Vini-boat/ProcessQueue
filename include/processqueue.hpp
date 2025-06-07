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
        
        void addComputingProcess(int a, int b, MathExpression::Operation operation);
        void addWritingProcess(int a, int b, MathExpression::Operation operation);
        void addReadingProcess();
        void addPrintingProcess();
        
        void executeNext();
        void executeByPID(int pid);

        void saveToFile(const string& filename);
        void loadFromFile(const string& filename);
        
    private:
        Queue<Process*> queue;
        int current_pid;

};

#endif