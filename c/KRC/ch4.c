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

    calhelp();
    while((type=getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s)); break;
            case CMD:
                if(strcmp(s, "ptop")==0) {
                    if(sp>0) printf("stack top %f\n", val[sp-1]);
                    else     printf("WARN: stack empty\n");
                } else if(strcmp(s, "duptop")==0) {
                    if(sp>0 && sp<MAXVAL) {
                        val[sp] = val[sp-1];
                        sp++;
                    } else if(sp==0)
                        printf("WARN: stack empty\n");
                    else if(sp==MAXVAL)
                        printf("WARN: stack full\n");
                } else if(strcmp(s, "swaptop")==0) {
                    if(sp>1 && sp<MAXVAL) {
                        op2 = val[sp-1];
                        val[sp-1] = val[sp-2];
                        val[sp-2] = op2;
                    } else if(sp==0)
                        printf("WARN: stack empty\n");
                    else if(sp==MAXVAL)
                        printf("WARN: stack full\n");
                } else if(strcmp(s, "clrstack")==0) {
                    sp = 0;
                } else if(strcmp(s, "sin")==0) {
                    push(sin(pop())); break;
                } else if(strcmp(s, "exp")==0) {
                    push(exp(pop())); break;
                } else {
                    printf("ERROR: unknow cmd str %s\n", s);
                }
                break;
            case '+':
                push(pop() + pop()); break;
            case '*':
                push(pop() * pop()); break;
            case '-':
                op2 = pop();
                push(pop() - op2); break;
            case '/':
                if((op2=pop()) !=0.0)
                    push(pop() / op2);
                else
                    printf("ERROR: zero divisor\n");
                break;
            case '%':
                if((op2=pop()) != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("ERROR: zero mod\n");
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2)); break;
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
    printf("push: %f \n", f);
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
        printf("pop: %f \n", val[sp-1]);
        return val[--sp];
    } else {
        printf("ERROR: stack empty\n");
        return 0.0;
    }
}

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i=0;
    int c;
    while((s[0]=c=getch())==' ' || c=='\t')
        ;
    s[1]='\0';
    if(!isdigit(c) && c!='.' &&
            c!='-' && c!='+' &&
            c!=':') {
        return c;       // NAN
    } else if(c==':') {
        while(!isspace(s[i++]=c=getch()))
            ;
        s[i-1] = '\0';
        return CMD;     // CMD
    } else if(c=='+' || c=='-') {
        s[++i]=c=getch();
        if(isspace(c) || c==EOF) {
            ungetch(c);
            return s[--i];
        } else if(!isdigit(c) && c!='.') {
            s[i++]='\0';
            ungetch(c);
            return c;
        }
    }
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
    //return getch_();    // HACK to ungetc ex4-8
    return (bufp>0)? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    //ungetch_(c); return;// HACK to ungetc ex4-8
    if(bufp >= BUFSIZE)
        printf("ERROR: ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}
void calhelp()
{
    printf("reverse polish cal, input the expression\n");
    printf("eg: 1 1 +\n");
    printf("support cmd: (begin with :)\n");
    printf("    ptop:     cmd print the top element of the stack\n");
    printf("    duptop:   cmd duplicate ...\n");
    printf("    swaptop:  cmd swap the top two element\n");
    printf("    clrstack: cmd clear the stack\n");
    printf("    sin: sine of x\n");
    printf("    exp: exponential of e^x\n");
    printf("eg: 1 :ptop\n");
}

/* Exercise 4-4
 * Add commands to print the top element of the stack without popping,
 * to duplicate it, and to swap the top two elements.
 * Add a command to clear the stack. 
 */


/* Exercise 4-5
 * Add access to library functions like sin, exp, and pow.
 * See <math.h> in Appendix B, Section 4.
 */


/* Exercise 4-6 TODO!!! how?
 * Add commands for handling variables.
 * (It's easy to provide twenty-six variables with single-letter names.)
 * Add a variable for the most recently printed value. 
 */


/* Exercise 4-7
 * Write a routine ungets(s) that will
 * push back an entire string onto the input.
 * Should ungets know about buf and bufp,
 * or should it just use ungetch ? 
 */

void ungets(char * s)
{
    int i = strlen(s);
    ungetch(EOF);   // ATTN: EOF != NUL
    while(i>=0) {
        ungetch(*(s+i-1));
        i--;
    }
}


/* Exercise 4-8
 * Suppose there will never be more than one character of pushback.
 * Modify getch and ungetch accordingly. 
 */

char bufc = EOF;
int getch_(void)
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
void ungetch_(int c)
{
    if(bufc!=EOF)
        printf("ERROR: ungetch: char occupyed\n");
    else {
        bufc = c;
    }
}

/* Exercise 4-9
 * Our getch and ungetch do not handle a pushed-back EOF correctly.
 * Decide what their properties ought to be if an EOF is pushed BACK,
 * then implement your design.
 */

// change :char buf[BUFSIZE];
// to     :int buf[BUFSIZE];
// FIXME: char work fine on my mechine,
//        unsigned char not work. WHY???


/* Exercise 4-10
 * An alternate organization uses getline to read an entire input line;
 * this makes gech and ungetch unnecessary.
 * Revise the calculator to use this approach.
 */

// TODO: 
// read an entire line, put in a char[].
// getop use pointer to access. do not need getch and ungetch.

/* Exercise 4-11
 * Modify getop so that it doesn't need to use ungetch.
 * Hint: use an internal static variable.
 */
//TODO
//int getop(char s[])
//{
//    static int bufc = EOF;
//    ...
//    when unget, store c in bufc
//    when getch, check bufc first
//}


/* Exercise 4-12
 * Adapt the ideas of printd to write a recursive version of atoi;
 * that is, convert an integer into a string by calling a recursive routine. 
 */

void itoa(int n, char s[], int idx)
{
    static int i=0;
    if(n==0)
        return;
    itoa(n/idx, s, idx);
    s[i++]=(char)((n%idx) + '0');
}

void itoa_wrap()
{
    char s[10];
    int n = 9876;
    itoa(n, s, 10);
    printf("out : %d\t%s\n", n,s);
    printf("s : %s\n", s);
    reverse(s);
    printf("s : %s\n", s);
}

/* Exercise 4-13
 * Write a recurisve version of the function reverse(s),
 * which reverses the string s in place.
 */

void reverse(char s[])
{
    int l = strlen(s);
    if(l<=1)
        return;
    else {
        char c;
        c = s[l-1];
        s[l-1] = '\0';
        reverse(s+1);
        s[l-1] = s[0];
        s[0] = c;
    }
}


/* Exercise 4-14
 * Define a macro swap(t, x, y) that
 * interchange two arguements of type t. (Block structure will help)
 */

#define swap(t, x, y) \
    do {t tmp;\
     tmp = x;\
     x = y;\
     y = tmp;\
    } while(0);

