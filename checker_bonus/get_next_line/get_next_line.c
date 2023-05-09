/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:55:34 by zbouhami          #+#    #+#             */
/*   Updated: 2022/12/24 17:56:43 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	my_free(void *to_free)
{
	if (!to_free)
		return ;
	free(to_free);
	to_free = NULL;
}

static char	*ft_find_line(int fd, char *buffer)
{
	char	*buff;
	ssize_t	read_return;

	if (!buffer)
		buffer = ft_strdup("");
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (my_free(buffer), NULL);
	read_return = 1;
	while (!find_newline(buffer) && read_return != 0)
	{
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return < 0)
			return (my_free(buffer), my_free(buff), NULL);
		buff[read_return] = '\0';
		if (read_return == 0)
			return (my_free(buff), buffer);
		buffer = ft_strjoin(buffer, buff);
	}
	my_free(buff);
	return (buffer);
}

static char	*split_line(char *to_split)
{
	char	*is_line;
	int		indx;

	indx = 0;
	if (!to_split[indx])
		return (NULL);
	while (to_split[indx] && to_split[indx] != '\n')
		indx++;
	if (to_split[indx] == '\n')
		indx++;
	is_line = malloc((indx + 1) * sizeof(char));
	if (!is_line)
		return (NULL);
	indx = 0;
	while (to_split[indx] && to_split[indx] != '\n')
	{
		is_line[indx] = to_split[indx];
		indx++;
	}
	if (to_split[indx] == '\n')
		is_line[indx++] = '\n';
	is_line[indx] = '\0';
	return (is_line);
}

static char	*rest_of_content(char *save)
{
	char	*tmp;
	char	*rest;
	size_t	indx;

	indx = 0;
	while (save[indx])
	{
		if (save[indx] == '\n')
		{
			tmp = &save[indx + 1];
			rest = malloc(ft_strlen(save) - indx + 1 * 1);
			if (!rest)
				return (my_free(save), NULL);
			rest = make_copy(rest, tmp);
			return (my_free(save), rest);
		}
		indx++;
	}
	return (my_free(save), NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*hold;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	hold = ft_find_line(fd, hold);
	if (!hold)
		return (NULL);
	line = split_line(hold);
	hold = rest_of_content(hold);
	return (line);
}
