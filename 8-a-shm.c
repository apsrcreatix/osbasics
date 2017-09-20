#include<stdio.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(){
	int *ptr , shmid;
	shmid = shmget((key_t)1 , 10 , IPC_CREAT|0666);
	ptr = shmat(shmid , 0 , 0 );
	printf("%d" , *ptr );
	return 0;
}
