/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:53:18 by we                #+#    #+#             */
/*   Updated: 2024/03/18 17:32:42 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	prepend_bin(char **cmd)
{
	char	*tmp;

	tmp = ft_strjoin("/bin/", *cmd);
	free(*cmd);
	*cmd = tmp;
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
