/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:39:47 by mshazaib          #+#    #+#             */
/*   Updated: 2023/10/17 21:07:49 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char *cmd, char **env)
{
	int		i;
	char	**all_paths;
	char	*piece_path;
	char	*res;

	i = 0;
	if (env == NULL)
		exit (1);
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	if (env[i] == NULL)
		return (0);
	all_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (all_paths[++i])
	{
		piece_path = ft_strjoin(all_paths[i], "/");
		res = ft_strjoin(piece_path, cmd);
		if (access(res, F_OK) == 0)
			return (res);
		else
			free(res);
	}
	return (0);
}

char	*ft_pwd_path(char *cmd, char **env)
{
	int		i;
	char	*pwd_path;
	char	*res;
	int		j;

	i = 0;
	j = -1;
	if (env == NULL)
		exit (1);
	while (env[i] && ft_strnstr(env[i], "PWD=", 4) == 0)
		i++;
	if (env[i] == NULL)
		exit(0);
	pwd_path = (char *)malloc((ft_strlen(env[i]) - 4) * sizeof(char));
	while (++j < ft_strlen(env[i]) - 4)
		pwd_path[j] = env[i][j + 4];
	pwd_path = ft_strjoin(pwd_path, "/");
	res = ft_strjoin(pwd_path, cmd);
	if (access(res, F_OK) == 0)
		return (res);
	else
		free(res);
	exit(0);
}

void	ft_get_cmd(char *argv, char **env)
{
	char	**cmd;
	char	**cmd2;
	char	*path;
	int		i;

	i = 0;
	cmd2 = ft_split(argv, ' ');
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
	{	
		cmd = ft_split(argv, '/');
		while (cmd[i])
			i++;
		cmd = ft_split(cmd[i - 1], ' ');
		execve(cmd2[0], cmd, env);
	}
	path = ft_path(cmd[0], env);
	if (path == NULL)
		path = ft_pwd_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{	
		perror("Command error");
		exit(1);
	}
}

void	ft_parent_process(char **argv, char **env, int *fd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		write(2, "Permission denied error\n", 24);
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(fd_out, 1);
	close(fd[1]);
	ft_get_cmd(argv[3], env);
}

void	ft_child_process(char **argv, char **env, int *fd)
{
	if (access(argv[1], F_OK) != 0)
	{
		write(2, "No such file or directory error\n", 32);
		exit(1);
	}
	if (access(argv[1], R_OK) != 0)
	{
		write(2, "Permission denied error\n", 25);
		exit(1);
	}
	dup2(fd[1], 1);
	dup2(open(argv[1], O_RDONLY), 0);
	close(fd[0]);
	ft_get_cmd(argv[2], env);
}









































// int main(int argc, char *argv[]) {
  
//   int status;
//   int fds[2];                                 // an array that will hold two file descriptors
//   size_t i;
//   pid_t pid = fork();                         // create child process that is a clone of the parent
  
//   i = 0;
//   pipe(fds);                                  // populates fds with two file descriptors
  
//   if (pid == 0)
//   {                             // if pid == 0, then this is the child process
//     dup2(fds[0], STDIN_FILENO);                         //In the child process, this line duplicates the file descriptor fds[0] to file descriptor 0, This means that any data written to STDIN in the child process will actually come from the pipe.
//     close(fds[0]);                                      // file descriptor no longer needed in child since stdin is a copy
//     close(fds[1]);                                      // file descriptor unused in child
//     char *argv[] = {(char *)"sort", NULL};              // create argument vector specifies that the child process to use sort
//     if (execvp(argv[0], argv) < 0) exit(0);             // execute the sort command in the child process using execvp . if it cant returns with 0
//   } 

// // if we reach here, we are in parent process
//   close(fds[0]);                                         // file descriptor unused in parent
//   const char *words[] = {"pear", "peach", "apple"};      // write input to the writable file descriptor so it can be read in from child:
  
//   size_t numwords = sizeof(words)/sizeof(words[0]);      //calculate the numbers of words used in the array
    
//     while(i < numwords)
//       {
//         dprintf(fds[1], "%s\n", words[i]);               //use a loop to write each word to the write end of the pipe so that the child process can read them
//         i++;
//       }

//   close(fds[1]);                                        //this signals the end of the input data to the child process

//   pid_t wpid = waitpid(pid, &status, 0);                // wait for child to finish before exiting
//   return wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
// }

/*



           ██╗      ██████╗ ██████╗ ███████╗    ██████╗ ███████╗ ██████╗ ██╗   ██╗██╗██████╗ ███╗   ███╗███████╗███╗   ██╗████████╗███████╗
           ╚██╗     ██╔══██╗██╔══██╗██╔════╝    ██╔══██╗██╔════╝██╔═══██╗██║   ██║██║██╔══██╗████╗ ████║██╔════╝████╗  ██║╚══██╔══╝██╔════╝
█████╗█████╗╚██╗    ██████╔╝██║  ██║█████╗      ██████╔╝█████╗  ██║   ██║██║   ██║██║██████╔╝██╔████╔██║█████╗  ██╔██╗ ██║   ██║   ███████╗
╚════╝╚════╝██╔╝    ██╔═══╝ ██║  ██║██╔══╝      ██╔══██╗██╔══╝  ██║▄▄ ██║██║   ██║██║██╔══██╗██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║   ╚════██║
           ██╔╝     ██║     ██████╔╝██║         ██║  ██║███████╗╚██████╔╝╚██████╔╝██║██║  ██║██║ ╚═╝ ██║███████╗██║ ╚████║   ██║   ███████║
           ╚═╝      ╚═╝     ╚═════╝ ╚═╝         ╚═╝  ╚═╝╚══════╝ ╚══▀▀═╝  ╚═════╝ ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   ╚══════╝





Arguments : :file1 cmd1 cmd2 file2

External functs

link for more info (https://dev.to/herbievine/42-a-comprehensive-guide-to-pipex-5165)

open,			  to topen files
close,			to close the files
read,			  to read the files
write,			to print
malloc,			memory alloc
free,			  freeing the allocated memory
perror,			print error
strerror,		returns pointer to the error message from the array
access,     checks if the file or the dir specified by path exists and can be accessed with the file access permission given by amode
dup,        creates a copy of the file descriptor (uses the lowest numbered unused fd, they both refer to the same open fd )
dup2,       same as dup ^ but can specify the number for the fd, 
execve,     executes the program pointed by the filename/file path (env variables)
exit,       terminates the process and closses any open fd's and child process
fork,       splits into child, child is the duplicate of the parent to the point of split, process identifier (PID) are different for each process
            if the process returns 0 we in the child
            if the process return 1 we in the parent process
            we then use wait in the parent to make the child run first, this also prevents it from becoming a zombie
            link (https://www.youtube.com/watch?v=xVSPv-9x3gk)

pipe,			  is a system call that creates a unidirection data channel that can be used for interprocess communication.

int main()
{
    int fd[2];
    pid_t pid;
    char buffer[13];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        close(fd[0]); // close the read end of the pipe
        write(fd[1], "Hello parent!", 13);
        close(fd[1]); // close the write end of the pipe
        exit(EXIT_SUCCESS);
    }
    else
    {
        close(fd[1]); // close the write end of the pipe
        read(fd[0], buffer, 13);
        close(fd[0]); // close the read end of the pipe
        printf("Message from child: '%s'\n", buffer);
        exit(EXIT_SUCCESS);
    }
}


unlink      it elimates the link of a specifiic file or directory from the file system 
wait,			  delay i think
waitpid			wait for a specific process id to finish

Should run like this:			./pipex file1 cmd1 cmd2 file2
Must take  arguments 			file1 and file2 (file name) cmd1 and cmd2 (shell commands with their parameters)



           ██╗      ███╗   ██╗ ██████╗ ████████╗███████╗███████╗
           ╚██╗     ████╗  ██║██╔═══██╗╚══██╔══╝██╔════╝██╔════╝
█████╗█████╗╚██╗    ██╔██╗ ██║██║   ██║   ██║   █████╗  ███████╗
╚════╝╚════╝██╔╝    ██║╚██╗██║██║   ██║   ██║   ██╔══╝  ╚════██║
           ██╔╝     ██║ ╚████║╚██████╔╝   ██║   ███████╗███████║
           ╚═╝      ╚═╝  ╚═══╝ ╚═════╝    ╚═╝   ╚══════╝╚══════╝




parents and child process connected to each other through a pipe
fd[0] for the read end of the pipe
fd[1] for the write end of the pipe

behaves as FIFO (first in first out)

can write 512 bytes at a time but can read only 1 byte at a time 

fork() ---> no idea wtf is this

*/