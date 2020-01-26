#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<utmp.h>

void printusers()
{
int logsize=3;
FILE *fp=fopen("/var/run/utmp","r");
     if(fp==NULL)
        perror("file error");
    else
      {
       struct utmp *user;
        setutent();
        user=getutent();
       while(user)
        {
        if(user->ut_type==USER_PROCESS)
                printf("-->%s\n",user->ut_user);
                user=getutent();
      }
  fclose(fp);
  }
}
int main()
{
        printf("before the forking ");
        printf("parent's pid is %d\n",(int)getpid());
        printf("parent PPID is %d\n",(int)getppid());

        printf("forking processing\n");
        pid_t pid=fork();
//display child procss pid and ppid 
                if(pid==0)
                        {
                  printf("inside the child procss\n");
                  printf("id of the child pid is : %d\n",getpid());
                  printf("id of the child PPID is :%d\n",getppid());
        pid_t pid1=fork();

                        if(pid1==0)
                              {
                                printf("inside the granchild\n ");
                                printf("id of the child pid is : %d\n",getpid());
                                printf("id of the child PPID is :%d\n",getppid());
                                printusers();
                                exit(0);
                                }
                wait(NULL);
                printf("Child stops waiting for grandchild\n");
                exit(0);


                      }
wait(NULL);
printf("Parent stop waiting for child\n");
return 0;
}


