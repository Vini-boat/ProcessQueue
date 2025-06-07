#ifndef MATHEXPRESSION_C
#define MATHEXPRESSION_C
#include "mathExpression.hpp"
#include <stdexcept>

MathExpression::MathExpression(int a, int b, MathExpression::Operation operation)
{
    if (operation == Operation::DIVISION && b == 0)
        throw std::invalid_argument("Division by zero is not allowed.");
    this->a = a;
    this->b = b;
    this->operation = operation;
}

int MathExpression::eval()
{
    switch (operation)
    {
    case Operation::ADDITION:
        return a + b;
    case Operation::SUBTRACTION:
        return a - b;
    case Operation::MULTIPLICATION:
        return a * b;
    case Operation::DIVISION:
        return a / b;
}

#endif