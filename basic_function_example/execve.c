#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

extern char **environ;

int main(int ac, char **av)
{
	char **new_argv;
	char command[] = "ls";
	int idx;

	new_argv = (char **)malloc(sizeof(char *) * (ac + 1));
	new_argv[0] = command;

	for (idx = 1; idx < ac; idx++)
	{
		new_argv[idx] = av[idx];
	}
	new_argv[ac] = NULL;
	if (execve("/usr/bin/ls", new_argv, environ) == -1)
	{
		fprintf(stderr, "error : %s\n", strerror(errno));
		return (1);
	}
	printf("this part not executed\n");
	return (0);
}