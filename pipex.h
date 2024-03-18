/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:19:38 by we                #+#    #+#             */
/*   Updated: 2024/03/18 17:32:24 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "libft/c_libft.h"

void	validation(int argc, char *file1, char *cmd1, char *cmd2);
void	prepend_bin(char **cmd);
void	free_words(char *words[]);

#endif