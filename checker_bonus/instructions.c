/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbouhami <zbouhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:05:29 by zbouhami          #+#    #+#             */
/*   Updated: 2023/05/09 17:26:24 by zbouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_node(t_stack *s1, t_stack *s2)
{
	if (!s1 || !s2)
		return ;
	s1->data ^= s2->data;
	s2->data ^= s1->data;
	s1->data ^= s2->data;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp_head;
	t_stack	*tmp_2;

	if (!(*stack))
		return ;
	tmp_2 = *stack;
	tmp_head = *stack;
	*stack = (*stack)->next;
	while (tmp_head)
	{
		if (tmp_head->next == NULL)
		{
			tmp_head->next = tmp_2;
			tmp_2->next = NULL;
			break ;
		}
		tmp_head = tmp_head->next;
	}
}

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = *stack;
	while (head)
	{
		if (head->next == NULL)
			last = head;
		head = head->next;
	}
	head = *stack;
	last->next = head;
	while (head)
	{
		if (head->next == last)
			head->next = NULL;
		head = head->next;
	}
	*stack = last;
}

void	push_to_stack(t_stack **from, t_stack **to)
{
	t_stack	*tmp_head;

	tmp_head = NULL;
	if (*from == NULL)
		return ;
	tmp_head = *from;
	*from = ((*from)->next);
	tmp_head->next = *to;
	*to = tmp_head;
}
