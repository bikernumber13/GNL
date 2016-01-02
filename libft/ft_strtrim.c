/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:22:08 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/04 17:37:59 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_blanks(char c)
{
	if (c == 32 || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	while (ft_blanks(s[i]) == 1)
		i++;
	while (ft_blanks(s[len - 1]) == 1)
		len--;
	return (ft_strsub(s, i, (len != 0) ? len -= i : len));
}
