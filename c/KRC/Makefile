
CH = ch2
WARN = -Wall

.PHONY: $(CH)
$(CH): _cwrap.so

_cwrap.so: $(CH).o cwrap.o
	gcc  $(WARN) -shared $(CH).o cwrap.o -o _cwrap.so

$(CH).o: $(CH).c
	gcc  $(WARN) -fPIC -c $(CH).c

cwrap.o: cwrap.c
	gcc  $(WARN) -fPIC -c cwrap.c -I /usr/include/python2.7/

cwrap.c cwrap.py: cwrap.i
	swig $(WARN) -python -o cwrap.c cwrap.i

.PHONY: clean
clean:
	-rm *.o *.so *.pyc  cwrap.{py,c} a.out ch*.py -f


