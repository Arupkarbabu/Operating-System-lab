#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
int fd;
char *myfifo="/temp/myfifo";
mkfifo(myfifo,0666);
char str1[60],str2[70];

while(1)
{
fd=open(myfifo,O_WRONLY);
fgets(str1,80,stdin);
write(fd,str1,strlen(str1)+1);
close(fd);

fd=open(myfifo,O_RDONLY);
read(fd,str2,sizeof(str2));
printf("user2:%s\n",str2);





}
return 0;



}

