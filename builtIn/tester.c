#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	pid_t	pid;
	pid_t	pwait;
	int		status;
	char	**menv;
	char	*out;
	int i;
	int	gnl;
	int	len;
	(void)argc;
	(void)argv;
	i = 0;
	menv = env;
	int fd_out;
	t_info	info;

	fd_out = open("./env_test",O_RDWR);
	info.env = env;
/*
	char *out;
	ft_salloc((void**)&out, sizeof(char), 5);
	char **out;
	ft_salloc((void**)&out, sizeof(char *), 7);
	ft_salloc((void&&)&out[1], sizeof(char), 5);	*/

while(1)
{
	pid	= fork();
	if (pid > 0)
	{
		pwait = wait(&status);
		printf("자식 = %d, 기록 = %d\n",pwait,status);
		if (status == 256)
			break;
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
			while(menv[i])
			{
				len = ft_strlen(menv[i]);
				write(1, menv[i], len);
				write(1, "\n", 1);
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
				if (menv[i][0] == 'A' && menv[i][1] == '=')
				{
					menv[i][2] = '9';
					menv[i][3] = '9';
					menv[i][4] = '9';
				}
				i++;
			}
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
		return (-1);
	}

}

}
