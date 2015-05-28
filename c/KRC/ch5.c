#include "ch5.h"

int main(void)
{
    return 0;
}

/* Exercise 5-1
 * As written, getint treats a + or - not followed by a digit
 * as a valid representation of zero.
 * Fix it to push such a character back on the input. 
 */
// what is the meaning? this need hang!
int getint(int *pn)
{
    int c, sign;
    while(isspace(c=getch()))
        /*skip white space*/;
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-') {
        ungetch(c);         // NAN
        return 0;
    }
    sign = (c=='-')? -1 : 1;
    if(c=='+' || c=='-') {
        c=getch();
        if(!isdigit(c)) {
            ungetch(c);// FIXME: do we need push +/- back?
            return 0;
        }
    }
    for(*pn=0; isdigit(c); c=getch())
        *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if(c!=EOF)
        ungetch(c);
    return c;
}
char bufc = EOF;
int getch(void)
{
    if (bufc==EOF) {
        return getchar();
    } else {
        int temp;
        temp = bufc;
        bufc = EOF;
        return temp;
    }
}
void ungetch(int c)
{
    if(bufc!=EOF)
        printf("ERROR: ungetch: char occupyed\n");
    else {
        bufc = c;
    }
}


/* Exercise 5-2
 * Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value?
 */

/* getfloat: get next float from input into *pn*/
int getfloat(float *pn)
{
    int c, sign;
    while(isspace(c=getch()))
        /*skip white space*/;
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-') {
        ungetch(c);         // NAN
        return 0;
    }
    sign = (c=='-')? -1 : 1;
    if(c=='+' || c=='-')
        c=getch();
    for(*pn=0; isdigit(c); c=getch())
        *pn = 10 * *pn + (c-'0');
    if(c=='.') {
        int pwr;
        c = getch();
        for(pwr=1; isdigit(c); c=getch()) {
            *pn = 10 * *pn + (c-'0');
            pwr *= 10.0;
        }
        *pn /= pwr;
    }
    *pn *= sign;
    if(c!=EOF)
        ungetch(c);
    return c;
}

/* Exercise 5-3
 * Write a pointer version of the function strcat
 * that we showed in Chapter 2: strcat(s,t)
 * copies the string t to the end of s . 
 */

void strcate(char *s, char *t)
{
    while(*s++!=NUL)
        ;
    s -= 1;
    //while(*t++!=NULL)
    //    *s++=*t++;
    //*s=NULL;
    while((*s++=*t++)!=NUL)
        ;
}


/* Exercise 5-4
 * Write the function strend(s,t),
 * which returns 1 if the string t occurs at the end of the string s,
 * and zero otherwise. 
 */

int strend(char *s, char *t)
{
    while(strlen(s)>strlen(t))
        s++;
    while((*s==*t) && (*t!=NUL) && (*s!=NUL)) {
        s++;
        t++;
    }
    if((*s==NUL) && (*t==NUL))
        return 1;
    else
        return 0;
}


/* Exercise 5-5
 * Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings. 
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B. 
 */

char *strncpy_(char *s, const char *ct, int n)
{
    char *ret = s;
    while((n>0) && (*ct!=NUL)) {
        *s++=*ct++;
        n--;
    }
    return ret;
}

char *strncat_(char *s, const char *ct, int n)
{
    char *ret = s;
    while(*s!=NUL)
        s++;
    while((n>0) && (*ct!=NUL)) {
        *s++=*ct++;
    }
    *s = NUL;
    return ret;
}

int strncmp_(const char *cs, const char *ct, int n)
{
    if(strlen(cs)<strlen(ct)) {
        return -1;
    } else if(strlen(cs)>strlen(ct)) {
        return 1;
    }
    while((n>0) && *ct!=NUL) {
        if(*cs++ < *ct++) {
            return -1;
        } else if(*cs++ > *ct++) {
            return 1;
        }
        n--;
    }
    return 0;
}

#include <stdlib.h>
void str_wrap(void)
{
    char a[2];
    char b[12] = "xxxxx";

    printf("%s\n", strncpy_(a, b, 10));
    printf("%s\n", strncpy(a, b, 10));

    strcpy(a, "this is the");
    strcpy(b, "final cd");
    printf("%s\n", strncat_(a, b, 10));
    printf("%s\n", strncat(a, b, 10));

    printf("%d\n", strncmp_(a, b, 10));
    printf("%d\n", strncmp(a, b, 10));
}


/* Exercise 5-6 
 * Rewrite appropriate programs from earlier chapters and
 * exercises with pointers instead of array indexing.
 * Good possibilities include getline (Chapters 1 and 4),
 * atoi , itoa , and their variants (Chapters 2, 3, and 4),
 * reverse (Chapter 3), and strindex and getop (Chapter 4). 
 */

//TODO


/* Exercise 5-7
 * Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage.
 * How much faster is the program? 
 */

//TODO
//depend on the num of input lines


/*Exercise 5-8
 * There is no error-checking in day_of_year or month_day.
 * Remedy this defect. 
 */

int day_of_month(int month, bool leap)
{
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(leap)
                return 28;
            else
                return 29;
        default:
            return -1;
    };
}

bool is_leap(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}

/*day_of_year: set day of year from month & day*/
int day_of_year(int year, int month, int day)
{
    bool leap;
    leap = is_leap(year);
    int i;
    for(i=1; i<month; i++) {
        day += day_of_month(i, leap);
    }
    return day;
}

/*month_day: set month, day from day of year*/
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i;
    bool leap;
    leap = is_leap(year);
    for(i=1;yearday>day_of_month(i, leap);i++) {
        yearday -= day_of_month(i, leap);
    }
    *pmonth = i;
    *pday = yearday;
}


/* Exercise 5-9
 * Rewrite the routines day_of_year and month_day with pointers
 * instead of indexing.
 */

// TODO: 5-8 do not use static array any more. :(

/* Exercise 5-10
 * Write the program expr,
 * which evaluates a reverse Polish expression from the command line,
 * where each operator or operand is a separate argument.
 * For example, expr 2 3 4 + *, evaluates 2 X (3 + 4). 
 */

void expr(void)
{
}



