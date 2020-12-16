#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void stop(int sig){
    printf("CHILD : Stopped by parent with signal %d\n",sig);
    exit(3);
}


void main (void)
{

    signal(SIGUSR1, stop);
    
    system("free -a");
    
}

