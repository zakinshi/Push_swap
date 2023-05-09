/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:03:41 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/15 15:32:14 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = NULL;
	call_instruction(&stack_a, &tmp, "sa");
}

void	sort_three(t_stack **stack_a)
{
	int		a;
	int		b;
	int		c;
	t_stack	*tmp;
	t_stack	*tmp_2;

	tmp = NULL;
	tmp_2 = *stack_a;
	a = tmp_2->data;
	b = tmp_2->next->data;
	c = tmp_2->next->next->data;
	if (a > b && a < c && b < c)
		call_instruction(stack_a, &tmp, "sa");
	else if (a > b && a > c && b < c)
		call_instruction(stack_a, &tmp, "ra");
	else if (a < b && a > c && b > c)
		call_instruction(stack_a, &tmp, "rra");
	else
		sort_three_2(stack_a, a, b, c);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		smallest;
	t_stack	*tmp;

	tmp = NULL;
	smallest = the_small(*stack_a);
	if (smallest == 0)
		call_instruction(stack_a, stack_b, "pb");
	else if (smallest == 1)
	{
		call_instruction(stack_a, &tmp, "ra");
		call_instruction(stack_a, stack_b, "pb");
	}
	else if (smallest == 3)
	{
		call_instruction(stack_a, &tmp, "rra");
		call_instruction(stack_a, stack_b, "pb");
	}
	else
		sort_four_2(stack_a, stack_b, smallest);
	sort_three(stack_a);
	call_instruction(stack_a, stack_b, "pa");
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		smallest;
	int		size;
	t_stack	*tmp;

	tmp = NULL;
	size = lst_len(*stack_a);
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
	sort_five_2(stack_a, stack_b, size);
	sort_three(stack_a);
	call_instruction(stack_a, stack_b, "pa");
	call_instruction(stack_a, stack_b, "pa");
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(*stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
