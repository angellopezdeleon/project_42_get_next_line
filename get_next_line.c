/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anglopez <anglopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:21:47 by anglopez          #+#    #+#             */
/*   Updated: 2023/05/08 17:00:55 by anglopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *buff_for_next(char *buff_for_line)
{
	int i;
	int j;
	char *buff_for_next;

	i = 0;
	j = 0;
	while (buff_for_line[i] != '\n' && buff_for_line[i] != '\0')
		i++;
	if (buff_for_line[i] == '\0')
	{
		free(buff_for_line);
		return (NULL);
	}
	buff_for_next = ft_calloc(ft_strlen(buff_for_line) - i, sizeof(char));
	i++;
	while (buff_for_line[i] != '\0')
		buff_for_next[j++] = buff_for_line[i++];
	free(buff_for_line);
	return (buff_for_next);
}

static char *get_line(char *recived_buff)
{
	int i;
	char *line;

	i = 0;
	while (recived_buff[i] != '\n' && recived_buff[i] != '\0')
		i++;
	line = ft_substr(recived_buff, 0, i);
	return (line);
}

static char *join_buff(char *buff_a, char *buff_b)
{
	char *temp_buff;

	temp_buff = ft_strjoin(buff_a, buff_b);
	free(buff_a);
	return (temp_buff);
}

// Lee el archivo y llena el buffer hasta encontrar un salto de línea
static char *read_file(int fd, char *recived_buff)
{
	int fd_result;
	char *temp_buff;

	temp_buff = ft_calloc(BUFFER_SIZE, sizeof(char));
	fd_result = 1;
	while (fd_result > 0)
	{
		fd_result = read(fd, temp_buff, BUFFER_SIZE);
		recived_buff = join_buff(recived_buff, temp_buff);
		if (ft_strchr(recived_buff, '\n'))
			break ;
		fd_result = read(fd, temp_buff, BUFFER_SIZE);
	}
	free(temp_buff);
	return (recived_buff);
}

// Recibe un archivo y devuelve línea por línea
char *get_next_line(int fd)
{
    static char		*buffer;
    char			*line;

	printf("\nGNL llamada\n");
	printf("\nBUFFER_SIZE= %d\n", BUFFER_SIZE);
    if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	printf("\nGNL en proceso\n");
    buffer = read_file(fd, buffer);
	printf("\nbuffer: %s\n", buffer);
	if (!buffer)
		return (NULL);	
	line = get_line(buffer);
	printf("\nline: %s\n", line);
	buffer = buff_for_next(buffer);
    return (line);
}
