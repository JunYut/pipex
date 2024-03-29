/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:53:18 by we                #+#    #+#             */
/*   Updated: 2024/03/21 11:30:41 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clean_up(t_pipex *var)
{
	free_words(var->cmd1);
	free_words(var->cmd2);
	free_words(var->path1);
	free_words(var->path2);
	free(var);
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
			free(*tmp);
			*tmp = NULL;
			tmp++;
		}
		free(words);
	}
}

void	*c_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		perror("Error: malloc");
		exit(1);
	}
	return (ptr);
}
