#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void	sig_handler(int signo)
{
	if (signo == SIGQUIT)
		printf("core dump called \n");
	if (signo == SIGINT)
		printf("ctrl + c called \n");
	return ;
}

int		main()
{
	int i = 0;
	signal(SIGINT, (void *)sig_handler);
	signal(SIGQUIT, (void *)sig_handler);
	while (1)
	{
		printf("%d\n", i);
		i++;
		sleep(1);
	}
	return (1);
}