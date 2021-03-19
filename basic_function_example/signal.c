#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void	sig_handler(int signo)
{
	printf("SIGINT occured\n");
}

int		main()
{
	int i = 0;
	signal(SIGINT, (void *)sig_handler);
	while (1)
	{
		printf("%d\n", i);
		i++;
		sleep(1);
	}
	return (1);
}