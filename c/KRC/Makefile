
CH = ch2
WARN = -Wall

.PHONY: $(CH)
$(CH): _$(CH).so

_$(CH).so: $(CH).o $(CH)_wrap.o
	gcc  $(WARN) -shared $(CH).o $(CH)_wrap.o -o _$(CH).so

$(CH).o: $(CH).c
	gcc  $(WARN) -fPIC -c $(CH).c

$(CH)_wrap.o: $(CH)_wrap.c
	gcc  $(WARN) -fPIC -c $(CH)_wrap.c -I /usr/include/python2.7/

$(CH)_wrap.c $(CH)_wrap.py: $(CH).i
	swig $(WARN) -python $(CH).i

.PHONY: clean
clean:
	-rm *.o *.so *.pyc  *_wrap.* a.out ch*.py -f


