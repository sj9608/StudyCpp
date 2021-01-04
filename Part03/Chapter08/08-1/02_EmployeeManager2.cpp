#include <iostream>
#include <cstring>
using namespace std;

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
        cout << "salary : " << salary << endl;
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
            /*
            empList[i]->ShowSalaryInfo();
            */
        }
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for(int i = 0; i < empNum; i++)
        {/*
            sum += empList[i]->GetPay();*/
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
    // 직원관리 목적으로 설계된 컨트롤 클래스의 생성
    EmployeeHandler handler;

    // 직원등록
    handler.AddEmployee(new PermanentWorker("Lee", 1000));
    handler.AddEmployee(new PermanentWorker("Kim", 2000));
    handler.AddEmployee(new PermanentWorker("Hong", 3000));

    // 이번달 지불해야할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번달 지불해야할 급여의 총합
    handler.ShowTotalSalary();
    
    return 0;   
}