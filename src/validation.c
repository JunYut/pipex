/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:38:27 by we                #+#    #+#             */
/*   Updated: 2024/03/18 15:47:26 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	valid_file(char *path);
static void	valid_cmd(char *cmd);

void	validation(int argc, char *argv[])
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
		exit(1);
	}
	valid_file(argv[1]);
	valid_cmd(argv[2]);
	valid_cmd(argv[3]);
}

static void	valid_file(char *path)
{
	if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
	{
		strerror(errno);
		exit(1);
	}
}

static void	valid_cmd(char *cmd)
{
	if (access(cmd, F_OK) == -1 || access(cmd, X_OK) == -1)
	{
		strerror(errno);
		exit(1);
	}
}
