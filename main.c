/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:47 by we                #+#    #+#             */
/*   Updated: 2024/04/03 10:04:12 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	*var;
	int		i;

	ft_printf("PID: %d\n", getpid());	// debug
	var = (t_pipex *)ft_calloc(1, sizeof(t_pipex));

	// argc validation
	valid_argc(argc, var);

	// parse arguments
	parser(var, argv, envp);

	// input validation
	validation(argv[1], var);

	// open file1 & file2
	var->fd1 = open(argv[1], O_RDONLY);
	var->fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dup2(var->fd1, 0);

	i = -1;
	while (++i < var->count)
	{
		// ft_printf("i: %d\n", i);	// debug
		// ft_printf("path: %s\n", var->paths[i][0]);	// debug
		// for (int j = 0; var->cmds[i][j]; j++)	// debug
			// ft_printf("%s ", var->cmds[i][j]);	// debug
		// ft_printf("\n");	// debug
		// create pipe
		if (i < var->count - 1)
			pipe(var->pipes[i]);

		// execute cmd
		if (fork() == 0)
		{
			if (i == 0)
			{
				close(var->pipes[i][0]);
				dup2(var->pipes[i][1], 1);
			}
			else
			{
				dup2(var->pipes[i - 1][0], 0);
				if (i == var->count - 1)
					dup2(var->fd2, 1);
				else
					dup2(var->pipes[i][1], 1);
			}
			execve(var->paths[i][0], var->cmds[i], NULL);
		}
		if (i < var->count - 1)
			close(var->pipes[i][1]);
		wait(NULL);
		// // ft_printf("debug[%d]\n", i);	// debug
	}
	// create pipe 1
	// pipe(pipe1);

	// execute cmd1
	// if (fork() == 0)
	// {
	// 	close(pipe1[0]);
	// 	dup2(pipe1[1], 1);
	// 	execve(var->path1[0], var->cmd1, NULL);
	// }
	// wait(NULL);
	// close(pipe1[1]);

	// execute cmd2
	// if (fork() == 0)
	// {
	// 	dup2(pipe1[0], 0);
	// 	dup2(fd1, 1);
	// 	execve(var->path2[0], var->cmd2, NULL);
	// }
	// wait(NULL);
	// close(fd1);
	// close(fd0);
	// pause();	// debug
	clean_up(var);
}
