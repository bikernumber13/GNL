/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:55:14 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/03 17:10:32 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int size_s1;
	int count;

	size_s1 = ft_strlen(s1);
	count = 0;
	while (s2[count] != '\0')
	{
		s1[size_s1] = s2[count];
		count++;
		size_s1++;
	}
	s1[size_s1] = '\0';
	return (s1);
}
