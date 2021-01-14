#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// 사용자의 선택 메뉴
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 신용 등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

// 계좌의 종류
enum {NORMAL = 1, CREDIT = 2};
#endif