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

int main()
{

}
/*



           ██╗      ██████╗ ██████╗ ███████╗    ██████╗ ███████╗ ██████╗ ██╗   ██╗██╗██████╗ ███╗   ███╗███████╗███╗   ██╗████████╗███████╗
           ╚██╗     ██╔══██╗██╔══██╗██╔════╝    ██╔══██╗██╔════╝██╔═══██╗██║   ██║██║██╔══██╗████╗ ████║██╔════╝████╗  ██║╚══██╔══╝██╔════╝
█████╗█████╗╚██╗    ██████╔╝██║  ██║█████╗      ██████╔╝█████╗  ██║   ██║██║   ██║██║██████╔╝██╔████╔██║█████╗  ██╔██╗ ██║   ██║   ███████╗
╚════╝╚════╝██╔╝    ██╔═══╝ ██║  ██║██╔══╝      ██╔══██╗██╔══╝  ██║▄▄ ██║██║   ██║██║██╔══██╗██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║   ╚════██║
           ██╔╝     ██║     ██████╔╝██║         ██║  ██║███████╗╚██████╔╝╚██████╔╝██║██║  ██║██║ ╚═╝ ██║███████╗██║ ╚████║   ██║   ███████║
           ╚═╝      ╚═╝     ╚═════╝ ╚═╝         ╚═╝  ╚═╝╚══════╝ ╚══▀▀═╝  ╚═════╝ ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   ╚══════╝





Arguments : :file1 cmd1 cmd2 file2

External functs

open,			to topen files
close,			to close the files
read,			to read the files
write,			to print
malloc,			memory alloc
free,			freeing the allocated memory
perror,			print error
strerror,		returns pointer to the error message from the array (link)
access,
dup,            creates a copy of the file descriptor (uses the lowest nmbered unused fd, they bith refer to the same open fd )
dup2,           same as dup ^ but can specify the number for the fd
execve,         executes the program pointed by the filename/file path (env variables)
exit,
fork,           splits
pipe,			the main pipe function
unlink
wait,			delay i think
waitpid			delay a specific process id?

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