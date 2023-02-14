default: eleves

all: eleves

clean:
	rm *.o  eleves

eleves: eleves.o main3.o
	gcc eleves.o main3.o -o $@

%.o: %.c 
	gcc -c $<

eleves.o: eleves.h
main3.o: main3.c