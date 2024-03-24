/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:47 by we                #+#    #+#             */
/*   Updated: 2024/03/23 13:09:51 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	*var;

	var = (t_pipex *)c_malloc(sizeof(t_pipex));

	// parse arguments
	parser(var, argv, envp);

	// input validation
	validation(argc, argv[1], var);
	for (int i = 0; var->cmd1[i]; i++)
		printf("%s ", var->cmd1[i]);
	printf("\n");
	for (int i = 0; var->cmd2[i]; i++)
		printf("%s ", var->cmd2[i]);
	printf("\n");

	// // open file & read file
	// var->fd[2] = open(argv[1], O_RDONLY);
	// read(var->fd[2], var->f_buffer, 1024);
	// close(var->fd[2]);

	// // create pipe
	// pipe(var->fd);

	// // create child process
	// if (fork() == 0)
	// {
	// 	close(var->fd[0]);
	// 	dup2(var->fd[1], 1);
	// 	execve((*(var->cmd1))++, var->cmd1, NULL);
	// }
	// else
	// {
	// 	wait(NULL);
	// 	close(var->fd[1]);
	// 	var->fd[2] = open(argv[4], O_CREAT | O_WRONLY);
	// 	if (fork() == 0)
	// 	{
	// 		dup2(var->fd[2], 1);
	// 		execve((*(var->cmd2))++, var->cmd2, NULL);
	// 	}
	// 	else
	// 		wait(NULL);
	// }

	// // clean up
	// close(var->fd[2]);
	clean_up(var);
}
