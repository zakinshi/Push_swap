/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:55:21 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 17:17:55 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_message(char *msg, char *color)
{
	put_str(color);
	put_str(msg);
	put_str(WHITE);
	exit(1);
}

bool	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	stacks_protection(t_stack **stack_a, t_stack **stack_b, char s)
{
	if (!stack_a && !stack_b)
		exit_message("STACK_NOT_EXIST..", RED);
	if (!*stack_a && !*stack_b)
		exit_message("STACK EMPTY..", RED);
	if (s == 'a' && !*stack_a)
		exit_message("STACK A EMPTY..", RED);
	else if (s == 'b' && !*stack_b)
		exit_message("STACK B EMPTY..", RED);
	else if (s == 's' && (!*stack_a || !*stack_b))
		exit_message("One Of Stacks is EMPTY..", RED);
}
