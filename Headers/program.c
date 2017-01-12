#include <stdio.h>
#include "pingpong.h"
//Don't ever include c files. Just include the h and let it do it's thing.

//Prototype the functions - Declare them, make compiler aware of signature and existence.
void ping();
void pong(); //Gee, that was easy.

int main(void)
{
    ping();
    return 0;
}


