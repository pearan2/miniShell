#include <unistd.h>
#include <stdio.h>

int 	main()
{
	char buf[255];
	getcwd(buf, 255);
	printf("%s\n",buf);
}