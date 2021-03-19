#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
	int pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("fork error : ");
		exit(0);
	}
	if (pid == 0)
	{
		printf("Im child\n");
		sleep(10);
		return (2);
	}
	else
	{
		printf("Parent wait (%d)\n", pid);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("safe return\n");
			printf("return value : %d\n", WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status))
		{
			printf("child receive signal\n");
			printf("signal number %d\n", WTERMSIG(status));
		}
	}
	exit(0);
}