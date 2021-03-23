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

	char *out;
	ft_salloc((void**)&out, sizeof(char), 5);
	char **out;
	ft_salloc((void**)&out, sizeof(char *), 7);
	ft_salloc((void&&)&out[1], sizeof(char), 5);	

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
