#include <stdio.h>
#include <unistd.h>

int 	main()
{
	char strBuffer[260] = {0,};
	char strChangeDir[260] = {"/home/honlee/Desktop/miniShell"};

	int result = chdir (strChangeDir);
	if (result == 0)
	{
		printf("change dir sucess >> ");
		getcwd(strBuffer, 260);
		printf("%s\n", strBuffer);
	}
	else if (result == -1)
	{
		perror("faile - ");
	}
	return (0);
}