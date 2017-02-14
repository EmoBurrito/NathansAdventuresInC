CC=gcc
EXT=o
program: DMA.$(EXT) program.o
	$(CC) -o program.exe DMA.$(EXT) program.$(EXT) -lm
DMA.o: DMA.c DMA.h
	$(CC) -c DMA.c
program.o: program.c DMA.h
	$(CC) -c program.c
clean: 
	rm *.$(EXT) *.exe