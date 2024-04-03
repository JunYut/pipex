/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:53:18 by we                #+#    #+#             */
/*   Updated: 2024/04/03 10:41:26 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clean_up(t_pipex *var)
{
	int	i;

	close(var->fd1);
	close(var->fd2);
	i = -1;
	while (++i < var->cmd_count)
	{
		free_words(var->cmds[i]);
		free_words(var->paths[i]);
	}
	free_pipes(var->pipes);
	c_free(var->cmds);
	c_free(var->paths);
	c_free(var);
	var = NULL;
}

void	free_pipes(int *pipes[])
{
	int	**tmp;

	tmp = pipes;
	if (tmp)
	{
		while (*tmp)
		{
			c_free(*tmp);
			*tmp = NULL;
			tmp++;
		}
		c_free(pipes);
	}
}

void	free_words(char *words[])
{
	char	**tmp;

	tmp = words;
	if (tmp)
	{
		while (*tmp)
		{
			c_free(*tmp);
			*tmp = NULL;
			tmp++;
		}
		c_free(words);
	}
}

void	c_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
