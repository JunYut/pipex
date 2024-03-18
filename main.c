/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:47 by we                #+#    #+#             */
/*   Updated: 2024/03/18 18:49:21 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	int		p_fd[2];
	int		fd;
	char	**cmd1;
	char	**cmd2;
	char	*f_buffer[1024];

	// parse arguments
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	prepend_bin(cmd1);
	prepend_bin(cmd2);

	// input validation
	validation(argc, argv[1], *cmd1, *cmd2);

	// open file & read file
	fd = open(argv[1], O_RDONLY);
	read(fd, f_buffer, 1024);
	close(fd);

	// create pipe
	pipe(p_fd);

	// create child process
	if (fork() == 0)
	{
		printf("child process\n");	// debug
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		execve((*cmd1)++, cmd1, NULL);
	}
	else
	{
		wait(NULL);
		printf("parent process\n");	// debug
		close(p_fd[1]);
		fd = open(argv[4], O_CREAT | O_WRONLY);
		if (fork() == 0)
		{
			dup2(fd, 1);
			execve((*cmd2)++, cmd2, NULL);
		}
		else
			wait(NULL);
	}

	// clean up
	printf("clean up\n");	// debug
	close(fd);
	free_words(cmd1);
	free_words(cmd2);
}
