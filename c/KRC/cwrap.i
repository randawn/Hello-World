
%module cwrap

%{
#define SWIG_FILE_WITH_INIT
#include "ch1.h"
#include "ch2.h"
#include "ch3.h"
#include "ch4.h"
%}

%include "carrays.i"
%array_class(int, intArray);

int strrindex(char * s, char * t);
double atofn(char * s);
void calculator();

