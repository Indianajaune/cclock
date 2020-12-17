#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void stop(int sig){
    printf("CHILD : Stopped by parent with signal %d\n",sig);
    exit(5);
}

int main(void)
{
    signal(SIGUSR1, stop);


    int h,m,s;

    printf("\n\n*******Format du compte a rebours : HH : MM : SS*******\n\n");
    printf("Entrer le temps du compte a rebours : \n");
    printf("Heures : ");
    scanf("%d", &h);
    printf("\nMinutes : ");
    scanf("%d", &m);
    printf("\nSecondes : ");
    scanf("%d", &s);
    while(h>=0)
    {
        while(m>=0)
        {
            while(s>=0)
            {
                system("clear");
                printf("\n%02d : %02d : %02d\n",h,m,s);
                sleep(1);
                s--;
            }
            s=59;
            m--;
        }
        m=59;
        h--;
    }
    return(0);
}

