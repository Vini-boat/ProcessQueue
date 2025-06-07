#ifndef COMPUTINGPROCESS_C
#define COMPUTINGPROCESS_C
#include "processes/computingProcess.hpp"
#include "mathExpression.hpp"

#include <iostream>

ComputingProcess::ComputingProcess(int pid, int a, int b, MathExpression::Operation operation)
{
    this->pid = pid;
    this->expression = new MathExpression(a, b, operation);
}

// ostream& operator<<(ostream& os, const ComputingProcess& process)
// {
//     os << "C " << process.a << " " << process.operation << " " << process.b;
//     return os;
// }

void ComputingProcess::execute()
{

}

#endif