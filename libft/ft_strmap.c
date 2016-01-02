/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:20:57 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/04 17:33:16 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;
	int		count;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	count = 0;
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		str[count] = (*f)(s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}
