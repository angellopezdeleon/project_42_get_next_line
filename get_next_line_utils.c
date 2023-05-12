/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anglopez <anglopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:57:54 by anglopez          #+#    #+#             */
/*   Updated: 2023/05/12 11:58:50 by anglopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
		temp[--n] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem_zeros;

	mem_zeros = malloc(count * size);
	if (!mem_zeros)
		return (NULL);
	ft_bzero(mem_zeros, count * size);
	return (mem_zeros);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*str;
	size_t		total_len;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!s1 || !s2 || !str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
