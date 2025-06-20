#ifndef WRITINGPROCESS_C
#define WRITINGPROCESS_C
#include <string>
#include "../../include/processes/writingProcess.hpp"
#include <iostream>
#include <fstream>
using namespace std;

WritingProcess::WritingProcess(int pid, MathExpression expression)
{
    this->pid = pid;
    this->expression = expression;
}

// ostream& operator<<(ostream& os, const WritingProcess& process)
// {
//     os << "C " << process.a << " " << process.operation << " " << process.b;
//     return os;
// }

void WritingProcess::execute()
{
    ofstream file("expressions.txt",ios::app);
    file << expression.toString() << endl;
    file.close();
}

string WritingProcess::toString()
{
    return "Writing - PID: " + to_string(pid) + ", Expression: " + expression.toString();
}
#endif
