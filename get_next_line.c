/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 18:15:51 by mbouhier          #+#    #+#             */
/*   Updated: 2016/01/08 18:22:45 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_end_line(char *tmp2, char *tmp)
{
	tmp[0] = 0;
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
	static char tmp[256][BUFF_SIZE];

	if (!line || fd < 0 || fd > 255 || BUFF_SIZE < 1)
		return (-1);
	if (!(*line = *tmp[fd] ? ft_strdup(tmp[fd]) : ft_strnew(1)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*line = ft_strjoin_free(line, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	tmp2 = ft_strchr(*line, '\n');
	if (ft_end_line(tmp2, tmp[fd]) == 1 || ft_strlen(*line) || ret > 0)
		return (1);
	return (ret == 0 ? 0 : -1);
}
