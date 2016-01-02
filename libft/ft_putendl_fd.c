/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:20:15 by mbouhier          #+#    #+#             */
/*   Updated: 2015/11/24 18:24:58 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int count;

	count = 0;
	while (s[count] != '\0')
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
	ft_putchar_fd('\n', fd);
}
