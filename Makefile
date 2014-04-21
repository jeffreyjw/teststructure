all: build

build:
	gcc -o ts.out main.c parameters.c -lm
	
clean:
	rm *.out