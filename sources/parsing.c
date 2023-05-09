/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:24:21 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 15:33:25 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		exit_message("Error : Over INT_MAX", BLUE);
	else if ((unsigned int)rslt > 2147483648 && sign == -1)
		exit_message("Error : Over INT_MIN", BLUE);
	return (rslt * sign);
}

void	str_to_int(t_stack **stack_a, char *s)
{
	t_stack	*tmp_node;
	char	**str_data;
	int		i;

	i = -1;
	str_data = ft_split(s, ' ');
	while (str_data[++i])
	{
		tmp_node = new_node(ft_atoi(str_data[i]));
		ft_addnode_back(stack_a, tmp_node);
	}
	free_all(str_data);
}

bool	is_duplicate(t_stack *start)
{
	bool	dup;
	t_stack	*tmp1;
	t_stack	*tmp2;

	dup = true;
	tmp1 = start;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
			{
				free_stack(&start);
				exit_message("Error : There's a Dup Number...", YELLOW);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (false);
}

void	check_string(char *s)
{
	int	i;
	int	non_int;
	int	is_sign;

	i = 0;
	is_sign = 0;
	non_int = 0;
	while (s[i])
	{
		non_int = (s[i] != ' ' && s[i] != '\t' && s[i] != '\n');
		is_sign = (s[i] == '+' || s[i] == '-');
		if (is_sign && !is_digit(s[i + 1]))
			exit_message("Error : NON-Intger Value After a Sign...", RED);
		else if (!is_digit(s[i]) && non_int && !is_sign)
			exit_message("Error : NON-Intger Value In The Args...", RED);
		i++;
	}
}
