/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:49:13 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/19 18:13:03 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

void	ft_cpy(char	*buff,char *str)
{
	int	i;

	i = 0;
	while (buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
}

char *get_next_line(int fd)
{
	static char	*buf;
	char	*str = malloc(1024);;
	int		h;

	h = 0;
	while (read(fd, buf, BUFFER_SIZE) != -1)
	{
		if ((h = is_new(buf)) == -1)
		{
			ft_cpy(buf, str);
		}
		else
		{
			ft_cpy(buf,str);
			break;
		}
	}
	return (str);
}

int main()
{
	int	fd;

	fd = open("text.txt", O_RDWR | O_CREAT);
	char *str = get_next_line(fd);
	printf("%s",str);
}