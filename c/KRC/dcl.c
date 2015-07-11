
// recursive-descent parser

//dcl is based on the grammar that specifies a declarator,
//dcl:        optional *'s direct-dcl
//direct-dcl: name
//            (dcl)
//            direct-dcl()
//            direct-dcl[optional size]

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;          // type of last token
char token[MAXTOKEN];   // last token string
char name[MAXTOKEN];    // id name
char datatype[MAXTOKEN];// data type: char, int, etc.
char out[1000];         // output string
int getch(void);
void ungetch(int);

// convert declaration to words
int main(void)
{
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

void dcl(void)
{
    int ns;
    for(ns=0; gettoken()=='*'; )
        ns++;   // count *'s
    dirdcl();
    while(ns-->0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;
    if (tokentype=='('){
        dcl();
        if(tokentype!=')'){
            printf("error: missing )\n");
        }
    } else if (tokentype == NAME)
        strcpy(name, token);
    else
        printf("error: expected name or (dcl). got %c\n", tokentype);
    while ((type=gettoken())==PARENS ||
            type==BRACKETS) {
        if (type==PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int gettoken(void)
{
    int c;
    char *p = token;
    while((c=getch())==' ' || c=='\t')
        ;
    if (c=='('){
        if ((c=getch())==')'){
            strcpy(token, "()");
            return tokentype=PARENS;
        } else {
            ungetch(c);
            return tokentype= '(';
        }
    } else if (c=='['){
        for (*p++=c; (*p++=getch() != ']');)
            ;
        *p='\0';
        return tokentype= BRACKETS;
    } else if (isalpha(c)){
        for (*p++=c; isalnum(c=getch());)
            *p++=c;
        *p='\0';
        ungetch(c);
        return tokentype= NAME;
    } else
        return tokentype= c;
}

#define GETCHV
#ifdef GETCHV
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;
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
#else
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
#endif
