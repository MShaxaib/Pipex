/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:39:49 by mshazaib          #+#    #+#             */
/*   Updated: 2023/10/17 18:53:41 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

char	**ft_split(const char *s, char c);
int		ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_path(char *cmd, char **env);
char	*ft_pwd_path(char *cmd, char **env);
void	ft_get_cmd(char *argv, char **env);
void	ft_parent_process(char **argv, char **env, int *fd);
void	ft_child_process(char **argv, char **env, int *fd);
int		main(int argc, char **argv, char **env);



#endif

