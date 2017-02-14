#ifndef FILEIO_H_
#define FILEIO_H_
#define MAXSIZE 100
#define MAX_NAME_SIZE 20
#define NUM_RECORDS 3

int demoOpenClose(const char *, const char *);
int demoRead(const char *, const char *);
int demoWrite(const char *, const char *, const char *);
int demoWriteBinary(const char *, const char *, const int *);

//Practice writing to file (binary)
int exerciseBinaryWrite(const char* fileName, const char * fileMode);
int exerciseBinaryRead(const char * filename, const char * fileMode, int id);

#endif // FILEIO_H_INCLUDED
