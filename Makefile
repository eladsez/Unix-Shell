CC = gcc
DEBUG = -g -Wall
LIB_OBJ = cmd_helper.o util.o history.o
# SOURCES = main.c

all:myshell

run:myshell
	./myshell && make clean

myshell: main.o shell_lib.a
	$(CC) $(DEBUG) main.o shell_lib.a -o myshell

shell_lib.a: $(LIB_OBJ)
	ar -rcs shell_lib.a $(LIB_OBJ)

%.o: %.c
	$(CC) $(DEBUG) -c -o $@ $<

clean:
	rm -f *.o *.a test* myshell
