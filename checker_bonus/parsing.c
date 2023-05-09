/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:50:47 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/17 00:18:24 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	rslt;

	sign = 1;
	rslt = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		rslt = rslt * 10 + s[i] - '0';
		i++;
	}
	if ((unsigned int)rslt > 2147483647 && sign == 1)
		exit_message("Error", WHITE);
	return (rslt * sign);
}

void	str_to_int(t_stack **stack, char *s)
{
	t_stack	*tmp_node;
	char	**str_data;
	int		i;

	i = -1;
	str_data = ft_splited(s, ' ');
	while (str_data[++i])
	{
		tmp_node = new_node(ft_atoi(str_data[i]));
		ft_addnode_back(stack, tmp_node);
	}
	free_all(str_data);
}

bool	is_duplicate(t_stack *start)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = start;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				exit_message("Error : There Is a Duplicate Number ..", BLUE);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (false);
}

void	check_string(char *s)
{
	int	i;
	int	is_space;
	int	is_sign;

	i = 0;
	while (s[i])
	{
		is_space = (s[i] == ' ' || s[i] == '\t' || s[i] == '\n');
		is_sign = (s[i] == '+' || s[i] == '-');
		if (is_sign && !is_digit(s[i + 1]))
			exit_message("Error : Non-Int Value Entred After a Sign..", RED);
		else if (!is_digit(s[i]) && !is_space && !is_sign)
			exit_message("Error : Non-Int Value In The Args..", RED);
		i++;
	}
}
