#include <stdio.h>

const char * parseInt(int data)
{
    static char str[16] = {0};
    int i = 0;

    int t = 0;
    for (; t < 16; t++) {
        str[t] = 0;
    }

    if (data < 0) {
        data = -data;
        str[i++] = '-';
    }
    int tmp = data;
    while (tmp / 10 != 0) {
        char ch = tmp % 10 + 48;
        tmp = tmp / 10;
        str[i++] = ch;
    }

    str[i++] = tmp % 10 + 48;

    return str;
}

int main()
{
    printf("%s\n", parseInt(123));
    printf("%s\n", parseInt(12345678));
    printf("%s\n", parseInt(-89790));

    printf("%s, %s, %s\n", parseInt(98989),parseInt(-4567), parseInt(123456));

    printf("%s\n", parseInt(0x8FFFFFFF));
    printf("%s\n", parseInt(0xFFFFFFFF));

    return 0;
}
~                      
