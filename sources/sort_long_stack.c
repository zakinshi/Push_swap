/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:46:11 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/16 17:54:45 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_b_2(t_stack **stack_a, t_stack **stack_b, int *z)
{
	if ((*z)++ == 0)
	{
		call_instruction(stack_a, stack_b, "pb");
	}
	else
	{
		call_instruction(stack_a, stack_b, "pb");
		call_instruction(stack_a, stack_b, "rb");
	}
}

int	cible(t_stack *stack, int rank)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->rank <= rank)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	find_cible(t_stack **stack_a, int interval, int local)
{
	t_stack	*null;

	null = NULL;
	if (local < lst_len_non_index(*stack_a) / 2)
		while ((*stack_a)->rank > interval)
			call_instruction(stack_a, &null, "ra");
	else
		while ((*stack_a)->rank > interval)
			call_instruction(stack_a, &null, "rra");
}

void	chunks_sort_b(t_stack **stack_a, t_stack **stack_b, int end, int len)
{
	int			i;
	static int	z;
	int			half;
	int			local;

	i = 0;
	half = len / 2;
	while ((*stack_a) && i <= len - 1)
	{
		local = cible(*stack_a, end);
		if ((*stack_a)->rank <= end)
		{
			if ((*stack_a)->rank <= end - half)
				call_instruction(stack_a, stack_b, "pb");
			else
				chunk_b_2(stack_a, stack_b, &z);
			i++;
		}
		else
			find_cible(stack_a, end, local);
	}
}

void	long_sort(t_stack **stack_a, t_stack **stack_b, int size, int pieces)
{
	int	len_chunk;
	int	end;

	len_chunk = size / pieces;
	end = len_chunk;
	while (true)
	{
		size = lst_len_non_index(*stack_a);
		chunks_sort_b(stack_a, stack_b, end, len_chunk);
		if (lst_len_non_index(*stack_a) == 0)
			break ;
		end += len_chunk;
	}
	lst_len(*stack_b);
	chunk_sort_a(stack_a, stack_b);
}
