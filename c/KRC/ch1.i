%module ch1_wrap

%{
#define SWIG_FILE_WITH_INIT
#include "ch1.h"
%}
//#include "ch1.h"

void reverseLineWrap(void);
