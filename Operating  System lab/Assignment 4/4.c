#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
 main()
{
int fb;
struct flock lock;
char msg[40];
fb=open("hello.txt",O_RDWR);

if(fb==-1)
{
printf("error file not here in computer");
exit(0);
}

lock.l_type=F_RDLCK;
lock.l_whence=SEEK_SET;
lock.l_start=0;
lock.l_len=0;
lock.l_pid=getpid();

if(fcntl(fb,F_SETLKW,&lock)== -1)
{
printf(" block the terminal\n");
fcntl(fb,F_GETLK,&lock);
read(fb,msg,80);
printf("the msg terminal = %s",msg);
}
else
{
printf(" terminal 2 ");
read(fb,msg,80);
getchar();
lock.l_type=F_UNLCK;
fcntl(fb,F_SETLKW,&lock);

}     

close(fb);
return 0;
}
