#include <stdio.h>
#include "ch1.h"

int main(void)
{
    return 0;
}

/* Exercise 1-1
 * Run the "hello, world" program on your system.
 * Experiment with leaving out parts of the program,
 * to see what error messages you get. 
 */
void print_hello(void)
{
    printf("hello, world\n");
}

/* Exercise 1-2
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

/* Exercise 1-3
 * Modify the temperature conversion program to print a heading above the table. 
 */
void print_head(void)
{
    printf("%10s\t%10s\n", "fahr", "celsius");
}

/* Exercise 1-4
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

/* Exercise 1-5
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

/* Exercise 1-6
 * Verify that the expression getchar() != EOF is 0 or 1. 
 */
void verify_EOF(void)
{
    printf("(getchar() != EOF) = %d\n", (getchar() != EOF));
}

/* Exercise 1-7
 * Write a program to print the value of EOF . 
 */
void print_EOF(void)
{
    printf("EOF =  %x\n", EOF);
}

/* Exercise 1-8
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

/* Exercise 1-9
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

/* Exercise 1-10
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

/* Exercise 1-11
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

/* Exercise 1-12
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

/* Exercise 1-13
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

/* Exercise 1-14
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

/* Exercise 1-15
 * Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. 
 */
float fahr2celsius(int fahr)
{
    float celsius;
    celsius = (fahr - 32) / 9 * 5.0;
    return celsius;
}

/* Exercise 1-16
 * Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrarily long input lines,
 * and as much as possible of the text.
 */
#define MAXCHAR 100
#define NUL '\0'
void print_longest_line() {
    char line[MAXCHAR];
    char max_line[MAXCHAR];
    int cnt = 0;
    int max_cnt = -1;

    while ((cnt = lineCnt(getLine(line, MAXCHAR))) >0) {
        if (cnt > max_cnt) {
            max_cnt = cnt;
            copyLine(line, max_line);
        }
    }
    printf("max_line: %s\n", max_line);
    printf("max_cnt: %d\n", max_cnt);
}
char * getLine(char line[], int lim) {
    char char_in;
    int i = 0;
    while (i<lim-1 && (char_in = getchar()) != EOF && char_in != '\n') {
        line[i++] = char_in;
    }
    if (char_in == '\n') {
        line[i++] = '\n';
    }
    line[i] = NUL;
    return line;
}
int lineCnt(char line[])
{
    int i = 0;
    while(line[i] != NUL) {
        i++;
    };
    return i;
}
void copyLine(char from[], char to[])
{
    int i = 0;
    while(from[i] != NUL) {
        to[i] = from[i];
        i++;
    }
    to[i] = NUL; /* \0 char!!! */
    return;
}

/* Exercise 1-17
 * Write a program to print all input lines that are longer than 80 characters. 
 */
void print_line80pchar()
{
    char line[81];
    int cnt = 0;
    int cntLim = 10;

    while ((cnt = lineCnt(getLine(line, 100))) >0) {
        if (cnt > cntLim) {
            printf("line with cnt %d: %s", cnt, line);
        }
    }
}

/* Exercise 1-18
 * Write a program to remove all trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines. 
 */
void trailRemoveWrap() {
    char line[81];
    int cntBefor = 0;
    int cntAfter = 0;

    while ((cntBefor = lineCnt(getLine(line, 100))) >0) {
        trailRemove(line);
        cntAfter = lineCnt(line);
        printf("cnt befor : %d cnt after: %d \n", cntBefor, cntAfter);
        printf("line : %s", line);
    }
}

void trailRemove(char line[])
{
    int i = 0;
    int mark = -1; // in case NUL line
    while(line[i] != NUL) {
        if((line[i] != ' ') && (line[i] != '\t') && (line[i] !='\n'))
            mark = i;
        i++; 
    }
    line[mark+1] = '\n';
    line[mark+2] = NUL;
}

/* Exercise 1-19
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time. 
 */
void reverseLineWrap()
{
    char line[81];
    int cnt = 0;

    while ((cnt = lineCnt(getLine(line, 100))) >0) {
        printf("line before : %s", line);
        reverseLine(line);
        printf("line reverse: %s", line);
    }
}
void reverseLine(char line[])
{
    int i = 0;
    int cnt = 0;
    char swap_tmp;
    cnt = lineCnt(line); // do not swap the last NUL and '\n'
    for(i=0; i<(cnt/2); i++){
        swap_tmp = line[i];
        line[i] = line[cnt-2-i]; // start from zero
        line[cnt-2-i] = swap_tmp;
    }
    return;
}

/* TODO
 * 1-20
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter? 
    void deTab(char line[])
    {
        int i = 0;
        int j = 0;
        int k = 0;
        char line_copy[MAXCHAR];// *4 for the corner
        copy(line, line_copy);
        while(line_copy[i] != NUL) {
            if(line_copy[i] == '\t') {
                for(j = 0; j<TABSTOP; j++) {
                    line[k++] = ' ';
                }
            } else {
                line[k++] = line_copy[i];
            }
            i++;
        }
        line[k] = NUL;
        return;
    }
 * 1-21
 * Write a program entab that replaces strings of blanks
 * with the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference? 
    void enTab(char line[])
    {
        int i = 0;
        int j = 0;
        int k = 0;
        int l = 0;
        char line_copy[MAXCHAR];// *4 for the corner
        copy(line, line_copy);
        while(line_copy[i] != NUL) {
            if(line_copy[i] == ' ') {
                j++;
                if(j == TABSTOP) {
                    line[k++] = '\t';
                    j = 0;
                }
            } else {
                for(l=0; l<j; l++) {
                    line[k++] = ' ';
                }
                line[k++] = line_copy[i];
                j = 0;
            }
            i++;
        }
        line[k] = NUL;
        return;
    }
 * 1-22
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n -th column of input.
 * Make sure your program does something intelligent with very long lines,
 * and if there are no blanks or tabs before the specified column. 
    void longCut(char line[])
    {
        int i = 0;
        int last_s_mark = 0;//space
        int last_l_mark = 0;//line end
        int k = 0;
        int offset = 0;
        int char_num = 0;
        int flag = 0;       // 0:all char 1:get ' ' 2:get NUL
        if (lineCnt(line) < MAXLINE) {
            return;
        }
        char line_copy[MAXCHAR];// *4 for the corner
        copy(line, line_copy);
        while(1) {
            flag = 0;
            for(i=last_l_mark; i<last_l_mark+MAXLINE; i++) {
                if(line_copy[i] == ' ') {
                    last_s_mark = i;
                    flag = 1;
                } else if(line_copy[i] == NUL) {
                    last_s_mark = i;
                    flag = 2;
                    break;
                }
            }
            if (flag==0) { // no ' ' and NUL
                last_s_mark = i;
            }
            if(flag == 0) {
                last_l_mark = i;
                line[offset+i] = '\n';
                for(k=0; k<MAXLINE; k++) {
                    i--;
                    line[offset+i] = line_copy[i];
                }
                offset++;
            } else {
                char_num = last_s_mark-last_l_mark;
                if (flag == 2) {
                    line[offset+last_s_mark] = NUL;
                } else {
                    last_l_mark = last_s_mark + 1; // +1 for space
                    line[offset+last_s_mark] = '\n';
                }
                for(k=0; k<char_num; k++) {
                    last_s_mark--;
                    line[offset+last_s_mark] = line_copy[last_s_mark];
                }
            }
            if(flag == 2) {
                break;
            }
        }
        return;
    }
 * 1-23
 * TODO
 * 1-24
 * TODO
 *
void printLine(char line[], char * note)
{
    printf("%s:\n", note);
    int i = 0;
    while(line[i] != NUL) {
        if(line[i] == ' ')
            printf("\\s");
        else if(line[i] == '\t')
            printf("\\t");
        else if(line[i] == '\n') {
            printf("\\n");
            printf("\n");
        } else
            printf("%c", line[i]);
        i++;
    }
    printf("\n");
}
*/

