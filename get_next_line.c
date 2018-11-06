/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:31:03 by amedvede          #+#    #+#             */
/*   Updated: 2018/11/05 20:33:28 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cut_end_line(char **thread, char **line,
		const int fd, ssize_t bytes_read)
{
	char	*tmp;
	int		line_length;

	line_length = 0;
	while (thread[fd][line_length] != '\0' && thread[fd][line_length] != '\n')
		line_length++;
	if (thread[fd][line_length] == '\n')
	{
		*line = ft_strsub(thread[fd], 0, line_length);
		tmp = ft_strdup(thread[fd] + line_length + 1);
		free(thread[fd]);
		thread[fd] = tmp;
	}
	else if (thread[fd][line_length] == '\0')
	{
		if (bytes_read == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(thread[fd]);
		ft_strdel(&thread[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*thread[254];
	ssize_t			bytes_read;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (thread[fd] == NULL)
			thread[fd] = ft_strnew(1);
		tmp = ft_strjoin(thread[fd], buf);
		free(thread[fd]);
		thread[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bytes_read < 0)
		return (-1);
	if (bytes_read == 0 && (thread[fd] == NULL || thread[fd][0] == '\0'))
		return (0);
	return (cut_end_line(thread, line, fd, bytes_read));
}
