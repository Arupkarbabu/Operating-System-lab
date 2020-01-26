#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void create_child(int sig)
{
int a=fork();
        if(a<0)
                {
                printf("child process creation unsuessfull\n");
                 }
        else
                {
                        if(a==0)
                                {

                                printf("child process create sucessfully\ninside the child ");
                                printf("the ID of the child process is :%d",getpid());
                                printf("the ID of the parent process is :%d",getppid());

                                }
                        else {
                                printf("inside parent process\n");
                                printf("The ID of the parent process :%d\n",getpid());
                                printf("The ID of the child process : %d\n",getppid());
                            }


}

}
int main()
{
//SIGINT  interactive attention request sent to the program.
signal(SIGINT ,create_child);
while(1)
{
sleep(1);

}
return 0;
}
