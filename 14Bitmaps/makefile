CC=gcc
EXT=o
executable:bitmap program
	$(CC) -o program.exe bitmap.$(EXT) program.$(EXT) -lm
bitmap:
	$(CC) -c bitmap.c
program:
	$(CC) -c program.c
clean:
	rm *.$(EXT) *.exe