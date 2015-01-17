#include <stdio.h>
#include "ch1.h"

int main(void)
{
    word_cnt();
    return 0;
}

/* 1-1
 * Run the "hello, world" program on your system.
 * Experiment with leaving out parts of the program,
 * to see what error messages you get. 
 */
void print_hello(void)
{
    printf("hello, world\n");
}

/* 1-2
 * Experiment to find out what happens
 * when printf 's argument string contains \c,
 * where c is some character not listed above. 
 */
void print_escapechar(void)
{
    //printf("non-specified escape sequence invokes undefined behaviour.\\c \c\n");
    printf("Audible or visual alert. \a\n");  
    printf("Form feed.\\f \f\n");
    printf("This escape,\\r \r, moves the active position to the initial position of the current line.\n");
    printf("Vertical tab\\v \v is tricky, as its behaviour is unspecified under certain conditions.\n");
}

/* 1-3
 * Modify the temperature conversion program to print a heading above the table. 
 */
void print_head(void)
{
    printf("%10s\t%10s\n", "fahr", "celsius");
}

/* 1-4
 * Write a program to print the corresponding Celsius to Fahrenheit table. 
 */
void print_table(void)
{
    int lower=0;
    int upper=300;
    int step=20;

    int celsius;
    print_head();
    for ( celsius=lower; celsius<=upper; celsius+=step) {
        printf("%10d\t%10.1f\n", celsius, celsius2fahr(celsius));
    }
}

/* 1-5
 * Modify the temperature conversion program to print the table in reverse order, that is,
 * from 300 degrees to 0. 
 */
void print_table_r(void)
{
    int lower=0;
    int upper=300;
    int step=20;

    int celsius;
    print_head();
    for ( celsius=upper; celsius>=lower; celsius-=step) {
        printf("%10d\t%10.1f\n", celsius, celsius2fahr(celsius));
    }
}
float celsius2fahr(int celsius)
{
    float fahr;
    fahr = celsius * 9 / 5.0 + 32;
    return fahr;
}

/* 1-6
 * Verify that the expression getchar() != EOF is 0 or 1. 
 */
void verify_EOF(void)
{
    printf("(getchar() != EOF) = %d\n", (getchar() != EOF));
}

/* 1-7
 * Write a program to print the value of EOF . 
 */
void print_EOF(void)
{
    printf("EOF =  %x\n", EOF);
}

/* 1-8
 * Write a program to count blanks, tabs, and newlines. 
 */
void cnt_b_t_n(void)
{
    char c;
    int cnt_space = 0;
    int cnt_tab = 0;
    int cnt_nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            cnt_space++;
        } else if (c == '\t') {
            cnt_tab++;
        } else if (c == '\n') {
            cnt_nl++;
        }
    }
    printf("blank_cnt:%d\ttab_cnt:%d\tnewline_cnt:%d\n", cnt_space, cnt_tab, cnt_nl);
}

/* 1-9
 * Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank. 
 */
void dup_blank_rm(void)
{
    char c;
    int flag = 0;
    while ((c = getchar()) != EOF) {
        if (flag == 1 && c == ' ') { 
            ;
        } else {
            //printf("%c", c);
            putchar(c);
        }
        if (c == ' ') {
            flag = 1;
        } else {
            flag = 0;
        }
    }
}

/* 1-10
 * Write a program to copy its input to its output,
 * replacing each tab by \t , each backspace by \b , and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way. 
 */
void disp_invisible_char(void)
{
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') { 
            printf("\\b");
        } else if (c == '\t') {
            printf("\\t");
        } else if (c == '\\') {
            printf("\\\\");
        } else if (c == '\n') {
            printf("\\n");
            printf("\n");
        } else {
            printf("%c", c);
        }
    }
}

/* 1-11
 * How would you test the word count program?
 * What kinds of input are most likely to uncover bugs if there are any? 
 */
void word_cnt(void)
{
    char c;
    int cnt_char = 0;
    int cnt_line = 0;
    int cnt_word = 0;
    enum {IN, OUT} flag;
    flag = OUT;
    while ((c = getchar()) != EOF) {
        cnt_char++;
        if(c == '\n') {
            cnt_line++;
        }
        if(c == ' '||c == '\t'||c == '\n') {
            flag = OUT;
        } else if (flag == OUT) {
            cnt_word++;
            flag = IN;
        }
    }
    printf("char cnt:  %d\n", cnt_char);
    printf("line char:  %d\n", cnt_line);
    printf("word cnt:  %d\n", cnt_word);
}

/* 1-12
 * Write a program that prints its input one word per line. 
 */
void word_put(void)
{
    char c;
    enum {IN, OUT} flag;
    flag = OUT;
    while ((c = getchar()) != EOF) {
        if(c == ' '||c == '\t'||c == '\n') {
            if(flag == IN) {
                putchar('\n');
                flag = OUT;
            }
        } else if (flag == OUT) {
            flag = IN;
        }
        putchar(c);
    }
}

/* 1-13
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging. 
 */
void word_len_hist(void)
{
    char c;
    enum {IN, OUT} flag;
    flag = OUT;
    int word_len[10] = {0};
    int len_cnt = 0;
    int i;
    while ((c = getchar()) != EOF)
    {
        if(c == ' '||c == '\t'||c == '\n') {
            if(flag == IN) {
                if(len_cnt>=10)
                    word_len[0] += 1;
                else
                    word_len[len_cnt] += 1;
                flag = OUT;
            }
        } else if (flag == OUT) {
                len_cnt = 1;
                flag = IN;
        } else {
                len_cnt++;
        } 
    }
    // print header
    for (i = 0; i < 10; i++) {
        printf(" [%d] ", i);
    }
    printf("\n");
    // if we need print any more
    int sum = 0;
    for (i = 0; i < 10; i++) {
        sum += word_len[i];
    }
    while(sum > 0) {
        for (i = 0; i < 10; i++) {
            if (word_len[i] ==0) {
                printf("     ");
            }
            else if (word_len[i]-- > 0) {
                printf("  *  ");
            } else {
                printf("ERROR\n");
            }
        }
        printf("\n");
        sum = 0;
        for (i = 0; i < 10; i++) {
            sum += word_len[i];
        }
    }
    printf("\n");
}

/* 1-14
 * Write a program to print a histogram of the frequencies of different characters in its input. 
 */
void char_freq_hist(void)
{
    char c;
    int char_cnt[128] = {0};
    int i;
    while ((c = getchar()) != EOF)
    {
        if(32 <= c && c <= 125) {
            char_cnt[c-31] += 1;
        } else {
            char_cnt[0] += 1;
        }
    }
    // print header
    printf("%d", 0);
    for (i = 32; i <= 125; i++) {
        printf("%c", i);
    }
    printf("\n");
    // if we need print any more
    int sum = 0;
    for (i = 0; i < 128; i++) {
        sum += char_cnt[i];
    }
    while(sum > 0) {
        for (i = 0; i < 125-32+1+1; i++) {
            if (char_cnt[i] ==0) {
                printf(" ");
            }
            else if (char_cnt[i]-- > 0) {
                printf("*");
            } else {
                printf("ERROR\n");
            }
        }
        printf("\n");
        sum = 0;
        for (i = 0; i < 10; i++) {
            sum += char_cnt[i];
        }
    }
}

/* 1-15
 * Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. 
 */
float fahr2celsius(int fahr)
{
    float celsius;
    celsius = (fahr - 32) / 9 * 5.0;
    return celsius;
}

