#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void stop(int sig){
    printf("CHILD : Stopped by parent with signal %d\n",sig);
    exit(3);
}

int main(void)
{
    signal(SIGUSR1, stop);

    time_t rawtime;
    struct tm * timeinfo, timetoring;
    char buffer [80];

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    strftime (buffer,80,"%H:%M:%S %d/%m/%y.",timeinfo);
    puts (buffer);

    return 0;

}
