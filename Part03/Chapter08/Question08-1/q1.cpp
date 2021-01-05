#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
    enum {RISK_A = 3, RISK_B = 2, RISK_C = 1 };
}

class Employee
{
private:
    char name[100];
public:
    Employee(char * name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name : " << name << endl;
    }
    virtual int GetPay() const { return 0; }
    virtual void ShowSalaryInfo() const { }
};

class PermanentWorker : public Employee
{
private:
    int salary; // 월 급여
public:
    PermanentWorker(char * name, int money)
        : Employee(name), salary(money)
    { }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary : " << salary << endl << endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime; // 일한 시간
    int payPerHour; // 시간당급여
public:
    TemporaryWorker(char * name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const // 함수 오버라이딩
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const // 함수 오버라이딩
    {
        ShowYourName();
        cout << "salary : " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult; // 월 판매실적
    double bonusRatio; // 상여금 비율
public:
    SalesWorker(char * name, int money, double ratio)
        : PermanentWorker(name, money), bonusRatio(ratio)
    { }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const // 함수 오버라이딩
    {
        return PermanentWorker::GetPay() // PermanentWorker의 GetPay 함수 호출
                        + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary : " << GetPay() << endl << endl; // SalesWorker의 GetPay 함수 호출
    }
};

class ForeignSalesWorker : public SalesWorker
{
private:
    int riskLevel;
public:
    ForeignSalesWorker(char * name, int money, double ratio, int rLevel)
        : SalesWorker(name, money, ratio), riskLevel(rLevel)
    { }
    int GetRiskPay() const
    {
        return (int)SalesWorker::GetPay() * 0.1 * riskLevel;
    }
    int GetPay() const 
    {
        return SalesWorker::GetPay() + GetRiskPay();
    }
    
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary : " << SalesWorker::GetPay() << endl;
        cout << "risk pay : " << GetRiskPay() << endl;
        cout << "sum : " << GetPay() << endl << endl;

    }
};
class EmployeeHandler
{
private:
    Employee * empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    { }
    void AddEmployee(Employee * emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i = 0; i < empNum; i++)
        {
            empList[i]->ShowSalaryInfo();
        }
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for(int i = 0; i < empNum; i++)
        {
            sum += empList[i]->GetPay();
        }
        cout << "Total Salary is : " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for(int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
    }
};

int main(void)
{
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 생성
    EmployeeHandler handler;

    // 해외 영업직 등록
    ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller1);
    
    ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller2);
    
    ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller3);

    // 이번달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    return 0;
}