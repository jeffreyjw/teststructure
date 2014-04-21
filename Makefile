all: build

build:
	gcc -o ts.out main.c -lm
	
clean:
	rm *.out