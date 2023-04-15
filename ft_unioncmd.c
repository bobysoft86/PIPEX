/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unioncmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:15:18 by roberodr          #+#    #+#             */
/*   Updated: 2023/04/14 18:10:41 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_addspace(char *str)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	result = malloc(sizeof(char ) * (i + 2));
	if (result == NULL)
		return (0);
	while (j != i)
	{
		result[j] = str[j];
		j++;
	}
	result[j] = ' ';
	result[j + 1] = '\0';
	return (result);
}

char	**ft_unioncmd(char**str)
{
	t_union1	union1;

	union1.i = 2;
	union1.j = 0;
	if (str[2] == NULL)
		return (str);
	union1.result = malloc(3 * sizeof(char *));
	if (union1.result == NULL)
		return (0);
	union1.result[2] = NULL;
	while (union1.j < 2)
	{
		union1.result[union1.j] = str[union1.j];
		union1.j++;
	}
	while (str[union1.i] != NULL)
	{
		union1.tmp = ft_addspace(union1.result[1]);
		union1.result[1] = ft_strjoin(union1.tmp, str[union1.j]);
		union1.j++;
		union1.i++;
	}
	return (union1.result);
}
