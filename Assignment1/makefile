all: stack

stack_asm: main.c stack.c
	gcc -S main.c
	gcc -S stack.c

stack: main.o stack.o
	gcc main.o stack.o -o Assignment1

main.o: main.c
	gcc -c main.c

stack.o: stack.c
	gcc -c stack.c

debug: main.c stack.c
	gcc main.c stack.c -g -o Assignment1_Debug

clean:
	@[ -f ./Assignment1 ] && rm *o Assignment1 || true
	@[ -f ./Assignment1_Debug ] && rm Assignment1_Debug || true
