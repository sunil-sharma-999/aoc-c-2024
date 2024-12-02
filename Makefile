CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 \
         -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
         -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 \
         -Wwrite-strings -Waggregate-return -Wcast-qual \
         -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code

all: \
	day1.0 \
	
day1.0: src/day1.0.c
	$(CC) $(CFLAGS) $< -o $@.o

clean:
	rm -rf ./*.o