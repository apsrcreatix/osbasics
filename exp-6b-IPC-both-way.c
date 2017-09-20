/*
*Name : Aditya Pratap Singh Rajput
*Registration Number : RA1511008010237
*Aim : To create a child process and establish communication between 
parent and child usnig pipes.
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(){
	int fd1[2],fd2[2],nbytes1,nbytes2;
	/*pid_t data type is a signed integer type which is capable of representing a process ID. 
	*header files needed : 
                *unistd.h
                *sys/types.h
	*/
	pid_t childpid;
	char string1[] = "How Are You ?\n";
	char string2[] = "I am fine\n";
	//initialising two readbuffers
	char readbuffer[80],readbuffer1[80];
//creating pipes for pipelining 
pipe(fd1);
pipe(fd2);
//creating a process
childpid = fork();
	if (childpid==-1)
	 {
	printf("Erro\n");
	}
	if (childpid==0)
	 {	
	 //closing writing section of fd2 then accessing reading section by read
	 	close(fd2[1]);
	 	nbytes2=read(fd2[0],readbuffer1,sizeof(readbuffer1));
	 	printf("Child : %s\n",readbuffer1);
	 	/*child process closes up input side of pipeline*/
	 	close(fd1[0]);
	 	write(fd1[1],string2,strlen(string2)+1);

	 }else{
	 //closing reading section of fd2 then accessing writing section by read
	 	close(fd2[0]);
	 	write(fd2[1],string1,strlen(string1)+1);
	 //closing writing section of fd1 then accessing reading section by read
	 	close(fd1[1]);
	 	nbytes1=read(fd1[0],readbuffer,sizeof(readbuffer));
	 	printf("Parent : %s\n",readbuffer );
	 } 
	return 0 ;
}
