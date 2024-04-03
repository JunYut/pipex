/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:47 by we                #+#    #+#             */
/*   Updated: 2024/04/03 12:57:35 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	*var;
	int		i;

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
	while (++i < var->cmd_count)
	{
		// create pipe
		if (i < var->cmd_count - 1)
			pipe(var->pipes[i]);

		// execute cmd
		if (fork() == 0)
		{
			if (i == 0)
			{
				dup2(var->pipes[0][1], 1);
			}
			else
			{
				dup2(var->pipes[i - 1][0], 0);
				close(var->pipes[i - 1][0]);
				if (i == var->cmd_count - 1)
					dup2(var->fd2, 1);
				else
					dup2(var->pipes[i][1], 1);
			}
			execve(var->paths[i][0], var->cmds[i], NULL);
		}
		if (i < var->cmd_count - 1)
			close(var->pipes[i][1]);
		if (i > 0)
			close(var->pipes[i - 1][0]);
		wait(NULL);
	}

	clean_up(var);
}
