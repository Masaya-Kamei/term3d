/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:14 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/21 14:06:27 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

static int	split_into_line_and_save(char **line, char **save)
{
	char	*new_line_ptr;
	char	*tmp;

	new_line_ptr = ft_strchr(*line, '\n');
	if (new_line_ptr == NULL)
		return (0);
	tmp = *line;
	*line = ft_substr(*line, 0, new_line_ptr - *line);
	if (*line == NULL)
	{
		free(tmp);
		return (-1);
	}
	*save = ft_substr(new_line_ptr + 1, 0, ft_strlen(new_line_ptr + 1));
	free(tmp);
	if (*save == NULL)
	{
		free(*line);
		return (-1);
	}
	return (1);
}

static int	read_until_include_nl(int fd, char **line)
{
	ssize_t	readsize;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (GNL_BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	readsize = 1;
	while (ft_strchr(*line, '\n') == NULL)
	{
		readsize = read(fd, buf, GNL_BUFFER_SIZE);
		if (readsize <= 0)
			break ;
		buf[readsize] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		if (*line == NULL)
		{
			free(buf);
			return (-1);
		}
	}
	free(buf);
	return (readsize);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;

	if (fd < 0 || fd >= 256 || line == NULL || GNL_BUFFER_SIZE <= 0)
		return (-1);
	if (save == NULL)
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
	}
	else
	{
		*line = save;
		save = NULL;
	}
	if (read_until_include_nl(fd, line) == -1)
	{
		free(*line);
		return (-1);
	}
	return (split_into_line_and_save(line, &save));
}
