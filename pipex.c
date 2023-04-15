/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:13:50 by roberodr          #+#    #+#             */
/*   Updated: 2023/04/14 18:14:20 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_index	i;

	if (argc != 5)
		ft_error(strerror(errno));
	i.infile = open(argv[1], O_RDONLY);
	if (i.infile < 0)
		i.infile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	i.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (i.outfile < 0)
		ft_error(strerror(errno));
	i.cmd1 = ft_split_cmd_arg(argv[2]);
	i.cmd2 = ft_split_cmd_arg(argv[3]);
	if (pipe(i.fd) == -1)
		return (1);
	i.pid1 = fork();
	if (i.pid1 < 0)
		return (0);
	ft_child(i, envp);
	ft_father(i, envp);
	waitpid(i.pid1, NULL, 0);
	return (1);
}
