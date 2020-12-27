#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

class Calculator
{
private:
    int opCountAdd;
    int opCountMin;
    int opCountMul;
    int opCountDiv;

public:
    void Init();
    void ShowOpCount();
    float Add(float numA, float numB);
    float Min(float numA, float numB);
    float Mul(float numA, float numB);
    float Div(float numA, float numB);
};
#endif