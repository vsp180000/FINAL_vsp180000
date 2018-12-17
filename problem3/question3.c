#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
char c;
int status;
int pid;
int fd [2];
char *first_argument = argv[1];
char *second_argument = argv[2];
FILE *ptr;
FILE *ptr1;
if (argc < 3) 
	{
	printf ("Need atleast THREE argument.\n");
	exit(1);
	}
	
if (pipe (fd) == -1)
	{
	perror("PIPE.");
	exit (1);
	}

pid = fork ();
	if (pid == 0)
		{
		close (fd[1]);
		dup2(fd[0],0);
		close(fd[0]);
		execl("/usr/bin/cat", "cat", "-b" , first_argument, NULL);
		}
	else
		{
		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);
		ptr = fopen(first_argument, "r");
		ptr1 = fopen(second_argument, "w");
		while((c=fgetc(ptr)) != EOF)
			{
			fprintf(stdout,"%c", c);
			fputc(c, ptr1);
			}
		fclose(ptr);	
		fclose(ptr1);
		wait(&status);
		}

return 0;

}
