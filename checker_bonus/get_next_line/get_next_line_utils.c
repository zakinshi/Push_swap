/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:32:29 by zbouhami          #+#    #+#             */
/*   Updated: 2023/03/20 19:33:24 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline(char *search_in)
{
	size_t	indx;

	indx = 0;
	while (search_in && search_in[indx])
	{
		if (search_in[indx] == '\n')
			return (&search_in[indx + 1]);
		indx++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s) + 1;
	copy = (char *)malloc(len * sizeof(char));
	if (!copy)
		return (NULL);
	len = 0;
	while (*(s + len) != '\0')
	{
		*(copy + len) = *(s + len);
		len++;
	}
	*(copy + len) = '\0';
	return (copy);
}

char	*make_copy(char *copy, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	ls1;
	size_t	ls2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	joined = malloc(ls1 + ls2 + 1);
	if (!joined)
		return (my_free(s1), NULL);
	joined = make_copy(joined, s1);
	ls2 = 0;
	while (s2[ls2])
	{
		joined[ls1 + ls2] = s2[ls2];
		ls2++;
	}
	joined[ls1 + ls2] = '\0';
	my_free(s1);
	return (joined);
}
