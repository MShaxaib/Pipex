/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:39:09 by codespace         #+#    #+#             */
/*   Updated: 2023/11/25 20:43:31 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

// void	msg_error()
// {
// 	fprintf(stderr, "Error executing command:\n");
// 	exit(2);
// }
