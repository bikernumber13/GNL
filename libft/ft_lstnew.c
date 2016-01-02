/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:22:44 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/04 17:43:36 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strndup(char const *s, size_t n)
{
	size_t	count;
	char	*str;

	count = 0;
	if (!(str = (char*)malloc(sizeof(str) * n)))
		return (NULL);
	while (count < n)
	{
		str[count] = s[count];
		count++;
	}
	return (str);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst_new;

	if (!(lst_new = (t_list*)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (!content)
	{
		lst_new->content = NULL;
		lst_new->content_size = 0;
	}
	else
	{
		lst_new->content = ft_strndup((char const *)content, content_size);
		lst_new->content_size = content_size;
	}
	lst_new->next = NULL;
	return (lst_new);
}
