/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anglopez <anglopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:21:47 by anglopez          #+#    #+#             */
/*   Updated: 2023/05/10 13:36:57 by anglopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *buff_for_next(char *buff_for_line)
{
	int		i;
	int		j;
	char	*buff_for_next;

	i = 0;
	j = 0;
	while (buff_for_line[i] && buff_for_line[i] != '\n')
		i++;
	if (!buff_for_line[i])
	{
		free(buff_for_line);
		return (NULL);
	}
	buff_for_next = ft_calloc(ft_strlen(buff_for_line) - i + 1, sizeof(char));
	i++;
	while (buff_for_line[i])
		buff_for_next[j++] = buff_for_line[i++];
	free(buff_for_line);
	return (buff_for_next);
}

char	*getting_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char *join_buff(char *buff_for_free, char *buff)
{
	char	*temp_buff;

	temp_buff = ft_strjoin(buff_for_free, buff);
	free(buff_for_free);
	return (temp_buff);
}

static char *read_file(int fd, char *recived_buff)
{
	int		fd_result;
	char	*temp_buff;

	if (!recived_buff)
		recived_buff = ft_calloc(1, sizeof(char));
	temp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	fd_result = 1;
	while (fd_result > 0)
	{
		fd_result = read(fd, temp_buff, BUFFER_SIZE);
		if (fd_result == -1)
		{
			free(temp_buff);
			return (NULL);
		}
		temp_buff[fd_result] = 0;
		recived_buff = join_buff(recived_buff, temp_buff);
		if (ft_strchr(temp_buff, '\n'))
			break ;
	}
	free(temp_buff);
	return (recived_buff);
}

char *get_next_line(int fd)
{
    static char		*buffer;
    char			*line;

    if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
    buffer = read_file(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = getting_line(buffer);
	buffer = buff_for_next(buffer);
    return (line);
}
