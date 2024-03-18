/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:47 by we                #+#    #+#             */
/*   Updated: 2024/03/18 17:38:05 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	char	**cmd1;
	char	**cmd2;

	// parse arguments
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	prepend_bin(cmd1);
	prepend_bin(cmd2);

	// input validation
	validation(argc, argv[1], *cmd1, *cmd2);

	// open file & read file

	// write the contents of the file to stdin

	// create child process

	// clean up
	free_words(cmd1);
	free_words(cmd2);
}
