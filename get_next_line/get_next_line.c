/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:35:51 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/12 14:54:10 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	byt_bef_newl(char *buff)
{
	size_t	x;

	x = 0;
	if (ft_strchr(buff, '\n') == NULL)
		return (ft_strlen(buff));
	while (buff[x] != '\n')
		x++;
	x++;
	return (x);
}

void	buff_surplus(char *buff)
{
	if (ft_strchr(buff, '\n'))
		ft_strcpy(buff, ft_strchr(buff, '\n') + 1);
	else
		buff[0] = '\0';
}

char	*final_processing(char *line, char *buff)
{
	char	*tmp;

	tmp = line;
	line = ft_substr(line, 0, byt_bef_newl(line));
	free(tmp);
	buff_surplus(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	int			r;

	line = ft_substr(buff, 0, BUFFER_SIZE);
	if (ft_strchr(buff, '\n'))
		return (final_processing(line, buff));
	r = read(fd, buff, BUFFER_SIZE);
	if ((fd < 0 || r <= 0 || BUFFER_SIZE < 1) && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	while (r > 0)
	{
		buff[r] = '\0';
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
		r = read(fd, buff, BUFFER_SIZE);
	}
	return (final_processing(line, buff));
}
