#include <iostream>
#include <cstring>

using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int n) : gasolineGauge(n)
    {

    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGague;
public:
    HybridCar(int gas, int n)
        : Car(gas), electricGague(n)
    {

    }
    int GetElecGauge()
    {
        return electricGague;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int gas, int elec, int water)
        : HybridCar(gas, elec), waterGauge(water)
    {
        
    }
    void ShowCurrentGague()
    {
        cout << "잔여 가솔린  : " << GetGasGauge() << endl;
        cout << "잔여 전기량  : " << GetElecGauge() << endl;
        cout << "잔여 워터량  : " << waterGauge << endl;
    }
};

int main(void)
{
    HybridWaterCar Watercar1(60, 50, 40);

    Watercar1.ShowCurrentGague();
    return 0;
}