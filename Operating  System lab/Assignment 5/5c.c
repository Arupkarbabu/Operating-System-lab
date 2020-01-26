#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer{

long msg_key;
char msg_text[100];
}msg;



int main()
{

key_t key;
int msgid;
key=12;
printf("%d",key);

msgid= msgget(key ,0666 |IPC_CREAT);
msgrcv(msgid, &msg,sizeof(msg),1,0);
printf("receve : %s\n",msg.msg_text);
msgctl(msgid ,IPC_RMID ,NULL);
return 0;

}


