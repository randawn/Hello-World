
#include <stdio.h>
#include <string.h>

int strrindex(char * s, char * t);      // ex 4-1
double atofn(char * s);                 // ex 4-2
#include <ctype.h>
#include <math.h>
                                        // ex 4-3
                                        // ex 4-4
                                        // ex 4-5
                                        // ex 4-6 TODO
#include <stdlib.h> // atof()
#define MAXOP   100 // max size of operand or operator
#define NUMBER  '0' // signal that a num was found
#define CMD     '1' // signal that a cmd was found
#define MAXVAL 100  // max depth of val stack
#define BUFSIZE 100
void calculator(void);
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void calhelp();
void ungets(char * s);                  // ex 4-7
int getch_(void);                         // ex 4-8
void ungetch_(int);
