#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>


#define MAX 64


int main(void)
{
    unsigned short int N=0;
    pid_t index[USHRT_MAX];
    int status ;
    char * argv[2];


        printf("\x1B[34m        ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄   ▄\n");
        printf("       █       █       █   █   █       █       █   █ █ █\n");
        printf("       █       █       █   █   █   ▄   █       █   █▄█ █\n");
        printf("       █     ▄▄█     ▄▄█   █   █  █ █  █     ▄▄█      ▄█\n");
        printf("       █    █  █    █  █   █▄▄▄█  █▄█  █    █  █     █▄\n");
        printf("       █    █▄▄█    █▄▄█       █       █    █▄▄█    ▄  █\n");
        printf("       █▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄█ █▄█\n \n \x1B[37m \n");

do{
char menu = ' ' ;
printf("input menu letter? ") ;
scanf(" %c", &menu) ;
menu = toupper(menu) ;
/* case */
switch(menu)
        {
        case 'R':
                
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="alarm";
                    argv[1]=NULL;
                    execvp("alarm",argv);
                }
                printf("alarm clock opened in another window \n") ;
        break ;
                
        case 'C':
                index[N]=fork();
                N++;
                
                if(index[N-1] == 0){
                    argv[0]="chronometer";
                    argv[1]=NULL;
                    execvp("chronometer",argv);
                }
                printf("chronometer opened in another window \n") ;
        break ;
                
        case 'T':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="timer";
                    argv[1]=NULL;
                    execvp("timer",argv);
                }
                printf("timer opened in another window \n") ;
        break ;
                
        case 'S':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="statistics";
                    argv[1]=NULL;
                    execvp("statistics",argv);
                }
                printf("statistics opened in another window \n") ;
        break ;
                
        case 'M':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="monitor";
                    argv[1]=NULL;
                    execvp("monitor",argv);
                }
                printf("monitoring opened in another window \n") ;
        break ;
                
        case 'E':
                for(unsigned short int i =0;i<N;i++){
                kill(index[i],SIGUSR1);
                wait(&status);
                printf("PARENT : Child stopped with status %d\n", status>>8);
                }
                return 0 ;
        break ;
                
        default:
                printf("Invalid selection \n") ;

        }

        }while (true);



    }

