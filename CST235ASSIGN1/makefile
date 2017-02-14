CC=gcc
EXT=o
program: q1.$(EXT) q2.$(EXT) q3.$(EXT) program.$(EXT)
	$(CC) -o A1.exe q1.$(EXT) q2.$(EXT) q3.$(EXT) program.$(EXT) -lm
q1.o: q1.c q1.h
	$(CC) -c q1.c
q2.o: q2.c q2.h
	$(CC) -c q2.c
q3.o: q3.c q3.h
	$(CC) -c q3.c
clean: 
	rm *.$(EXT) *.exe