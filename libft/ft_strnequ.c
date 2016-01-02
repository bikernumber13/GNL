/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:51:48 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/04 17:47:18 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	count;
	int		verif;

	verif = 1;
	count = 0;
	if (!s1 || !s2)
		return (0);
	while (count < n)
	{
		if (s1[count] != s2[count])
		{
			verif = 0;
			return (verif);
		}
		count++;
	}
	return (verif);
}
