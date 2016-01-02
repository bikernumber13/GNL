/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:20:18 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/04 17:35:43 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(s);
	while (len >= count)
	{
		if (c == s[len])
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
