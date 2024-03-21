/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:53:18 by we                #+#    #+#             */
/*   Updated: 2024/03/21 10:54:13 by we               ###   ########.fr       */
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
	if (words)
	{
		while (*words)
		{
			free(*words);
			*words = NULL;
			words++;
		}
		free(words);
	}
}
