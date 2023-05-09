/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:43:05 by zbouhami          #+#    #+#             */
/*   Updated: 2023/04/15 14:20:29 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_swap(t_stack *stack_a, t_stack *stack_b, char which_stack)
{
	if (which_stack == 'a')
	{
		(void)stack_b;
		ft_swap_data_lst(stack_a, stack_a->next);
		put_str("sa\n");
	}
	else if (which_stack == 'b')
	{
		(void)stack_a;
		ft_swap_data_lst(stack_b, stack_b->next);
		put_str("sb\n");
	}
	else if (which_stack == 's')
	{
		ft_swap_data_lst(stack_a, stack_a->next);
		ft_swap_data_lst(stack_b, stack_b->next);
		put_str("ss\n");
	}
	else
		exit_message("Instrictions Not Defined..", RED);
}

void	call_push(t_stack **stack_a, t_stack **stack_b, char which_stack)
{
	if (which_stack == 'a')
	{
		push_to_stack(stack_b, stack_a);
		put_str("pa\n");
	}
	else if (which_stack == 'b')
	{
		push_to_stack(stack_a, stack_b);
		put_str("pb\n");
	}
	else
		exit_message("Instrictions Not Defined..", RED);
}

void	call_rotate(t_stack **stack_a, t_stack **stack_b, char which_stack)
{
	if (which_stack == 'a')
	{
		(void)stack_b;
		ft_rotate(stack_a);
		put_str("ra\n");
	}
	else if (which_stack == 'b')
	{
		(void)stack_a;
		ft_rotate(stack_b);
		put_str("rb\n");
	}
	else if (which_stack == 'r')
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		put_str("rr\n");
	}
	else
		exit_message("Instrictions Not Defined..", RED);
}

void	call_rev_rotate(t_stack **stack_a, t_stack **stack_b, char which_stack)
{
	if (which_stack == 'a')
	{
		(void)stack_b;
		ft_rev_rotate(stack_a);
		put_str("rra\n");
	}
	else if (which_stack == 'b')
	{
		(void)stack_a;
		ft_rev_rotate(stack_b);
		put_str("rrb\n");
	}
	else if (which_stack == 'r')
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
		put_str("rrr\n");
	}
	else
		exit_message("Instrictions Not Defined..", RED);
}

void	call_instruction(t_stack **stack_a, t_stack **stack_b, char *ins)
{
	if (ins[0] != 'p')
		stacks_protection(stack_a, stack_b, ins[1]);
	if (ins[0] == 's')
		call_swap((*stack_a), (*stack_b), ins[1]);
	else if (ins[0] == 'r')
	{
		if (ins[1] == 'r' && ins[2])
			call_rev_rotate(stack_a, stack_b, ins[2]);
		else
			call_rotate(stack_a, stack_b, ins[1]);
	}
	else if (ins[0] == 'p')
		call_push(stack_a, stack_b, ins[1]);
}
