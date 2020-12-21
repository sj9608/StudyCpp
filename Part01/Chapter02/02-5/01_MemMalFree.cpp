#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

char* MakeStrAdr(int len)
{
    char *str = (char *)malloc(sizeof(char) * len);
    return str;
}

int main(void)
{
    int len;
    cin >> len ;

    char *str = MakeStrAdr(len);
    cin >> str;

    cout << str << endl;
    free(str);

    return 0;
}