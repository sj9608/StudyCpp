#include <iostream>
#include <cstring>
#include "Calculator.h"
using namespace std;

float Calculator::Add(float numA, float numB)
{
    opCountAdd += 1;
    return (numA + numB);
}
float Calculator::Min(float numA, float numB)
{
    opCountMin += 1;
    return (numA - numB);
}
float Calculator::Mul(float numA, float numB)
{
    opCountMul += 1;
    return (numA * numB);
}
float Calculator::Div(float numA, float numB)
{
    opCountDiv += 1;
    return (numA / numB);
}

void Calculator::Init()
{
    opCountAdd = 0;
    opCountMin = 0;
    opCountMul = 0;
    opCountDiv = 0;
}

void Calculator::ShowOpCount()
{
    cout << "덧셈 : " << opCountAdd <<
    " 뺄셈 : " << opCountMin <<
    " 곱셈 : " << opCountMul <<
    " 나눗셈 : " << opCountDiv << endl;
}