/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:38:27 by we                #+#    #+#             */
/*   Updated: 2024/03/18 16:59:47 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	valid_file(char *path);
static void	valid_cmd(char *cmd);

void	validation(int argc, char *file1, char *cmd1, char *cmd2)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
		exit(1);
	}
	valid_file(file1);
	valid_cmd(cmd1);
	valid_cmd(cmd2);
}

static void	valid_file(char *path)
{
	if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
	{
		perror(path);
		exit(1);
	}
}

static void	valid_cmd(char *cmd)
{
	if (access(cmd, F_OK) == -1 || access(cmd, X_OK) == -1)
	{
		perror(cmd);
		exit(1);
	}
}
