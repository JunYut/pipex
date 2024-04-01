/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:42:57 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/01 17:48:55 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parser(t_pipex *var, char **argv, char *envp[])
{
	int	i;

	var->cmds = (char ***)ft_calloc(var->count + 1, sizeof(char **));
	var->paths = (char ***)ft_calloc(var->count + 1, sizeof(char **));
	i = -1;
	while (++i < var->count)
		var->cmds[i] = ft_split(argv[2 + i], ' ');
	var->cmds[i] = NULL;
	i = -1;
	while (++i < var->count)
		var->paths[i] = path_parser(envp, *(var->cmds[i]));
	var->paths[i] = NULL;
}

char	**path_parser(char *envp[], char *cmd)
{
	char	**path_list;
	int		i;

	i = -1;
	while (envp[++i] && ft_strncmp(envp[i], "PATH=", 5))
		;
	path_list = ft_split(envp[i], ':');
	prepend_cmd(path_list, cmd);
	path_list[0] = trim_path(path_list[0], "PATH=");
	return (path_list);
}

char	*trim_path(char *cmd, char *path)
{
	char	*tmp;
	size_t	path_len;

	path_len = ft_strlen(path);
	tmp = ft_calloc(ft_strlen(cmd) - path_len + 1, 1);
	ft_memmove(tmp, cmd + path_len, ft_strlen(cmd) - path_len);
	c_free(cmd);
	return (tmp);
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
