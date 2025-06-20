#ifndef PROCESSQUEUE_C
#define PROCESSQUEUE_C
#include "../include/processqueue.hpp"
#include "../include/datastructures/queue.hpp"
#include "../include/processes/process.hpp"
#include "../include/mathExpression.hpp"

#include "../include/processes/computingProcess.hpp"
#include "../include/processes/writingProcess.hpp"
#include "../include/processes/readingProcess.hpp"
#include "../include/processes/printingProcess.hpp"

#include <fstream>
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

void ProcessQueue::addComputingProcess(MathExpression expression)
{
    Process* proc = new ComputingProcess(current_pid++, expression);
    queue.push(proc);
}

void ProcessQueue::addWritingProcess(MathExpression expression)
{
    Process* proc = new WritingProcess(current_pid++, expression);
    queue.push(proc);
}

void ProcessQueue::addReadingProcess()
{
    Process* proc = new ReadingProcess(current_pid++, this);
    queue.push(proc);
}

void ProcessQueue::addPrintingProcess()
{
    Process* proc = new PrintingProcess(current_pid++, this);
    queue.push(proc);
}

void ProcessQueue::executeNext()
{
    if (queue.isEmpty()) {
        return;
    }
    Process* proc = queue.pop();
    proc->execute();
    delete proc;
}

void ProcessQueue::executeByPID(int pid)
{
    bool found = false;
    Process* proc_to_execute;
    Queue<Process*> tempQueue;
    while(!queue.isEmpty()) {
        Process* proc = queue.pop();

        if(proc->getPid() == pid)
        {
            found = true;
            proc_to_execute = proc;
            continue;
        }

        tempQueue.push(proc);
    }
    while(!tempQueue.isEmpty()) {
        queue.push(tempQueue.pop());
    }
    proc_to_execute->execute();
    delete proc_to_execute;
    char t;
    cin >> t;
}

void ProcessQueue::saveToFile(const string& filename)
{
    ofstream file("filas/" + filename + ".txt",ios::app);

    Queue<Process*> tempQueue;
    while(!queue.isEmpty()) {
        Process* proc = queue.pop();
        file << proc->toString() << endl;
        tempQueue.push(proc);
    }
    while(!tempQueue.isEmpty()) {
        queue.push(tempQueue.pop());
    }
    file.close();
}

void ProcessQueue::loadFromFile(const string& filename)
{
    ifstream file("filas/" + filename + ".txt");
    string line;

    while(getline(file, line))
    {
        if (line.find("Computing") == 0) {
            int a, b;
            char op;
            if (sscanf(line.c_str(), "Computing - PID: %*d, Expression: %d %c %d", &a, &op, &b) == 3) {
                MathExpression expr(a, b, MathExpression::toOperation(op));
                this->addComputingProcess(expr);
            }
        } else if (line.find("Writing") == 0) {
            int a, b;
            char op;
            if (sscanf(line.c_str(), "Writing - PID: %*d, Expression: %d %c %d", &a, &op, &b) == 3) {
                MathExpression expr(a, b, MathExpression::toOperation(op));
                this->addWritingProcess(expr);
            }
        } else if (line.find("Reading") == 0) {
            this->addReadingProcess();
        } else if (line.find("Printing") == 0) {
            this->addPrintingProcess();
        }
    }
}

void ProcessQueue::printQueue()
{
    Queue<Process*> tempQueue;
    while(!queue.isEmpty()) {
        Process* proc = queue.pop();
        cout << proc->toString() << endl;
        tempQueue.push(proc);
    }
    while(!tempQueue.isEmpty()) {
        queue.push(tempQueue.pop());
    }
    char t;
    cin >> t;
}

#endif
