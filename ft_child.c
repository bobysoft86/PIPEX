/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:20:00 by roberodr          #+#    #+#             */
/*   Updated: 2023/04/14 13:52:11 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(t_index index, char **envp)
{
	if (index.pid1 == 0)
	{
		ft_get_path(index.cmd1[0], envp, &index.path);
		if (index.path == NULL)
		{
			perror ("ERROR PATH 1");
			strerror(errno);
			exit(1);
		}
		index.cmd1 = ft_unioncmd(index.cmd1);
		dup2(index.fd[1], STDOUT_FILENO);
		close(index.fd[0]);
		close(index.fd[1]);
		dup2(index.infile, STDIN_FILENO);
		close(index.infile);
		if (execve(index.path, index.cmd1, envp) == -1)
		{
			perror("execve");
			strerror(errno);
			exit(1);
		}
		exit(0);
	}
}
