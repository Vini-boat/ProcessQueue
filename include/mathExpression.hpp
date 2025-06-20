#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H
#include <string>

using namespace std;
class MathExpression
{
    public:
        enum class Operation {
        ADDITION = '+',
        SUBTRACTION = '-',
        MULTIPLICATION = '*',
        DIVISION = '/'
        };
        MathExpression();
        MathExpression(int a, int b, MathExpression::Operation operation);
        void setA(int a);
        void setB(int b);
        void setOperation(MathExpression::Operation operation);

        string toString();
        int eval();
        static bool isValidOperation(char c);
        static Operation toOperation(char c);
    private:
        int a;
        int b;
        MathExpression::Operation operation;
};

#endif
