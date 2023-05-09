/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:37:51 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/15 20:15:20 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reach_in(t_stack *stack, int indx)
{
	if (indx < lst_len_non_index(stack) - indx)
		return (indx);
	return (lst_len_non_index(stack) - indx);
}

int	find_target(t_stack *stack, int rank)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->rank == rank)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	head_it(t_stack **stack_b, int rank, int i)
{
	t_stack	*null;

	null = NULL;
	if (i < lst_len_non_index(*stack_b) / 2)
		while ((*stack_b)->rank != rank)
			call_instruction(&null, stack_b, "rb");
	else
		while ((*stack_b)->rank != rank)
			call_instruction(&null, stack_b, "rrb");
}

void	cible_push(t_stack **stack_a, t_stack **stack_b, int *size, int crush)
{
	int	bigger;

	head_it(stack_b, *size - 1, crush);
	call_instruction(stack_a, stack_b, "pa");
	bigger = find_target(*stack_b, *size);
	head_it(stack_b, *size, bigger);
	(*size)--;
	call_instruction(stack_a, stack_b, "pa");
	call_instruction(stack_a, stack_b, "sa");
}

void	chunk_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	bigger;
	int	crush;

	size = lst_len(*stack_b);
	while (size > 0)
	{
		size--;
		bigger = find_target((*stack_b), size);
		crush = find_target((*stack_b), size - 1);
		if (size == 0 || reach_in(*stack_b, bigger) < reach_in(*stack_b, crush))
		{
			head_it(stack_b, size, bigger);
			call_instruction(stack_a, stack_b, "pa");
		}
		else
			cible_push(stack_a, stack_b, &size, crush);
	}
}
