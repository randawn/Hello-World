
CH = ch4
WARN = -Wall
DEBUG = -g
TOOL = g++

.PHONY: $(CH)
$(CH): _cwrap.so

_cwrap.so: $(CH).o cwrap.o
	$(TOOL)  $(WARN) $(DEBUG) -shared $(CH).o cwrap.o -o _cwrap.so

$(CH).o: $(CH).c
	$(TOOL)  $(WARN) $(DEBUG) -fPIC -c $(CH).c

cwrap.o: cwrap.c
	$(TOOL)  $(WARN) $(DEBUG) -fPIC -c cwrap.c -I /usr/include/python2.7/

cwrap.c cwrap.py: cwrap.i
	swig $(WARN) -python -o cwrap.c cwrap.i

.PHONY: clean
clean:
	-rm *.o *.so *.pyc  cwrap.{py,c} a.out ch*.py -f

