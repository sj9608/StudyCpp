문제 08-1 [상속 관계의 확장과 추상 클래스]
---
08-2 예제 03_EmployeeManager4.cpp 를 확장하여 다음 특성에 해당하는 ForeginSalesWorker 클래스를 추가로 정의해보자.
> "영업직 직원중 일부는 오지산간으로 시장개척을 진행하고 있다. 일부는 아마존, 또 일부는 테러위험이 있는 지역에서 영업활동을 진행중이다. 따라서 이러한 직원들을 대상으로 별도의 위험수당을 지급하고자 한다."

위험수당 지급방식은 '위험 노출도' 에 따라서 다음과 같이 나뉘며, 한번 결정된 직원의 '위험 노출도'는 변경되지 않는다고 가정한다 (이는 const 멤버변수의 선언을 유도)
* 리스크 A : 영업직의 기본급여 + 인센티브 합계 총액의 30% 추가 지급
* 리스크 B : 영업직의 기본급여 + 인센티브 합계 총액의 20% 추가 지급
* 리스크 C : 영업직의 기본급여 + 인센티브 합계 총액의 10% 추가 지급

다음의 main 함수와 함께 동작하도록 ForeignSalesWorker 클래스를 정의하기 바라며, Employee 클래스는 객체 생성이 불가능한 추상 클래스로 정의하기 바란다.

**[main 함수]**
``` C++
int main(void)
{
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 생성
    EmployeeHandler handler;

    // 해외 영업직 등록
    ForeginSalesWorker * fseller1 = new ForeginSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::A);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller1);
    
    ForeginSalesWorker * fseller2 = new ForeginSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::B);
    fseller2->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller2);
    
    ForeginSalesWorker * fseller3 = new ForeginSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::C);
    fseller3->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller3);

    // 이번달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    return 0;
}

```
[실행 결과]
``` bash
name : Hong
salary : 1700
risk pay : 510
sum : 2210

name : Yoon
salary : 1700
risk pay : 340
sum : 2040

name : Lee
salary : 1700
risk pay : 170
sum : 1870
```