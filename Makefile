CC = gcc
DEBUG = -g -Wall
LIB_OBJ = obj/cmd_helper.o obj/util.o obj/history.o
SHELL_OBJ = obj/main.o obj/shell_lib.a
# SOURCES = main.c

all:myshell

run:myshell
	./myshell && make clean

myshell: $(SHELL_OBJ)
	$(CC) $(DEBUG) $(SHELL_OBJ) -o myshell

obj/shell_lib.a: $(LIB_OBJ)
	ar -rcs obj/shell_lib.a $(LIB_OBJ)

obj/%.o: src/%.c obj
	$(CC) $(DEBUG) -c -o $@ $<

obj:
	mkdir -p obj

clean:
	rm -f *.o *.a test* myshell
	rm -rf obj
