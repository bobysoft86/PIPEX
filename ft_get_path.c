/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:26:53 by roberodr          #+#    #+#             */
/*   Updated: 2023/04/14 13:38:43 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*mini_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	ft_get_path(char *cmd, char **envp, char **f_path)
{
	char	**paths;
	char	*path;
	char	*path_cmd;
	int		i;
	int		fd;

		i = 0;
	paths = ft_split(ft_strchr(mini_path(envp), '/'), ':');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		fd = open(path_cmd, O_RDONLY);
		if (fd >= 0)
		{
			*f_path = path_cmd;
			close(fd);
			return ;
		}
		free(path_cmd);
		i++;
	}
	free(paths);
}
