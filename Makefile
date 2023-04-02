CC = gcc
DEBUG = -g
LIB_OBJ = cmd_helper.o util.o history.o
# SOURCES = main.c

all:shell

run:shell
	./myshell && make clean

shell: history.o util.o cmd_helper.o shell_lib.a main.o
	$(CC) $(DEBUG) main.o shell_lib.a -o myshell

shell_lib.a: $(LIB_OBJ)
	ar -rcs shell_lib.a $(LIB_OBJ)

%.o: %.c
	$(CC) $(DEBUG) -c -o $@ $<

clean:
	rm -f *.o *.a test* myshell
