/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:21:59 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/15 15:36:52 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int		min_index;

	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (min > tmp->data && tmp->rank == -1)
		{
			min = tmp->data;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (min_index);
}

void	set_rank(t_stack *stack)
{
	int		len_stack;
	int		i;
	int		min_indx;
	t_stack	*tmp;

	i = 0;
	tmp = (stack);
	len_stack = lst_len(tmp);
	while (--len_stack > -1)
	{
		tmp = stack;
		min_indx = is_min(stack);
		while (tmp->index != min_indx)
			tmp = tmp->next;
		if (tmp->rank == -1)
			tmp->rank = i;
		i++;
	}
}

void	init_all_rank(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->rank = -1;
		tmp = tmp->next;
	}
}

int	the_small(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int		min_indx;

	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			min_indx = tmp->index;
		}
		tmp = tmp->next;
	}
	return (min_indx);
}
