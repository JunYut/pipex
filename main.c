/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:47 by we                #+#    #+#             */
/*   Updated: 2024/03/21 10:17:28 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	*var;

	var = (t_pipex *)malloc(sizeof(t_pipex));
	// parse arguments
	parser(var, argv, envp);

	// input validation
	validation(argc, argv[1], var->path1, var->path2);

	// open file & read file
	var->fd[2] = open(argv[1], O_RDONLY);
	read(var->fd[2], var->f_buffer, 1024);
	close(var->fd[2]);

	// create pipe
	pipe(var->fd);

	// create child process
	if (fork() == 0)
	{
		printf("child process\n");	// debug
		close(var->fd[0]);
		dup2(var->fd[1], 1);
		execve((*(var->cmd1))++, var->cmd1, NULL);
	}
	else
	{
		wait(NULL);
		printf("parent process\n");	// debug
		close(var->fd[1]);
		var->fd[2] = open(argv[4], O_CREAT | O_WRONLY);
		if (fork() == 0)
		{
			dup2(var->fd[2], 1);
			execve((*(var->cmd2))++, var->cmd2, NULL);
		}
		else
			wait(NULL);
	}

	// clean up
	printf("clean up\n");	// debug
	close(var->fd[2]);
	clean_up(var);
}
