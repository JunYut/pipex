/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:47 by we                #+#    #+#             */
/*   Updated: 2024/03/29 12:00:39 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	*var;
	int		fd[2];
	int		pipe1[2];

	var = (t_pipex *)ft_calloc(1, sizeof(t_pipex));

	// parse arguments
	parser(var, argv, envp);

	// input validation
	validation(argc, argv[1], var);
	// ft_printf("%s\n", var->path1[0]);
	// for (int i = 0; var->cmd1[i]; i++)
	// 	ft_printf("%s ", var->cmd1[i]);
	// ft_printf("\n\n");
	// ft_printf("%s\n", var->path2[0]);
	// for (int i = 0; var->cmd2[i]; i++)
	// 	ft_printf("%s ", var->cmd2[0]);
	// ft_printf("\n");
	ft_printf("This is parent\n");	// debug

	// open file1
	fd[0] = open(argv[1], O_RDONLY);
	dup2(fd[0], 0);

	// create pipe 1
	pipe(pipe1);

	// execute cmd1
	if (fork() == 0)
	{
		ft_printf("This is child 1\n");	// debug
		close(pipe1[0]);
		dup2(pipe1[1], 1);
		execve(var->path1[0], var->cmd1, NULL);
	}
	wait(NULL);
	close(pipe1[1]);

	// open file2
	fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	// execute cmd2
	if (fork() == 0)
	{
		ft_printf("This is child 2\n");	// debug
		dup2(pipe1[0], 0);
		dup2(fd[1], 1);
		execve(var->path2[0], var->cmd2, NULL);
	}
	wait(NULL);
	close(fd[1]);
	close(fd[0]);
	clean_up(var);
}
