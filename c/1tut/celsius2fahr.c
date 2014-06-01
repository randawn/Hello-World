
#include <stdio.h>

void main ()
{
    float fahr;
    int celsius;

    printf("%10s\t%10s\n", "celsius", "fahr");
    for ( celsius=0; celsius<=300; celsius+=20) {
       fahr = celsius * 9 / 5 + 32;
       printf("%10d\t%10.1f\n", celsius, fahr);
    }
}
