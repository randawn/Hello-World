#include <stdio.h>
#include "ch3.h"

int main(void)
{
    return 0;
}

/* Exercise 3-1
 * Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside).
 * Write a version with only one test inside the loop and
 * TODO: measure the difference in run-time. 
 */
/* binsearch: find x in v[0]<=v[1]<=...<=v[n-1]*/
int _binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid -1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high= n-1;
    mid = (low+high) / 2;
    while (low <= high && x!=v[mid]) {
        if (x < v[mid])
            high = mid -1;
        else
            low = mid + 1;
        mid = (low+high) / 2;
    }
    if(x==v[mid])
        return mid;
    return -1;
}

/* Exercise 3-2
 * Write a function escape(s,t) that
 * converts characters like newline and tab
 * into visible escape sequences like \n and \t
 * as it copies the string t to s . Use a switch .
 * Write a function for the other direction as well,
 * converting escape sequences into the real characters. 
 */

void escape(char * s, char * t)
{
    int i=0;
    int j=0;
    while(s[i]!='\0') {
        switch(s[i]){
            case '\a': t[j++]='\\', t[j++]='a'; break;
            case '\b': t[j++]='\\', t[j++]='b'; break;
            case '\t': t[j++]='\\', t[j++]='t'; break;
            case '\n': t[j++]='\\', t[j++]='n'; break;
            case '\v': t[j++]='\\', t[j++]='v'; break;
            case '\f': t[j++]='\\', t[j++]='f'; break;
            case '\r': t[j++]='\\', t[j++]='r'; break;
            default:   t[j++]=s[i];
        }
        i++;
    }
    t[j]='\0';
}
void unescape(char * t, char * s)
{
    int i=0;
    int j=0;
    while(t[i]!='\0') {
        switch(t[i]){
            case '\\':
                switch(t[++i]) {
                    case 'a': s[j++]='\a'; break;
                    case 'b': s[j++]='\b'; break;
                    case 't': s[j++]='\t'; break;
                    case 'n': s[j++]='\n'; break;
                    case 'v': s[j++]='\v'; break;
                    case 'f': s[j++]='\f'; break;
                    case 'r': s[j++]='\r'; break;
                    default: s[j++]='\\'; s[j++]=t[i];
                }
                break;
            default:    s[j++]=t[i];
        }
        i++;
    }
    s[j]='\0';
}

void escape_wrap()
{
    //char s0[100]= "\\a"; TODO: handle more than abtnvfr
    char s0[100]= "\a\\aHello,\n\tWorld!  Mistakee\b was \"Extra 'e'\"!\n";
    char t0[100];
    escape(s0, t0);
    printf("s: %s\n", s0);
    printf("t: %s\n", t0);
    unescape(t0, s0);
    printf("t: %s\n", t0);
    printf("s: %s\n", s0);
}


/* Exercise 3-3
 * Write a function expand(s1,s2) that
 * expands shorthand notations like a-z in the string s1
 * into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */

void expand(char * s1, char * s2)
{
    int i;
    int j=0;
    int k;
    for(i=0; s1[i]!='\0'; i++) {
        if(s1[i]=='-' && i>=1 && s1[i-1]<s1[i+1]) {
            for(k=s1[i-1]+1; k<s1[i+1]; k++) {
                s2[j++] = k;
            }
        } else
            s2[j++] = s1[i];
    }
    s2[j]='\0';
}
void expand_wrap()
{
    char s1[100]= "z-a";
    char s2[100];
    expand(s1, s2);
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
}

/* Exercise 3-4
 * In a two's complement number representation,
 * our version of itoa does not handle the largest negative number,
 * that is, the value of n equal to -(2 to the power (wordsize - 1)) .
 * Explain why not.
 * Modify it to print that value correctly
 * regardless of the machine on which it runs. 
 */
int len(char s[])
{
    int i=0;
    while(s[i] != '\0')
        i++;
    return i;
}
void reverse(char s[])
{
    int l = len(s);
    int i;
    char c;
    for(i=0; i<=l/2; i++) {
        c = s[i];
        s[i] = s[l-1-i];
        s[l-1-i] = c;
    }
}
int abs(int n)
{
    return n>0?n:-n;
}
void itoa(int n, char s[])
{
    int i, sign;
    if((sign=n)<0)
        n = -n;
    i = 0;
    do {
        s[i++] = abs(n%10) + '0';
    } while (n/=10);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void itoa_wrap()
{
    char s[10];
    int n = ~0<<31;
    itoa(n, s);
    printf("out : %d\t%s\n", n,s);
}

/* Exercise 3-5
 * Write the function itob(n,s,b)
 * that converts the integer n
 * into a base b character representation in the string s.
 * In particular, itob(n,s,16) formats n as a hexadecimal integer in s .
 */

void itob(int n, char s[], int b)
{
    int i, sign;
    char ctoh[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                     'a', 'b', 'c', 'd', 'e', 'f'};
    if((sign=n)<0)
        n = -n;
    i = 0;
    do {
        s[i++] = ctoh[abs(n%b)];
    } while (n/=b);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void itob_wrap()
{
    char s[100];
    int n = 27;
    itob(n, s, 3);
    printf("out : %x\t%s\n", n,s);
}

/* Exercise 3-6
 * Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width;
 * the converted number must be padded with blanks on the left if necessary
 * to make it wide enough.
 */

void itoaw(int n, char s[], int w)
{
    int i, sign;
    if((sign=n)<0)
        n = -n;
    i = 0;
    do {
        s[i++] = abs(n%10) + '0';
    } while (n/=10);
    if (sign < 0)
        s[i++] = '-';
    while(len(s)<w) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
void itoaw_wrap()
{
    char s[10];
    int n = 123;
    itoaw(n, s, 8);
    printf("out :%d\n%s\n", n,s);
}


