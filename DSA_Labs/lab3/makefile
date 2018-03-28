compile : ex2.o ex3.o ex5.o cycle1.o Driver.o
	gcc ex2.o ex3.o ex5.o cycle1.o Driver.o -o myProg

ex2.o : ex2.c ex3.h
	gcc -c ex2.c
ex3.o : ex3.c ex3.h
	gcc -c ex3.c
ex5.o : ex5.c ex3.h
	gcc -c ex5.c
cycle1.o : cycle1.c ex3.h
	gcc -c cycle1.c
Driver.o : Driver.c ex3.h
	gcc -c Driver.c
	
	
	
run: ex2.o ex3.o ex5.o cycle1.o Driver.o
	gcc ex2.o ex3.o ex5.o cycle1.o Driver.o -o myProg
	./myProg
