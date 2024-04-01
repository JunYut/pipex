/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:38:27 by we                #+#    #+#             */
/*   Updated: 2024/04/01 16:39:14 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	validation(char *file1, t_pipex *var)
{
	int	i;

	valid_file(file1, var);
	i = -1;
	while (++i < var->count)
		var->paths[0] = valid_path(var->paths[i], var);
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
	int		i;

	i = -1;
	while (path[++i])
	{
		if (access(path[i], F_OK) == 0 && access(path[i], X_OK) == 0)
		{
			c_free(path[0]);
			return (ft_strdup(path[i]));
		}
	}
	ft_putstr_fd("Error: command not found\n", 2);
	clean_up(var);
	exit(1);
}

void	valid_argc(int argc, t_pipex *var)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
		exit(1);
	}
	var->count = argc - 3;
}
