04-2 캡슐화
---
캡슐화의 예제를 들기위해 알약을 예시로 들어보자.
감기약에 포함된 기능은 "재채기, 콧물, 코막힘"의 완화 이다.
코감기에 걸렸을 때 이 세가지 기능이 따로따로 캡슐화가 되어있다면 코감기에 걸렸을 때 3개의 알약을 먹어야 한다면 이는 캡슐화가 성립되지 않은 상황이다.

아래의 예제를 통해 캡슐화의 중요성을 확인해보자.
> 01_Encaps1.cpp
``` C++
ColdPatient sufferer; // 환자
sufferer.TakeSinivelCap(scap);
sufferer.TakeSneezeCap(zcap);
sufferer.TakeSnuffleCap(ncap);
```

위 내용이 캡슐화가 무너진 대표적인 사례이다.
> 코감기는 항상 콧물, 재채기, 코막힘을 동반한다.
> 약의 복용은 SinivelCap, SneezeCap, SnuffleCap 순서로 이루어져야 한다.

**캡슐화의 이해**
이번엔 캡슐화가 잘 된  예제 02_encaps2.cpp를 확인하자
