#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H

class MathExpression
{
    public:
        enum class Operation {
        ADDITION = '+',
        SUBTRACTION = '-',
        MULTIPLICATION = '*',
        DIVISION = '/'
    };
    MathExpression(int a, int b, MathExpression::Operation operation);
    int eval();
};

#endif