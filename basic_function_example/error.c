#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/errno.h>

int		main()
{
	int fd = open("main.asdfc", O_RDONLY);

	if (fd < 0)
		printf("%s", strerror(errno));
}