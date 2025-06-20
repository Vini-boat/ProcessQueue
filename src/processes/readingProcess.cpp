#ifndef READINGPROCESS_C
#define READINGPROCESS_C
#include <string>
#include <fstream>
#include <sstream>
#include "../../include/processes/readingProcess.hpp"
#include "../../include/processqueue.hpp"

using namespace std;


ReadingProcess::ReadingProcess(int pid, ProcessQueue* queue)
{
    this->pid = pid;
    this->queue = queue;
}

// ostream& operator<<(ostream& os, const ReadingProcess& process)
// {
//     os << "C " << process.a << " " << process.operation << " " << process.b;
//     return os;
// }

void ReadingProcess::execute()
{
    string line;
    ifstream file("expressions.txt");

    while(getline(file,line))
    {
        stringstream ss(line);
        int a,b;
        char op;
        ss >> a >> op >> b;
        MathExpression exp(a, b, MathExpression::toOperation(op));
        queue->addComputingProcess(exp);
    }
    file.close();
    ofstream clear("expressions.txt", ios::trunc);
    clear.close();
}

string ReadingProcess::toString()
{
    return "Reading - PID: " + to_string(pid);
}

#endif
