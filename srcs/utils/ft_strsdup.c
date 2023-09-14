/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:10:22 by astachni          #+#    #+#             */
/*   Updated: 2023/09/14 16:14:17 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char	**ft_strsdup(char **src)
{
	ssize_t	i;
	char	**dest;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dest = malloc (sizeof(char *) * (i + 1));
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
