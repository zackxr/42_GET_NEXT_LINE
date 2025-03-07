/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:10:18 by ael-majd          #+#    #+#             */
/*   Updated: 2024/12/05 13:49:35 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (byte_read < 0)
			return (free(buffer), NULL);
		buffer[byte_read] = '\0';
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
	int		linenew;
	int		i;

	linenew = f_strchr(*rest);
	if (linenew < 0)
		return (ft_strdup(*rest));
	line = malloc(linenew + 2);
	if (!line)
		return (free(*rest), *rest = NULL, NULL);
	i = 0;
	while (i <= linenew)
	{
		line[i] = (*rest)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_rest(char **rest)
{
	int		linenew;
	char	*new_rest;

	linenew = f_strchr(*rest);
	if (linenew == -1)
		return (free(*rest), *rest = NULL, NULL);
	new_rest = ft_strdup((*rest + linenew + 1));
	if (!new_rest)
		return (free(*rest), *rest = NULL, NULL);
	free(*rest);
	*rest = NULL;
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(rest), rest = NULL, NULL);
	rest = ft_full(fd, rest);
	if (!rest || *rest == '\0')
		return (free(rest), rest = NULL, NULL);
	line = ft_line(&rest);
	rest = ft_rest(&rest);
	return (line);
}
