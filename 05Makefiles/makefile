#Can create macros by assigning them at top, like a define. Used incase you switch to Microsoft's compiler, you don't have to huntdown every "gcc" in the document
CC=gcc
EXT=o
statistics:display.$(EXT) mathfuncs.$(EXT) stats.$(EXT) #This line is whatever you called the others. Could say "Bryce" if you wanted
	$(CC) -o stats.exe display.$(EXT) mathfuncs.$(EXT) stats.$(EXT) -lm # Normally, you'd put your linker here to link these three together. GCC is integrated compiler/linker
	# -lm is required for linux to link in the library, not sure why
display.o: display.c mathfuncs.h
	$(CC) -c display.c
mathfuncs.o: mathfuncs.c mathfuncs.h
	$(CC) -c mathfuncs.c #Only compile the source code, not the header files
stats.o: stats.c mathfuncs.h
	$(CC) -c stats.c #Don't want an executable yet, so use -c
clean: #This will run at the end. Can put whatever command line statements you want
	rm *.$(EXT) *.exe #Use del on DoS. When you clean a project in Eclipse, this is exactly what it's doing