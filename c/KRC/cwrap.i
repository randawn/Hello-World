
%module cwrap

%{
#define SWIG_FILE_WITH_INIT
#include "ch1.h"
#include "ch2.h"
#include "ch3.h"
%}

%include "carrays.i"
%array_class(int, intArray);

void itoaw_wrap();

