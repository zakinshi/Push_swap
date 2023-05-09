/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:06:06 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 18:00:33 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack))
		return ;
	tmp = (*stack);
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void	stack_check(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && lst_len(stack_b) == 0)
	{
		put_str(GREEN);
		put_str("OK\n");
	}
	else
	{
		put_str(RED);
		put_str("KO\n");
	}
	put_str(WHITE);
}
