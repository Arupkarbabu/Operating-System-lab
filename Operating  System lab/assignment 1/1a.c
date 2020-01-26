#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{

int pid;
int pid1;
pid=fork();

        if(pid<0)
                {
                printf("child process create unsucessfully");
                exit(1);
                }
        else
                {
                        pid1=fork();
                        if(pid==0)
                                {
                        printf("child process create sucessfully\n inside the child process\n");
                        printf("the id of the child process pid is  :%d\n",getpid());
                        printf("the id of the parent process ppid is :%d\n",getppid());

                           if(pid1==0)
                                        {
                                                printf("inside the grandchild\n");
                                                printf("ROLLNO : CSB17031\n");
                                                printf(" the id for grandchild process pid is %d\n",getpid());
                                                printf(" the id for granchild process ppid is %d\n",getppid());

                                                exit(0);
                                        }

                                }
                        else
                                {
                                printf("inside parent  process\n");
                                printf("the id of parent process pid:%d\n",getpid());
                                printf("the id of the child process :%d\n",pid);
                                }
                }
exit(0);
}


