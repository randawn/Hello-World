
#include <stdio.h>

int strrindex(char * s, char * t);      // ex 4-1
double atofn(char * s);                 // ex 4-2
                                        // ex 4-3
#include <stdlib.h> // atof()
#include <ctype.h>
#define MAXOP   100 // max size of operand or operator
#define NUMBER  '0' // signal that a num was found
#define MAXVAL 100  // max depth of val stack
#define BUFSIZE 100
void calculator(void);
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

