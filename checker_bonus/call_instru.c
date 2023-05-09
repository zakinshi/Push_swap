/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instru.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:08:44 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 18:03:21 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	call_swap(t_stack *stack_a, t_stack *stack_b, char which_stack)
{
	if (which_stack == 'a')
	{
		(void)stack_b;
		swap_node(stack_a, stack_a->next);
	}
	else if (which_stack == 'b')
	{
		(void)stack_a;
		swap_node(stack_b, stack_b->next);
	}
	else if (which_stack == 's')
	{
		swap_node(stack_a, stack_a->next);
		if (!stack_b || !stack_b->next)
			return ;
		swap_node(stack_b, stack_b->next);
	}
	else
		exit_message("Error : SWAP stack Not Defined..", RED);
}

void	call_push(t_stack **stack_a, t_stack **stack_b, char which_stack)
{
	if (which_stack == 'a')
		push_to_stack(stack_b, stack_a);
	else if (which_stack == 'b')
		push_to_stack(stack_a, stack_b);
	else
		exit_message("Error : PUSH Instrictions Not Defined..", RED);
}

void	call_rotate(t_stack **stack_a, t_stack **stack_b, char which_stack)
{
	if (which_stack == 'a')
	{
		(void)stack_b;
		ft_rotate(stack_a);
	}
	else if (which_stack == 'b')
	{
		(void)stack_a;
		ft_rotate(stack_b);
	}
	else if (which_stack == 'r')
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else
		exit_message("Error : Rotate Instrictions Not Defined..", RED);
}

void	call_rev_rotate(t_stack **stack_a, t_stack **stack_b, char which_stack)
{
	if (which_stack == 'a')
	{
		(void)stack_b;
		ft_rev_rotate(stack_a);
	}
	else if (which_stack == 'b')
	{
		(void)stack_a;
		ft_rev_rotate(stack_b);
	}
	else if (which_stack == 'r')
	{
		if (!*stack_a)
			return ;
		ft_rev_rotate(stack_a);
		if (!*stack_b)
			return ;
		ft_rev_rotate(stack_b);
	}
	else
		exit_message("Error : Rev-Rotate Instrictions Not Defined..", RED);
}

void	call_instruction(t_stack **stack_a, t_stack **stack_b, char *ins)
{
	ins_protect(ins);
	if (ins[0] == 's')
		call_swap((*stack_a), (*stack_b), ins[1]);
	else if (ins[0] == 'r')
	{
		if (ins[1] == 'r' && ins[2] != '\n')
			call_rev_rotate(stack_a, stack_b, ins[2]);
		else
			call_rotate(stack_a, stack_b, ins[1]);
	}
	else if (ins[0] == 'p')
		call_push(stack_a, stack_b, ins[1]);
}
