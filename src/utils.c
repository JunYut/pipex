/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:53:18 by we                #+#    #+#             */
/*   Updated: 2024/03/29 12:00:22 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clean_up(t_pipex *var)
{
	free_words(var->cmd1);
	free_words(var->cmd2);
	free_words(var->path1);
	free_words(var->path2);
	c_free(var);
	var = NULL;
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

