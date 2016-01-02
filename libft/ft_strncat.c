/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:38:16 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/04 17:46:34 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		size_s1;
	size_t	count;

	size_s1 = ft_strlen(s1);
	count = 0;
	while (count < n)
	{
		s1[size_s1] = s2[count];
		count++;
		size_s1++;
	}
	s1[size_s1] = '\0';
	return (s1);
}
