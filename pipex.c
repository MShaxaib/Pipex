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
    pid_t	pid;
    int		fd[2];
    char	buffer[13];

    if (pipe	(fd) == -1)
    {
        perror	("pipe");
        exit	(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit  (EXIT_FAILURE);
    }

    if (pid == 0)
    {
        close(fd[0]); // close the read end of the pipe
        write(fd[1], "Hello parent!", 13);
        close(fd[1]); // close the write end of the pipe
        exit (EXIT_SUCCESS);
    }
    else
    {
        close (fd[1]); // close the write end of the pipe
        read  (fd[0], buffer, 13);
        close (fd[0]); // close the read end of the pipe
        printf("Message from child: '%s'\n", buffer);
        exit  (EXIT_SUCCESS);
    }
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

link for more info (https://dev.to/herbievine/42-a-comprehensive-guide-to-pipex-5165)

open,			to topen files
close,			to close the files
read,			to read the files
write,			to print
malloc,			memory alloc
free,			freeing the allocated memory
perror,			print error
strerror,		returns pointer to the error message from the array
access,     	checks if the file or the dir specified by path exists and can be accessed with the file access permission given by amode
dup,        	creates a copy of the file descriptor (uses the lowest numbered unused fd, they both refer to the same open fd )
dup2,       	same as dup ^ but can specify the number for the fd, 
execve,     	executes the program pointed by the filename/file path (env variables)
exit,       	terminates the process and closses any open fd's and child process
fork,       	splits into child, child is the duplicate of the parent to the point of split, process identifier (PID) are different for each process
            
			if the process returns 0 we in the child
            if the process return 1 we in the parent process
            we then use wait in the parent to make the child run first, this also prevents it from becoming a zombie
            link (https://www.youtube.com/watch?v=xVSPv-9x3gk)

pipe,			is a system call that creates a unidirection data channel that can be used for interprocess communication.




unlink      	it elimates the link of a specifiic file or directory from the file system 
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




//██████╗ ███████╗███████╗██████╗ ███████╗███╗   ██╗ ██████╗███████╗     ██████╗ ██████╗ ██████╗ ███████╗███████╗
//██╔══██╗██╔════╝██╔════╝██╔══██╗██╔════╝████╗  ██║██╔════╝██╔════╝    ██╔════╝██╔═══██╗██╔══██╗██╔════╝██╔════╝
//██████╔╝█████╗  █████╗  ██████╔╝█████╗  ██╔██╗ ██║██║     █████╗      ██║     ██║   ██║██║  ██║█████╗  ███████╗
//██╔══██╗██╔══╝  ██╔══╝  ██╔══██╗██╔══╝  ██║╚██╗██║██║     ██╔══╝      ██║     ██║   ██║██║  ██║██╔══╝  ╚════██║
//██║  ██║███████╗██║     ██║  ██║███████╗██║ ╚████║╚██████╗███████╗    ╚██████╗╚██████╔╝██████╔╝███████╗███████║
//╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝     ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝

// int main(int argc, char *argv[]) 
// {
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


// int main()
// {
//     int fd[2];
//     pid_t pid;
//     char buffer[13];

//     if (pipe(fd) == -1)
//     {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }

//     pid = fork();
//     if (pid == -1)
//     {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (pid == 0)
//     {
//         close(fd[0]); // close the read end of the pipe
//         write(fd[1], "Hello parent!", 13);
//         close(fd[1]); // close the write end of the pipe
//         exit(EXIT_SUCCESS);
//     }
//     else
//     {
//         close(fd[1]); // close the write end of the pipe
//         read(fd[0], buffer, 13);
//         close(fd[0]); // close the read end of the pipe
//         printf("Message from child: '%s'\n", buffer);
//         exit(EXIT_SUCCESS);
//     }
// }