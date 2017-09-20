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
{
int mqid,v1,v2;

mqid=msgget((key_t)26,IPC_CREAT|0666);



printf("program 1 running\n");

s1.mnum=1;
strcpy(s1.mtext,"hello");


v1=msgsnd(mqid,&s1,sizeof(s1.mtext),0);


if(v1<0)

{
printf("message sending failed");

}
else
{

printf("message send succesfully\n");
printf("the message send is %s",&s1.mtext);

return 0;
}
}

