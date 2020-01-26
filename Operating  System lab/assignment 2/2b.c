#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
int main()
{
pid_t pid;
printf("enter the process ID ");
scanf("%d",&pid);
kill(pid,SIGKILL);
return 0;
}


