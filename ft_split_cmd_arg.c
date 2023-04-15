/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:16:53 by roberodr          #+#    #+#             */
/*   Updated: 2023/04/13 15:56:35 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split_cmd_arg(char *argv)
{
	char	**cmd_arg;
	int		i;

	i = 0;
	cmd_arg = ft_split(argv, ' ');
	return (cmd_arg);
}
