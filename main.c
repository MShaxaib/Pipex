
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Pipe error");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Fork error");
			exit(1);
		}
		if (pid == 0)
			ft_child_process(argv, env, fd);
		ft_parent_process(argv, env, fd);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}