#include "miniShell.h"

void	show_info(t_info *info)
{
	int idx;

	idx = 0;
	printf("%s\n", info->order);
	while (info->opt[idx] != 0)
	{
		printf("%s\n", info->opt[idx]);
		idx++;
	}
	printf("%d\n" ,info->fd_stdin);
	printf("%d\n" ,info->fd_stdout);
	printf("%d\n" ,info->is_append);
}