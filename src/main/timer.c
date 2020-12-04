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

int main(void)
{
    signal(SIGUSR1, stop);
    for(;;)
    {
        sleep(1);
    }
}

