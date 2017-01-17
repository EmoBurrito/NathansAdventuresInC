#include <stdio.h>
#include "pingpong.h"

void ping()
{
    printf("Ping\n");
    pong();
}

void pong()
{
    //static essentially makes iCount a global variable for each instance of pong()
    static int iCount = 0;
    iCount++;
    printf("Pong\n");
    if (iCount < 10)
    {
        ping();
    }
}
