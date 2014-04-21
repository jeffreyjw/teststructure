all: build

build:
	gcc -o ts.out main.c parameters.c parser.c file_to_string.c -lm
	
clean:
	rm *.out