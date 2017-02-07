#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED
#define MAXSIZE 100

int demoOpenClose(const char *, const char *);
int demoRead(const char *, const char *);
int demoWrite(const char *, const char *, const char *);
int demoWriteBinary(const char *, const char *, const int *);

#endif // FILEIO_H_INCLUDED
