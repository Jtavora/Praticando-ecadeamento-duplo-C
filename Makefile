programa: arq.o
	gcc functions.o encadeamentoduplo.o -o programa.exe

arq.o: Encadeamentoduplo.c Encadeamentoduplo.h Functions.c
	gcc -c -g Functions.c -o functions.o
	gcc -c -g Encadeamentoduplo.c -o encadeamentoduplo.o

run: programa 
	./programa.exe

clean:
	rm functions.o encadeamentoduplo.o programa.exe

all: programa run clean