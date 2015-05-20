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



