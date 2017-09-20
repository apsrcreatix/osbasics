/*
*Name : Aditya Pratap Singh Rajput
*Registration Number : RA1511008010237
*Aim : To create a child process and establish communication between 
parent and child usnig pipes.
*/
        
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

int main(){
	int msgID,var1,var2,beta=100,fr;
	//defining structure
	struct alpha
	{
	long mnum;
	char mtext[15];	
	}m1,m2;

	msgID = msgget((key_t)beta,IPC_CREAT|06666);
	
	fr=fork();

	if(fr>=0){

		if(fr==0){
		
			printf("Child is sending message...\n");
		
			m1.mnum=1;
		
			strcpy(m1.mtext,"hello");
		
			var1=msgsnd(msgID,&m1,sizeof(m1.mtext),0);
		
			}else if(fr>0){
				printf("Parent is sending message...\n");
		
				var2=msgrcv(msgID,&m2,15,1,0);
			}
				printf("The message number is %lo .\nThe message is %s .",m2.mnum,m2.mtext);
			
			}
			else
				printf("Message has not been created by chilld\n");
	
	return 0;
}
