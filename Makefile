CC = gcc
DEBUG = -g -Wall
LIB_OBJ = obj/cmd_helper.o obj/util.o obj/history.o
SHELL_OBJ = obj/main.o obj/shell_lib.a

all:myshell

run:myshell
	./myshell && make clean

myshell: obj $(SHELL_OBJ)
	$(CC) $(DEBUG) $(SHELL_OBJ) -o myshell

obj/shell_lib.a: obj $(LIB_OBJ)
	ar -rcs obj/shell_lib.a $(LIB_OBJ)

obj/%.o: src/%.c
	$(CC) $(DEBUG) -c -o $@ $<

obj: .history
	mkdir -p obj

.history:
	@echo "You don't have any history yet." > .history

clean:
	rm -f *.o *.a test* myshell .history
	rm -rf obj
