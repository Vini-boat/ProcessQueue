#ifndef MATHEXPRESSION_C
#define MATHEXPRESSION_C
#include "../include/mathExpression.hpp"
#include <stdexcept>

using namespace std;
MathExpression::MathExpression()
{
    a = 0;
    b = 0;
    operation = Operation::ADDITION;
}

MathExpression::MathExpression(int a, int b, MathExpression::Operation operation)
{
    if (operation == Operation::DIVISION && b == 0)
        throw std::invalid_argument("Division by zero is not allowed.");
    this->a = a;
    this->b = b;
    this->operation = operation;
}

void MathExpression::setA(int a)
{
    this->a = a;
}

void MathExpression::setB(int b)
{
    this->b = b;
}

void MathExpression::setOperation(MathExpression::Operation operation)
{
    this->operation = operation;
}

int MathExpression::eval()
{
    switch (operation)
    {
    case Operation::ADDITION:
        return a + b;
        break;
    case Operation::SUBTRACTION:
        return a - b;
        break;
    case Operation::MULTIPLICATION:
        return a * b;
        break;
    case Operation::DIVISION:
        return a / b;
        break;
    default:
        return 0;
    }
}

bool MathExpression::isValidOperation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

MathExpression::Operation MathExpression::toOperation(char c) {
    if (!isValidOperation(c))
        throw std::invalid_argument("Operação inválida");

    return static_cast<MathExpression::Operation>(c);
}

string MathExpression::toString()
{
    return to_string(a) + " " + static_cast<char>(operation) + " " + to_string(b);
}


#endif
