/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:47:25 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/21 17:47:55 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	nb;

	nb = 0;
	while (str[nb])
		nb++;
	return (nb);
}

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*result;

	i = 0;
	if (!(result = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = ft_strnew(ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		count;
	char		*str;

	if (!s)
		return (NULL);
	count = 0;
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	while ((count < len) && (s[start]))
		str[count++] = s[start++];
	str[count] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(s) + 1;
	while (count <= len)
	{
		if (c == s[count])
		{
			s = &s[count];
			return ((char *)s);
		}
		count++;
	}
	return (NULL);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buf;
	static char *tmp[1024];

	if (!line || fd < 0 || BUFF_SIZE < 1 || (!(tmp = !tmp ? ft_strnew(1) : str[fd])))
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while (!ft_strchr(tmp[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE) > 0))
	{
		buf[ret] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
	}
	if (!ft_strchr(tmp[fd], '\n'))
		*line = ft_strdup(tmp[fd]);
	else
		{
			*line = ft_strsub(tmp[fd], 0, ft_strchr(tmp[fd], '\n') - tmp[fd]);
			tmp[fd] = ft_strsub(tmp[fd], ft_strchr(tmp[fd], '\n') - tmp[fd] + 1, ft_strlen(ft_strchr(tmp[fd], '\n')));
		}
	if (ret == -1)
		return (-1);
	return (!ret && !ft_strlen(tmp[fd]) ? 0 : 1);
}
// result sans le \n
// return (1) == ligne lue
// return (0) == lecture terminee
// return (-1) == error
// lire depuis un fichier / entree standart / redirection / etc...
