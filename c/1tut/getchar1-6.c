#include <stdio.h>

#define IN 1
#define OUT 0

/* counting digits, white space, others */
void main (int argc, char **argv)
{
    char c;
    int i;
    int j;
    int sum;
    int cnt_digit[10] = {};
    int cnt_space = 0;
    int cnt_other = 0;
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            cnt_digit[c - '0']++;
        } else if (c == ' ') {
            cnt_space++;
        } else {
            cnt_other++;
        }
    }
    for (i = 0; i < 10; i++)
    {
        //printf("num[%d]: %d", i, cnt_digit[i]);
        printf(" [%d] ", i);
    }
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        sum += cnt_digit[i];
    }
    while(sum > 0)
    {
        for (i = 0; i < 10; i++)
        {
            if (cnt_digit[i] ==0)
            {
                printf("     ");
            }
            else if (cnt_digit[i]-- > 0)
            {
                printf("  *  ");
            } else {
                printf("ERROR\n");
            }
        }
        printf("\n");
        sum = 0;
        for (i = 0; i < 10; i++)
        {
            sum += cnt_digit[i];
        }
    }
    printf("\n");
    printf("cnt space: %d\n", cnt_space);
    printf("cnt other: %d\n", cnt_other);
    printf("char EOF: %x\n", EOF);
}
