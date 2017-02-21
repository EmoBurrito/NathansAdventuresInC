CC=gcc
EXT=o
program: program.o
	$(CC) -o program.exe program.$(EXT) -lm
program.o: program.c
	$(CC) -c program.c
clean: 
	rm *.$(EXT) *.exe