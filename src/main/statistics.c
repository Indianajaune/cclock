#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void stop(int sig){
    printf("CHILD : Stopped by parent with signal %d\n",sig);
    exit(4);
}


int main (void)
{

    FILE *data;

    unsigned short int nb;

    if ((data = fopen("data.txt","r")) == NULL){

        printf("Error! opening file");
 


        exit(1);
    }
    fscanf(data,"%hu", &nb);
    printf("Launches : %hu ", nb);
    fclose(data);
    
    signal(SIGUSR1, stop);
    
    return(0);
    
}

