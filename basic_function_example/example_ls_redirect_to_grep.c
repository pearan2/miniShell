#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
extern char **environ;
int		main()
{
	int fd[2];
	pipe(fd); // fd[0] -> read , fd[1] -> write
	int pid;

	pid = fork();
	if (pid == 0)
	{
		//child
		dup2(fd[1], 1);
		dup2(fd[1], 2);
		close(fd[0]);
		char *cmd[] = {
			"ls","-al",">" ,NULL
		};
		execve("/bin/ls", cmd, environ);
	}else{
		//parent
		int status;
		waitpid(pid, &status, 0);
	}
	pid = fork();
	if (pid == 0)
	{
		//child
		dup2(fd[0], 0); // change fd[0] to stdin
		close(fd[1]);
		char *cmd[] = {
			"grep","d", NULL
		};
		//you should check "which grep" in terminal
		execve("/usr/bin/grep",cmd,environ);
	}
	else{
		sleep(1);
		printf("parent done \n");
	}
}