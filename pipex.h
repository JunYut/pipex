/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:19:38 by we                #+#    #+#             */
/*   Updated: 2024/03/27 13:25:21 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include "libft/c_libft.h"

typedef struct s_pipex
{
	int		fd[3];
	char	*cmd1;
	char	*cmd2;
	char	**args1;
	char	**args2;
	char	**path1;
	char	**path2;
	char	*f_buffer[1024];
}	t_pipex;

void	parser(t_pipex *var, char **argv, char *envp[]);
char	**path_parser(char *envp[], char *cmd);
void	trim_path(char **path_list);
void	prepend_cmd(char **path_list, char *cmd);
void	validation(int argc, char *file1, t_pipex *var);
void	valid_file(char *file, t_pipex *var);
char	*valid_path(char **path, t_pipex *var);
void	clean_up(t_pipex *var);
void	free_words(char *words[]);
void	*c_malloc(size_t size);

#endif
