#include <stdio.h>

int main(int argc, char *argv[])
{
    int s;
    int i;
    for (i = 0; i < 10; ++i)
    {
        s = power(2, i);
        printf(" %d**2 = %d\n", i, s);
    }
    return 0;
}

int power(int x, int y)
{
    int p = 1;
    int i;
    for (i = 0; i < y; ++i)
    {
        p *= x;
    }
    return p;
}
