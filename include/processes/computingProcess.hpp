#ifndef COMPUTINGPROCESS_H
#define COMPUTINGPROCESS_H
#include "processes/process.hpp"
#include <iostream>
#include "mathExpression.hpp"

class ComputingProcess : public Process
{
    public:
        ComputingProcess(int pid, int a, int b, MathExpression::Operation operation);
        void execute() override;
        
        //friend ostream& operator<<(ostream& os, const ComputingProcess& process);
    
    private:
        MathExpression* expression;
};

#endif