#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void stop(int sig)
{
    printf("CHILD : Stopped by parent with signal %d\n",sig);
    exit(3);
}

int main(void)
{
    signal(SIGUSR1, stop);
    time_t start, stop;
    int laps;
    int space;
    int nb;

    nb = 0;

    start=time(NULL);

    while(nb != '3')
    {
        printf("Appuyez sur ESPACE puis ENTREE pour passer le tour");
        do
        {
            space = getchar();  
        }

        while(space!=' ');

            stop=time(NULL) ;
            laps = difftime(stop, start);
            printf("\n\nTour : %d.00s\n\n", laps);
            start=time(NULL);

        nb++;
    }
    return 0;
}