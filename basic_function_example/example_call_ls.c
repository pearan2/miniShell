#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

extern char **environ;

int main(int ac, char **av)
{
	char **new_argv;
    char **grep_param;
	int idx;
    int pid;
    int fd[2];

	new_argv = (char **)malloc(sizeof(char *) * (ac + 1));
	new_argv[0] = "ls";

	for (idx = 1; idx < ac; idx++)
	{
		new_argv[idx] = av[idx];
	}
	new_argv[ac] = NULL;
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        //child
        close(fd[0]); // close read fd
        dup2(fd[1], 1);
        dup2(fd[1], 2);
        //ls 의 위치 찾기 > 터미널에서 which ls
        execve("/bin/ls", new_argv, environ);
    }
    else{
        close(fd[1]);  // close write fd
        sleep(1);
        printf("hello im parent\n");
        char buf;
        while ( (read(fd[0], &buf, 1)) > 0 )
        {
            write(1, &buf, 1);
        }
    }
	return (0);
}