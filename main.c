/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:47 by we                #+#    #+#             */
/*   Updated: 2024/04/01 17:25:52 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	*var;

	var = (t_pipex *)ft_calloc(1, sizeof(t_pipex));

	// argc validation
	valid_argc(argc, var);

	// parse arguments
	parser(var, argv, envp);

	// input validation
	validation(argv[1], var);

	ft_printf("cmd:\n");
	for (int i = 0; i < var->count; i++)
	{
		for (int j = 0; var->cmds[i][j]; j++)
		{
			ft_printf("%s\n", var->cmds[i][j]);
		}
	}
	ft_printf("\npath:\n");
	for (int i = 0; i < var->count; i++)
	{
		for (int j = 0; var->paths[i][j]; j++)
		{
			ft_printf("%s\n", var->paths[i][j]);
		}
		ft_printf("\n");
	}

	// // open file1
	// fd[0] = open(argv[1], O_RDONLY);
	// dup2(fd[0], 0);

	// // create pipe 1
	// pipe(pipe1);

	// // execute cmd1
	// if (fork() == 0)
	// {
	// 	close(pipe1[0]);
	// 	dup2(pipe1[1], 1);
	// 	execve(var->path1[0], var->cmd1, NULL);
	// }
	// wait(NULL);
	// close(pipe1[1]);

	// // open file2
	// fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	// // execute cmd2
	// if (fork() == 0)
	// {
	// 	dup2(pipe1[0], 0);
	// 	dup2(fd[1], 1);
	// 	execve(var->path2[0], var->cmd2, NULL);
	// }
	// wait(NULL);
	// close(fd[1]);
	// close(fd[0]);
	clean_up(var);
}
