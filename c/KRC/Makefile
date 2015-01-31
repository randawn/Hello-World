
CH = ch1
WARN = -Wall

# ch1_wrap.c ch1_wrap.py 
# ch1_wrap.c ch1_wrap.py ch1.o 
# ch1_wrap.c ch1_wrap.py ch1.o ch1_wrap.o 
# ch1_wrap.c ch1_wrap.py ch1.o ch1_wrap.o _ch1.so 

$(CH):
	swig $(WARN) -python $(CH).i
	gcc  $(WARN) -fPIC -c $(CH).c
	gcc  $(WARN) -fPIC -c $(CH)_wrap.c -I /usr/include/python2.7/
	gcc  $(WARN) -shared $(CH).o $(CH)_wrap.o -o _$(CH).so

.PHONY: clean
clean:
	rm *.o *.so *.pyc  *_wrap.* a.out -f


