/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:18:08 by we                #+#    #+#             */
/*   Updated: 2024/03/18 12:25:59 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	valid_file(char *file);
static void	valid_command(char *command);

void	validation(int argc, char *argv[])
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		exit(1);
	}
	valid_file(argv[1]);
	valid_command(argv[2]);
	valid_command(argv[3]);
}

static void	valid_file(char *file)
{
	if (access(file, F_OK) == -1)
	{
		perror("Error: file does not exist");
		exit(1);
	}
	if (access(file, R_OK) == -1)
	{
		perror("Error: file is not readable");
		exit(1);
	}
}

static void	valid_command(char *command)
{
	if (access(command, F_OK) == -1)
	{
		perror("Error: command does not exist");
		exit(1);
	}
	if (access(command, X_OK) == -1)
	{
		perror("Error: command is not executable");
		exit(1);
	}
}
