#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int		main()
{
	int n, fd[2];
	char buf[255];
	int pid;

	if (pipe(fd) < 0)
	{
		perror("pipe error : ");
		exit(0);
	}

	if ((pid = fork()) < 0)
	{
		perror("fork error : ");
		exit(0);
	}
	
	//child
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			memset(buf, 0, 255);
			sprintf(buf, "Hello : %d\n", getpid());
			write(fd[1], buf, strlen(buf));
			sleep(1);
		}
	}
	else{
		close(fd[1]);
		while(1)
		{
			memset(buf, 0, 255);
			n = read(fd[0], buf, 255);
			fprintf(stderr, "%s\n", buf);
		}
	}
}