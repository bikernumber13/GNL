/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 18:15:51 by mbouhier          #+#    #+#             */
/*   Updated: 2016/01/02 13:33:10 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_end_line(char **line, char **tmp, int const fd, char *tmp2)
{
	*line = ft_strsub(tmp[fd], 0, ft_strchr(tmp[fd], '\n') - tmp[fd]);
	tmp2 = tmp[fd];
	tmp[fd] = ft_strsub(tmp[fd], ft_strchr(tmp[fd], '\n') - tmp[fd] + 1,
		ft_strlen(ft_strchr(tmp[fd], '\n')));
	free(tmp2);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE];
	char		*tmp2;
	static char *tmp[1024];

	if (!line || fd < 0 || BUFF_SIZE < 1 || (!(tmp[fd] = !tmp[fd] ?
			ft_strnew(1) : tmp[fd])))
		return (-1);
	while (!ft_strchr(tmp[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp2 = tmp[fd];
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		free(tmp2);
	}
	if (!ft_strchr(tmp[fd], '\n'))
	{
		*line = ft_strdup(tmp[fd]);
		tmp[fd] = NULL;
	}
	else
		ft_end_line(line, tmp, fd, tmp2);
	if (ret == -1)
		return (-1);
	return (!ret && !tmp[fd] && !ft_strlen(*line) ? 0 : 1);
}
