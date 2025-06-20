#ifndef COMPUTINGPROCESS_C
#define COMPUTINGPROCESS_C
#include "../../include/processes/computingProcess.hpp"
#include "../../include/mathExpression.hpp"
#include <string>

#include <iostream>
using namespace std;

ComputingProcess::ComputingProcess(int pid, MathExpression expression)
{
    this->pid = pid;
    this->expression = expression;
}

// ostream& operator<<(ostream& os, const ComputingProcess& process)
// {
//     os << "C " << process.a << " " << process.operation << " " << process.b;
//     return os;
// }

void ComputingProcess::execute()
{
    int result = expression.eval();
    std::cout << "Process " << pid << " result: " << result << std::endl;
    char t;
    cin >> t;
}

string ComputingProcess::toString()
{
    return "Computing - PID: " + to_string(pid) + ", Expression: " + expression.toString();
}

#endif
