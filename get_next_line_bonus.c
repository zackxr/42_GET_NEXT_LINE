/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:56:28 by ael-majd          #+#    #+#             */
/*   Updated: 2024/12/05 13:50:15 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	f_strchr(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_full(int fd, char *rest)
{
	int		byte_read;
	char	*buffer;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(rest), NULL);
	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		if (byte_read < 0)
			return (free(buffer), NULL);
		temp = rest;
		rest = ft_strjoin(rest, buffer);
		free(temp);
		if (!rest)
			return (free(buffer), NULL);
		temp = NULL;
		if (f_strchr(rest) >= 0)
			break ;
	}
	free(buffer);
	return (rest);
}

char	*ft_line(char **rest)
{
	char	*line;
	int		len;
	int		i;

	len = f_strchr(*rest);
	if (len < 0)
		return (ft_strdup(*rest));
	line = malloc(len + 2);
	if (!line)
		return (free(*rest), *rest = NULL, NULL);
	i = 0;
	while (i <= len)
	{
		line[i] = (*rest)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_rest(char **rest)
{
	int		f_new;
	char	*new_rest;

	f_new = f_strchr(*rest);
	if (f_new == -1)
		return (free(*rest), *rest = NULL, NULL);
	new_rest = ft_strdup(*rest + f_new + 1);
	if (!new_rest)
		return (free(*rest), *rest = NULL, NULL);
	free(*rest);
	*rest = NULL;
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (free(rest[fd]), rest[fd] = NULL, NULL);
	rest[fd] = ft_full(fd, rest[fd]);
	if (!rest[fd] || *rest[fd] == '\0')
		return (free(rest[fd]), rest[fd] = NULL, NULL);
	line = ft_line(&rest[fd]);
	rest[fd] = ft_rest(&rest[fd]);
	return (line);
}
