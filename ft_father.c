/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:01:24 by roberodr          #+#    #+#             */
/*   Updated: 2023/04/14 13:55:31 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_father(t_index index, char **envp)
{
	dup2(index.fd[0], STDIN_FILENO);
	ft_get_path(index.cmd2[0], envp, &index.path);
	if (index.path == NULL)
	{
		perror("ERRROR PATH 2");
		strerror(errno);
		exit(1);
	}
	index.cmd2 = ft_unioncmd(index.cmd2);
	close(index.fd[0]);
	close(index.fd[1]);
	dup2(index.outfile, STDOUT_FILENO);
	close(index.infile);
	if (execve(index.path, index.cmd2, envp) == -1)
	{
		perror("execve");
		strerror(errno);
		exit(1);
	}
}
