#include <stdio.h>

void print_hello();                 // ex 1-1
                                    // ex 1-2
void print_head();                  // ex 1-3
void print_table();                 // ex 1-4
void print_table_r();               // ex 1-5
float celsius2fahr(int celsius);
void verify_EOF();                  // ex 1-6
void print_EOF();                   // ex 1-7
void cnt_b_t_n();                   // ex 1-8
void dup_blank_rm();                // ex 1-9
void disp_invisible_char();         // ex 1-10
void word_cnt();                    // ex 1-11
void word_put();                    // ex 1-12
void word_len_hist();               // ex 1-13
void char_freq_hist();              // ex 1-14
float fahr2celsius(int fahr);       // ex 1-15

int main()
{
    char_freq_hist();
    return 0;
}

void print_hello () 
{
    printf("hello, world\n");
}

void print_head()
{
    printf("%10s\t%10s\n", "fahr", "celsius");
}

void print_table()
{
#define LOWER   (0)
#define UPPERS  (300)
#define STEP    (20)
    int celsius;
    print_head();
    for ( celsius=LOWER; celsius<=UPPERS; celsius+=STEP) {
        printf("%10d\t%10.1f\n", celsius, celsius2fahr(celsius));
    }
}

void print_table_r()
{
#define LOWER   (0)
#define UPPERS  (300)
#define STEP    (20)
    int celsius;
    print_head();
    for ( celsius=UPPERS; celsius>=LOWER; celsius-=STEP) {
        printf("%10d\t%10.1f\n", celsius, celsius2fahr(celsius));
    }
}
float celsius2fahr(int celsius)
{
    float fahr;
    fahr = celsius * 9 / 5.0 + 32;
    return fahr;
}

void verify_EOF()
{
    printf("(getchar() != EOF) = %d\n", (getchar() != EOF));
}
void print_EOF()
{
    printf("EOF =  %x\n", EOF);
}

void cnt_b_t_n()
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

void dup_blank_rm()
{
    char c;
    int flag = 0;
    while ((c = getchar()) != EOF) {
        if (flag == 1 && c == ' ') { 
            ;
        } else {
            printf("%c", c);
        }
        if (c == ' ') {
            flag = 1;
        } else {
            flag = 0;
        }
    }
}

void disp_invisible_char()
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

void word_cnt()
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

void word_put()
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

void word_len_hist()
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

void char_freq_hist()
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

float fahr2celsius(int fahr)
{
    float celsius;
    celsius = (fahr - 32) / 9 * 5.0;
    return celsius;
}

