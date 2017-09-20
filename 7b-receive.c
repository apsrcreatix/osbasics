#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct alpha
{
long mnum;
char mtext[15];
}s1,s2,r1;

int main()
{int mqid,v1,v2;

mqid=msgget((key_t)26,IPC_CREAT|0666);


printf("is responsible to receive the data\n");

v2=msgrcv(mqid,&r1,16,1,0);

printf("message succesfully received\n");
printf("message received is %s\n",&r1.mtext);
return 0;
}
