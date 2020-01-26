#include<stdio.h>
#include<pthread.h>
void *hello(void *arg)
{
printf("HELLO WORLD\n");
pthread_exit(0);
}




int main()
{
pthread_t tid;
printf("Before pthread\n");
pthread_create(&tid,NULL,hello,NULL);
pthread_join(tid,NULL);
printf("%d\n",*(unsigned char*)&tid);
printf("After Pthread\n");
return 0;

}

