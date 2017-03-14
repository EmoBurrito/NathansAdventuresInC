CC=gcc
EXT=o
executable:structs.$(EXT) program.$(EXT)
	$(CC) -o program.exe program.$(EXT) structs.$(EXT) -lm
structs.o:
	$(CC) -c structs.c
program.o:
	$(CC) -c program.c
clean:
	rm *.$(EXT) *.exe