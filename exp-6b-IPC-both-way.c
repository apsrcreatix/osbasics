#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(){
	int fd1[2],fd2[2],nbytes1,nbytes2;
	pid_t childpid;
	char string1[] = "How Are You ?\n";
	char string2[] = "I am fine\n";
	char readbuffer[80],readbuffer1[80];

pipe(fd1);
pipe(fd2);
childpid = fork();
	if (childpid==-1)
	 {
	printf("Erro\n");
	}
	if (childpid==0)
	 {		
	 	close(fd2[1]);
	 	nbytes2=read(fd2[0],readbuffer1,sizeof(readbuffer1));
	 	printf("Child : %s\n",readbuffer1);
	 	/*child process closes up input side of pipeline*/
	 	close(fd1[0]);
	 	write(fd1[1],string2,strlen(string2)+1);

	 }else{
	 	close(fd2[0]);
	 	write(fd2[1],string1,strlen(string1)+1);
	 	close(fd1[1]);
	 	nbytes1=read(fd1[0],readbuffer,sizeof(readbuffer));
	 	printf("Parent : %s\n",readbuffer );
	 } 
	return 0 ;
}