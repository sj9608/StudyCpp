#include <iostream>
using namespace std;

template <class T>

T SumArray(T arr[], int len)
{
    T sum = 0;
    for(int i = 0; i < len ; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    double arr[5] = { 1.2, 2.4, 3.5, 4.5, 5.6 };
    cout << SumArray<double>(arr, 5) << endl;

    return 0;
}