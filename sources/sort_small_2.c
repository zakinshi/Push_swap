/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:59:30 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/15 15:29:50 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_2(t_stack **stack_a, int a, int b, int c)
{
	t_stack	*tmp;

	tmp = NULL;
	if (a > b && a > c && b > c)
	{
		call_instruction(stack_a, &tmp, "sa");
		call_instruction(stack_a, &tmp, "rra");
	}
	else if (a < b && a < c && b > c)
	{
		call_instruction(stack_a, &tmp, "sa");
		call_instruction(stack_a, &tmp, "ra");
	}
}

void	sort_four_2(t_stack **stack_a, t_stack **stack_b, int smallest)
{
	t_stack	*tmp;

	tmp = NULL;
	if (smallest == 2)
	{
		call_instruction(stack_a, &tmp, "ra");
		call_instruction(stack_a, &tmp, "ra");
		call_instruction(stack_a, stack_b, "pb");
	}
	else if (smallest == 4)
	{
		call_instruction(stack_a, &tmp, "rra");
		call_instruction(stack_a, stack_b, "pb");
	}
	else
		exit_message("stack of 4 problem sort..", RED);
}

void	sort_five_2(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*tmp;
	int		smallest;

	tmp = NULL;
	smallest = the_small(*stack_a);
	if (smallest <= size / 2)
	{
		while ((*stack_a)->index != smallest)
			call_instruction(stack_a, &tmp, "ra");
		call_instruction(stack_a, stack_b, "pb");
	}
	else
	{
		while ((*stack_a)->index != smallest)
			call_instruction(stack_a, &tmp, "rra");
		call_instruction(stack_a, stack_b, "pb");
	}
}
