#include <stdio.h>

#define LOWER   (0)
#define UPPERS  (100)
#define STEP    (10)

float fahr2celsius(int fahr);
float celsius2fahr(int celsius);

void main ()
{
    int fahr;
    int celsius;

    printf("%10s\t%10s\n", "celsius", "fahr");
    for ( celsius=LOWER; celsius<=UPPERS; celsius+=STEP) {
       printf("%10d\t%10.1f\n", celsius, celsius2fahr(celsius));
    }
    printf("%10s\t%10s\n", "fahr", "celsius");
    for ( fahr=LOWER; fahr<=UPPERS; fahr+=STEP) {
       printf("%10d\t%10.1f\n", fahr, fahr2celsius(fahr));
    }
}

float fahr2celsius(int fahr)
{
    float celsius;
    celsius = (fahr - 32) * 5 / 9.0;
    return celsius;
}
float celsius2fahr(int celsius)
{
    float fahr;
    fahr = celsius * 9 / 5.0 + 32;
    return fahr;
}
