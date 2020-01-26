 #include<stdio.h>
 # include<sys/types.h>
 # include<sys/times.h>
 # include<sys/time.h>
 # include<sys/wait.h>
 # include<unistd.h>
 # include<stdlib.h>

 int main(){
       int a, b, i;
       FILE *fp = fopen("mona.txt","w+");
          a = fork();

            if (a<0)
                 {
                         printf("Child Process Creation Unsuccessful\n");
                             exit(1);
                                 }
             else
                     {
                             if(a == 0){
                                         int a = 0;
                                         struct tms a1, a2;
                                         times(&a1);
                                         for(i=0;i<1000000;i++){
                                              printf("A");
                                              a = a + 1;
                                         }
                                         printf("Child Process Created Successfully\nInside The Child Process\n");
                                         //printf("Enter To Terminate The Child Process");
                                         times(&a2);
                                         fprintf(fp,"User Time Used By Child Process\nCreation Time : %ld secs And Termination Time : %ld secs\n", a1.tms_utime,a2.tms_utime);
                                         fprintf(fp,"System Time Used By Child Process\nCreation Time : %ld secs And Termination Time : %ld secs\n", a1.tms_stime,a2.tms_stime);
                             }
                                     else{
                                                printf("Inside Parent Process\n");
                                                wait(NULL);
                                 }

                         }

             exit(0);
}

