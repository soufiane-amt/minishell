#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void if_sig(int sig)
{
    printf(" sig is %d\n", sig);
    exit(1);
}

int main()
{
    
    if (getchar() == EOF)
        exit(1);
    while (1);
}