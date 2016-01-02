/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:06:49 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/04 17:47:05 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	count_size;

	count_size = 0;
	while (count_size < n && src[count_size] != '\0')
	{
		dst[count_size] = src[count_size];
		count_size++;
	}
	if (count_size < n)
		while (count_size < n)
		{
			dst[count_size] = '\0';
			count_size++;
		}
	return (dst);
}
