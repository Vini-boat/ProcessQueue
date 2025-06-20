#ifndef COMPUTINGPROCESS_H
#define COMPUTINGPROCESS_H
#include "../../include/processes/process.hpp"
#include <iostream>
#include "../../include/mathExpression.hpp"

class ComputingProcess : public Process
{
    public:
        ComputingProcess(int pid, MathExpression expression);
        void execute() override;
        string toString() override;

        //friend ostream& operator<<(ostream& os, const ComputingProcess& process);

    private:
        MathExpression expression;
};

#endif
