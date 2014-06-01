#include <stdio.h>

#define IN 1
#define OUT 0

void main (int argc, char **argv)
{
    char c;
    int cnt_blank = 0;
    int cnt_tab = 0;
    int cnt_line = 0;
    int cnt_word = 0;
    int flag = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (flag == IN)
            {
                putchar('\n');
            }
            flag = OUT;
        }
        switch(c)
        {
            case ' ':
                cnt_blank++;
                break;
            case '\t':
                cnt_tab++;
                break;
            case '\n':
                cnt_line++;
                break;
            default:
                if (flag == OUT)
                    cnt_word++;
                flag = IN;
                putchar(c);
        }
    }
    if (flag == IN)
    {
        cnt_word++;
    }
    printf("blank cnt:  %d\n", cnt_blank);
    printf("tab cnt:    %d\n", cnt_tab);
    printf("line char:  %d\n", cnt_line);
    printf("word cnt:  %d\n", cnt_word);
    printf("char EOF: %x\n", EOF);
}
