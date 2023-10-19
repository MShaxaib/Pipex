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



int main() {
    int pipefd[2];  // An array to hold the read and write file descriptors for the pipe
    pid_t pid;      // For storing the process ID after fork()
    char buffer[128];
    const char *message = "Hello, child process!";

    if (pipe(pipefd) == -1) {  // Create a pipe
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();  // Create a child process
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // This block will be executed by the child process
        close(pipefd[1]);  // Close the write end of the pipe in the child process

        read(pipefd[0], buffer, sizeof(buffer));  // Read from the pipe
        printf("Child received: %s\n", buffer);

        close(pipefd[0]);  // Close the read end of the pipe
        _exit(EXIT_SUCCESS);
    } else {  // This block will be executed by the parent process
        close(pipefd[0]);  // Close the read end of the pipe in the parent process

        write(pipefd[1], message, strlen(message));  // Write to the pipe
        close(pipefd[1]);  // Close the write end of the pipe

        wait(NULL);  // Wait for the child process to finish
    }

    return 0;
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
strerror,		returns pointer to the error message from the array
access,         checks if the file or the dir specified by path exists and can be accessed with the file access permission given by amode
dup,            creates a copy of the file descriptor (uses the lowest numbered unused fd, they both refer to the same open fd )
dup2,           same as dup ^ but can specify the number for the fd
execve,         executes the program pointed by the filename/file path (env variables)
exit,           terminates the process and closses any open fd's and child process
fork,           splits
pipe,			the main pipe function
unlink          it elimates the link of a specifiic file or directory from the file system 
wait,			delay i think
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