#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <pthread.h>
#include <errno.h>
#include <setjmp.h>
#include <fcntl.h>
#include <assert.h>
#include <iso646.h>



int main(void);
void sig_handler(int);

int main()
{
    printf("%c \a",7);
    int status ;
    signal(SIGCHLD,sig_handler);
    unsigned short int N=0,nbr;
    pid_t index[USHRT_MAX];
    char * argv[3];
    FILE *fptr;

    if ((fptr = fopen("data.txt","r")) == NULL){
        printf("Error! opening file");

        
        exit(1);
    }

    fscanf(fptr,"%hu", &nbr);
    fclose(fptr);
    if ((fptr = fopen("data.txt","w")) == NULL){
        printf("Error! opening file");

        
        exit(1);
    }
    fprintf(fptr,"%d",nbr+1);
    fclose(fptr);

        printf("\x1B[34m        ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄   ▄\n");
        printf("       █       █       █   █   █       █       █   █ █ █\n");
        printf("       █       █       █   █   █   ▄   █       █   █▄█ █\n");
        printf("       █     ▄▄█     ▄▄█   █   █  █ █  █     ▄▄█      ▄█\n");
        printf("       █    █  █    █  █   █▄▄▄█  █▄█  █    █  █     █▄\n");
        printf("       █    █▄▄█    █▄▄█       █       █    █▄▄█    ▄  █\n");
        printf("       █▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄█ █▄█\n \n \x1B[37m \n");
    
    printf( "_____________________________________________\n" );
    printf("\nPlease choose one of the following options:\n\n" );
    printf("r. Alarm\n");
    printf("c. Chronometer\n");
    printf("t. Timer\n");
    printf("m. Monitor\n");
    printf("s. Statistics\n");
    printf("e.Exit\n");
    printf( "_____________________________________________\n\n" );
    printf( "\t\t \e[5m Enter Choice: \e[25m \t" );

do{
    assert(N<=USHRT_MAX);
    char menu = ' ' ;
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
                    argv[1]="1";
                    argv[2]=NULL;
                    execv("alarm",argv);
                    //execl("/Applications/Utilities/XQuartz.app","xterm","-e" ,"./alarm", "alarm", NULL);
                }
                printf("alarm clock opened in another window \n") ;
        break ;
                
        case 'C':
                index[N]=fork();
                N++;
                
                if(index[N-1] == 0){
                    argv[0]="chronometer";
                    argv[1]=NULL;
                    execv("chronometer",argv);
                    //execl("/Applications/Utilities/XQuartz.app","xterm","-e" ,"./chronometer", "chronometer", NULL);
                }
                printf("chronometer opened in another window \n") ;
        break ;
                
        case 'T':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="timer";
                    argv[1]=NULL;
                    execv("timer",argv);
                    //execl("/Applications/Utilities/XQuartz.app","xterm","-e" ,"./timer", "timer", NULL);
                }
                printf("timer opened in another window \n") ;
        break ;
                
        case 'S':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="statistics";
                    argv[1]=NULL;
                    execv("statistics",argv);
                    //execl("/Applications/Utilities/XQuartz.app","xterm","-e" ,"./statictics", "statictics", NULL);
                }
                printf("statistics opened in another window \n") ;
        break ;
                
        case 'M':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="monitor";
                    argv[1]=NULL;
                    //execv("monitor",argv);
                    execl("/Applications/Utilities/XQuartz.app","xterm","-e" ,"./monitor", "monitor", NULL);
                }
                printf("monitoring opened in another window \n") ;
        break ;
                
        case 'E':
                for(unsigned short int i = 0;i<N;i++){
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


void sig_handler(int sig){
    switch(sig){
        case SIGHUP :
            
            break;
        case SIGINT :
            
            break;
            
        case SIGQUIT :
            
            break;
            
        case SIGILL :
            
            break;
            
        case SIGTRAP :
            
            break;
            
        case SIGABRT :
            
            break;
            
        case SIGBUS :
            
            break;
            
        case SIGFPE :
            
            break;
            
        case SIGKILL :
            
            break;
            
        case SIGUSR1 :
            
            break;
            
        case SIGUSR2 :
            
            break;
            
        case SIGSEGV :
            
            break;
            
        case SIGPIPE :
            printf("\n \e[31m Consoomer has died press F to pay your respects!\x1B[37m \n");
            break;
            
        case SIGALRM :
            
            break;
            
        case SIGTERM :
            
            break;
            
        case SIGCHLD :
            printf("\n \e[31m Child has died press F to pay your respects!\x1B[37m \n");
                
            
            break;
            
        case SIGCONT :
            
            break;
            
        case SIGSTOP :
            
            break;
            
        case SIGXCPU :
            exit(EXIT_FAILURE);
            break;
            
        default :
            printf("\n What the fuck happened? \n");
            
    }
    
}



/*

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <pthread.h>




void DisplayMainMenu()
{
    printf("\x1B[34m        ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄   ▄\n");
    printf("       █       █       █   █   █       █       █   █ █ █\n");
    printf("       █       █       █   █   █   ▄   █       █   █▄█ █\n");
    printf("       █     ▄▄█     ▄▄█   █   █  █ █  █     ▄▄█      ▄█\n");
    printf("       █    █  █    █  █   █▄▄▄█  █▄█  █    █  █     █▄\n");
    printf("       █    █▄▄█    █▄▄█       █       █    █▄▄█    ▄  █\n");
    printf("       █▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄█ █▄█\n \n \x1B[37m \n");
    printf( "_____________________________________________\n" );
    printf("\nPlease choose one of the following options:\n\n" );
    printf("r. Alarm\n");
    printf("c. Chronometer\n");
    printf("t. Timer\n");
    printf("m. Monitor\n");
    printf("s. Statistics\n");
    printf("e.Exit\n");
    printf( "_____________________________________________\n\n" );
    printf( "\t\tEnter Choice:\t" );

}

int main(void)
{
    unsigned short int N=0;
    pid_t index[USHRT_MAX];
    int status ;
    char * argv[2];



do{
char menu = ' ' ;
DisplayMainMenu();
scanf(" %c", &menu) ;
menu = toupper(menu) ;
    fflush(NULL);

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
                printf("\n alarm clock opened in another window \n") ;
        break ;
                
        case 'C':
                index[N]=fork();
                N++;
                
                if(index[N-1] == 0){
                    argv[0]="chronometer";
                    argv[1]=NULL;
                    execvp("chronometer",argv);
                }
                printf("\n chronometer opened in another window \n") ;
        break ;
                
        case 'T':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="timer";
                    argv[1]=NULL;
                    execvp("timer",argv);
                }
                printf("\n timer opened in another window \n") ;
        break ;
                
        case 'S':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="statistics";
                    argv[1]=NULL;
                    execvp("statistics",argv);
                }
                printf("\n statistics opened in another window \n") ;
        break ;
                
        case 'M':
                index[N]=fork();
                N++;

                if(index[N-1] == 0){
                    argv[0]="monitor";
                    argv[1]=NULL;
                    execvp("monitor",argv);
                }
                printf("\n monitoring opened in another window \n") ;
        break ;
                
        case 'E':
                for(unsigned short int i = 0;i<N;i++){
                    printf("\ntest %u \n",N);
                kill(index[i],SIGUSR1);
                    printf("\ntest %u \n",N);
                wait(&status);
                    printf("\ntest %u \n",N);
                printf("\n Child program stopped with status %d\n", status>>8);
                };
                return 0 ;
        break ;
                
        default:
                printf("\n Invalid selection \n") ;

        }

        }while (true);



    }

*/
