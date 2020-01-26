#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc ,char *argv[])
{
 int pid;
 printf("Forking the parent procss\n");
 pid=fork();

if(pid==0)
{
//exit(4); note that this would have return exit code 4
//execve() executes the program pointed to by filename. filename must be either a binary executable, or a script starting with a line of the form:
execv(argv[1],argv);
//note that anything below execv command wont be execuit here
//for this particular processs.
printf("Child is existing \n");
exit(4);//this exit code would not be return as program doesnot get here !!
}
printf("Parent wait for child \n");
int exitCode=0;
int childpid=wait(&exitCode);
printf("Child process with PID : %d\n ",(int)childpid);
printf("exicute with code : %d\n",WEXITSTATUS(exitCode));
printf("wait for over\n");






}

