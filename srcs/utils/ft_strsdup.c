/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:10:22 by astachni          #+#    #+#             */
/*   Updated: 2023/11/06 10:49:15 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char	**ft_strsdup(char **src)
{
	ssize_t	i;
	char	**dest;

	if (!src)
		return (NULL);
	dest = malloc (sizeof(char *) * (ft_strslen(src) + 1));
	if (!dest)
		return (free(dest), NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
			return (free_strs(dest), NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
