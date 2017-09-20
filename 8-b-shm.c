#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(){
	char *ptr ;
	int pid,  shmid;
	shmid = shmget((key_t)1 , 10 , IPC_CREAT|0666);
	if(shmid < 0 ) {
		printf("shared memory creation error:\n");	
	}
	pid = fork();
	ptr = shmat(shmid , 0 , 0 );
	if (pid > 0 ){
		strcpy( ptr , "hello world\n");
	}
	else{
		printf("%s" , ptr);
	}


	return 0;
}
