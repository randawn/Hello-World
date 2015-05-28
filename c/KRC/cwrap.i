
%module cwrap

%{
#define SWIG_FILE_WITH_INIT
#include "ch1.h"
#include "ch2.h"
#include "ch3.h"
#include "ch4.h"
#include "ch5.h"
%}

%include "carrays.i"
%array_class(int, intArray);


%include "typemaps.i"

//int getint(int *pn);
int getint(int *INOUT);
//int getfloat(float *pn);
int getfloat(float *INOUT);

void strcate(char *s, char *t);
int strend(char *s, char *t);

void str_wrap(void);

int day_of_year(int year, int month, int day);
//void month_day(int year, int yearday, int *pmonth, int *pday);
void month_day(int year, int yearday, int *OUTPUT, int *OUTPUT);



