/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:38:27 by we                #+#    #+#             */
/*   Updated: 2024/03/21 10:20:31 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	validation(int argc, char *file1, char **path1, char **path2)
{
	int	i;

	if (argc != 5)
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
		exit(1);
	}
	valid_file(file1);
	i = -1;
	while (path1[++i])
		valid_cmd(path1[i]);
	i = -1;
	while (path2[++i])
		valid_cmd(path2[i]);
}

void	valid_file(char *path)
{
	if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
	{
		perror(path);
		exit(1);
	}
}

void	valid_cmd(char *cmd)
{
	if (access(cmd, F_OK) == -1 || access(cmd, X_OK) == -1)
	{
		perror(cmd);
		exit(1);
	}
}
