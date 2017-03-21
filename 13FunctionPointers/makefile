CC=gcc
EXT=o
executable:funcs program
	$(CC) -o program.exe program.$(EXT) funcs.$(EXT) -lm
funcs:
	$(CC) -c funcs.c
program:
	$(CC) -c program.c
clean:
	rm *.$(EXT) *.exe