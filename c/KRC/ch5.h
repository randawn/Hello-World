
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUL '\0'

int getint(int *pn);                    // ex 5-1
int getch(void);
void ungetch(int c);
int getfloat(float *pn);                // ex 5-2
void strcate(char *s, char *t);         // ex 5-3
int strend(char *s, char *t);           // ex 5-4
char *strncpy_(char *s, const char *ct, int n); // ex 5-5
char *strncat_(char *s, const char *ct, int n);
int strncmp_(const char *cs, const char *ct, int n);
void str_wrap(void);
int day_of_month(int month, bool leap); // ex 5-8
bool is_leap(int year);
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

