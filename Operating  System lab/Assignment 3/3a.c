#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
void my(int sig)
{
int d;
int a=0,b=1,c=0,n,i=0,result,p[2],pid;
//enter the n value;
//pipe create;
if(pipe(p)<0)
{
printf("messange canot be send");
exit(0);
}
printf("enter N for the fibonacci series :");
scanf("%d",&n);

        if(n>0)
                {
                a=fork();
                        if(a<0)
                        printf("create unsuccesfully fork()");

                else
                {

                        if(a==0)
                                {       close(p[0]);

                                printf("child process sucsesfully create\n");
                                printf("inside the child process\n");
                                pid=getpid();
                                write(p[1],&pid,sizeof(int));
                                if(n==1)
                                write(p[1],&a,sizeof(int));
                                else if(n>=2)
                                        {
                        write(p[1],&a,sizeof(int));
                        write(p[1],&b,sizeof(int));
                                for(i=0;i<n-2;i++)
                                        {
                                         c=a+b;
                                         a=b;
                                        b=c;
                        write(p[1],&c,sizeof(int));
                                         }
                         write(p[1],&sig,sizeof(int));
                           }//ELSE
                  close(p[1]);
                      }

        else
                {
                close(p[1]);
                printf("inside the parent\n");
                read(p[0],&pid,sizeof(int));
                printf("ID of chile process :%d\n",pid);

             wait(NULL);
                printf("the fibonacci series is :");
                for(i=0;i<n;i++)
                  {
                        read(p[0],&result,sizeof(int));
                        printf("%d",result);
                  }
        read(p[0],&result,sizeof(int));
        printf("\nthe signal id :%d\n",result);
        close(p[0]);
                printf("fibanacci series complete\n");                                        
                 }


   }
}
else
 printf("invalide value of n");
exit(1);

}



int main()
{

int i;
signal(SIGINT,my);
while(1);
{
sleep(1);
}
return 0;
}
  


















