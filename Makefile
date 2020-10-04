
CC=gcc
.DEFAULT_GOAL := all

jump_calc: src/jump_calc.c
	$(CC) -o jump_calc src/jump_calc.c

calculate:
	./jump_calc
all: jump_calc calculate
clean:
	rm -f jump_calc
