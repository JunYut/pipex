/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:53:18 by we                #+#    #+#             */
/*   Updated: 2024/03/21 11:08:10 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clean_up(t_pipex *var)
{
	printf("debug6\n");	// debug
	free_words(var->cmd1);
	printf("debug7\n");	// debug
	free_words(var->cmd2);
	printf("debug8\n");	// debug
	free_words(var->path1);
	printf("debug9\n");	// debug
	free_words(var->path2);
	printf("debug10\n");	// debug
	free(var);
	printf("debug11\n");	// debug
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
