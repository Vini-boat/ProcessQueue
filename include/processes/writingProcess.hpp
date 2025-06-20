#ifndef WRITINGPROCESS_H
#define WRITINGPROCESS_H
#include "../../include/processes/process.hpp"
#include "../../include/processQueue.hpp"
#include "../mathExpression.hpp"
#include <iostream>
#include <string>

class WritingProcess : public Process
{
    public:
        WritingProcess(int pid, MathExpression expression);
        void execute() override;
        string toString() override;

        //friend ostream& operator<<(ostream& os, const ComputingProcess& process);

    private:
        MathExpression expression;
};



#endif
