/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:20:39 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/04 17:48:02 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countword(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_countword(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] != c && s[i + len])
				len++;
			tab[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	tab[j] = 0;
	return (tab);
}
