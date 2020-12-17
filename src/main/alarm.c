#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void stop(int sig){
    printf("CHILD : Stopped by parent with signal %d\n",sig);
    exit(1);
}


const int HOUR_TO_MIN = 60;
const int MIN_TO_SEC = 60;
const int HOUR_TO_SEC = 3600;

int main(int argc, char **argv)
{
    signal(SIGUSR1, stop);
    
    
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    strftime (buffer,80,"%H:%M:%S %d/%m/%y.",timeinfo);
    puts (buffer);
    
    int duration_in_sec = ((argc > 1) ? atoi(argv[1]) :  7) * HOUR_TO_SEC;

    for (int remaining_time_time_in_sec = duration_in_sec; remaining_time_time_in_sec >= 0; remaining_time_time_in_sec -= MIN_TO_SEC) {
        int h = (remaining_time_time_in_sec / HOUR_TO_SEC);
        int m = (remaining_time_time_in_sec - h * HOUR_TO_SEC) / HOUR_TO_MIN;
        int s = (remaining_time_time_in_sec - h * HOUR_TO_SEC - m * MIN_TO_SEC);

        printf("\nTime remaining till alarm %02d:%02d:%02d \n", h, m, s);
        fflush(stdout);
        sleep(MIN_TO_SEC);
    }

    
    printf("\nTime up.. %c\a \n",7);
    return 0;
}


