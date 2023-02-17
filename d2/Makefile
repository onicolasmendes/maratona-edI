all: peixoto.o
	@gcc peixoto.o -o programa -Wall
	@rm -rf *.o
peixoto.o: peixoto.c
	@gcc -c peixoto.c -Wall
run:
	@./programa
