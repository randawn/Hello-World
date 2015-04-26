#include <stdio.h>
#include "ch4.h"

int main(void)
{
    return 0;
}

/* Exercise 4-1
 * Write the function strrindex(s,t) ,
 * which returns the position of the rightmost occurrence of t in s ,
 * or -1 if there is none. 
 */

int strrindex(char * s, char * t)
{
    if(t[0]=='\0')
        return -1;

    int i, j;
    int p = -1;
    for(i=0; s[i]!='\0'; i++) {
        for(j=i; t[j-i]!='\0'; j++) {
            if(t[j-i] != s[j])
                break;
        }
        if(t[j-i]=='\0' && i>=p)
            p = i;
    }
    return p;
}


/* Exercise 4-2
 * Extend atof to handle scientific notation of the form 123.45e-6
 * where a floating-point number may be followed by e or E
 * and an optionally signed exponent.
 */

#include <ctype.h>
#include <math.h>
double atofn(char * s)
{
    double val, vale, power;
    int i, sign, signe;

    for(i=0; isspace(s[i]); i++)
        /*skip white space*/;
    sign = (s[i]=='-')? -1: 1;
    if (s[i]=='+' || s[i]=='-')
        i++;
    for (val=0.0; isdigit(s[i]); i++)
        val = 10.0*val + (s[i]-'0');
    if(s[i]=='.')
        i++; 
    for (power=1.0; isdigit(s[i]); i++) {
        val = 10.0*val + (s[i]-'0');
        power *= 10.0;
    }
    if(s[i]=='e' || s[i]=='E')
        i++;
    signe = (s[i]=='-')? -1: 1;
    if (s[i]=='+' || s[i]=='-')
        i++;
    for (vale=0.0; isdigit(s[i]); i++)
        vale = 10.0*vale + (s[i]-'0');
    return sign * val/power * pow((pow(10, vale)), (signe));
}

/* Exercise 4-3
 * Given the basic framework,
 * it's straightforward to extend the calculator.
 * Add the modulus ( % ) operator and provisions for negative numbers. 
 */
int sp = 0;         // next free stack position
double val[MAXVAL]; // val stack
char buf[BUFSIZE];
int bufp=0;

// reverse Polish calculator
void calculator(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while((type=getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s)); break;
            case '+':
                push(pop() + pop()); break;
            case '*':
                push(pop() * pop()); break;
            case '-':
                op2 = pop();
                push(pop() - op2); break;
            case '/':
                op2 = pop();
                if(op2!=0.0)
                    push(pop() / op2);
                else
                    printf("ERROR: zero divisor\n");
                break;
            case '\n':
                printf("\t%8g\n", pop()); break;
            default:
                printf("ERROR: unknow cmd %s\n", s);
        }
    }
}

// push: push f onto value stack
void push(double f)
{
    //printf("sp: %d MAXVAL %d\n", sp, MAXVAL);
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("ERROR: stack full, can't push %g\n", f);
        exit(-1);
    }
}
// pop: pop and return top value from stack
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("ERROR: stack empty\n");
        return 0.0;
    }
}

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i, c;
    while((s[0]=c=getch())==' ' || c=='\t')
        ;
    s[1]='\0';
    if(!isdigit(c) && c!='.') {
        return c;   // NAN
    }
    i = 0;
    if(isdigit(c))  // int part
        while(isdigit(s[++i]=c=getch()))
            ;
    if(c=='.')      // fraction part
        while(isdigit(s[++i]=c=getch()))
            ;
    s[i]='\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
    return (bufp>0)? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ERROR: ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}

