#include <iostream>
#include <cstring>
#include "Printer.h"

void Printer::SetString(char *str)
{
    strcpy(strArr, str);
}

void Printer::ShowString()
{
    std::cout << strArr << std::endl;
}