/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:47:25 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/21 17:47:55 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int		ret;
	int		i;
	int		j;
	char	*buf;

	i = 0;
	if (!(line = (char **)malloc(sizeof(char*) * "YOLO")))
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while (ret = read(fd, buf, BUFF_SIZE))
	{
		buf[ret] = '\0';
		if (!(line[i] = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
		j = 0;
		while (buf[j++])
			line[i][j] = buf[j];
		i++;
	}
	return (0);
}
// result sans le \n
// return (1) == ligne lue
// return (0) == lecture terminee
// return (-1) == error
// lire depuis un fichier / entree standart / redirection / etc...
