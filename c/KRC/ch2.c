#include <stdio.h>
#include "ch2.h"

int main(void)
{
    return 0;
}


/* Exercise 2-1
 * Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned,
 * by printing appropriate values from standard headers and by direct computation.
 * Harder if you compute them:
 * determine the ranges of the various floating-point types. 
*/
#include <limits.h>
void print_range()
{
    printf("word size  - %d \n", __WORDSIZE);
    printf("Char  %d bit range: %d - %d \n", CHAR_BIT, CHAR_MIN, CHAR_MAX);
    printf("short %d bit range: %d - %d \n", (int)sizeof(short)<<3, SHRT_MIN, SHRT_MAX);
    printf("int   %d bit range: %d - %d \n", (int)sizeof(int)<<3,  INT_MIN, INT_MAX);
    printf("long  %d bit range: %ld- %ld\n", (int)sizeof(long)<<3, LONG_MIN, LONG_MAX);

    printf("range char  %d - %d \n",
            (char)(0x1<<(8*sizeof(char)-1)),
            (char)(~(0x1<<(8*sizeof(char)-1)))
            );
    printf("range short %d - %d \n",
            (short)(0x1<<(8*sizeof(short)-1)),
            (short)(~(0x1<<(8*sizeof(short)-1)))
            );
    printf("range int   %d - %d \n",
            (int)(0x1<<(8*sizeof(int)-1)),
            (int)(~(0x1<<(8*sizeof(int)-1)))
            );
    printf("range long  %ld - %ld \n",
            (long)(0x1L<<(8*sizeof(long)-1)),
            (long)(~(0x1L<<(8*sizeof(long)-1)))
            );

    printf("uChar %d bit range: 0 - %u \n", (int)sizeof(unsigned char)<<3, UCHAR_MAX);
    printf("uShort%d bit range: 0 - %u \n", (int)sizeof(unsigned short)<<3, USHRT_MAX);
    printf("uInt  %d bit range: 0 - %u \n", (int)sizeof(unsigned int)<<3, UINT_MAX);
    printf("uLong %d bit range: 0 - %lu \n",(int)sizeof(unsigned long)<<3, ULONG_MAX);

    printf("hello world\n");
}

