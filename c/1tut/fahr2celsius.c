#include <stdio.h>

#define LOWER   (0)
#define UPPERS  (300)
#define STEP    (20)

void main ()
{
    int fahr;
    float celsius;

    printf("%10s\t%10s\n", "fahr", "celsius");
    for ( fahr=LOWER; fahr<=UPPERS; fahr+=STEP) {
       celsius = (fahr - 32) * 5 / 9;
       printf("%10d\t%10.1f\n", fahr, celsius);
    }
}
