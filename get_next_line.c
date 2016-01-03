/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 18:15:51 by mbouhier          #+#    #+#             */
/*   Updated: 2016/01/02 20:47:08 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_end_line(char *tmp2, char *tmp)
{
	if (!tmp2)
		return (0);
	*tmp2 = '\0';
	tmp2++;
	ft_strcpy(tmp, tmp2);
	ft_memset(tmp2, 0, ft_strlen(tmp2));
	return (1);
}

static char	*ft_strjoin_free(char **line, char *buf)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	return (*line);
}

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp2;
	static char tmp[1024][BUFF_SIZE];

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(*line = *tmp[fd] ? ft_strdup(tmp[fd]) : ft_strnew(1)))
		return (-1);
	while (!(tmp2 = ft_strchr(*line, '\n')) &&
		(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*line = ft_strjoin_free(line, buf)))
			return (-1);
	}
	if (ft_end_line(tmp2, tmp[fd]) == 1 || ret > 0)
		return (1);
	return (ret == 0 ? 0 : -1);
}
