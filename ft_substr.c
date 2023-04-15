/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:12:47 by roberodr          #+#    #+#             */
/*   Updated: 2023/04/13 15:54:16 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*init;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		len = 0;
		init = malloc(sizeof(*init));
		if (init == NULL )
			return (0);
		*init = 0;
		return (init);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	init = malloc(sizeof(char) * (len + 1));
	if (init == NULL )
		return (NULL);
	ft_strlcpy(init, s + start, len + 1);
	return (init);
}
