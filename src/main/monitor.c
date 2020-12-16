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

int monitor()
{

    const char * top = "vmstat 2";
    int cr = system(top);

    if(cr != 0)
    {
        fprintf( stderr, "Impossible de lancer la commande : %s\n", top );
    }

    return 0;
}

