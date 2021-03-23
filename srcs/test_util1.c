#include "minishell.h"

void	show_info(t_info *info)
{
	int idx;

	idx = 0;
	printf("order	>>	%s\n", info->order);
	while (info->opt[idx] != 0)
	{
		printf("opt %d	>>	%s\n",idx, info->opt[idx]);
		idx++;
	}
	printf("stdin	>>	%d\n" ,info->fd_stdin);
	printf("stdout	>>	%d\n" ,info->fd_stdout);
	printf("stdout_r	>>	%d\n" ,info->fd_stdout_r);
	printf("append	>>	%d\n" ,info->is_append);
	printf("is_print	>>	%d\n" ,info->is_print);
	printf("is_redirect	>>	%d\n" ,info->is_redirect);
}