/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:42:57 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/28 15:28:56 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parser(t_pipex *var, char **argv, char *envp[])
{
	var->cmd1 = ft_split(argv[2], ' ');
	var->cmd2 = ft_split(argv[3], ' ');
	var->path1 = path_parser(envp, *(var->cmd1));
	var->path2 = path_parser(envp, *(var->cmd2));
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
	free(cmd);
	return(tmp);
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
// 		printf("cmd1: %s\n", var->path1[i]);
// 	printf("\n");
// 	i = -1;
// 	while (var->path2[++i])
// 		printf("cmd2: %s\n", var->path2[i]);

// 	(void)argc;
// 	(void)argv;
// 	return (0);
// }
