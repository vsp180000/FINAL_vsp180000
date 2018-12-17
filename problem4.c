#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <math.h>
#include <time.h>

void child(int);
void parent(int);

int main(void)
{
srand(time(NULL));
struct sigaction sig;
sig.sa_handler = child;

if (sigaction (SIGINT, &sig, NULL) < 0)
	{
	perror ("invalid argument");
	exit(1);
	}

	pid_t pid;
	if ((pid = fork()) < 0)
		{
		perror("error in fork");
		exit(1);
		}
	if (pid == 0)
		{
		while(1)
			{
			printf("child waiting\n");
			sleep(1);
			}
		
		}
	else 
	{
	sleep(1);
	printf("parent sending signal%d\n");
	kill(pid, SIGINT);
	sleep(2);
	printf("\nparent sending signal\n");
	kill(pid, SIGKILL);
	sleep(2);
	}
return 0;
}
