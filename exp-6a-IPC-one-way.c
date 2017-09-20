/*
*Name : Aditya Pratap Singh Rajput
*Registration Number : RA1511008010237
*Aim : To create a child process and establish communication between 
parent and child usnig pipes.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
        int     fd[2], nbytes;
        /*pid_t data type is a signed integer type which is capable of representing a process ID. 
	*header files needed : 
                *unistd.h
                *sys/types.h
	*/       
        pid_t   childpid;
        char    string[] = "Hello, world!\n";
        char    readbuffer[80];
//creating single pipe
        pipe(fd);
        
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                /* Child process closes up input side of pipe */
                close(fd[0]);

                /* Send "string" through the output side of pipe */
                write(fd[1], string, (strlen(string)+1));
                
        }
        else
        {
                /* Parent process closes up output side of pipe */
                close(fd[1]);

                /* Read in a string from the pipe */
                nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                printf("Received string: %s", readbuffer);
        }
        
        return(0);
}

