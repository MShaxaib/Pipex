/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:39:09 by codespace         #+#    #+#             */
/*   Updated: 2023/12/05 17:58:03 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	msg(char *err)
{
	fprintf(stderr, "%s", err);
	exit(127);
}
// void	msg_error(void)
// {
// 	fprintf(stderr, "Error executing command:\n");
// 	exit(2);
// }
