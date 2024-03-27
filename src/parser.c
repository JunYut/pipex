/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:42:57 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/27 13:24:51 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parser(t_pipex *var, char **argv, char *envp[])
{
	var->args1 = ft_split(argv[2], ' ');
	var->args2 = ft_split(argv[3], ' ');
	var->path1 = path_parser(envp, *(var->args1));
	var->path2 = path_parser(envp, *(var->args2));
}

char	**path_parser(char *envp[], char *cmd)
{
	char	**path_list;
	int		i;

	i = -1;
	while (envp[++i] && ft_strncmp(envp[i], "PATH=", 5))
		;
	path_list = ft_split(envp[i], ':');
	trim_path(path_list);
	prepend_cmd(path_list, cmd);
	return (path_list);
}

void	trim_path(char **path_list)
{
	char	*tmp;

	tmp = (char *)calloc(ft_strlen(path_list[0] + 5) + 1, 1);
	ft_memmove(tmp, path_list[0] + 5, ft_strlen(path_list[0] + 5));
	free(path_list[0]);
	path_list[0] = tmp;
}

void	prepend_cmd(char **path_list, char *cmd)
{
	int	i;

	i = -1;
	while (path_list[++i])
	{
		path_list[i] = c_strjoin(path_list + i, "/");
		path_list[i] = c_strjoin(path_list + i, cmd);
	}
}

// int main(int argc, char *argv[], char *envp[])
// {
// 	t_pipex	*var = (t_pipex *)malloc(sizeof(t_pipex));
// 	int		i;

// 	parser(var, argv, envp);
// 	i = -1;
// 	while (var->path1[++i])                               `
// 		printf("args1: %s\n", var->path1[i]);
// 	printf("\n");
// 	i = -1;
// 	while (var->path2[++i])
// 		printf("args2: %s\n", var->path2[i]);

// 	(void)argc;
// 	(void)argv;
// 	return (0);
// }
