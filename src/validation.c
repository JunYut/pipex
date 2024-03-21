/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:38:27 by we                #+#    #+#             */
/*   Updated: 2024/03/21 11:30:51 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	validation(int argc, char *file1, t_pipex *var)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
		clean_up(var);
		exit(1);
	}
	valid_file(file1, var);
	free(var->cmd1[0]);
	var->cmd1[0] = valid_path(var->path1, var);
	free(var->cmd2[0]);
	var->cmd2[0] = valid_path(var->path2, var);
}

void	valid_file(char *file, t_pipex *var)
{
	if (access(file, F_OK) == -1 || access(file, R_OK) == -1)
	{
		perror(file);
		clean_up(var);
		exit(1);
	}
}

char	*valid_path(char **path, t_pipex *var)
{
	int	i;

	i = -1;
	while (path[++i])
		if (access(path[i], F_OK) == 0 && access(path[i], X_OK) == 0)
			return (ft_strdup(path[i]));
	ft_putstr_fd("Error: command not found\n", 2);
	clean_up(var);
	exit(1);
}
