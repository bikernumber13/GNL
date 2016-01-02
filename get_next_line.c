/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 18:15:51 by mbouhier          #+#    #+#             */
/*   Updated: 2016/01/02 13:01:24 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buf;
	static char *tmp[1024];

	if (!line || fd < 0 || BUFF_SIZE < 1 || (!(tmp[fd] = !tmp[fd] ?
			ft_strnew(1) : tmp[fd])))
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!ft_strchr(tmp[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
	}
	if (!ft_strchr(tmp[fd], '\n'))
	{
		*line = ft_strdup(tmp[fd]);
		tmp[fd] = NULL;
	}
	else
	{
		*line = ft_strsub(tmp[fd], 0, ft_strchr(tmp[fd], '\n') - tmp[fd]);
		tmp[fd] = ft_strsub(tmp[fd], ft_strchr(tmp[fd], '\n') - tmp[fd] + 1,
			ft_strlen(ft_strchr(tmp[fd], '\n')));
	}
	if (ret == -1)
		return (-1);
	free(buf);
	return (!ret && !tmp[fd] && !ft_strlen(*line) ? 0 : 1);
}
