compile : Driver.o ex1.o ex2.o stack.o
	gcc Driver.o ex1.o ex2.o stack.o -o myProg

Driver.o : Driver.c ex1.h sorted.txt
	gcc -c Driver.c
ex1.o : ex1.c ex1.h
	gcc -c ex1.c
ex2.o : ex2.c ex1.h
	gcc -c ex2.c
stack.o : stack.c stack.h
	gcc -c stack.c
	

run : Driver.o ex1.o ex2.o stack.o
	make compile
	./myProg
