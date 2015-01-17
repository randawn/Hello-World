
all:
	swig -Wall -python ch1.i
	gcc -Wall -fPIC -c ch1.c
	gcc -Wall -fPIC -c ch1_wrap.c -I /usr/include/python2.7/
	gcc -Wall -shared ch1.o ch1_wrap.o -o _ch1.so

test:
	gcc -Wall ch1.c

clean:
	rm *.o *.so *.pyc  *_wrap.* a.out -f
