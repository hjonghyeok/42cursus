/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:51:38 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/10 16:43:29 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *tmp)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (tmp[len] != '\n')
		len++;
	len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = tmp[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static char	*line_return(char **tmp, char *buf)
{
	char	*line;
	char	*free_tmp;

	free_tmp = *tmp;
	line = get_line(*tmp);
	if (!line)
		return (NULL);
	*tmp = ft_strdup(ft_strchr(*tmp, '\n') + 1);
	free(free_tmp);
	free(buf);
	free_tmp = NULL;
	buf = NULL;
	return (line);
}

static int	read_file(int fd, char *buf)
{
	int	ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
	{
		free(buf);
		buf = NULL;
		return (-1);
	}
	buf[ret] = 0;
	return (ret);
}

static char	*end_file(char **tmp, char *buf)
{
	char	*dest;

	free(buf);
	buf = NULL;
	if (ft_strlen(*tmp))
	{
		dest = *tmp;
		*tmp = NULL;
		return (dest);
	}
	else
	{
		free(*tmp);
		*tmp = NULL;
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buf;
	long		ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(tmp, '\n'))
	{
		ret = read_file(fd, buf);
		if (ret < 0)
			return (NULL);
		tmp = ft_strjoin(tmp, buf);
		if (!tmp)
			return (NULL);
		if (!ret)
			return (end_file(&tmp, buf));
	}
	return (line_return(&tmp, buf));
}
