#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	pid_t	pid;
	pid_t	pwait;
	int		status;
	char	**menv;
	char	*out;

	char	*print;

	int i;
	int	gnl;
	int	len;
	(void)argc;
	(void)argv;
	i = 0;
	menv = env;
	int fd_out;
	t_info	info;


	i = 0;
	while(env[i])
		i++;

	ft_salloc((void**)&info.env, sizeof(char *), i + 1);
	int j;
	i = 0;
	while(env[i])
	{
		j = 0;
		while(env[i][j])
			j++;
		ft_salloc((void*)&info.env[i], sizeof(char), j + 1);
		j = 0;
		while(env[i][j])
		{
			info.env[i][j] = env[i][j];
			j++;
		}
		info.env[i][j] = '\0';
		i++;
	}
	env[i] = 0;


	fd_out = open("./stdout",O_RDWR);
/*
	char *out;
	ft_salloc((void**)&out, sizeof(char), 5);
	char **out;
	ft_salloc((void**)&out, sizeof(char *), 7);
	ft_salloc((void*)&out[1], sizeof(char), 5);	*/

while(1)
{
	pid	= fork();
	if (pid > 0)
	{
		pwait = wait(&status);
		printf("자식 = %d, 기록 = %d\n",pwait,status/256);
		if (status / 256 == 1)
			break;
		else if (status / 256 > 1 && status / 256 < 10)
		{
			fd_out = open("./stdout",O_RDONLY);
			write(1, "stdout::\n",9);
			while (get_next_line(fd_out,&print) > 0)
			{
				len = ft_strlen(print);
				write(1, print, len);
				write(1, "\n", 1);
				free(print);
			}
			len = ft_strlen(print);
			write(1, print, len);
			write(1, "\n", 1);
			free(print);
			close(fd_out);
		}
		write(1, "\nim mom\n", 8);
	}
	else if (pid == 0)
	{
		write(1, "in child\n",9);
		write(1, "input = ",8);
		gnl = get_next_line(0,&out);
		len = ft_strlen(out);
		write(1, "gnl = ",6);
		write(1, out, len);
		write(1, "\n", 1);
		if (out[0] == 'e' && out[1] == 'n' && out[2] == 'v')
		{
			i = 0;
			
			fd_out = open("./stdout",O_TRUNC|O_RDWR);
			info.opt = (char **)malloc(sizeof(char *) * 2);
			info.opt[0] = (char *)malloc(sizeof(char) * 4);
			info.opt[0][0] = 'e';
			info.opt[0][1] = 'n';
			info.opt[0][2] = 'v';
			info.opt[0][3] = '\0';
			info.opt[1] = 0;
			info.fd_stdout = fd_out;
		   	ft_built_in(&info);	
			free(info.opt[0]);
			free(info.opt);
			close(fd_out);
			exit(2);
		}

		if (out[0] == 'p' && out[1] == 'w' && out[2] == 'd')
		{
			i = 0;

			fd_out = open("./stdout",O_TRUNC|O_RDWR);
			info.opt = (char **)malloc(sizeof(char *) * 2);
			info.opt[0] = (char *)malloc(sizeof(char) * 4);
			info.opt[0][0] = 'p';
			info.opt[0][1] = 'w';
			info.opt[0][2] = 'd';
			info.opt[0][3] = '\0';
			info.opt[1] = 0;
			info.fd_stdout = fd_out;
		   	ft_built_in(&info);	
			free(info.opt[0]);
			free(info.opt);
			close(fd_out);
			return (3);
		}

		if (out[0] == 'e' && out[1] == 'x' && out[2] == 'i' && out[3] == 't')
		{
			free(out);
			exit(1);
		}
		free(out);
		exit(0);
	}
	else
	{
		exit(1);
	}

}
	i = 0;
	while(info.env[i])
	{
		free(info.env[i]);
		i++;
	}
	free(info.env);
}
