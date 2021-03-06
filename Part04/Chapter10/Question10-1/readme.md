문제 10-1 [두 가지 방법의 연산자 오버로딩]
---
연산자 오버로딩을 이해하는 가장 좋은 방법은 연산자를 직접 오버로딩 해 보는 것이다. 연산자를 오버로딩 하는 과정에서 자신이 이해하지 못한 부분이 드러나면서, 그 부분을 이해하게 되는 경우가 많기 때문이다. 따라서 앞서 예제 GFunctionOverloading.cpp 에서 보인 Point 클래스를 대상으로 아래의 요구대로 연산자 오버로딩을 해보자.

#### 문제 1
Point 클래스에 대해서 다음 조건을 만족하는 형태로 - 연산자를 오버로딩 해보자.
✔ 전역함수 기반으로 오버로딩
✔ 멤버 별 - 연산의 결과를 담은 Point 객체 반환

#### 문제 2
Point 클래스에 대해서 다음 조건을 만족하는 형태로 += 연산자와 -= 연산자를 오버로딩 해보자.
✔ 멤버함수 기반으로 오버로딩
✔ 연산 'pos1 += pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값 만큼 멤버 별 증가
✔ 연산 'pos1 -= pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값 만큼 멤버 별 감소
✔ 연산의 결과로 값이 증가 및 감소한 pos1의 객체를 반환하도록 (이왕이면 참조형으로 반환 하도록) 연산자 오버로딩

#### 문제 3
Point 클래스에 대해서 다음 조건을 만족하는 형태로 == 연산자와 != 연산자를 오버로딩 해보자.
✔ 둘 다 전역함수의 형태로 오버로딩
✔ 연산 'pos1 == pos2'의 결과로 모든 멤버의 값이 같다면 true, 그렇지 않다면 false를 반환
✔ 연산 'pos1 != pos2'의 결과로 모든 멤버의 값이 같다면 false, 그렇지 않다면 true를 반환
✔ 연산자 == 를 먼저 오버로딩 한 다음에, 이를 이용하는 형태로 != 연산자를 오버로딩

총 3문제 이지만 하나의 답안에 모두를 담아도 된다.